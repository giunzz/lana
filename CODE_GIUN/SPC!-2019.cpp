#include<bits/stdc++.h>
using namespace std;

#define ll long long

// x = 

const mxdigit = 5;
ll n;
vector<ll> digit;

ll sol(ll pos, ll num, bool ok)
{
    if(pos == mxdigit - 1){

    } else{
        ll cnt = 0;
        for(int i = 0; i <= 9; ++i){
            if(ok){
                
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("giun.inp", "r", stdin);
    freopen("giun.out", "w", stdout);
    cin >> n;
    while(n) digit.push_back(n % 10), n /= 10;
    while(digit.size() < mxdigit) digit.push_back(0);
    reverse(digit.begin(), digit.end());
    cout << sol(0, 0, 1);
}