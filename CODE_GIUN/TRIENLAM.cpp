#include <bits/stdc++.h>
#define ll long long
#define giuncute ios_base::sync_with_stdio(0),cin.tie(0);
const ll maxn = 1e4 + 7;;
ll n ;
using namespace std;
struct giun
{
    int x , y ;
} a[maxn];
bool cmp (giun &a , giun &b)
{
    return (a.y <= b.y);
}
int main()
{
    giuncute;
    freopen("giun.inp" , "r",stdin);
    freopen("giun.out", "w" ,stdout);
    cin >> n;
    for (int i = 1 ; i <= n ; i++)  cin >> a[i].x >> a[i].y;
    sort (a + 1 , a + 1 + n , cmp) ;
    for (int i = 1 ; i <= n ; i++) cerr << a[i].x << " " << a[i].y << endl;

}

