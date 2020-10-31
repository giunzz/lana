#include <bits/stdc++.h>
#define ll long long
#define FOR(i, a, b) for(int i = (a); i <= (b); i ++)
#define FORd(i, a, b) for(int i = (a); i >= (b); i --)
#define FORv(i, a, b) for(int i = (a); i < (b); i ++)
#define II pair<int, int>
#define x first
#define y second
#define pb push_back
#define mp make_pair
using namespace std;
int T, a, b;
int main()
{
    freopen("MINSUM.inp", "r", stdin);
    freopen("MINSUM.out", "w", stdout);
    ios :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> T;
    while(T --){
        cin >> a >> b;
        map<int, int> p_a, p_b;
        for(int i = 2; i * i <= a; i ++){
            if(a % i == 0){
                int cnt = 0;
                while(a % i == 0){
                    cnt ++;
                    a /= i;
                }
                p_a[i] = cnt;
            }
        }
        if(a > 1) p_a[a] = 1;
        for(int i = 2; i * i <= b; i ++){
            if(b % i == 0){
                int cnt = 0;
                while(b % i == 0){
                    cnt ++;
                    b /= i;
                }
                p_b[i] = cnt;
            }
        }
        if(b > 1) p_b[b] = 1;
        vector<int> temp;
        for(map<int, int> :: iterator it = p_a.begin(); it != p_a.end(); it ++){
            map<int, int> :: iterator t_it = p_b.find(it -> x);
            if(t_it == p_b.end()){
                if((it -> y) % 2) temp.pb(it -> x);
            }
            else{
                int sl = abs((it -> y) - (t_it -> y));
                if(sl % 2) temp.pb(it -> x);
            }
        }
        for(map<int, int> :: iterator it = p_b.begin(); it != p_b.end(); it ++){
            if(p_a.find(it -> x) == p_a.end()){
                if((it -> y) % 2) temp.pb(it -> x);
            }
        }
        if(temp.size() == 0){
            cout << 1 << ' ' << 1 << endl;
            continue;
        }
        int n = temp.size();
        int maxn = (1 << n) - 1;
        ll resa = 1e18, resb = 1e18;
        for(int i = 0; i <= maxn; i ++){
            ll tempa = 1, tempb = 1;
            for(int j = 0; j <= n - 1; j ++){
                if((i >> j) & 1)tempa *= temp[j];
                    else tempb *= temp[j];
            }
            if(tempa + tempb < resa + resb){
                resa = tempa;
                resb = tempb;
            }
        }
        cout << resa << ' ' << resb << endl;
    }
    return 0;
}
