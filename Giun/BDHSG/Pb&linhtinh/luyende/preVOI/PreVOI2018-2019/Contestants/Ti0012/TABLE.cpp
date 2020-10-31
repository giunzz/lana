#include<bits/stdc++.h>
using namespace std;
int n,m,k;
long long f[305][305],a[305][305],oo=(long long)1e15;
int main()
{
	freopen("TABLE.inp","r",stdin);
	freopen("TABLE.out","w",stdout);
	cin>>n>>m>>k;
	for (int i=1;i<=n;i++) for (int j=1;j<=m;j++) cin>>a[i][j];
	for (int g=1;g<=k;g++)
    {
        int u1,v1,u2,v2;
        cin>>u1>>v1>>u2>>v2;
        long long res=oo;
        for (int p=u1;p<=u2;p++) for (int q=v1;q<=v2;q++)
        {
            if ((p==u1 && q==v1)||(p==u2 && q==v2)) continue;
            for (int i=u1;i<=u2;i++) for (int j=v1;j<=v2;j++)
            {
                if (i==u1 && j==v1)
                {
                    if (u1==p && v1==q) f[u1][v1]=0; else f[u1][v1]=a[u1][v1];
                    continue;
                }
                f[i][j]=-oo;
                if (i-1>=u1 && ((i-1==1 && j==1)||(q!=i-1 || p!=j))) f[i][j]=max(f[i][j],f[i-1][j]+a[i][j]);
                if (j-1>=v1 && ((i-1==1 && j==1)||(q!=i || p!=j-1))) f[i][j]=max(f[i][j],f[i][j-1]+a[i][j]);
            }
            if (p==u2 && q==v2) res=min(res,max(f[u2-1][v2],f[u2][v2-1])); else res=min(res,f[u2][v2]);
        }
        cout<<res<<endl;
    }
	return 0;
}
