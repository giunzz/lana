#include <bits/stdc++.h>
#define ll long long
#define cll const ll
#define lp(a, b, c) for(ll a = b; a <= c; ++a)
#define lpd(a, b, c) for(ll a = b; a >= c; --a)
#define vec(a) vector<a>
#define pp(a, b) pair<a, b>
#define EACHCASE lpd(cs, read(), 1)
#define Fname "year"
using namespace std;

template <typename T> inline void Read(T &x){
    x = 0; char c;
    while(!isdigit(c = getchar()));
    do
    {
        x = x * 10 + c - '0';
    } while (isdigit(c = getchar()));
}

ll read(){
    ll tmp;
    cin >> tmp;
    return tmp;
}

void giuncute(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
}

void OF(){
    freopen(Fname".inp", "r", stdin);
    freopen(Fname".out", "w", stdout);
}

cll mxn = 1e3 + 6;
ll n;
string num[mxn];

void prc(string &a, string b){
    string tmp, res = "";
    lp(i, 0, 3){
        tmp = a;
        lpd(j, '9', '0'){
            if(!i && j == '0') continue;
            tmp[i] = j;
            if(tmp <= b){
                res = max(tmp, res);
            }
        }
    }
    a = res;
}

int main(){
    giuncute();
    #ifndef ONLINE_JUDGE
    OF();
    #endif
    cin >> n;
    lp(i, 1, n) cin >> num[i];
    num[n + 1] = "2011";
    lpd(i, n, 1){
        prc(num[i], num[i + 1]);
        if(num[i] == ""){
            cout << "-1";
            return 0;
        }
    }
    lp(i, 1, n) cout << num[i] << '\n';
}