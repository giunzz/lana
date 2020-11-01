#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> oo;
vector <int> g[5001];
int n,d[5001];
void khoitao()
{
    freopen("TREE.INP","r",stdin);
    freopen("TREE.OUT","w",stdout);
}
void dong()
{
    fclose(stdin);
    fclose(stdout);
}
struct ii
{
    int val,cha;
};
ii root[5001];
void nhap()
{
    cin>>n;int p1,p2;
    for(int i=1;i<=n;i++)
    {
        cin>>root[i].val;
    }
    d[1]=1;
    for(int i=1;i<=n-1;i++)
    {
        cin>>p1>>p2;
        root[p2].cha=p1;
        if(p2!=1) d[p2]=d[p1]+1;
        g[p1].push_back(p2);
    }

}
bool cmp(oo a,oo b)
{
    return a.first>b.first;
}
void xuli()
{
    int ans=0;
    for(int i=1;i<=n;i++)
        if(g[i].size()==0 && root[i].val!=1)
    {

        ans+=abs(root[i].val-1);
         root[i].val=1;
    }
    int h;
    vector <oo> p;
    for(int i=1;i<=n;i++)
        if(g[i].size()!=0 )
    {

        p.push_back(oo(d[i],i));

    }
    sort(p.begin(),p.end(),cmp);
    for(int i=0;i<p.size();i++)
    {
        h=0;
        for(int j=0;j<g[p[i].second].size();j++)
        {
            h+=root[g[p[i].second][j]].val;
        }
        if(root[p[i].second].val!=h) {ans+=abs(root[p[i].second].val-h);root[p[i].second].val=h;}
    }
   cout<<ans;
}
int main()
{
    khoitao();
    nhap();
    xuli();
    dong();
}
