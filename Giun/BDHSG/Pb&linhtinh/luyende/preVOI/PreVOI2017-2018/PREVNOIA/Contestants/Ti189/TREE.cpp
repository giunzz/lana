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
const int maxn = 1e4 + 69;
int n, u, v, gt[maxn], temp[maxn], p[maxn], cha[maxn];
vector<II> la;
vector<int> a[maxn];
ll res;
void dfs(int u)
{
    if(a[u].size() == 0){
        la.pb(mp(p[u], u));
        return;
    }
    FORv(i, 0, a[u].size()){
        int v = a[u][i];
        p[v] = p[u] + 1;
        dfs(v);
    }
}
void update(int u, int j)
{
    temp[u] = gt[u] = j;
    while(u != 1){
        u = cha[u];
        temp[u] += j;
    }
}
int get(int u, int j)
{
    int res = abs(gt[u] - j);
    while(u != 1){
        u = cha[u];
        res += abs(gt[u] - (temp[u] + j));
    }
    return res;
}
int main()
{
    freopen("TREE.inp", "r", stdin);
    freopen("TREE.out", "w", stdout);
    ios :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    scanf("%d", &n);
    FOR(i, 1, n) scanf("%d", &gt[i]);
    FOR(i, 1, n - 1){
        scanf("%d%d", &u, &v);
        a[u].pb(v);
        cha[v] = u;
    }
    dfs(1);
    sort(la.begin(), la.end());
    FORd(i, (int)la.size() - 1, 0){
        int u = la[i].y;
       // cout << u << ' ';;
        int temp0 = get(u, 0);
        int temp1 = get(u, 1);
      //  cout << u << ' ' << temp0 << ' ' << temp1 << endl;
        if(temp0 < temp1){
            res += gt[u];
            update(u, 0);
        }
        else if(temp1 < temp0){
            res += abs(gt[u] - 1);
            update(u, 1);
        }
        else{
            if(gt[u] != 0){
                res += abs(gt[u] - 1);
                update(u, 1);
            }
        }
     //   cout << gt[u] << ' ' << res << endl;
    }
   // FOR(i, 1, n) cout << temp[i] << ' ';
   // cout << endl;
  //  cout << res << endl;
    FOR(i, 1, n) res += abs(gt[i] - temp[i]);
    printf("%lld", res);
    return 0;
}
