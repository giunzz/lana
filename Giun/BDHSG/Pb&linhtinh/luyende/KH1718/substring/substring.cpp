#include <bits/stdc++.h>
#define ll long long
#define cll const long long
#define lp(a, b, c) for(ll a = b; a <= c; a++)
#define lpd(a, b, c) for(ll a = b; a >= c; a--)
#define vec(a) vector<a>
using namespace std;

void file(const string file){
    freopen((file + ".inp").c_str(), "r", stdin);
    freopen((file + ".out").c_str(), "w", stdout);
}

string s;
ll n, k;

ll dec(char c){
    return c - 'a';
}

void sol(){
    ll r = 0, cnt[30] = {0}, ct = 1, ans = 0;
    cnt[dec(s[0])] = 1;
    lp(l, 0, s.size() - 1)
    {
        while(r < s.size() - 1 && ((!cnt[dec(s[r + 1])] && ct + 1 <= k) || cnt[dec(s[r + 1])])) ct += (cnt[dec(s[++r])]++ ? 0 : 1);
        if (ct == k) ans = max(ans, r - l + 1);
        if(r == s.size() - 1) break;
        while(ct == k) ct -= (--cnt[dec(s[l++])] ? 0 : 1);
        --l; 
    }
    cout << ans;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    file("substring");
    cin >> n >> k >> s;
    sol();
}