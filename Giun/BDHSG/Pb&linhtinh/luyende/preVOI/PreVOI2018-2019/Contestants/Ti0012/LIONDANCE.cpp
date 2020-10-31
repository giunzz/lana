#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
#define fs first
#define sd second
int n,delta,f[1005][1005],val[1005][1005],a[1005],b[1005],res=0,val1;
vector<int> ans;
ii vt,trace[1005][1005];
int main()
{
	freopen("LIONDANCE.inp","r",stdin);
	freopen("LIONDANCE.out","w",stdout);
	cin>>n>>delta;
	for (int i=1;i<=n;i++) cin>>a[i];
	for (int i=1;i<=n;i++) cin>>b[i];
	for (int i=n;i>=1;i--) for (int j=n;j>=1;j--)
    {
        if (a[i]==b[j])
        {
            f[i][j]=1; trace[i][j]=ii(i,j);
            for (int g=n;g>i;g--) for (int k=n;k>j;k--) if (a[g]==b[k] && abs(a[g]-a[i])<=delta)
            {
                if (f[i][j]<f[g][k]+1)
                {
                    f[i][j]=f[g][k]+1;
                    val[i][j]=a[g];
                    trace[i][j]=ii(g,k);
                } else if (f[i][j]==f[g][k]+1 && a[g]>val[i][j])
                {
                    val[i][j]=a[g];
                    trace[i][j]=ii(g,k);
                }
            }
        } else f[i][j]=0;
        if (res<f[i][j]) {res=f[i][j];val1=a[i]; vt=ii(i,j);}
        else if (res==f[i][j] && val1<a[i]) {val1=a[i];vt=ii(i,j);}
    }
    cout<<res<<endl;
    while (f[vt.fs][vt.sd]!=1) {ans.push_back(a[vt.fs]); vt=trace[vt.fs][vt.sd];}
    for (int i=0;i<ans.size();i++) cout<<ans[i]<<" ";cout<<a[vt.fs];
	return 0;
}
//8 3
//2 1 2 3 9 4 5 7
//2 3 2 1 7 4 5 9
