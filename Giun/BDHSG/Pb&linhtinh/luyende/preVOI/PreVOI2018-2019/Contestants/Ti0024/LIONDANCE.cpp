#include <bits/stdc++.h>
using namespace std;
#define maxn 4005
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define pii pair<int,int>
int n,d,L[maxn],R[maxn],f[maxn][maxn],res,dem;
pii id[16000005];
int qu[16000005];
main()
{
    freopen("LIONDANCE.inp","r",stdin);
    freopen("LIONDANCE.out","w",stdout);
    scanf("%d%d",&n,&d);
    for(int i=1; i<=n; ++i)
        scanf("%d",&L[i]);
    for(int i=1; i<=n; ++i)
        scanf("%d",&R[i]);
    for(int i=1; i<=n; ++i)
        for(int j=1; j<=n; ++j)
           if(L[i]==R[j])
    {
        qu[++dem]=L[i];
        id[dem]=mp(i,j);
    }
       for(int t=dem; t>=1; --t)
        {
            int i=id[t].F;
            int j=id[t].S;
            f[i][j]=1;
            int q=upper_bound(id+1,id+dem+1,mp(i,j)) - id;
            if(q!=dem+1)
            {
                for(int u=q; u<=dem; ++u)
                   if(abs(qu[u]-L[i]) <= d && abs(qu[u]-R[j]) <= d && id[u].S > j && id[u].F > i)
                       f[i][j]=max(f[i][j],f[id[u].F][id[u].S]+1);
            }
            res=max(res,f[i][j]);
        }
    int pos=0;
    printf("%d\n",res);
    while(res > 0)
    {
        int pos1=pos;
        int maxx=0;
        for(int i=pos+1; i<=dem; ++i)
            if(f[id[i].F][id[i].S]==res && id[i].S > id[pos1].S && id[i].F > id[pos1].F)
                if(qu[i] > maxx)
                    {
                        maxx=qu[i];
                        pos=i;
                    }
        printf("%d ",maxx);
        res--;
    }
}
