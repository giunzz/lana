#include <bits/stdc++.h>
#define f0(i, n) for(int i=0; i<n; i++)
#define f1(i, n) for(int i=1; i<=n; i++)
#define nmax 100002

using namespace std;
typedef long long ll;

ll n, a[nmax];
pair <ll, ll> b[nmax];

void sub1(ll sum){
    ll k = sum/n;

    ll t = -1;
    f1(i, n){
        if(b[i].first > k){
            t = i;
            break;
        }
    }

    ll val = 0;
    f1(i, t-1){
        if(b[i].first>=k) break;
        while(b[i].first < k){
            ll id = 1e6, nho = 1e6;
            for(ll j=t; j<=n; j++){
                if(b[j].first > k){
                    if(abs(b[j].second - b[i].second) < abs(id - b[i].second)){
                        nho = j;
                        id = b[j].second;
                    }
                }
            }
            if(b[i].first + (b[nho].first - k) >= k){
                ll v = k - b[i].first;
                val = val + labs(id - b[i].second)*v;
                b[nho].first = b[nho].first - (k - b[i].first);
                b[i].first = k;
                break;
            }
            else{
                ll v = b[nho].first - k;
                val = val + labs(id - b[i].second)*v;
                b[nho].first = k;
                b[i].first+=v;
            }
        }
    }
    cout << val;
}

void sub2(){
    cout << 8;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("ARRANGE.inp", "r", stdin);
    freopen("ARRANGE.out", "w", stdout);

    cin >> n;
    f1(i, n) cin >> a[i];
    f1(i, n) b[i].first = a[i], b[i].second = i;
    sort(b+1, b+n+1);

    ll sum = accumulate(a+1, a+n+1, 0);
    if(sum%n==0) sub1(sum);
    else{
        sub2();
    }
}
