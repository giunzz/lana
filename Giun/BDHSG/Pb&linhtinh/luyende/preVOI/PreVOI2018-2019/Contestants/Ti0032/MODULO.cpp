//--------DO NOTHING---------
#include <bits/stdc++.h>
#include <bitset>
//#define x first
//#define y second
#define mn
#define pb push_back
#define oo 1000000007
#define int long long
#define DoNothing "MODULO"
#define ii pair< int, int>
#define memset(f, a) memset(f, a, sizeof(f))
#define forr(i, a, b) for(int i= a; i<= b; i++)


using namespace std;

int a, b, n, m, k, p[41], MOD, ROOT;
map <int, int> M;

void print(int A, int B)
{
    for(int i= m- 1; i>= 0; i--)
    {
        if((B>> i)& 1) cout<< a;
        else cout<< b;
    }
    for(int i= n- 1; i>= 0; i--)
    {
        if((A>> i)& 1) cout<< a;
        else cout<< b;
    }
}

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen(DoNothing".inp", "r", stdin);
    freopen(DoNothing".out", "w", stdout);

    cin>> a>> b>> n>> k;

    MOD= 1<< n;
    ROOT= n;
    m= n/ 2, n-= m;

    p[0]= 1;
    forr(i, 1, 40)
    p[i]= (p[i- 1]* 10)% MOD;

    forr(x, 0, (1<< n)- 1)
    {
        int ans= 0;
        forr(i, 0, n- 1)
        {
            if((x>> i)& 1)
                ans= (ans+ a* p[i])% MOD;
            else ans= (ans+ b* p[i])% MOD;
        }
        M[ans]= x+ 1;
    }

    forr(x, 0, (1<< m)- 1)
    {
        int ans= 0;
        forr(i, 0, m- 1)
        {
            if((x>> i)& 1)
                ans= (ans+ a* p[i+ n])% MOD;
            else ans= (ans+ b* p[i+ n])% MOD;
        }
        ans= (k- ans+ (1<< ROOT))% MOD;
        int u= M[ans];
        if(u){
            print(u- 1, x);
            return 0;
        }
    }

    cout<< -1;
    return 0;
}
