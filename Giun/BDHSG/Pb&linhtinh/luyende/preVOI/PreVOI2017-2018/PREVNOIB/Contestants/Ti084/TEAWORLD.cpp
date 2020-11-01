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
typedef struct
{
	double x,y,z;
	double r;
} point;
typedef struct
{
	double x,y,z;
	long long e;
} tea_point;
typedef struct
{
	double x,y,z;
} pvh_point;
void io()
{
    freopen("TEAWORLD.inp","r",stdin);
    freopen("TEAWORLD.out","w",stdout);
}
int m,n,k;
long long cal(pvh_point a,tea_point b,point c)
{
	double s=(a.x*b.y-a.y*b.x+b.x*c.y-b.y*c.x+c.x*a.y-c.y*a.x);
	s=s*s;
	double ch=((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
	double h=s/ch;
	double r1=(c.x-a.x)*(c.x-a.x)+(c.y-a.y)*(c.y-a.y);
	double r2=(c.x-b.x)*(c.x-b.x)+(c.y-b.y)*(c.y-b.y);
	if(c.r*c.r>=min(r1,r2) and c.r*c.r<max(r1,r2)) return 1;
	if(r1<=c.r*c.r and r2<=c.r*c.r) return 0;
	if(a.x==0 and b.x==0)
	{
		if(c.y>=min(a.y,b.y) and c.y<=max(a.y,b.y)) if(h<=c.r*c.r) return 1;
		return 0;
	}
	if(a.y==0 and b.y==0)
	{
		if(c.x>=min(a.x,b.x) and c.x<=max(a.x,b.x)) if(h<=c.r*c.r) return 1;
		return 0;
	}
	if(c.x>=min(a.x,b.x) and c.x<=max(a.x,b.x) and c.y>=min(a.y,b.y) and c.y<=max(a.y,b.y))
			if(h<=c.r*c.r) return 1;
	return 0;
}
pvh_point pvh;
point a[2001];
tea_point b[2001];
vector <int> X[20];
int d[2001],er=0,x[20];
long long res=0,ans=0;
void bk(int i)
{
	if(i>n)
	{
		res=max(res,ans);
		return;
	}
	ft(j,0,1)
	{
		x[i]=j;
		if(j==0) bk(i+1);
		else
		{
			ftm(z,0,X[i].size())
			{
				int v=X[i][z];
				if(d[v]==0) er++;
				d[v]++;
			}
			ans+=b[i].e;
			if(er<=k) bk(i+1);
			ans-=b[i].e;
			ftm(z,0,X[i].size())
			{
				int v=X[i][z];
				d[v]--;
				if(d[v]==0) er--;
			}
		}
	}
}
int main()
{
    #ifndef Mirai
        io();
    #endif //Mirai
    scanf("%d%d%d",&m,&n,&k);
    ft(i,1,m)
    	scanf("%lf%lf%lf%lf",&a[i].x,&a[i].y,&a[i].z,&a[i].r);
    ft(i,1,n)
    	scanf("%lf%lf%lf%lld",&b[i].x,&b[i].y,&b[i].z,&b[i].e);
    scanf("%lf%lf%lf",&pvh.x,&pvh.y,&pvh.z);
    ft(i,1,n)
    {
    	if(b[i].x==pvh.x and b[i].y==pvh.y) continue;
    	ft(j,1,m)
    	{
    		int ans=cal(pvh,b[i],a[j]);
    		if(ans==1) X[i].add(j);
    	}
    }
    bk(1);
    cout<<res;
    return 0;
}
/*
12 5 4
0 10 0 1
1 5 0 2
1 4 0 2
0 0 0 2
10 0 0 1
3 -1 0 2
5 -1 0 2
10 10 0 15
0 -10 0 1
10 -10 0 1
-10 -10 0 1
10 10 0 1
0 10 0 240
10 0 0 200
10 -2 0 52
-10 0 0 100
1 1 0 2
0 0 0

1 2 0
0 0 0 1
-1 0 0 5
2 0 0 100
1 0 0


1 1 4
0 0 0 1
0 0 0 10
0 0 0
*/