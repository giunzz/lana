#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll maxn = 1e6;
ll  m ,n , t,a[maxn+7]={0}, b[maxn+7]={0},d=0;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("taphop.inp","r",stdin);
    freopen("taphop.out","w",stdout);
    cin >> m >> n ;
    for (int i = 1 ; i <= m ; i++)
    {
        cin >> t;
        a[t] = 1;
    }
    for (int i = 1 ; i <= n ; i++)
    {
        cin >> t;
        b[t] = 1;
    }
    d = 0;
    for (int i = 1 ; i <= maxn ; i++)
    {
        if (b[i]==1 || a[i] == 1) cout << i << " ",d++;
    }
    if (d == 0) cout <<"#"<<endl;
    else cout << endl;
    d = 0;
    for (int i = 1 ; i <= maxn ; i++)
    {
        if (b[i]==1 && a[i] == 1) cout << i << " ",d++;
    }
    if (d == 0) cout <<"#"<<endl;
    else cout << endl;
    d = 0;
    for (int i = 1 ; i <= maxn ; i++)
    {
        if (a[i]==1 && b[i] == 0) cout << i << " ",d++;
    }
    if (d == 0) cout <<"#"<<endl;
    else cout << endl;
}
