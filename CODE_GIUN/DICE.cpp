#include<bits/stdc++.h>

using namespace std;

long long n , d[]={3,6,4,1};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("dice.inp","r",stdin);
    freopen("dice.out","w",stdout);
    cin >> n;
    cout << d[n%4];
}