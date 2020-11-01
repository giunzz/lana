#include <bits/stdc++.h>
#define taskname "ARRANGE"
#define FORU(i,a,b) for(int i=a;i<=b;++i)
#define FORD(i,a,b) for(int i=a;i>=b;--i)
#define mp make_pair
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef pair<int ,int> ii;
const ll oo=1000000000;
const int nmax=100007;
int n;
vector<int> a(1LL*nmax);
vector<int> cnt(1LL*1000007,0);
vector<int> scnt(1LL*1000007,0);
vector<ll> s(1LL*1000007,0);
int heapmin=oo,heapmax=-oo;
void input()
{
    cin >> n;
    FORU(i,1,n)
    {
        cin >> a[i];
        ++cnt[a[i]];
        heapmax=max(heapmax,a[i]);
        heapmin=min(heapmin,a[i]);
    }
    FORU(i,1,1000000)
    {
        scnt[i]=cnt[i]+scnt[i-1];
        s[i]=i*cnt[i]+s[i-1];
    }
}
void process1()
{
    int tmp=s[heapmax]/n;
    int res=0;
    FORU(i,1,n) if(a[i]>tmp) res+=a[i]-tmp;
    cout << res;
}
void process2()
{
    heapmin=s[heapmax]/n;
    cout << heapmin;
}
int main()
{
    #ifndef ONLINE_JUDGE
    freopen(taskname".INP","r",stdin);
    freopen(taskname".OUT","w",stdout);
    #endif // ONLINE_JUDGE
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    input();
    if(s[heapmax]%n==0) process1();
    else process2();
    return 0;
}
