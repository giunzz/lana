#include <bits/stdc++.h>
#define f0(i, n) for(int i(0); i < (n); i++)
#define f1(i, n) for(int i(1); i <= n; i++)

using namespace std;
typedef long long ll;
const int N = 4002;

int m, delta, a[N], b[N];
vector <int> ***f;
vector <int> rong;

bool operator <(vector <int> a1, vector <int> a2){
    int sz1 = a1.size(), sz2 = a2.size();
    if(sz2==0) return 0;
    if(sz1==0) return 1;
    if(sz1 > sz2) return 0;
    if(sz2 > sz1) return 1;
    f0(i, sz1){
        if(a1[i] < a2[i]) return 1;
        if(a1[i] > a2[i]) return 0;
    }
    return 0;
}

vector <int> calc(int i, int j, int prea){
    if(i > m || j > m){
        return rong;
    }
    int SZ = f[i][j][prea].size();
    if(SZ > 0) return f[i][j][prea];
    vector <int> ans;
    vector <int> cur1 = calc(i, j + 1, prea);
    vector <int> cur2 = calc(i + 1, j, prea);
    if(ans < cur1){
        ans = cur1;
    }
    if(ans < cur2){
        ans = cur2;
    }
    if(a[i]==b[j]){
        cur1.clear();
        if(prea==0){
            cur1 = calc(i + 1, j + 1, i);
            cur1.insert(cur1.begin(), a[i]);
        }
        else{
            if(abs(a[i] - a[prea]) <= delta){
                cur1 = calc(i + 1, j + 1, i);
                cur1.insert(cur1.begin(), a[i]);
            }
        }
        if(ans < cur1){
            ans = cur1;
        }
    }
    f[i][j][prea] = ans;
    return ans;
}

int main(){
    ios_base::sync_with_stdio(0);
    freopen("LIONDANCE.inp", "r", stdin);
    freopen("LIONDANCE.out", "w", stdout);

    cin >> m >> delta;
    f1(i, m) cin >> a[i];
    f1(i, m) cin >> b[i];

    ///-----------
    f = new vector <int> **[m + 2];
    f0(i, m + 2){
        f[i] = new vector <int> *[m + 2];
        f0(j, m + 2){
            f[i][j] = new vector <int> [m + 2];
            f0(k, m + 2){
                f[i][j][k].clear();
            }
        }
    }
    /// -----------

    vector <int> answer = calc(1, 1, 0);
    int sz = answer.size();
    cout << sz << "\n";
    for(int i = 0; i < sz; i++){
        cout << answer[i] << " ";
    }
}

