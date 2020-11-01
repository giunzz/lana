#include <bits/stdc++.h>
#define f first
#define s second
#define mp make_pair
#define pb push_back
#define ll long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define test "gifts"
using namespace std;

void home(){
    #ifndef ONLINE_JUDGE
    freopen(test".inp","r",stdin);
    freopen(test".out","w",stdout);
    #endif // ONLINE_JUDGE
}

void in();
void sol();

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    home();
    in();
    sol();
}

const int N = 1e6 + 100;
int a[N];
ll s[N];
ll tr[N];
ll su[N];
int n,k;

void in(){
    scanf("%d%d",&n,&k);
    for(int i = 1; i <= n; ++i)
        scanf("%d",a + i);
    for(int i = 1; i <= n; ++i)
        s[i] = s[i-1] + a[i];
    for(int i = k; i <= n; ++i)
        tr[i] = max(tr[i-1],s[i] - s[i-k]);
    for(int i = n-k+1; i >= 1; --i)
        su[i] = max(su[i+1],s[i+k-1] - s[i-1]);
}

void sol(){
    ll res = 1e18;
    for(int i = 1; i <= n-k+1; ++ i)
        res = min(res,max(tr[i-1],su[i+k]));
    cout << res;
}
