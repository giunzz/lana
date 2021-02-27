/*#include<bits/stdc++.h>

using namespace std;

long n , s;

void xuat()
{
    cout << s;
}

void slove( long q )
{
    long x , k ;
    s = 0 ;
    while (q != 0)
    {
        x = q % 10;
        s += x;
        q = q / 10;
    }
    k = s;
    if (s > 9) slove(k);
    else xuat();
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("SONUT.INP","r",stdin);
    freopen("SONUT.OUT","w",stdout);
    cin >> n;
    if (n < 10 ) cout << n ;
    else slove(n);
    return 0;
}
#include<bits/stdc++.h>

using namespace std;

long n , s;

long slove( long q )
{
    long x , k , s =  0;
    while (q != 0)
    {
        x = q % 10;
        s += x;
        q = q / 10;
    }
    k = s;
    if (s > 9) slove(k);
    else xuat();
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("SONUT.INP","r",stdin);
    freopen("SONUT.OUT","w",stdout);
    cin >> n;
    if (n < 10 ) cout << n ;
    else slove(n);
    return 0;
}*/
#include<bits/stdc++.h>

using namespace std;

int n;

int Sol(int n) {
    if (n < 10) return (n);
    int tmp = n;
    int res = 0;
    while (tmp != 0) {
        res += (tmp % 10);
        tmp /= 10;
    }
    if (res > 9) return (Sol(res));
    return (res);
}

int main()
{
    freopen("SONUT.INP","r",stdin);
    freopen("SONUT.OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    cout << Sol(n);
    return 0;
}