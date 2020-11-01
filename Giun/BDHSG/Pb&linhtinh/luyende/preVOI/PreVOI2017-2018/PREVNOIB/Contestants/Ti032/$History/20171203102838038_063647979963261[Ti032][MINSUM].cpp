#include<bits/stdc++.h>

#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define ll long long
#define file "MINSUM"

using namespace std;

const int maxn = 1e6+5;
ll a , b ;
ll ans_a , ans_b;
int test;
typedef pair < long long , int > li ;
vector < li > a1 , b1; //phan tich ra thua so nguyen to

void fr()
{
    freopen (file".INP" , "r" , stdin);
    freopen (file".OUT" , "w" , stdout);
}

void enter()
{
    scanf("%lld%lld" , &a , &b);
}

bool snt(ll n)
{
    if (n<2) return false;
    if (n == 2 || n == 3) return true;
    if (n>3)
    {
        if(n % 2 == 0 || n % 3 == 0) return false;
        else
            for(ll i = 5;i * i <= n;i+=6)
                if(n % i == 0 || n % ( i + 2 ) == 0)
                    return false;
    }
    return true;
}

void solve()
{
    if (snt(a) && snt(b))
        printf("%lld %lld\n" , a , b);
    else
    {
    int cnt = 0 ;
    ll _a = a , _b = b;
    if (!snt(a))
    {
    for (ll i = 2 ; i <= _a ; ++i)
        if (_a % i == 0)
        {
            a1.pb(mp(i , 0));
            while (_a % i == 0)
            {
                a1[cnt].se++;
                _a /= i;
            }
            cnt++;
        }
    a = 1;
    for (int i = 0 ; i <= a1.size() ; ++i)
        if (a1[i].se % 2)
            a *= (1LL * a1[i].fi);
    }

    if (!snt(b))
    {
    cnt = 0;
    for (ll i = 2 ; i <= _b ; ++i)
        if (_b % i == 0)
        {
            b1.pb(mp(i , 0));
            while (_b % i == 0)
            {
                b1[cnt].se++;
                _b /= i;
            }
            cnt++;
        }
    b = 1;
    for (int i = 0 ; i <= b1.size() ; ++i)
        if (b1[i].se % 2)
            b *= (1LL * b1[i].fi);
    }

    ans_a = a , ans_b = b;
    ll GCD = __gcd(a , b);
    a /= GCD , b /= GCD;
    ll pro = a * b;
    ans_a = a , ans_b = b;
    for (ll i = sqrt(pro) ; i >= 1 ; --i)
        if (pro % i == 0)
            if (i + (pro / i) < (ans_a + ans_b))
            {
                ans_a = i ,  ans_b = pro / i;
                break;
            }
    printf("%lld %lld\n" , ans_a , ans_b);
    }
}

int main()
{
    fr();
    scanf("%d" , &test);
    for (int we = 1 ; we <= test ; ++we)
    {
        a1.clear() ; b1.clear();
        enter();
        solve();
    }
    return 0;
}
