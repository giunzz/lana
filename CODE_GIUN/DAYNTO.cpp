#include<bits/stdc++.h>
using namespace std; 
const int nmax = 1e7 + 7;
#define giuncute ios_base::sync_with_stdio(0),cin.tie(0);
#define ballolo freopen("DAYNTO.inp","r",stdin) , freopen("DAYNTO.out","w",stdout) ; 
bool sang[nmax];

void xaysang()
{
    sang[0] = 1; sang[1] = 1;
    for (int i = 2; i * i <= 1e7; i++)
        if (!sang[i]) 
           for (int j = i * 2; j <= 1e8; j += i) sang[j] = 1;
}
int n , num;
int main()
{
    giuncute;
    ballolo;
    xaysang();
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> num;
        if (!sang[num]) cout << "YES\n";
        else cout << "NO\n";
    }
}