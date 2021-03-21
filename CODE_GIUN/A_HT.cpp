#include<bits/stdc++.h>
using namespace std;
#define giuncute ios_base::sync_with_stdio(0) , cin.tie(0);
#define ll long long
const ll maxn = 1e5+7;
string s[maxn] , s1[maxn];
string s2 = "";
ll n , h , p , x , y , st , siz;
int main()
{
    giuncute;
    //freopen("giun.inp","r",stdin);
    //freopen("giun.out","w",stdout);
    cin >> n ;
    for (int i = 1 ; i <= n ; i++) cin >> siz >> s[i];
    for (int i = 1  ; i <= n ; i++)
    {
        cin >> h;
        s1[h] += s[i];
    }
    for (int i = 1 ; i <= n ; i++ ) 
    {
        //cerr << s1[i] << " ";
        s2 += s1[i];
    }
    cin >> p ;
    for (int i = 1 ; i <= p ; i++)
    {
        cin >> x >> y;
        char c = s2[y-1] , m = s2[x-1];
        s2[x-1] = c , s2[y-1] = m ;
    }
    cout << s2;
}
