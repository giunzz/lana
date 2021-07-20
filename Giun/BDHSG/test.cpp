#include <bits/stdc++.h>
#define ll unsigned long long
#define cll const ll
#define lp(a, b, c) for(ll a = b; a <= c; ++a)
#define lpd(a, b, c) for(ll a = b; a >= c; --a)
#define vec(a) vector<a>
#define pp(a, b) pair<a, b>
#define EACHCASE lpd(cs, read(), 1)
#define Fname "f"
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
    // freopen(Fname".out", "w", stdout);
}

cll mxdig = 63;
ll l, r, k, ans;// memo[mxdig + 3][2][2][2][mxdig + 3];
bool ok = 0;

bool val(ll x, ll pos){return (x >> pos) & 1;}

void sol(ll pos, bool check1, bool check2, bool dig, ll cnt){
    if(!pos){
        ok = 1;
        return;
    }
    ll npos = pos - 1, ncheck1 = check1, ncheck2 = check2;
    lp(i, 0, 1){
        if(check1){
            if(val(l, npos) < i) ncheck1 = 0;
            else if(val(l, npos) == i) ncheck1 = 1;
            else continue;
        }
        if(check2){
            if(val(r, npos) > i) ncheck2 = 0;
            else if(val(l, npos) == i) ncheck2 = 1;
            else continue;
        }
        // if(k - cnt == pos && i) ans += (i << npos), sol(npos, ncheck1, ncheck2, i, cnt + i);
        if((!i && k - cnt < pos) || (i && k - cnt <= pos && k - cnt >= 1)){
            ans += (i << npos), sol(npos, ncheck1, ncheck2, i, cnt + i);
            if(ok) return;
            ans -= (i << npos);
        }
    } 
}

// void trace(ll pos, bool check1, bool check2, bool dig, ll cnt){
//     ll npos = pos - 1, ncheck1 = check1, ncheck2 = check2;
//     if(!pos){ok = 1; return;}
//     lp(i, 0, 1){
//         if(check1){
//             if(val(l, npos) < i) ncheck1 = 0;
//             else if(val(l, npos) == i) ncheck1 = 1;
//             else continue;
//         }
//         if(check2){
//             if(val(r, npos) > i) ncheck2 = 0;
//             else if(val(l, npos) == i) ncheck2 = 1;
//             else continue;
//         }
//         if(memo[npos][ncheck1][ncheck2][i][cnt + i]){
//             ans += (i << npos);
//             trace(npos, ncheck1, ncheck2, i, cnt + i);
//             break;
//         }
//     }
// }

int main(){
    giuncute();
    #ifndef ONLINE_JUDGE
    OF();
    #endif
    EACHCASE{
        ok = ans = 0;
        // memset(memo, -1, sizeof memo);
        cin >> l >> r >> k;
        sol(mxdig, 1, 1, 0, 0);
        // trace(mxdig, 1, 1, 0, 0);
        // cerr << memo[mxdig][1][1][0][0] << '\n';
        if(ok) cout << ans << '\n';
        else cout << "-1\n";
    }
}
