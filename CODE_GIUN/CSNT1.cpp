#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 7;
int d[maxn] = {0}, n, t, ans[maxn] = {0}, tk = 0;

bool cnt(int k){
    for (int i = 2; i * i <= k; i++){
        if (!(k % i)) return false;
    }
    return 1;
}

int dao(int k){
    int b = 0;
    while (k){
        b = b * 10 + k % 10;
        k /= 10;
    }
    return b;
}

int main(){
    freopen("giun.INP", "r", stdin);
    freopen("giun.OUT", "w", stdout);
    scanf("%d", &n);
    for (int i = 12; i <= n; i++){
        if(!cnt(i)) continue;
        t = dao(i);
        if(!cnt(t) || t == i || d[i] || d[t]) continue;
        ans[++tk] = i;       
        d[i] = 1, d[t] = 1;
    }
    printf("%d\n", tk);
    for(int i = 1; i <= tk; i++) printf("%d %d\n", ans[i], dao(ans[i]));
}