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
struct tree{
    int val;
    string s;
    tree * pt;
    vector<tree *> n;
    tree(int v,string s1,tree *pt1)
    {
        pt=pt1;
        val=v;
        s=s1;
    }
};
void pre(tree *root)
{
    if(root!=NULL)
    {
        for(auto it:root->n)
            pre(it);
        if(root->pt!=NULL)
        root->pt->val+=root->val;
    }
}
int c=70000000;
void ct(tree *root,int z)
{
    if(root!=NULL)
    {
        if(root->val+z>=30000000)
            c=min(c,root->val);
        for(auto it:root->n)
            ct(it,z);
    }
}
void solve()
{
    string myText;
    ifstream MyReadFile("C:/Users/Ronit/Desktop/input.txt");
    tree *root=new tree(0,"/",NULL);
    tree *root1=root;
    tree *root2=root;
    while (getline (MyReadFile, myText)) 
    {
        if(myText[0]=='$')
        {
            string s1=myText.substr(2,2);
            if(s1=="cd")
            {
                string s2;
                for(int i=5;i<myText.size();i++)
                    s2.push_back(myText[i]);
                // cout<<s2<<" ";
                if(s2=="..")
                { 
                    // cout<<root->pt->s<<" ";
                    if(root->pt!=NULL)
                        root=root->pt;
                }
                else
                {
                    if(s2=="/")
                        continue;
                    // cout<<root->n.size()<<" ";
                    for(auto it:root->n)
                    {
                        if(it->s == s2)
                        {
                            root=it;
                            break;
                        }
                    }
                }
            }
        }
        else
        {
            string s1=myText.substr(0,3);
            if(s1=="dir")
            {
                string s2;
                for(int i=4;i<myText.size();i++)
                    s2.push_back(myText[i]);
                tree *z=new tree(0,s2,root);
                root->n.push_back(z);
            }
            else
            {
                string s2;
                for(int i=0;i<myText.size();i++)
                {
                    if(myText[i]>='0'&&myText[i]<='9')
                    s2.push_back(myText[i]);
                }
                root->val+=stoll(s2);
            }
        }
    }
    pre(root1);
    int z=70000000-root1->val;
    ct(root1,z);
    cout<<c<<endl;
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
