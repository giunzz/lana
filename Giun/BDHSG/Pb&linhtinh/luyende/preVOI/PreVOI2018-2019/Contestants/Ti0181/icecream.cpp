#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) x.begin(),x.end()
#define rep(i,x) for(int _x=x,i=0;i<_x;++i)
#define finc(i,a,b) for(int _b=b,i=a;i<=_b;++i)
#define fdec(i,a,b) for(int _b=b,i=a;i>=_b;--i)
#define fast_io ios_base::sync_with_stdio(false); cin.tie(nullptr)
#define pb push_back
typedef pair<int,int> ii;
#define x first
#define y second
// -----------------------------------------------------------
struct iii{
    int d50=0,d1=0,d2=0;
};
const int N=500,mod=1e9+9;
int n,m50,m1,m2,P[N+2][2*N+2][N+2],sum,res,lim50,lim1,lim2;
void input(){
    int mmax;
    cin >> n >> mmax >> m50 >> m1 >> m2;
    lim50=mmax;
    lim1=(mmax-(m1-min(m1,n)));
    lim1=min(lim1,2*n);
    m1=min(m1,n);
    lim2=mmax-m2;
    lim2=min(lim2,n);
    m2=0;
}
void calc50(int i,iii a,int val){
    ++a.d50;
    if (a.d50>lim50) return;
    int &z=P[i+1][a.d1][a.d2];
    z+=val;
    if (z>=mod) z-=val;
}
void calc1(int i,iii a,int val){
    if (!a.d50) return;
    --a.d50;
    ++a.d1;
    if (a.d1>lim1) return;
    int &z=P[i+1][a.d1][a.d2];
    z+=val;
    if (z>=mod) z-=mod;
}
void calc2(int i,iii a,int val){
    ++a.d2;
    if (a.d2>lim2) return;
    if (a.d50&&a.d1){
        --a.d50;
        --a.d1;
    } else if (a.d50>=3){
        a.d50-=3;
    } else return;
    int &z=P[i+1][a.d1][a.d2];
    z+=val;
    if (z>=mod) z-=mod;
}
void solve(){
    int sum=m50*5+m1*10+m2*20;
    P[0][m1][m2]=1;
    finc(i,0,n-1){
        finc(d1,0,lim1)
            finc(d2,0,lim2) if (P[i][d1][d2]){
                iii tmp;
                tmp.d50=(sum-d1*10-d2*20)/5;
                tmp.d1=d1;
                tmp.d2=d2;
                calc50(i,tmp,P[i][d1][d2]);
                calc1(i,tmp,P[i][d1][d2]);
                calc2(i,tmp,P[i][d1][d2]);
            }
        sum+=5;
    }
    finc(d1,0,lim1)
        finc(d2,0,lim2){
            res+=P[n][d1][d2];
            if (res>=mod) res-=mod;
        }
    cout << res;
}
int main(){
    fast_io;
    freopen("icecream.inp","r",stdin);
    freopen("icecream.out","w",stdout);
    input();
    solve();
    return 0;
}







