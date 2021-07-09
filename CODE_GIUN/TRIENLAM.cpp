#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define giuncute ios_base::sync_with_stdio(0), cin.tie(0)

const ll maxn = 1e4+7;
int n , f[maxn] ={0},ans = 0;

struct giun
{
    int x,y;
}a[maxn];

bool cmp (giun &a , giun &b) {
    return (a.x <= b.x);
}

int main()
{ 
    giuncute;
    freopen("trienlam.inp", "r", stdin);
    freopen("trienlam.out", "w", stdout);
    cin >> n ;
    for (int i = 1 ; i <= n ; i++) cin >> a[i].x >> a[i].y;
    sort (a+1, a+1+n , cmp);
    for (int i = 1 ; i <= n ; i++)
    {
        for (int j = 1 ; j < i ; j++)
            if (a[j].y <= a[i].x ) f[i] = max(f[i],f[j]);
        f[i] += (a[i].y-a[i].x);
        ans = max (ans,f[i]);
    }
    cout << ans;
}
