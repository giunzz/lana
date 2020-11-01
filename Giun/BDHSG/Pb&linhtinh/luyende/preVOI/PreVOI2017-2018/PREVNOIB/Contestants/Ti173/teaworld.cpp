#include<bits/stdc++.h>
using namespace std;
int res,m,n,k,xs,ys,zs;
bool del[2003];

struct node
{
	int x,y,z,val;
};
node st, tra[20], cau[2003];

void read()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("teaworld.inp","r",stdin);
	freopen("teaworld.out","w",stdout);
	cin>>m>>n>>k;
	for (int i=1;i<=m;++i) cin>>cau[i].x>>cau[i].y>>cau[i].z>>cau[i].val;
	for (int i=1;i<=n;++i) cin>>tra[i].x>>tra[i].y>>tra[i].z>>tra[i].val;
	cin>>xs>>ys>>zs;
	node st;
	st.x=xs;st.y=ys;st.z=zs;st.val=0;
}

int dis(node a, node b)
{
	return ((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

void solve()
{
	for (int mask=0;mask<(1<<n);++mask)
	{
		memset(del,0,sizeof(del));
		/*for (int j=1;j<=m;++j)
			if (dis(st,cau[j]) <= cau[j].val*cau[j].val)
				del[j]=true;*/
		int tmp=0, sum=0;
		for (int i=0;i<n;++i)
			if (mask & (1<<i))
			{
				sum+=tra[i+1].val;
				for (int j=1;j<=m;++j)
				{
					bool ok1=(dis(tra[i+1],cau[j]) <= cau[j].val*cau[j].val);
					bool ok2=(dis(st,cau[j]) <= cau[j].val*cau[j].val);
					if ((ok1 && !ok2) || (ok2 && !ok1))
						del[j]=true;
				}
			}
		for (int i=1;i<=m;++i) if (del[i]) tmp++;
		if (tmp<=k) res=max(res,sum);
	}
	cout<<res;
}

int main()
{
	read();
	solve();
}