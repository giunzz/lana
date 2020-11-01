#include <bits/stdc++.h>
#define f0(i, n) for(int i(0); i < (n); i++)
#define f1(i, n) for(int i(1); i <= n; i++)

using namespace std;
typedef long long ll;
const int N = 3002;

int m, n, k, a[N], b[N];

void calc(int i, int j, int s){
    if(i > m && j > n) return ;
    int pos1 = -1, pos2 = -1, ma1 = 1e9, ma2 = 1e9;
    if(s==k){
        return ;
    }
    for(int u = i; u <= m; u++){
        int cur = m - u + n - j + 1 + s + 1;
        if(cur >= k){
            if(a[u] < ma1){
                pos1 = u, ma1 = a[u];
            }
        }
    }
    for(int v = j; v <= n; v++){
        int cur = n - v + m - i + 1 + 1 + s;
        if(cur >= k){
            if(b[v] < ma2){
                ma2 = b[v], pos2 = v;
            }
        }
    }
    if(pos2==-1){
        cout << ma1 << " ";
        calc(pos1 + 1, j, s + 1);
    }
    else if(pos1==-1){
        cout << ma2 << " ";
        calc(i, pos2 + 1, s + 1);
    }
    else{
        if(ma1 < ma2){
            cout << ma1 << " ";
            calc(pos1 + 1, j, s + 1);
        }
        else if(ma2 > ma1){
            cout << ma2 << " ";
            calc(i, pos2 + 1, s + 1);
        }
        else{
            if(m < n){
                cout << ma1 << " ";
                calc(pos1 + 1, j, s + 1);
            }
            else{
                cout << ma2 << " ";
                calc(i, pos2 + 1, s + 1);
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    freopen("SEQUENCE.inp", "r", stdin);
    freopen("SEQUENCE.out", "w", stdout);

    cin >> m >> n >> k;
    f1(i, m) cin >> a[i];
    f1(j, n) cin >> b[j];

    calc(1, 1, 0);
}

