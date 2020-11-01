#include <bits/stdc++.h>

using namespace std;
int n,a,l[4004],r[4004],ma=0,maxkc=0,b[4004],c[4004];
void dfs(int u,int v,int k)
{
    if(k==maxkc)
    {
        bool kt=true;
        for(int i=1;i<=maxkc;i++)
            if(b[i]>c[i]) kt=false;
        if(kt==false)
            for(int i=1;i<=maxkc;i++) c[i]=b[i];
    }
    if(k>maxkc)
    {
        maxkc=k;
        for(int i=1;i<=maxkc;i++) c[i]=b[i];
    }
    if(u>n || v>n) return;
    for(int i=u;i<=n;i++)
        for(int j=v;j<=n;j++)
            if(l[i]==r[j])
            {
                b[k]=l[i];
                dfs(i+1,j+1,k+1);
            }
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("LIONDANCE.INP","r",stdin);
    freopen("LIONDANCE.OUT","w",stdout);
    cin >> n >> a;
    for(int i=1;i<=n;i++) cin >> l[i];
    for(int i=1;i<=n;i++) cin >> r[i];
    c[1]=l[1];
    b[1]=l[1];
    for(int i=2;i<=4000;i++) b[i]=-1;
    dfs(2,2,2);
    for(int i=1;i<=maxkc;i++) if(c[i]!=-1) ma++;
    cout << ma<<endl;
    for(int i=1;i<=ma;i++) cout <<c[i] << " ";
    return 0;
}
