#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 3e3 + 5;

int m, n, k, a[N], b[N], pos, j, pos1;
vector <int> v, s;
int main() {
    #define file "SEQUENCE"
    freopen(file".INP", "r", stdin);  freopen(file".OUT", "w", stdout);
    ios_base :: sync_with_stdio(false); cin.tie(NULL);
    cin >> m >> n >> k;
    for(int i = 1; i <= m; ++i) cin >> a[i];
    for(int i = 1; i <= n; ++i) cin >> b[i];
    for(int i = 5; i <= 5; ++i) {
        j = k - i;
        for(int it = 1; it <= i; ++it) v.push_back(a[it]);
        for(int it = i + 1; it <= m; ++it) {
            v.push_back(a[it]);
            pos = i;
            for(int h = 0; h < i; ++h) {
                if (v[h] > v[h + 1]) {
                    pos = h;break;
                }
            }
            v.erase(v.begin() + pos);
        }
//        for(int it = 0; it < v.size(); ++it) cout << v[it] << " ";

        for(int it = 1; it <= j; ++it) s.push_back(b[it]);
        for(int it = j + 1; it <= n; ++it) {
            s.push_back(b[it]);
            pos = j;
            for(int h = 0; h < j; ++h) {
                if (s[h] > s[h + 1]) {
                    pos = h;break;
                }
            }
            s.erase(s.begin() + pos);
        }
        pos = lower_bound(v.begin(), v.end(), s[0]) - v.begin();
        v.insert(pos + v.begin(), s[0]);
        for(int it = 1; it < s.size(); ++it) {
            pos = lower_bound(v.begin(), v.end(), s[it]) - v.begin();
            pos1 = lower_bound(v.begin(), v.end(), s[it - 1]) - v.begin();
            pos = max(pos, pos1);
            v.insert(v.begin() + pos, s[it]);
        }
        for(int it = 0; it < v.size(); ++it) cout << v[it] << " ";
    }
    return 0;
}
