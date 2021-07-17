#include <bits/stdc++.h>
#define ll long long
#define giuncute ios_base::sync_with_stdio(0),cin.tie(0);
using namespace std;
const ll maxn = 1e4 + 7 ;
ll n , a[maxn];
vector<ll> b;
char numToString(int k){
    return (char)(k+48);
}
string iS (ll s)
{
    string tmp = "";
    int x ;
    while (s != 0)
    {
        x = s % 10 ;
        char v = numToString(x);
        tmp = tmp + v;
        s /= 10;
    }
    reverse(tmp.begin() , tmp.end());
    return tmp ;
}

bool check (int x , int y)
{
    string s = iS(x);
    string s1 = iS(y);
    while (s.size() > s1.size()) s1 = s1 + '0';
    for (int i = 0 ; i < (int) s.size() ; i++)
    {
        if (s[i] < s1[i]) return false;
        if (s[i] > s1[i]) return true;
    }
}
int main()
{
    ll d[maxn] = {0};
    giuncute;
    freopen("ghepso.inp","r",stdin);
    freopen("ghepso.out","w",stdout);
    cin >> n ;
    for (int i = 1 ; i <= n ; i++) cin >> a[i];
    sort(a + 1 , a + 1 + n);
    for (int i = n ; i >=1  ; i--)
    {
        if (d[a[i]] == 0)
        {
            int tmp = a[i];
            for (int j = 1 ; j < i ; j++)
            {
                if (d[a[j]] == 0)
                {   
                    if (check (a[i] , a[j]) == false) tmp = a[j];
                  //  cerr << a[i] << " " << a[j] << " " << check(a[i] , a[j]) << " " << tmp << endl;
                }
            }
            b.push_back(tmp) , d[tmp] = 1;
        }
    }
    for (int i =0 ; i < b.size() ; i++) cout << b[i];
}
