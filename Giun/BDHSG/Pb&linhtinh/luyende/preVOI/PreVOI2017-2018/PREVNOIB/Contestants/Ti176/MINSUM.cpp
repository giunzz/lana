#include <bits/stdc++.h>
#define int long long
using namespace std;
int a,b;
const int Nmax=1e5+7;
int t,uc[Nmax];
int get(int a,int b)
{
    if (b==0) return a;
    return get(b,a%b);
}
main()
{
    freopen("MINSUM.inp","r",stdin);
    freopen("MINSUM.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>t;
    for (int f=1;f<=t;f++)
    {
        cin>>a>>b;
        if (get(a,b)==1)
        {
            int w=a*b,Min=1e9+7;
            int amin,bmin,cnt=0;
            for (int i=1;i*i<=w;i++)
            {
                if (w%i==0)
                {
                    if ((i+w/i)<Min)
                    {
                        Min=i+w/i;
                        amin=i;
                        bmin=w/i;
                    }
                }
            }
            cout<<min(amin,bmin)<<" "<<max(amin,bmin)<<"\n";
        }
        else
        {
            int w=get(a,b);
            int cnt=0;
            for (int i=1;i*i<=w;i++)
            {
                if (w%i==0)
                {
                    uc[++cnt]=i;
                    uc[++cnt]=w/i;
                }
            }
            sort(uc+1,uc+cnt+1);
            int amin,bmin,Min=1e9+7;
            for (int i=1;i<=cnt;i++)
            {
                int x=a,y=b;
                int z=(a*b)/(uc[i]*uc[i]);
                for (int j=1;j*j<=z;j++)
                {
                    if (z%j==0)
                    {
                        if ((j+z/j)<Min)
                        {
                            Min=j+z/j;
                            amin=j;
                            bmin=z/j;
                        }
                    }
                }
            }
            cout<<min(amin,bmin)<<" "<<max(amin,bmin)<<"\n";
        }
    }
    return 0;
}
