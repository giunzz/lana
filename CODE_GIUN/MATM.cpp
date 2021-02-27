/*#include<bits/stdc++.h>
using namespace std;
const string tenfile = "giun";
#define balabalo freopen((tenfile + ".inp").c_str(), "r", stdin); freopen((tenfile + ".out").c_str(), "w", stdout)
#define ll long long
ll n , k ,  a[25] , b[25] , ans = 0 , c[25] ={0} , sum = 0 ;

void fastscan(ll &number) 
{ 
    bool negative = false; 
    register int c; 
    number = 0; 
    c = getchar(); 
    if (c == ' ') fastscan(number);
    if (c=='-') 
    { 
        negative = true; 
        c = getchar(); 
    } 
    for (; (c>47 && c<58); c=getchar()) 
        number = number *10 + c - 48; 
    if (negative) 
        number *= -1; 
}
void chon (int vt)
{
    if ( vt == n + 1) 
    {
        int sum = 0 ; 
        for (int i = 1 ; i <= n ; i++) sum += c[i] * a[i];
        if ( sum == k ) ans ++;
    }
    else 
    {   
        for (int j = 0 ; j <= b[vt] ; j++) 
        {
            c[vt] = j;
            chon (vt + 1);
        }
    }
}
int main()
{
    balabalo;
    fastscan(n) , fastscan(k);
    for (int i = 1 ; i <= n ; i++) fastscan(a[i]);
    for (int i = 1 ; i <= n ; i++) fastscan(b[i]);
    chon(1);
    cout << ans;
}*/

#include<bits/stdc++.h>
using namespace std;
const string tenfile = "MATM";
#define balabalo freopen((tenfile + ".inp").c_str(), "r", stdin); freopen((tenfile + ".out").c_str(), "w", stdout)
#define ll long long
#define giuncute ios_base::sync_with_stdio(0) , cin.tie(0);
#define lp(a, b, c) for(ll a = b; a <= c; a++)

ll n, k, a[25], b[25], c[25], sum = 0, ans = 0;
void fastscan(ll &number) 
{ 
    bool negative = false; 
    register int c; 
    number = 0; 
    c = getchar(); 
    if (c == ' ') fastscan(number);
    if (c=='-') 
    { 
        negative = true; 
        c = getchar(); 
    } 
    for (; (c>47 && c<58); c=getchar()) 
        number = number *10 + c - 48; 
    if (negative) 
        number *= -1; 
}

void chon(ll vt)
{
    if(sum == k) ++ans;
    if(sum >= k || vt == n + 1 || (sum + c[n] - c[vt - 1]) < k) return;
    lp(i, 0, b[vt])
    {
        sum += i * a[vt];
        chon(vt + 1);
        sum -= i * a[vt];
    }
}
int main()
{
    balabalo;
    giuncute
    c[0] = 0;
    cin >> n >> k;
    lp(i, 1, n) cin >> a[i];
    lp(i, 1, n) 
    {
        cin >> b[i];
        c[i] = a[i]*b[i] + c[i - 1];
    }
    chon(1);
    cout << ans;
}