#include<bits/stdc++.h>
using namespace std;

int n , t[107], d[107], p[107], a[107]={0}, ans = -1, s = 0, thoigian = 0;
void quaylui(int vt)
{
    if (vt == n+1)
    {
        s = 0 , thoigian = 0;
        for (int i = 1 ; i <= n ; i++)
        {
            if (a[i] == 1 && thoigian+t[i] < d[i])
            {
                s += p[i];
                thoigian += t[i];
            }
        }
        ans = max (ans,s);
    }
    else 
    {
        for (int i = 0 ; i <= 1 ; i++)
        {
            a[vt] = i;
            quaylui(vt+1);
        }
    }
}


int main()
{
 //   freopen("giun.inp","r",stdin);
 //   freopen("giun.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1 ; i <= n ; i++) cin >> t[i] >> d[i] >> p[i];
    quaylui(1);
    cout << ans;
}