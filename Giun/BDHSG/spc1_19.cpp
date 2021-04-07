#include<bits/stdc++.h>
using namespace std;

#define ll long long

const ll mxdigit = 5;
ll n;
vector<ll> digit;

ll cnt()

ll sol(ll pos, ll num, bool ok){
    if(pos == mxdigit - 1){

    } else{
        ll npos = pos + 1, res = 0;
        for(ll nnum = 0; nnum <= 9; ++nnum){
            if(ok){
                // 02435
                // 0241* 
                if(nnum < digit[npos]){
                    res += sol(npos, nnum, 0) + ;
                }
            }
        }
    }
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