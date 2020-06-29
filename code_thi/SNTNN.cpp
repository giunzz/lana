#include <bits/stdc++.h>
using namespace std;
int  n ;
bool kt (int x)
{
    for (int i = 2 ; i*i <= x ; i++)
        if ( x % i == 0) return false;
    return true;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("giun.inp","r",stdin);freopen("giun.out","w",stdout);
    freopen("SNTNN.inp","r",stdin);freopen("SNTNN.out","w",stdout);
    cin >> n;
    int k = n ;
    while ( kt(k) == false ) k++;
    cout << k;
    return 0;
}

