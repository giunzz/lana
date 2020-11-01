#include <bits/stdc++.h>
using namespace std;
int n,k;
int l[4003],r[4003];
int f[4003][4003];
int main()
{
    ifstream cin("LIONDANCE.inp");
    ofstream cout("LIONDANCE.out");
    cin>>n>>k;
    for(int i(1);i<=n;++i)
        cin>>l[i];
      for(int i(1);i<=n;++i)
        cin>>r[i];
    for(int i(1);i<=n;i++)
    {
        for(int j(1);j<=n;++j)
        {
            f[i][j]=max(f[i-1][j],f[j-1][i]);
            if(l[i]==r[j]) f[i][j]=max(f[i-1][j-1]+1,f[i][j]);
        }
    }
    cout<<f[n][n]<<endl;
    stack<int> V;
    int d=n,gt=f[n][n];
    f[0][0]=0;
    for(int i(n);i>=1;--i)
    {
        for(int j(d);j>=1;--j)
        {
            if(f[i][j]==gt-1&&f[i+1][j+1]==gt) {
                    V.push(l[i+1]);gt--;d=j-1;--i;}
        }
    }
    if(V.size()<f[n][n]) cout<<l[1]<<" ";
    while(!V.empty()) {cout<<V.top()<<" ";V.pop();}
}
