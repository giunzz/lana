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

cll mxn = 103;
ll n, m, k, a[mxn][mxn], cnt[28] = {0}, cnt_row[mxn][mxn][28] = {0}, save[mxn][mxn][mxn];

int main(){
    giuncute();
    #ifndef ONLINE_JUDGE
    OF();
    #endif
    cin >> n >> m >> k;
    lp(i, 1, n) lp(j, 1, m){
        char c;
        cin >> c;
        a[i][j] = c - 'A';
        lp(ic, 0, 'Z' - 'A') cnt_row[i][j][ic] = cnt_row[i - 1][j][ic];
        ++cnt_row[i][j][a[i][j]];
    }
    // cerr << cnt_row[3][1][1];``
    ll ans = 0;
    lp(line, 1, n) lp(height, 1, line){
        memset(cnt, 0, sizeof cnt);
        ll j = 1, top = line - height, tot;
        lp(i, 1, m){
            lp(k, 0, 'Z' - 'A') cnt[k] += cnt_row[line][i][k] - cnt_row[top][i][k];
            for(;;){
                tot = 0;
                lp(k, 0, 'Z' - 'A') if(cnt[k]) ++tot;
                // ans += (tot == k);
                // if (tot == k) cerr << line << ' ' << height << ' ' << i << ' ' << j << '\n';
                if(tot <= k) break;
                lp(k, 0, 'Z' - 'A') cnt[k] -= cnt_row[line][j][k] - cnt_row[top][j][k];
                ++j;
            }
            save[line][height][i] = j;
        }
    }
    lp(line, 1, n) lp(height, 1, line){
        memset(cnt, 0, sizeof cnt);
        ll j = 1, top = line - height, tot;
        lp(i, 1, m){
            lp(k, 0, 'Z' - 'A') cnt[k] += cnt_row[line][i][k] - cnt_row[top][i][k];
            for(;;){
                tot = 0;
                lp(k, 0, 'Z' - 'A') if(cnt[k]) ++tot;
                // if (tot == k) cerr << line << ' ' << height << ' ' << i << ' ' << j << '\n';
                if(tot < k) break;
                lp(k, 0, 'Z' - 'A') cnt[k] -= cnt_row[line][j][k] - cnt_row[top][j][k];
                ++j;
            }
            // cerr << line << ' ' << height << ' ' << i << ' ' << j << ' ' << save[line][height][i] << '\n';
            assert(j - save[line][height][i] >= 0);
            ans += j - save[line][height][i];
        }
    }
    cout << ans;
}