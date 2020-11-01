#include <bits/stdc++.h>
#define x first
#define y second
#define ii pair <int, int>
#define pb push_back
#define mp make_pair
using namespace std;

const long long mod=1e9+9;
const int N=305;
const int th=50;
int n, ma, x1, x2, x3;
long long tr[205][105][55], sa[205][105][55], kq;

void sub12()
{
    tr[th*3][th][0]=1;
    for(int i=1; i<=n; ++i)
    {
        for(int u1=0; u1<=min(th*3+n, th*3+ma); ++u1)
            for(int u2=0; u2<=min(th+n, th+ma); ++u2)
                for(int u3=0; u3<=min(n, ma); ++u3){
                    if(u3+x3<ma){
                        if(u2-th+x2>0 && u1-th*3+x1>0 && u2!=0 && u1!=0) sa[u1-1][u2-1][u3+1]=(sa[u1-1][u2-1][u3+1]+tr[u1][u2][u3])%mod;
                        if(u1-th*3+x1>2 && u1>2) sa[u1-3][u2][u3+1]=(sa[u1-3][u2][u3+1]+tr[u1][u2][u3])%mod;
                    }
                    if(u1-th*3+x1<ma) sa[u1+1][u2][u3]=(sa[u1+1][u2][u3]+tr[u1][u2][u3])%mod;
                    if(u2-th+x2<ma && u1-th*3+x1>0 && u1!=0) sa[u1-1][u2+1][u3]=(sa[u1-1][u2+1][u3]+tr[u1][u2][u3])%mod;
                }
        for(int u1=0; u1<=min(th*3+n, th*3+ma); ++u1)
            for(int u2=0; u2<=min(th+n, th+ma); ++u2)
                for(int u3=0; u3<=min(n, ma); ++u3){
                    tr[u1][u2][u3]=sa[u1][u2][u3];
                    if(i==n) kq=(kq+sa[u1][u2][u3])%mod;
                    sa[u1][u2][u3]=0;
                }
    }
    cout <<kq;
}

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("ICECREAM.inp", "r", stdin);
    freopen("ICECREAM.out", "w", stdout);
    cin >>n >>ma;
    cin >>x1 >>x2 >>x3;
    if(n<=50) { sub12(); return 0; }
    sub12();
    return 0;
}
