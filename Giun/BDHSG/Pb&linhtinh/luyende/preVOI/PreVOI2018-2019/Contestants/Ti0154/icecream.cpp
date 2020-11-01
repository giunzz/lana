#include <bits/stdc++.h>
#define For(i,a,b) for(int i=a;i<=b;i++)
#define mod 1000000007
using namespace std;
int n,m,f[51][101][101][101],p,q,r,X,Y,Z;
int F(int i,int x,int y,int z)
{
    if(f[i][x][y][z]!=-1) return f[i][x][y][z];
    if(i==n)
    {
        int res=0;
        if(x<m) res++;
        if(x>=1&&y<m) res++;
        if(x>=3&&z<m) res++;
        if(x>=1&&y>=1&&z<m) res++;
        return res;
    }
    long long res=0;
    if(x<m) res=(res+F(i+1,x+1,y,z))%mod;
    if(x>=1&&y<m) res=(res+F(i+1,x-1,y+1,z))%mod;
    if(x>=1&&y>=1&&z<m) res=(res+F(i+1,x-1,y-1,z+1))%mod;
    else if(x>=3&&z<m) res=(res+F(i+1,x-3,y,z+1))%mod;
    f[i][x][y][z]=res;
    return res;
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
    freopen("icecream.inp","r",stdin);
    freopen("icecream.out","w",stdout);
    cin>>n>>m>>p>>q>>r;
    For(i,1,n)
    For(j,0,m)
        For(k,0,m)
            For(l,0,m)
            f[i][j][k][l]=-1;
    cout<<F(1,p,q,r);
}
