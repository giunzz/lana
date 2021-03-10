#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define giuncute ios_base::sync_with_stdio(0) , cin.tie(0) , cout.tie(0)
ll n , k , t  , l , r;
int main()
{
    giuncute;
    freopen("giun.inp","r",stdin);
    freopen("giun.out","w",stdout);
    cin >> t;
    while (t--)
    {
        priority_queue<int , vector<int> , greater<int>>  q;
        cin >> n >> k ;
        for (int i = 1 ; i <= n ; i++)
        {
            cin >> l >> r;
            q.push(abs(l-r)+1);
        }
        cout << q.top() << endl;
    }
    
}
