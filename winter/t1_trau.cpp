#include<bits/stdc++.h>

using namespace std;

int n ;

int main()
{
    freopen("giun.inp","r",stdin);
    freopen("trau.out","w",stdout);
    cin >> n ;
    int s = 0;
    for (int i = 1 ; i <= n ; i++) s += i;
    cout << s;
}