#include <iostream>
#include <cstdio>
#define NAME "TEAWORLD."
#define FOR(i,a,b) for(int i=a;i<=b;++i)
using namespace std;
typedef  long long ll;
#define maxm (2000+2)
#define maxn (15+2)
int m,n,k;
struct cau{int x,y,z,r; cau(){} cau(int ix,int iy,int iz,int ir){x=ix;y=iy;z=iz;r=ir;} }c[maxm];
struct store{int x,y,z,e; store(){} store(int ix,int iy,int iz,int ie) {x=ix;y=iy;z=iz;e=ie;} }  s[maxn];
int xs,ys,zs;

void input(){
    cin>>m>>n>>k;
    FOR(i,1,m) {
        int x,y,z,r;
        cin>>x>>y>>z>>r;
        c[i]=cau(x,y,z,r);
    }
    FOR(i,1,n){
        int x,y,z,e;
        cin>>x>>y>>z>>e;
        s[i]=store(x,y,z,e);
//        cout<<s[i].x<<" "<<s[i].y<<" "<<s[i].z<<" "<<s[i].e<<"\n";
    }
    cin>>xs>>ys>>zs;
}

bool ok_s1(){
    FOR(i,1,m) if (c[i].y!=0 || c[i].z!=0) return false;
    FOR(i,1,n) if (s[i].y!=0 || s[i].z!=0) return false;
    if (ys!=0 || zs!=0) return false;
    return true;
}

bool check(int r){
//    FOR(i,xs,xs+r) (if i>=-500 && i<=500)

}

bool Xuli_s1(){
    #define e(x) sua[(x)+500]
    #define cnv(x) cnv[(x)+500]
    int sua[1010]={0};
    int cnv[1010]={0};
    FOR(i,1,n) e(s[i].x)=s[i].e;
//    FOR(i,-500+1,500) {e(i)+=e(i-1);} //cout<<e(i)<<"\n";}
    FOR(i,1,m) cnv(c[i].x)++;
//    FOR(i,-500+1,500) {cnv(i)+=cnv(i-1);}// cout<<cnv(i)<<"\n";}
    ll s1=0,s2=0;
    int prek=k;
    FOR(i,xs,500) {
        if (cnv(i)) k--;
        if (k<0) break;
        s1+=e(i);
    }
    k=prek;
    for(int i=xs;i>=-500;i--){
        if (cnv(i)) k--;
        if (k<0) break;
        s2+=e(i);
    }
    cout<<max(s1,s2);
}


int main()
{
    freopen(NAME"inp","r",stdin);
    freopen(NAME"out","w",stdout);
    iostream::sync_with_stdio(0);
    input();
    if (ok_s1()) {Xuli_s1(); return 0;}
}
