#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 7;
int n, f[maxn] = {0}, a[maxn], kq[maxn], c[maxn] = {0};

int getS(int i){
    int j = n, ans = 0;
    while (i <= j){
        if ((j - (j & (-j))) >= i){
            ans += f[j];
            j = j - (j & (-j));
        } 
        else {
            ans += c[j--];
        }
    }
    return ans;
}

void updt(int i){
    while(i <= n){
        ++f[i];
        i += i & (-i);
    }
}

void sol(int pi){
    kq[pi] = n - a[pi] - getS(pi);
    //if (pi == n) cerr << kq[pi];
    c[a[pi]] = 1;
    updt(pi);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("nghichthe.inp", "r", stdin);
    freopen("nghichthe.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = n; i >= 1; i--) sol(i);
    for (int i = 1; i <= n; i++) cout << kq[i] << " ";
}