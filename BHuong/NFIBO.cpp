/*#include<bits/stdc++.h>
using namespace std;
const string tenfile = "giun";
#define balabalo freopen((tenfile + ".inp").c_str(), "r", stdin); freopen((tenfile + ".out").c_str(), "w", stdout)
#define giuncute ios_base::sync_with_stdio(0) , cin.tie(0);
#define ll long long
ll n  , sang[(int) 2e5 + 7 ] = {0},f[155]={0}, ans = 0;

void xaysang()
{
    sang[0] = 1 , sang[1] = 1;
    for (int i = 2 ; i * i <= (int) 2e5 ; i++)
        if ( sang[i] == 0  )
            for (int j = i * 2 ; j <= (int) 2e5 ; j += i ) sang[j] = 1;
}
bool check (ll x)
{
    f[1] = 1 , f[2] = 1;
    for (int i = 3 ; i <= 151 ; i++) 
    {
        f[i] = f[i-1] + f[i-2];
        if ( f[i] == x) return true;
    }
    return false;
}
int main()
{
    balabalo;
    giuncute;
    cin >> n;
    xaysang();
    for (int i = 1 ; i <= n ; i++)
    {
        if (sang[i] == 0 && check(i) == true ) 
		{
            cerr << i << " ";
            ans++;
		} 
    }
    cout << ans;
    return 0;
}*/
#include <bits/stdc++.h>

using namespace std;

vector <int> a{3, 4, 5, 7, 11, 13, 17, 23, 29, 43, 47};
int d[100] = {0};

int main(){
    for (vector<int>::iterator it = a.begin() ; it != a.end(); ++it){
        d[*it] = 1;
    }
    freopen("giun.inp","r",stdin);
    freopen("giun.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++){
        d[i] += d[i - 1];
    }
    cout << d[n];
    //cerr << clock() << " ms";
    return 0;
}