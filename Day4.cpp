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
void solve()
{
    string myText;
    ifstream MyReadFile("C:/Users/Ronit/Desktop/input.txt");
    int ans=0,ans1=0;
    while (getline (MyReadFile, myText)) {
        string s;
        ans1++;
        vector<int> n;
        for(int i=0;i<myText.size();i++)
        {
            if(myText[i]=='-'||myText[i]==',')
            {
                n.push_back(stoi(s));
                s.clear();
            }
            else
                s.push_back(myText[i]);
        }
        n.push_back(stoi(s));
        if(n[1]<n[2]||n[3]<n[0])
        {
            // cout<<n[0]<<" ";
            ans++;
        }
    }
    cout<<ans1-ans<<" ";
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
