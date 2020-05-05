#include <bits/stdc++.h>
using namespace std;

int n, d, a[25] = {0}, s = 0, tt, check = 0;
vector<int> ans;

void printans()
{
    for (int i = 0; i < (int) ans.size(); ++i)
    {
        printf("%d ", a[ans[i]]);
    }
}

void quaylui(int vt)
{
    if (s > d || vt == n + 1 || check) return; 
    if (s == d)
    { 
        printans();
        check = 1;
        return;
    }
    if (vt == 1) tt = 1; 
    else tt = ans.back() + 1; 
    for (int i = tt; i <= n; i++)
    {
        s += a[i]; 
        ans.push_back(i);
        quaylui(vt + 1);
        s -= a[i];
        ans.pop_back();
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("tratien.inp", "r", stdin);
    freopen("tratien.out", "w", stdout);
    scanf("%d %d", &n, &d);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]); 
        s += a[i];
    }
    if (s < d) {
        printf("-1"); 
        return 0;
    } 
    sort(a + 1, a + 1 + n);
    if (s == d)
    {
        for(int i = 1; i <= n; i++) printf("%d", a[i]);
        return 0;
    }
    s = 0; 
    quaylui(1);
    if(!check) printf("-1");
}