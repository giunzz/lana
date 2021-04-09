#include <bits/stdc++.h>
#define ll long long
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
    freopen(Fname".out", "w", stdout);
}

ll n;
string s1, s2;

int main(){
    giuncute();
    #ifndef ONLINE_JUDGE
    OF();
    #endif
    cin >> n >> s1;
    ll pos = s1.find('*');
    lp(i, pos + 1, s1.size() - 1) s2.push_back(s1[i]);
    while(s1.size() != pos) s1.pop_back();
    lp(test, 1, n){
        string tmp;
        cin >> tmp;
        for(char &i : tmp) if(i < 'a') i += 32;
        if(s1.size() + s2.size() <= tmp.size() && tmp.substr(0, s1.size()) == s1 && tmp.substr(tmp.size() - s2.size(), s2.size()) == s2) cout << "YES\n";
        else cout << "NO\n";
    }
}