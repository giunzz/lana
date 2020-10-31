#include <bits/stdc++.h>
#define f first
#define s second
#define mp make_pair
#define pb push_back
#define ll long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define test "arrange"
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

const int N = 1e5 + 100;
int n;
int a[N];
ll sl = 0;
ll x = 0;
int f[N][2];
ll s[N];

void in(){
    cin >> n;
    for(int i = 1; i <= n; ++i)
        cin >> a[i],x = x + a[i];
    sl = x % n;
    x = x / n;
}
int t[N];
ll dp[2001][2001];

void sub1(){
    ll l = 1;
    ll res = 0;
    for(ll i = 1; i <= n; i++)
    if(a[i] > x){
        ll need = a[i] - x;
        while(need)
        if(a[l] < x){
            ll y = min(need,x - a[l]);
            a[l] += y;
            need -= y;
            res += y * abs(l - i);
            l += (a[l] == x);
        }
        else
            ++l;
    }
    cout << res;
}

void sub2(){
    int dem = 0;
    for(int i = 1; i <= n; ++ i)
        dem += (a[i] > x);
    ll res = 0;
    if(dem >= sl){
        ll l = 1;
        for(ll i = 1; i <= n; i++)
        if(a[i] > x + 1){
            ll need = a[i] - x - 1;
            while(need)
            if(a[l] < x){
                ll y = min(need,x - a[l]);
                a[l] += y;
                need -= y;
                res += y * abs(l - i);
                l += (a[l] == x);
            }
            else
                ++l;
            a[i] = x + 1;
        }
        if(sl == dem){
            cout << res;
            return;
        }
    }
    else{
        ll l = 1;
        for(ll i = 1; i <= n; i++)
        if(a[i] < x){
            ll need = x - a[i];
            while(need)
            if(a[l] > x + 1){
                ll y = min(need,a[l] - x - 1);
                a[l] -= y;
                need -= y;
                res += y * abs(l - i);
                l += (a[l] == x + 1);
            }
            else
                ++l;
            a[i] = x;
        }
    }
    if(dem < sl){
        int nw = 0;
        for(int i = 1; i <= n; i++)
            if(a[i] == x)
                t[++nw] = i;
        int tt = 0;
        for(int i = 1; i <= nw; ++i)
            s[i] = s[i-1] + t[i];
        for(int i = 1; i <= n; ++i)
            for(int j = 0; j <= nw; ++j)
                dp[i][j] = 1e18;
        for(int i = 1; i <= n; i++)
        if(a[i] > x + 1){
            ++tt;
            ll y = 1;
            int need = a[i] - x - 1;
            for(int j = 1; j <= nw - need + 1; ++j){
                ll l = j;
                ll r = l + need;
                while(y < r && t[y] < i) ++ y;
                ll cp = (y - l) * i - (s[y-1] - s[l-1]);
                cp += s[r-1] - s[y-1] - i * (r - y);
                dp[tt][j+need-1] = min(dp[tt][j+need-2],dp[tt-1][j-1] + cp);
            }
        }
        ll mi = 1e18;
        for(int i = 1; i <= nw; ++ i)
            mi = min(mi,dp[tt][i]);
        cout << res + mi;
    }
    else{
        int nw = 0;
        for(int i = 1; i <= n; i++)
            if(a[i] == x + 1)
                t[++nw] = i;
        int tt = 0;
        for(int i = 1; i <= nw; ++i)
            s[i] = s[i-1] + t[i];
        for(int i = 1; i <= n; ++i)
            for(int j = 0; j <= nw; ++j)
                dp[i][j] = 1e18;
        for(int i = 1; i <= n; i++)
        if(a[i] < x){
            ++tt;
            ll y = 1;
            int need = x - a[i];
            for(int j = 1; j <= nw - need + 1; ++j){
                ll l = j;
                ll r = l + need;
                while(y < r && t[y] < i) ++ y;
                ll cp = (y - l) * i - (s[y-1] - s[l-1]);
                cp += s[r-1] - s[y-1] - i * (r - y);
                dp[tt][j+need-1] = min(dp[tt][j+need-2],dp[tt-1][j-1] + cp);
            }
        }
        ll mi = 1e18;
        for(int i = 1; i <= nw; ++ i)
            mi = min(mi,dp[tt][i]);
        cout << res + mi;
    }
}

void sub3(){
    int dem = 0;
    for(int i = 1; i <= n; ++ i)
        dem += (a[i] > x);
    ll res = 0;
    if(dem >= sl){
        ll l = 1;
        for(ll i = 1; i <= n; i++)
        if(a[i] > x + 1){
            ll need = a[i] - x - 1;
            while(need)
            if(a[l] < x){
                ll y = min(need,x - a[l]);
                a[l] += y;
                need -= y;
                res += y * abs(l - i);
                l += (a[l] == x);
            }
            else
                ++l;
            a[i] = x + 1;
        }
        if(sl == dem){
            cout << res;
            return;
        }
    }
    else{
        ll l = 1;
        for(ll i = 1; i <= n; i++)
        if(a[i] < x){
            ll need = x - a[i];
            while(need)
            if(a[l] > x + 1){
                ll y = min(need,a[l] - x - 1);
                a[l] -= y;
                need -= y;
                res += y * abs(l - i);
                l += (a[l] == x + 1);
            }
            else
                ++l;
            a[i] = x;
        }
    }
    if(dem < sl){
        int l = 1;
        for(int i = 1; i <= n; ++i)
            if(a[i] > x + 1){
                int need = a[i] - x - 1;
                while(need){
                    if(a[l] == x){
                        res += abs(i - l);
                        --need;
                    }
                    ++l;
                }
            }
    }
    else{
        int l = 1;
        for(int i = 1; i <= n; ++i)
        if(a[i] < x){
            int need = x - a[i];
            while(need){
                if(a[l] == x+1){
                    res += abs(i-l);
                    --need;
                }
                ++l;
            }
        }
    }
    cout << res;
}

void sol(){
    if(sl == 0){
        sub1();
        return;
    }
    if(n <= 2000){
        sub2();
        return;
    }
    sub3();
}
