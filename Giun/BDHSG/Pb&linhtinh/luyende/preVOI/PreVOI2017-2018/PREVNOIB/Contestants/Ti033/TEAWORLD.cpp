#include<bits/stdc++.h>
#define N 22
#define M 1000000
using namespace std;
int m,n,k;
bool sub1=true, sub2=true;
double res=0;
double xx,yy,zz;
struct hdm{
    double x,y,z,r;
} b[100*N], a[N], Z;
vector<int> Cut[N];
bool d[100*N];
int getbit(int x, int i){return (x >> i) & 1;}
/*******************************************************************/
void update1(int val)
    {
        double mn=xx, mx=xx;
        double rs=0;
        for (int i=1; i <= n; i++)
            if (getbit(val,i-1)){
                rs+=a[i].r;
                mn=min(mn,a[i].x);
                mx=max(mx,a[i].x);
            }
        int sl=0;
        for (int i=1; i <= m; i++){
            if ((b[i].x-b[i].r <= mn)&&(mx <= b[i].x+b[i].r)) continue;
            if ((mn <= b[i].x)&&(b[i].x <= mx))
                sl++;
            else{
                if ((b[i].x-b[i].r <= mn)&&(mn <= b[i].x+b[i].r))
                    sl++;
                else{
                    if ((b[i].x-b[i].r <= mx)&&(mx <= b[i].x+b[i].r))
                        sl++;
                }
            }
        }
        if (sl <= k) res=max(res,rs);
    }
/*******************************************************************/
void update2(int val)
    {
    }
/*******************************************************************/
void sol12(int i, int val)
    {
        if (i > n){
            if (sub1){update1(val);return;}
            if (sub2){update2(val);return;}
            return;
        }
        sol12(i+1,val*2);
        sol12(i+1,val*2+1);
    }
void sub12()
    {
        sol12(1,0);
        cout<<res;
    }
/*******************************************************************/
double getDist(hdm p1, hdm p2)
    {
        double x=p1.x-p2.x;
        double y=p1.y-p2.y;
        double z=p1.z-p2.z;
        return x*x+y*y+z*z;
    }
bool cont(double l, double r){return r-l >= 0.00001;}
bool cut(hdm p1, hdm p2, hdm p3)
    {
        double dist=M;
        {
            double C1=getDist(p1,p3);
            double C2=getDist(p2,p3);
            double ll=0, rr=C1;
            double ml=ll+(rr-ll)/3, mr=rr-(rr-ll)/3;
            while (cont(ll,ml)&&cont(ml,mr)&&cont(mr,rr)){
                double len11=C1-ml*ml; len11=sqrt(len11);
                double len12=C2-ml*ml; len12=sqrt(len12);
                double len21=C1-mr*mr; len21=sqrt(len21);
                double len22=C2-mr*mr; len22=sqrt(len22);
                if (len11+len12 < len21+len22)
                    rr=ml;
                  else
                    rr=mr;
            }
            dist=(ll+rr)/2, dist=dist;
        }
        return (dist < p3.r*p3.r);
    }
bool inB(hdm p1, hdm p2)
    {
        return (getDist(p1,p2) <= p2.r*p2.r);
    }
void prepare()
    {
        for (int i=1; i <= n; i++)
            for (int j=1; j <= m; j++)
                if (inB(Z,b[j])&&inB(a[i],b[j])){

                }
                else{
                    if (cut(Z,a[i],b[j]))
                        Cut[i].push_back(j);
                }
    }
void update(int val)
    {
        memset(d,0,sizeof d);
        double rs=0;
        for (int i=1; i <= n; i++)
            if (getbit(val,i-1)){
                rs+=a[i].r;
                for (int j=0; j < Cut[i].size(); j++)
                    d[Cut[i][j]]=1;
            }
        int sl=0;
        for (int i=1; i <= m; i++)
            if (d[i]) sl++;
        if (sl <= k) res=max(res,rs);
    }
void sol(int i, int val)
    {
        if (i > n){
            update(val);
            return;
        }
        sol(i+1,val*2);
        sol(i+1,val*2+1);
    }
void solve()
    {
        sol(1,0);
    }
int main()
{
    freopen("TEAWORLD.inp","r",stdin);
    freopen("TEAWORLD.out","w",stdout);
    ios::sync_with_stdio(0);
    cin>>m>>n>>k;
    for (int i=1; i <= m; i++){
        cin>>b[i].x>>b[i].y>>b[i].z>>b[i].r;
        sub1&=((b[i].y == 0)&&(b[i].z == 0));
        sub2&=(b[i].z == 0);
    }
    for (int i=1; i <= n; i++){
        cin>>a[i].x>>a[i].y>>a[i].z>>a[i].r;
        sub1&=((a[i].y == 0)&&(a[i].z == 0));
        sub2&=(a[i].z == 0);
    }
    if (k == m){
        double res=0;
        for (int i=1; i <= n; i++)
            res+=a[i].r;
        cout<<res;
        return 0;
    }
    cin>>xx>>yy>>zz;
    if (sub12){
        sub12();
        return 0;
    }
    prepare();
    solve();
    return 0;
}
