#include<bits/stdc++.h>
using namespace std;

bool d[(long long ) 1e15]={0};
long long m;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    freopen("giun.inp","r",stdin);
    freopen("giun.out","w",stdout);
    cin >> m ;
    d[m] = 1;
    cout << d[m] << " " << m;
    }