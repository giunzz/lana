#include <bits/stdc++.h>
<<<<<<< HEAD
#define ll long long
#define lp(a, b, c) for(ll a = b; a <= c; a++)
=======
<<<<<<< HEAD
#include <sys/stat.h>
#define fname "b"

<<<<<<< HEAD
>>>>>>> a7296cb76eb2976b1feddcf3b90545372b53aa4f
=======
>>>>>>> a7296cb... sync
>>>>>>> 6e5178e... sync
using namespace std;

const ll Max = 1e6 + 7;
ll mu10[15];
bool snt[Max] = {0};
vector<ll> s, ss;

inline ll gp(ll a, ll b){
    ll num = a * mu10[(ll)log10((double)b)] + b;
    for(ll i = 2; i * i <= num; i ++){
        if(!(num % i)) return 0;
    }
    return num;
}

void ghep(){
    ll k = 0;
    for(ll i = 0; i < s.size(); i+=2){
        ll tmp  = gp(s[i], s[i+1]);
        if(tmp){
            ss.push_back(tmp);
            ++k;
        }
        if(k == 500) break;
    }
}

void xuly(){
    mu10[0] = 10;
    lp(i, 1, 14) mu10[i] = mu10[i - 1] * 10;
    lp(i, 2, 1e6){
        if(!snt[i]){
            s.push_back(i);
            for(ll j = i * i; j <= 1e6; j += i) snt[j] = 1;
        }
    }
    ghep();
}

int main(){
<<<<<<< HEAD
    xuly();
    ll k;
    cin >> k;
    cout << ss[k - 1];
=======
    struct stat buffer;
    if(!stat(fname".inp", &buffer))
        cout << 1;
    else cout << 0;
=======
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long a = (long long)1 << (long long)3;
    cout << a;
>>>>>>> 1b5c812d903df17d42541c82c30e0fc279825697
<<<<<<< HEAD
>>>>>>> a7296cb76eb2976b1feddcf3b90545372b53aa4f
=======
>>>>>>> a7296cb... sync
>>>>>>> 6e5178e... sync
}