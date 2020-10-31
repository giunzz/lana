#include<bits/stdc++.h>
using namespace std;
int a,b;
int n;
int c[10];
bool t=false;
unsigned long long mod=1,k;
void backb(vector<int > q)
{
    if(t==true) return ;
    if(q.size()>n) return ;
    if(q.size()==n)
    {
        unsigned long long smt=0;
        for(int i=0; i<q.size(); i++) smt=(smt*  (unsigned long long) 10+ (unsigned long long) q[i])%mod;
        if(smt==k)
        {
            for(int i=0; i<q.size(); i++) cout<<q[i];
            t=true;
        }
    }
    for(int i=0; i<2; i++)
    {
        q.push_back(c[i]);
        backb(q);
        q.pop_back();
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("MODULO.inp","r",stdin);
    freopen("MODULO.out","w",stdout);
    cin>>a>>b;
    cin>>n>>k;
    c[0]=a,c[1]=b;
    for(int i=1; i<=n; i++) mod=mod*(unsigned long long)2;
    vector<int > v;
    backb(v);
    if(t==false) cout<<"-1"<<"\n";
    //cout<<clock();
    return 0;
}
