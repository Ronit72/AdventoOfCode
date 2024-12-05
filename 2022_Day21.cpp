#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds; // find_by_order(iterator at that position), order_of_key(strictly less than elements)
#define int long long int  
#define float long double
#define mod 1000000007
#define fastio() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endl "\n"
map<string,pair<pair<string,string>,string>> m1;
map<string,int> m;
int sol(string &s)
{
    if(m.find(s)!=m.end())
        return m[s];
    int ans=0;
    if(m1.find(s)!=m1.end())
    {
        if(m1[s].second=="+")
            ans=sol(m1[s].first.first)+sol(m1[s].first.second);
        else if(m1[s].second=="-")
            ans=sol(m1[s].first.first)-sol(m1[s].first.second);
        else if(m1[s].second=="/")
            ans=sol(m1[s].first.first)/sol(m1[s].first.second);
        else 
            ans=sol(m1[s].first.first)*sol(m1[s].first.second);
    }
    return ans;
}
void solve()
{
    string myText;
    ifstream MyReadFile("C:/Users/Ronit/Desktop/input.txt");
    while (getline (MyReadFile, myText)) {
        string z=myText.substr(0,4);
        if(myText.size()==17)
        {
            string z1=myText.substr(6,4);
            string z2=myText.substr(13,4);
            string z3=myText.substr(11,1);
            m1[z]={{z1,z2},z3};
            // cout<<z1<<" "<<z2<<" "<<z3<<endl;
        }
        else
        {
            string z1;
            for(int i=6;i<myText.size();i++)
            {
                if(myText[i]>='0'&&myText[i]<='9')
                    z1.push_back(myText[i]);
            }
            m[z]=stoll(z1);
        }
    }
    string s="root";
    // cout<<sol(s)<<"\n";
    // cout<<m["humn"]<<" ";
    int i=3375719472500;
    int p=sol(m1[s].first.second);
    cout<<p<<"||";
    while(1)
    {
        m["humn"]=i;
        cout<<i<<"->";
        cout<<sol(m1[s].first.first)<<"\n";
        if(sol(m1[s].first.first)==p)
            break;
        // cout<<i<<" "; 
        i++;
    }
    cout<<"ans->->\n";
    cout<<i<<" ";
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
