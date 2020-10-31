#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
#define f first
#define s second
#define mk make_pair

const int N = 3e3 + 7;
const int M = 107;
int n, m, t, res, T, k;
int a[N], b[N];
ii rr[N*2];
vector<int> sav[M][M][M];
bool pass[M][M][M];

void Min(vector<int> &ans, vector<int> &a, vector<int> &b) {
    int m = a.size();
    for(int i = m - 1; i >= 0; -- i) {
        if(a[i] < b[i]) {
            for(int j = i; j >= 0; -- j) ans[j] = a[j];
            return ;
        }
        else
        if(a[i] > b[i]) {
            for(int j = i; j >= 0; -- j) ans[j] = b[j];
            return ;
        }
        else ans[i] = a[i];
    }
}
void write(vector<int> &ans) {
    for(int i = ans.size() - 1; i >= 0; -- i) cout << ans[i] << " "; cout << "\n";
}
void go(int x, int y, int num) {
    if(pass[x][y][num] || num == 0) return ;
    pass[x][y][num] = true;
    vector<int> ans;
    if(n - x + 1 + m - y + 1 == num) {
        if(x == n + 1) {
            for(int i = m; i >= y; -- i) ans.push_back(b[i]);
            sav[x][y][num] = ans;
        }
        else
            if(y == m + 1) {
                for(int i = n; i >= x; -- i) ans.push_back(a[i]);
                sav[x][y][num] = ans;
            }
            else {
                go(x, y + 1, num - 1); go(x + 1, y, num - 1);
                ans = sav[x][y + 1][num - 1];
                ans.push_back(b[y]);
                vector<int> tmp = sav[x + 1][y][num - 1];
                tmp.push_back(a[x]);
                Min(ans, ans, tmp);
                sav[x][y][num] = ans;
            }
//        cout << x << "  " << y << "  " << num << "  ok::\n";
//        write(ans);
    }
    else {
        if(x == n + 1) {
            go(x, y + 1, num - 1); go(x, y + 1, num);
            vector<int> tmp = sav[x][y + 1][num - 1];
            tmp.push_back(b[y]);
            ans = sav[x][y + 1][num];
            Min(ans, ans, tmp);
            sav[x][y][num] = ans;
        }
        else
        if(y == m + 1) {
            go(x + 1, y, num - 1); go(x + 1, y, num);
            vector<int> tmp = sav[x + 1][y][num - 1];
            tmp.push_back(a[x]);
            ans = sav[x + 1][y][num];
            Min(ans, ans, tmp);
            sav[x][y][num] = ans;
        }
        else {
            ans.resize(num);
            go(x + 1, y, num); go(x, y + 1, num); go(x + 1, y, num - 1); go(x, y + 1, num - 1);
            Min(ans, sav[x + 1][y][num], sav[x][y + 1][num]);
            vector<int> tmp = sav[x + 1][y][num - 1];
            tmp.push_back(a[x]);
            Min(ans, ans, tmp);
            tmp = sav[x][y + 1][num - 1];
            tmp.push_back(b[y]);
            Min(ans, ans, tmp);
            sav[x][y][num] = ans;
        }
//        cout << x << "  " << y << "  " << num << "  ok::\n";
//        write(ans);
    }
//    cout << x << "__" << y << "__" << num << "  ok::\n";
//    write(ans);
}
void sub1() {
    go(1, 1, k);
    write(sav[1][1][k]);
}
void sub2() {
//    for(int i = 1; i <= n; ++ i) {
//        rr[i].f = a[i];
//        rr[i].s = i;
//    }
//    for(int i = 1; i <= m; ++ i) {
//        rr[i + n].f = b[i];
//        rr[i + n].s = -i;
//    }
//
//    sort(rr + 1 , rr + m + n + 1);
//    rr[0].f = rr[1].f - 1;
//    int num = 0;
//    for(int i = 1; i <= n + m; ++ i) {
//        if(rr[i].f != rr[i - 1].f) ++ num, origin[num] = rr[i].f;
//        if(rr[i].s > 0) a[rr[i].s] = num;
//        else b[-rr[i].s] = num;
//    }
}

int main() {
//#define file "r"
#define file "SEQUENCE"
    freopen(file".inp", "r", stdin);
    freopen(file".out", "w", stdout);

    cin >> n >> m >> k;
    for(int i = 1; i <= n; ++ i) cin >> a[i];
    for(int j = 1; j <= m; ++ j) cin >> b[j];

    if(n <= 100 && m <= 100) sub1();
    else sub2();

    return 0;
}
