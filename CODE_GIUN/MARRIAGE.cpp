#include <bits/stdc++.h>
const int maxn = 2e6 + 7;
int t[maxn], m, a, b, x;

int main(){
    freopen("MARRIAGE.INP", "r", stdin);
    freopen("MARRIAGE.OUT", "w", stdout);
    //freopen("input.INP", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d%d", &a, &b, &m);
    for (int i = 1; i <= m; i++){
        scanf("%d", &x);
        t[x] = 1;
        scanf("%d", &x);
        t[x + a] = 1;
    }
    for (int i = 1; i <= a + b; i++){
        if (t[i])
            printf("YES\n");
        else 
            printf("NO\n");
    }
}