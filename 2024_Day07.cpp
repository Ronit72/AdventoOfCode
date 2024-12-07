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
void op(vector<int> &a,int &val,bool &check,int ind,int ca){
    if(val==ca && ind==a.size()-1){
        check=true;
        return;
    }
    if(ind>=a.size()-1||check)
        return;
    op(a,val,check,ind+1,ca*a[ind+1]);
    op(a,val,check,ind+1,ca+a[ind+1]);
    int z = log10(a[ind+1])+1;
    int po=1;
    while(z--)
        po*=10;
    op(a,val,check,ind+1,ca*po+a[ind+1]);
}
void solve()
{
    string myText;
    ifstream MyReadFile("C:/Users/Ronit/Desktop/aoc_2023/input.txt");
    string s;
    int ans=0;
    while (getline (MyReadFile, myText)) {
        s = myText;
        s.push_back(' ');
        vector<int> z;
        string x;
        int val;
        for(int i=0;i<s.size();i++){
            if(s[i]>='0'&&s[i]<='9')
                x.push_back(s[i]);
            else if(s[i]==':'){
                val=stoll(x);
                x="";
            }else if(s[i]==' '){
                if(x.size()>0)
                z.push_back(stoll(x));
                x="";
            }
        }
        bool check=false;
        op(z,val,check,0,z[0]);
        if(check){
            ans+=val;
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
