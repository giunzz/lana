#include<bits/stdc++.h>
using namespace std;
#define giuncute ios_base::sync_with_stdio(0) , cin.tie(0) , cout.tie(0)
int n , k , t  ;
struct giun
{
    int x , r ;
} a[(int) 1e6+7];
bool cmp (giun&u , giun&v)
{
    return (u.x <= v.x);
} 
int main()
{
    giuncute;
 //   freopen("giun.inp","r",stdin);
 //   freopen("giun.out","w",stdout);
    cin >> t;
    while (t--)
    {
        priority_queue<int,vector<int> , greater<int> > q;
        cin >> n >> k ;
        for (int i = 1 ; i <= n ; i++) cin >> a[i].x >> a[i].r;
        //for (int i = 1 ; i <= n ; i++) cerr << a[i].x << " " << a[i].r << endl;
        sort(a+1 , a+1+n , cmp);

        //for (int i = 1 ; i <= n ; i++) cerr << a[i].x << " " << a[i].r << endl;

        for (int i = 1 ; i <= k ; i++) q.push(a[i].r);
        int ans = q.top() - a[k].x +1;
        //cerr << q.top() << " ";
        for (int i = k + 1 ; i <= n ; i++)
        {
            q.pop();
            q.push(a[i].r);
            ans = max( ans , q.top() - a[i].x + 1);
        }
        cout << max(ans,0) << endl;
    }
    
}