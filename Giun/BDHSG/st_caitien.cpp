#include <bits/stdc++.h>
#define ll long long
#define cll const long long
#define lp(a, b, c) for(ll a = b; a <= c; a++)
#define lpd(a, b, c) for(ll a = b; a >= c; a--)
#define vec(a) vector<a>
#define pp(a, b) pair<a, b>
#define fname "f"
using namespace std;

void File(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen(fname".inp", "r", stdin);
    freopen(fname".out", "w", stdout);
}

cll maxn = 1e5 + 7;
ll n, t[maxn*2];

void build(){
    lpd(i, n - 1, 1) t[i] = t[i * 2] + t[i * 2 + 1]; //2^0 = 1 nen chay tu 1
}

//xu ly mang co index bat dau = 0

void upd(ll v, ll vl){
    for(t[--v += n] = vl; v > 1; v >>= 1){
        t[v >> 1] = t[v] + t[v ^ 1]; //nut cha cua v la nut v >> 1 , nut v >> 1 gom 2 nut *2 va *2 + 1 nut con lai cua v la v ^ 1 
    }
}

ll getS(ll l, ll r){
    ll sum = 0;
    --l+=n, --r += n;
    while(l < r){
        if(l&1) sum += t[l++];
        if(r&1) sum += t[--r]; //ve hinh
        l >>= 1;
        r >>= 1;
    }
    return sum;
}

//doan code ben tren dung dc cho cay nhi phan hoan chinh hoac ko hoan chinh

//doan duoi day cap nhat mat gia tri cac nut

//doan tro xuong xu ly gan giong lazy
void tangvl1doan(ll l, ll r, ll vl){ //[l, r)
    --l += n, --r += n;
    while(l < r){
        if(l&1) t[l++] += vl;
        if(r&1) t[--r] += vl;
        l >>= 1;
        r >>= 1;
    }
}

ll vlp(ll p){
    ll ans = 0;
    --p += n;
    while(p > 0){
        ans += t[p];
        p >>= 1;
    }
    return ans;
}

void down(){
    lp(i, 1, n - 1){
        t[i << 1] += t[i]; //i*2
        t[i << 1|1] += t[i]; //i*2+1
        t[i] = 0;
    }
}

int main(){
    File();
    cin >> n;
    lp(i, 0, n - 1) cin >> t[i + n]; //cay nhi phan hoan chinh vi du n = 16 cap nhat nut thu 16 tro di
    // build(); //van dung trong truong hop ko day du
    // upd(1, 1);
    // cout << getS(1, 8); // tinh tong [l, r)
    tangvl1doan(1, 3, 1);
    // cout << vlp(2);
    down();
    lp(i, 1, n) cout << t[i + n - 1] << ' ';
}