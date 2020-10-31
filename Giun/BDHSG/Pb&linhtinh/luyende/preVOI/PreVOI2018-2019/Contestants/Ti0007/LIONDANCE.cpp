#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
#define f first
#define s second
#define mk make_pair

const int N = 4e3 + 7;
int n, m, t, res, T, k;
int a[N], b[N], pre[N];
vector<int> sav[N][N];

vector<int> Max(vector<int> &a, vector<int> &b) {
    if(a.size() < b.size()) return b;
    if(a.size() > b.size()) return a;
    vector<int> ans;
    int n = a.size();
    ans.resize(n);
    for(int i = n - 1; i >= 0; -- i)
    if(a[i] < b[i]) {
        for(int j = i; j >= 0; -- j) ans[j] = b[j];
        return ans;
    }
    else
        if(a[i] > b[i]) {
            for(int j = i; j >= 0; -- j) ans[j] = a[j];
            return ans;
        }
    else ans[i] = a[i];
    return ans;
}
void go(int u, int v) {
    vector<int> ans;
    for(int i = u + 1; i <= n; ++ i) {
        for(int j = v + 1; j <= n; ++ j)
//           if(pre[i] > u || pre[j] > v) continue;
//           else
            if(a[i] == b[j]) {
                go(i, j);
                vector<int> tmp = sav[i][j];
                tmp.push_back(a[i]);
                ans = Max(ans, tmp);
           }
    }
    sav[u][v] = ans;
}
void write(vector<int> &a) {
    cout << a.size() << "\n";
    for(int i = a.size() - 1; i >= 0; -- i) cout << a[i] << " "; cout << "\n";
}
void sub1() {
    for(int i = 1; i <= n; ++ i)
        for(int j = 1; j < i; ++ j) {
            if(a[i] == a[i]) pre[i] = j;
            if(b[i] == b[j]) pre[i] = j;
    }
//    for(int i = 1; i <= n; ++ i) cout << pre[i] << " ";
    go(0, 0);
    write(sav[0][0]);
}

int main() {
//#define file "r"
#define file "LIONDANCE"
    freopen(file".inp", "r", stdin);
    freopen(file".out", "w", stdout);

    cin >> n >> m;
    for(int i = 1; i <= n; ++ i) cin >> a[i];
    for(int i = 1; i <= n; ++ i) cin >> b[i];
    if(n <= 100) sub1();

    return 0;
}
