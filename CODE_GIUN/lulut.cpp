#include<bits/stdc++.h>
using namespace std;

int n , t[107], d[107], p[107], a[107]={0}, ans = -1, s = 0, thoigian = 0, f[107]={0};
int main()
{
    freopen("giun.inp","r",stdin);
    freopen("giun.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1 ; i <= n ; i++) cin >> t[i] >> d[i] >> p[i];
    for (int i = 1 ; i < n ; i++)
    {
        for (int j = i+1 ; j <= n ; j++)
        {
            if (p[i] < p[j]) swap(t[i],t[j]),swap(d[i],d[j]),swap(p[i],p[j]);
        }
    }
    for (int i = 1 ; i <= n ; i++) 
    {
        cerr << t[i] << " " << d[i] << " " << p[i] << endl;
        if (f[i] < f[i-1] + p[i] && thoigian+t[i] < d[i])
        {
            f[i] = f[i-1] + p[i];
            thoigian += t[i];
        }
        else f[i] = f[i-1];
    }
    
    cout << f[n];
}