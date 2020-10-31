#include <bits/stdc++.h>
#define pb push_back
#define pf push_front
#define F first
#define S second
#define mp make_pair
#define LL long long
#define fort(i,a,b) for(LL i=(a); i<=(b); i++)
#define ford(i,a,b) for(LL i=(a); i>=(b); i--)

using namespace std;
LL n;
LL a[100005], sum=0,tmp,res=0,tam;
pair<LL,LL> f[100005];
LL dau, cuoi;
LL ok;
void Karl_Heinrich_Marx()
{
    #ifndef ONLINE_JUDGE
    freopen("arrange.inp","r",stdin);
    freopen("arrange.out","w",stdout);
    #endif // ONLINE_JUDGE
}

void Vladimir_Ilyich_Lenin()
{
    scanf("%lld",&n);
    fort(i,1,n) {
        scanf("%lld",&a[i]);
        sum+=a[i];
    }
    if( sum % n == 0 ) {
        tmp = sum / n;
        fort(i,1,n) {
            if( a[i] != tmp ) {
                tam = a[i] - tmp;
                if( tam > 0 ) ok = -1;
                else ok = 1;
                if( dau > cuoi ) {
                    cuoi++; f[cuoi] = mp( tam, i );
                }
                else {

                    while( dau <= cuoi ) {
                        if( tam * f[dau].F > 0 ) {
                            cuoi++; f[cuoi] = mp( tam, i );
                            tam = 0;
                            break;
                        }

                        if( tam == ok*f[dau].F ) {
                            res = res + abs( tam ) * ( i - f[dau].S );
                            tam = 0;
                            dau++;
                            break;
                        }

                        if( ok*(tam + f[dau].F) < 0 ) {
                            res = res + abs( f[dau].F )*( i - f[dau].S );
                            tam = tam + f[dau].F;
                            dau++;
                        }

                        else {
                            res = res + abs( tam )*( i - f[dau].S );
                            f[ dau ].S +=tam;
                            tam=0;
                            break;
                        }

                    }

                    if( tam !=0 && dau > cuoi ) {
                        cuoi++; f[cuoi] = mp( tam,i );
                    }

                }
            }
            //cerr<<res<<endl;
        }
        cout << res;
        exit(0);
    }
    res= 0;
    tmp = n/2;
    fort(i,1,n) {
        if( a[i] < tmp ) res = res + tmp - a[i];
        else res = res + a[i] - tmp + 1;
    }
    cout<<res/2 + res%2;

}
int main()
{
    Karl_Heinrich_Marx();
    Vladimir_Ilyich_Lenin();
    return 0;
}
