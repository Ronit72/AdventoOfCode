#include <bits/stdc++.h>
// #include<ext/pb_ds/assoc_container.hpp>
// #include<ext/pb_ds/tree_policy.hpp>
using namespace std;
// using namespace __gnu_pbds;
// typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds; // find_by_order(iterator at that position), order_of_key(strictly less than elements)
#define int long long int  
#define float long double
#define mod 1000000007
#define fastio() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endl "\n"
void solve()
{
    string myText;
    ifstream MyReadFile("C:/Users/Ronit/Desktop/input.txt");
    int ans=0,x=1,cc=0;
    vector<string> z2;
    string z1;
    while (getline (MyReadFile, myText)) 
    {
        string s=myText.substr(0,4);
        if(s=="noop")
            cc++;
        else
            cc+=2;
        string s1;
        int z=0;
        if(s!="noop")
        {
            for(int i=5;i<myText.size();i++)
                s1.push_back(myText[i]);
            z=stoll(s1);
            if(cc-1>=x&&cc-1<=x+2)
            {
                z1.push_back('#');
                if(z1.size()==40)
                {
                    z2.push_back(z1);
                    z1.clear();
                    cc=cc%40;
                }
                if(cc>=x&&cc<=x+2)
                    z1.push_back('#');
                else
                    z1.push_back('.');
            }
            else
            {
                z1.push_back('.');
                if(z1.size()==40)
                {
                    z2.push_back(z1);
                    z1.clear();
                    cc=cc%40;
                }
                if(cc>=x&&cc<=x+2)
                    z1.push_back('#');
                else
                    z1.push_back('.');
            }
        }
        else
        {
            if(cc>=x&&cc<=x+2)
            {
                z1.push_back('#');
            }
            else
            {
                z1.push_back('.');
            }
        }
        if(z1.size()==40)
        {
            z2.push_back(z1);
            z1.clear();
            cc=cc%40;
        }
        x=x+z;
    }
    for(auto it:z2)
    {
        for(int i=0;i<it.size();i++)
            cout<<it[i];
        cout<<endl;
    }
    MyReadFile.close();
}
int32_t main()
{
    fastio();
    int t = 1;
    // cin>>t;
    for(int test=1;test<=t;test++)
    {
        // cout<<"Case #"<<test<<": ";
        solve();
    }
    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
    return 0;
}
