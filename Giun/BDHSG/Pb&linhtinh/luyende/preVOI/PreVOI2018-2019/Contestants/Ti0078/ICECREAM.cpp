#include<bits/stdc++.h>
using namespace std;

const int modd=(int)1e9+9;

int n,mmax,m50,m1,m2;
long long f[300][300][300],g[300][300][300];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("ICECREAM.INP","r",stdin);
    freopen("ICECREAM.OUT","w",stdout);

    cin>>n>>mmax;
    cin>>m50>>m1>>m2;

    f[m50][m1][m2]=1;

    for(int per=0;per<n;++per)
    {
        //cout<<per<<":\n";

        for(int i=0;i<=mmax;++i)
        {
            for(int j=0;j<=mmax;++j)
            {
                for(int k=0;k<=mmax;++k)
                {
                    if(f[i][j][k]==0)continue;

                    //cout<<i<<" "<<j<<" "<<k<<" "<<f[i][j][k]<<'\n';

                    if(i<mmax)
                    {
                        //cout<<1<<'\n';
                        g[i+1][j][k]+=f[i][j][k];
                    }
                    if(i>=1 && j<mmax)
                    {
                        //cout<<2<<'\n';
                        g[i-1][j+1][k]+=f[i][j][k];
                    }
                    if(i>=1 && j>=1 && k<mmax)
                    {
                        //cout<<3<<'\n';
                        g[i-1][j-1][k+1]+=f[i][j][k];
                    }
                    else
                    {
                        if(i>=3 && k<mmax)
                        {
                            //cout<<4<<'\n';
                            g[i-3][j][k+1]+=f[i][j][k];
                        }
                    }
                }
            }
        }

        for(int i=0;i<=mmax;++i)
            for(int j=0;j<=mmax;++j)
                for(int k=0;k<=mmax;++k)f[i][j][k]=g[i][j][k]%modd,g[i][j][k]=0;
    }

    long long res=0;

    for(int i=0;i<=mmax;++i)
        for(int j=0;j<=mmax;++j)
            for(int k=0;k<=mmax;++k)res=(res+f[i][j][k])%modd;

    cout<<res;
}
