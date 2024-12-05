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
    int ans=0;
    while (getline (MyReadFile, myText)) {
        string s = myText;
        vector<int> a;
        string s1;
        for(int i=0;i<s.size();i++){
            if(s[i]==' '){
                a.push_back(stoll(s1));
                s1=' ';
            }
            else 
                s1.push_back(s[i]);
        }
        a.push_back(stoll(s1));
        int f=0,g=0,fault=0;
        if(a[0]>a[a.size()-1])
            g=1;
        for(int i=1;i<a.size();i++){
            if(g){
                if(a[i-1]-a[i]<1 || a[i-1]-a[i]>3){
                    fault++;
                    if(i+1<a.size() && (a[i-1]-a[i+1]<1 || a[i-1]-a[i+1]>3)){
                        f=1;
                        break;
                    }else{
                        if(i+1>=a.size()&&fault>1){
                            f=1;
                            break;
                        }
                        i++;
                    }
                }
            }else{
                if(a[i]-a[i-1]<1 || a[i]-a[i-1]>3){
                    fault++;
                    if(i+1<a.size() && (a[i+1]-a[i-1]<1 || a[i+1]-a[i-1]>3)){
                        f=1;
                        break;
                    }else{
                        if(i+1>=a.size()&&fault>1){
                            f=1;
                            break;
                        }
                        i++;
                    }
                }
            }
        }
        // for(auto it:a)
        //     cout<<it<<" ";
        // cout<<endl;
        // cout<<f<<endl;
        if(!f)
            ans++;
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
