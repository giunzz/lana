#include <bits/stdc++.h>
#define NaMe "modulo"
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
ll n,m,a,b,k,mod,s[100];
pair<ll,ll> l[9000009],l1[9000009];
void inkq(ll tg, ll s1, ll s2){
    fdto(i,tg-1,0)if(gb(s1,i))cout << b;else cout << a;
    fdto(i,tg-1,0)if(gb(s2,i))cout << b;else cout << a;
    exit(0);
}
void xuli1(){
    ll tg=n/2;
    l[0].fi=0;
    s[0]=1;
    fto(i,1,n)s[i]=(s[i-1]*10)%mod;
    fto(i,0,tg-1){
        l[0].fi=(l[0].fi+a*(s[i]))%mod;
    }
    fto(i,1,(1<<tg)-1){
        fto(j,0,tg-1)
        if(gb(i,j)){
            l[i].fi=((l[i-(1<<j)].fi+(b-a)*(s[j]))%mod+mod)%mod;
            break;
        }
    }
    fto(i,0,(1<<tg)-1){
        l[i].se=l1[i].se=i;
        l1[i].fi=((l[i].fi*(s[tg])-k)%mod+mod)%mod;
    }
    //fto(i,0,(1<<tg)-1)cout << l[i].fi <<' '<< l[i].se << ' '<< l1[i].fi << ' ' << l1[i].se << endl;
    sort(l,l+(1<<tg));
    if(n%2==0){
        sort(l1,l1+(1<<tg));
        ll j=(1<< tg)-1;
        fto(i,0,(1<<tg)-1){
            while(l1[j].fi+l[i].fi>mod && j!=0)--j;
            if((l1[j].fi+l[i].fi)%mod==0){
                inkq(tg,l1[j].se,l[i].se);
            }
        }
        cout << -1;
        exit(0);
    }
        ll tg1=(1<<n-1);
        fto(i,0,(1<<tg)-1)l1[i].fi=(l1[i].fi+a*s[n-1])%mod;
        ll j=(1<< tg)-1;
        sort(l1,l1+(1<<tg));
        fto(i,0,(1<<tg)-1){
            while(l1[j].fi+l[i].fi>mod && j!=0)--j;
            if((l1[j].fi+l[i].fi)%mod==0){
                cout << a;
                inkq(tg,l1[j].se,l[i].se);
            }
        }
        if(l[0].fi==0 && l1[0].fi==0)cout << a,inkq(tg,l1[0].se,l[0].se);
        fto(i,0,(1<<tg)-1)l1[i].fi=((l1[i].fi+(b-a)*s[n-1])%mod+mod)%mod;
        j=(1<< tg)-1;
        sort(l1,l1+(1<<tg));
        //fto(i,0,(1<<tg)-1)cout << l[i].fi << endl;
        //fto(i,0,(1<<tg)-1)cout << l1[i].fi << endl;
        fto(i,0,(1<<tg)-1){
            while(l1[j].fi+l[i].fi>mod && j!=0)--j;
            if((l1[j].fi+l[i].fi)%mod==0){
                cout << b;
                inkq(tg,l1[j].se,l[i].se);
            }
        }
    if(l[0].fi==0 && l1[0].fi==0)cout << b,inkq(tg,l1[0].se,l[0].se);
    cout << -1;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen(NaMe".inp","r", stdin);
    freopen(NaMe".out","w", stdout);
    cin >> a >> b >> n >> k;
    mod=(1<<n);
    if(k%2==1 && a%2==0 && b%2==0){cout << -1; return 0;}
    if(n<=47){xuli1(); return 0;}
    cout << -1;
    return 0;
}
