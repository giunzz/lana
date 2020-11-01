#include<bits/stdc++.h>
#define task "TEAWORLD"
#define ll long long
#define ff(i,a,b) for(int i=a; i<=b; ++i)
#define fd(i,a,b) for(int i=a; i>=b; --i)
#define rr(i,a,b) for(int i=a; i<b; ++i)
#define rd(i,a,b) for(int i=a; i>b; --i)
#define pb push_back
#define mp make_pair
using namespace std;

const int M=2E3+10;
const int N=30;
const double Episode_revenge_of_the_sith=1E-4;
struct pt
{
	double a, b, c;
	pt(){}
	pt(double aa, double bb, double cc){a=aa, b=bb, c=cc;}
};

struct point
{
	double x, y ,z;
	point(){}
	point(double xx, double yy, double zz){x=xx, y=yy, z=zz;}
} prof, b[N], a[M];

int res, n, m, k, e[N]; double r[M];
int choose[N]; bool av[M];

pt makePt(point a, point b)
{
	point v=point(a.y-b.y, b.x-a.x, 0); // vector
	// ax + by == ax0 + by0
	pt c=pt(v.x, v.y, -v.x*a.x-v.y*a.y);
	return c;
}

double calc(point a, pt b)
{
	if(b.a==0 && b.b==0)return 0;
	return abs(b.a*a.x + b.b*a.y + b.c)/sqrt(b.a*b.a + b.b*b.b);
	//cout<<b.a + b.b<<endl;
	//return abs(b.a*a.x + b.b*a.y + b.c)/sqrt(b.a + b.b);
}

point giao(pt a, pt b)
{
	double D, Dx, Dy, A1, B1, C1, A2, B2, C2;
	A1=a.a, B1=a.b, C1=-a.c;
	A2=b.a, B2=b.b, C2=-b.c;
	D=A1*B2-A2*B1;
	Dx=C1*B2-C2*B1;
	Dy=A1*C2-A2*C1;
	point res=point(Dx/D, Dy/D, 0);
	return res;
}

double CCW(point a, point b, point c)
{
	return (a.x-b.x)*(c.y-b.y) - (a.y-b.y)*(c.x-b.x);
}

bool wtf(point a, point b, point c, point d)
{
	//cout<<a.x<<" "<<a.y<<"      "<<b.x<<" "<<b.y<<endl;
	return CCW(a, c, d)*CCW(b, c, d)<=0 && CCW(c, a, b)*CCW(d, a, b)<=0; 
}

double D(point a, point b)
{
	return sqrt( (a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y) );
}

bool wtf1(point a, point b, point c)
{
	if(D(a, c)+D(b,c)==D(a,b))return true; else return false;
}

bool isAPoint(point a, point b)
{
	return a.x==b.x&&a.y==b.y;
}

bool cut(point a, point b, point c, pt gg)
{
	point v=point(-gg.b, gg.a, 0); // vector
	pt C=pt(v.x, v.y, -v.x*a.x-v.y*a.y); 
	point wp=giao(gg, C); //cout<<" giao = "<<a.x<<" "<<a.y<<endl;
	// lay dx
	point hf=point(wp.x*2-a.x, wp.y*2-a.y, 0); 
	if(isAPoint(a, hf))
		return wtf1(b, c, a); else
	return wtf(b, c, a, hf);
}

void checking()
{
	int melk=0; //cout<<D(a[1],prof)<<endl;
	memset(av, false, sizeof(av)); int sl=0;// cout<<endl;
	//ff(i, 1, n)if(choose[i])cout<<1<<" "; else cout<<0<<" "; cout<<endl;
	ff(i, 1, n)if(choose[i])
	{
		pt gg=makePt(prof, b[i]); 
		//cout<<i<<": "<<b[i].x<<" "<<b[i].y<<"   "<<gg.a<<" "<<gg.b<<" "<<gg.c<<endl;
		ff(j, 1, m)if(!av[j] && ( cut(a[j], prof, b[i], gg) || D(a[j],prof)<r[j] ) )
		{
			double dist = calc(a[j],  gg);
			//cout<<" "<<j<<": dust ="<<dist<<endl;
			if( dist<=r[j] && (D(prof, a[j])>r[j] || D(a[j], b[i])>r[j]) ) 
			{	av[j]=true, sl++;
				////cout<<"  "<<j<<" "<<D(a[j],prof)<<" is down\n";
			}
			if(sl>k)return;
		}
		
		melk+=e[i];
	}
	//cout<<"OK "<<melk<<"\n";
	res=max(res, melk);
}

void brute(int pos)
{
	if(pos>n) checking(); 
	else
	for(int i=0; i<=1; ++i)
	{
		choose[pos]=i;
		brute(pos+1);
	}
}

void sol1()
{
	brute(1);
	cout<<res;
}

int main()
{
	freopen(task".inp","r",stdin);
	freopen(task".out","w",stdout);
	cin >> m >> n >> k;
	ff(i, 1, m)cin >> a[i].x >> a[i].y >> a[i].z >> r[i];
	ff(i, 1, n)cin >> b[i].x >> b[i].y >> b[i].z >> e[i];
	//ff(i, 1, n)cout<<b[i].x<<" "<<b[i].y<<endl;
	cin >> prof.x >> prof.y >> prof.z;
	sol1();
	return 0;
}
