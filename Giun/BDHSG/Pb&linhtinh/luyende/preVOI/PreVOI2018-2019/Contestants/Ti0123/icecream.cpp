#include <bits/stdc++.h>
#define NaMe "icecream"
#define pii pair<int,int>
#define se second
#define fi first
#define mp make_pair
#define pb push_back
#define gb(i,j) ((i>>j)&1)
#define fto(i,a,b) for(int i=a; i<=b; ++i)
#define fdto(i,a,b) for(int i=a; i>=b; --i)
#define ll long long
using namespace std;
const ll oo=1e9+9;
ll l[17][12][12][12],n,m,a1,a2,a3;
void xuli1(){
    l[0][a1][a2][a3]=1;
    fto(i,0,n-1){
        fto(j1,0,m)
            fto(j2,0,m)
                fto(j3,0,m)
                if(l[i][j1][j2][j3]!=0){
                    if(j1<m){
                        l[i+1][j1+1][j2][j3]=(l[i+1][j1+1][j2][j3]+l[i][j1][j2][j3])%oo;
                    }
                    if(j1>0 && j2<m){
                        l[i+1][j1-1][j2+1][j3]=(l[i+1][j1-1][j2+1][j3]+l[i][j1][j2][j3])%oo;
                    }
                    if(j1>0 && j2>0 && j3<m){
                        l[i+1][j1-1][j2-1][j3+1]=(l[i+1][j1-1][j2-1][j3+1]+l[i][j1][j2][j3])%oo;
                    }
                    else
                    if(j1>=3 && j3<m){
                        l[i+1][j1-3][j2][j3+1]=(l[i+1][j1-3][j2][j3+1]+l[i][j1][j2][j3])%oo;
                    }
                }
    }
    ll res=0;
    fto(j1,0,m)
        fto(j2,0,m)
            fto(j3,0,m)res=(res+l[n][j1][j2][j3])%oo;
    cout << res;
    exit(0);

}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen(NaMe".inp","r", stdin);
    freopen(NaMe".out","w", stdout);
    cin >> n >> m;
    cin >> a1 >> a2 >> a3;
    if(m<=10)xuli1();
    ll res=1;
    fto(i,1,n)res=(res*3)%oo;
    cout << res;
    return 0;
}
