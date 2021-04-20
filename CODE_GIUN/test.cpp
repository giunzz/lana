#include<bits/stdc++.h>
using namespace std;

#define ll long long

const ll mxdigit = 17;
ll dp_sol[mxdigit][10][2], dp_cnt[mxdigit][10][2];
vector<ll> digit;

ll cnt(ll pos, ll num, bool ok){
    if(pos == mxdigit - 1)
        return dp_cnt[pos][num][ok] = 1; 
    if(~dp_cnt[pos][num][ok]) return dp_cnt[pos][num][ok];
    ll npos = pos + 1, res = 0;
    for(ll nnum = 0; nnum <= 9; ++nnum){
        if(ok){
            if(nnum < digit[npos]) res += cnt(npos, nnum, 0);
            else if(nnum == digit[npos]) res += cnt(npos, nnum, 1);
        } else{
            res += cnt(npos, nnum, ok);
        }
    }
    return dp_cnt[pos][num][ok] = res;
}

ll sol(ll pos, ll num, bool ok){
    if(pos == mxdigit - 1)
        return dp_sol[pos][num][ok] = num;
    if(~dp_sol[pos][num][ok]) return dp_sol[pos][num][ok];
    ll npos = pos + 1, res = 0;
    for(ll nnum = 0; nnum <= 9; ++nnum){
        if(ok){
            if(nnum < digit[npos]){
                res += sol(npos, nnum, 0) + num * cnt(npos, nnum, 0);
            } else if(nnum == digit[npos]) res += sol(npos, nnum, 1) + num * cnt(npos, nnum, 1);
        } else{
            res += sol(npos, nnum, ok) + num * cnt(npos, nnum, ok);
        }
    }
    return dp_sol[pos][num][ok] = res;
}

ll cal(ll n){
    digit.clear();
    while(n) digit.push_back(n % 10), n /= 10;
    while(digit.size() < mxdigit) digit.push_back(0);
    reverse(digit.begin(), digit.end());
    memset(dp_cnt, -1, sizeof dp_cnt);
    memset(dp_sol, -1, sizeof dp_sol);
    return sol(0, 0, 1);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ll tests;
    cin >> tests;
    while(tests--){
        ll l, r;
        cin >> l >> r;
        cout << cal(r) - cal(l - 1) << '\n';
    }
}

/*
#include<bits/stdc++.h>
using namespace std;

#define ll long long

const ll mxdigit = 5;
ll n;
vector<ll> digit;
// *****
// 

ll cnt(ll pos, ll num, bool ok){
    if(pos == mxdigit - 1)
        return 1; 
    ll npos = pos + 1, res = 0;
    for(ll nnum = 0; nnum <= 9; ++nnum){
        if(ok){
            if(nnum < digit[npos]) res += cnt(npos, nnum, 0);
            else if(nnum == digit[npos]) res += cnt(npos, nnum, 1);
        } else{
            res += cnt(npos, nnum, ok);
        }
    }
    return res;
}

// sol(2, 4, 1) -> sol(3, 1, 0)
// sol(2, 1, 0) -> sol(3, 1, 0)
// ....2    5 ... = 1000 + 2 * 99 
//    pos npos
// ..........6

ll sol(ll pos, ll num, bool ok){
    if(pos == mxdigit - 1)
        return num;
    ll npos = pos + 1, res = 0;
    for(ll nnum = 0; nnum <= 9; ++nnum){
        if(ok){
            // 024354
            // 021*** 
            if(nnum < digit[npos]){
                res += sol(npos, nnum, 0) + num * cnt(npos, nnum, 0);
            } else if(nnum == digit[npos]) res += sol(npos, nnum, 1) + num * cnt(npos, nnum, 1);
        } else{
            res += sol(npos, nnum, ok) + num * cnt(npos, nnum, ok);
        }
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("f.inp", "r", stdin);
    freopen("f.out", "w", stdout);
    cin >> n;
    while(n) digit.push_back(n % 10), n /= 10;
    while(digit.size() < mxdigit) digit.push_back(0);
    reverse(digit.begin(), digit.end());
    cout << sol(0, 0, 1);
}
*/