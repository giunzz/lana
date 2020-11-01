#include <bits/stdc++.h>
#define ft(i,x,y) for(int i=x;i<=y;i++)
#define ftd(i,x,y) for(int i=x;i>=y;i--)
#define ftm(i,x,y) for(int i=x;i<y;i++)
#define ftdm(i,x,y) for(int i=x;i>y;i--)
#define fi first
#define se second
#define add push_back
#define ad push
using namespace std;
void io()
{
    freopen("TREE.inp","r",stdin);
    freopen("TREE.out","w",stdout);
}
long long _fabs(long long a)
{
	if(a<0) return -a;
	return a;
}
int n;
int a[5002],in[5002],ou,_max[5002],leaf[5002];
long long f[5002][5002],res=1e18;
vector <int> X[5002];
void DFS(int u)
{
	if(X[u].size()==0)
	{
		f[u][0]=_fabs(a[u]-0);
		f[u][1]=_fabs(a[u]-1);
		_max[u]=1;
		return;
	}
	ftm(i,0,X[u].size())
	{
		int v=X[u][i];
		DFS(v);
	}
	if(X[u].size()==1)
	{
		int v=X[u][0];
		ft(i,0,_max[v])
			f[u][i]=f[v][i]+_fabs(a[u]-i);
		_max[u]=_max[v];
		return;
	}
	if(X[u].size()==2)
	{
		int v=X[u][0],v1=X[u][1];
		ft(i,0,_max[v])
			ft(j,0,_max[v1])
				f[u][i+j]=min(f[u][i+j],f[v][i]+f[v1][j]+_fabs(a[u]-(i+j)));
		_max[u]=_max[v]+_max[v1];
		return;
	}
}

void sub_1_2()
{
	ft(i,1,n)
    	if(X[i].size()==0) ou++;
    ft(i,0,n)
    	ft(j,0,ou) f[i][j]=1e18;
    ft(i,1,n)
    {
    	if(in[i]==0)
    	{
    		DFS(i);
    		ft(j,0,ou)
    		{
    			res=min(res,f[i][j]);
    			//cout<<res<<" "<<j<<"\n";
    		}

    		cout<<res;
    		break;
    	}
    }
}
int main()
{
    #ifndef Mirai
        io();
    #endif //Mirai
    scanf("%d",&n);
    ft(i,1,n) scanf("%d",&a[i]);
    ft(i,1,n-1)
    {
    	int u,v;
    	scanf("%d%d",&u,&v);
    	X[u].add(v);
    	in[v]++;
    }
    sub_1_2();
    return 0;
}


/*
5
1 2 9 5 0
1 2
1 3
3 4
3 5
*/
/*
7
1 0 2 9 2 6 99
1 2
1 3
2 4
2 5
3 6
3 7
*/