#include <bits/stdc++.h>
#define x first
#define y second
#define ii pair <long long, int>
#define pb push_back
#define mp make_pair
using namespace std;

const int N=2e6+5;
int a, b, d[25], kq, kh;
long long n, k, mod, dem;
vector <ii> x1, x2;

void tinh(int xx, int n1)
{
    if(kq) return;
    if(xx>n1){
        long long s=0;
        int cs=0;
        for(int i=n1; i>0; --i){
            int them;
            if(d[i]==0) them=a;
            else { them=b; cs+=(1ll<<i); }
            s=(s*10+them)%mod;
        }
        if(dem==0){
            if(s!=k) return;
            for(int i=n1; i>0; --i){
                if(d[i]==0) cout <<a;
                else cout <<b;
            }
            kq=1;
            return;
        }
        if(dem==1) {
            for(int i=1; i<=n-n1; ++i) s=(10*s)%mod;
            x1.pb(mp(s, cs));
            return;
        }
        x2.pb(mp(s, cs));
        return;
    }
    for(int i=0; i<2; ++i) { d[xx]=i; tinh(xx+1, n1); }
}

void sub1()
{
    mod=(1ll<<n);
    tinh(1, n);
    if(kq==0) cout <<-1;
}

void in(int kq1, int kq2)
{
    for(int i=kh; i>0; --i){
        if((1ll*kq1>>i)%2==0) cout <<a;
        else cout <<b;
    }
    for(int i=n-kh; i>0; --i){
        if((1ll*kq2>>i)%2==0) cout <<a;
        else cout <<b;
    }
}

void sub2()
{
    mod=(1ll<<n);
    ++dem;
    kh=n/2;
    tinh(1, kh);
    ++dem;
    tinh(1, n-kh);
    sort(x2.begin(), x2.end());
    for(int i=0; i<x1.size(); ++i){
        if(kq) break;
        if(x1[i].x<=k){
            int vt=lower_bound(x2.begin(), x2.end(), mp(k-x1[i].x, 0))-x2.begin();
            if((x1[i].x+x2[vt].x)%mod==k) { in(x1[i].y, x2[vt].y); kq=1; }
        }
        if(kq) break;
        int vtt=lower_bound(x2.begin(), x2.end(), mp(k+mod-x1[i].x, 0))-x2.begin();
            if((x1[i].x+x2[vtt].x)%mod==k) { in(x1[i].y, x2[vtt].y); kq=1; }
    }
    if(!kq) cout <<-1;
}

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("MODULO.inp", "r", stdin);
    freopen("MODULO.out", "w", stdout);
    cin >>a >>b >>n >>k;
    if(n<=20) { sub1(); return 0; }
    if(n<=40) { sub2(); return 0; }
    return 0;
}
