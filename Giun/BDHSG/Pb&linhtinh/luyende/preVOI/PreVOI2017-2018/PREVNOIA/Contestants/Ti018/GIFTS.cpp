#include <bits/stdc++.h>
#define taskname "GIFTS"
#define FORU(i,a,b) for(int i=a;i<=b;++i)
#define FORD(i,a,b) for(int i=a;i>=b;--i)
#define pf push_front
#define pof pop_front
#define pob pop_back
using namespace std;
typedef long long ll;
const ll oo=1000000000000000000;
const int nmax=1000007;
int n,k,a[nmax];
ll s[nmax],r=0,res=oo;
deque <ll> l;
void input()
{
    ll tmp=0;
    cin >> n >> k;
    FORU(i,1,n) cin >> a[i];
    FORD(i,n,1)
    {
        tmp+=a[i];
        if(i<=n-k+1)
        {
            tmp-=a[i+k];
            s[i]=tmp;
        }
    }
}
void process()
{
        FORD(i,n-k,1)
        {
            while(!l.empty() && s[l.front()]<= s[i]) l.pof();
            l.pf(i);
        }
        l.pf(0);
        FORD(i,n-k+1,1)
        {

            r=max(r,s[i+k]);
            if(l.back()>=i-k+1) l.pob();
            if(s[i]>=max(s[l.back()],r)) res=min(res,s[i]);
        }
        cout << res;
}
int main()
{
    #ifndef ONLINE_JUDGE
    freopen(taskname".INP","r",stdin);
    freopen(taskname".OUT","w",stdout);
    #endif // ONLINE_JUDGE
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    input();
    process();
    return 0;
}
