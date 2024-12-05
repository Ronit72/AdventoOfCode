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
    int f=0;
    vector<vector<int>> s;
    map<int,set<int>> m;
    while (getline (MyReadFile, myText)) {
        if(myText==""){
            f=1;
            continue;
        }
        if(f){
            vector<int> z;
            for(int i=0;i<myText.size();i+=3){
                z.push_back(stoll(myText.substr(i,2)));
            }
            s.push_back(z);
        }
        else{
            m[stoll(myText.substr(0,2))].insert(stoll(myText.substr(3,2)));
        }
    }
    int ans=0;
    for(int i=0;i<s.size();i++){
        int f1=0;
        for(int j=0;j<s[i].size();j++){
            for(int k=j+1;k<s[i].size();k++){
                if(m[s[i][j]].find(s[i][k])==m[s[i][j]].end()){
                    f1=1;
                    break;
                }
            }
            if(f1==1)
                break;
        }
        if(f1==1){
            int size=s[i].size()/2;
            for(int j=0;j<s[i].size();j++){
                int c=0;
                for(int k=0;k<s[i].size();k++){
                    if(j==k)
                        continue;
                    if(m[s[i][j]].find(s[i][k])!=m[s[i][j]].end()){
                        c++;
                    }
                }
                if(c==size){
                    ans=ans+s[i][j];
                    break;
                }
            }
        }
    }
    cout<<ans<<endl;
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
