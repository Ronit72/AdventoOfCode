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
#define INT_MAX LLONG_MAX
#define INT_MIN LLONG_MIN
void solve()
{
    string myText;
    ifstream MyReadFile("C:/Users/Ronit/Desktop/aoc_2023/input.txt");
    vector<string> s;
    while (getline (MyReadFile, myText)) {
        s.push_back(myText);
    }
    int ans=0;
    string s1="MAS";
    for(int i=0;i<s.size();i++){
        for(int j=0;j<s[0].size();j++){
            if(s[i][j]=='M'){
                //diagonal
                int r=i,c=j,p=0;
                while(c<s.size()&&r<s[0].size()&&s[r][c]==s1[p]){
                    r++;
                    c++;
                    p++;
                }
                if(p==3 && (s[i][c-1]=='M'&&s[r-1][j]=='S' || s[i][c-1]=='S'&&s[r-1][j]=='M'))
                    ans++;
                r=i,c=j,p=0;
                while(c<s.size()&&r>=0&&s[r][c]==s1[p]){
                    r--;
                    c++;
                    p++;
                }
                if(p==3 && (s[i][c-1]=='M'&&s[r+1][j]=='S' || s[i][c-1]=='S'&&s[r+1][j]=='M'))
                    ans++;
                r=i,c=j,p=0;
                while(c>=0&&r<s[0].size()&&s[r][c]==s1[p]){
                    r++;
                    c--;
                    p++;
                }
                if(p==3 && (s[i][c+1]=='M'&&s[r-1][j]=='S' || s[i][c+1]=='S'&&s[r-1][j]=='M'))
                    ans++;
                r=i,c=j,p=0;
                while(c>=0&&r>=0&&s[r][c]==s1[p]){
                    r--;
                    c--;
                    p++;
                }
                if(p==3 && (s[i][c+1]=='M'&&s[r+1][j]=='S' || s[i][c+1]=='S'&&s[r+1][j]=='M'))
                    ans++;
            }
        }
    }
    cout<<ans/2<<endl;
}
int32_t main()
{
    fastio();
    int t = 1;
    //cin>>t;
    for(int test=1;test<=t;test++)
    {
        // cout<<"Case #"<<test<<": ";
        solve();
    }
    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
    return 0;
}
