				///************** H.A.N Smile **************///
#include <bits/stdc++.h>
#define f first
#define s second
#define mp make_pair
#define MOD 1000000007
#define HAN "MINSUM"
#define ii pair<int , int>
#define lii pair <long long , int>
#define ll long long
#define pb push_back
using namespace std;
const int N = 1e5 + 5;
int T , h[N], snt, dem[N];
bool dd[N];
long long a , b;
void make_test()
{
	freopen(HAN".inp", "w", stdout);
	srand(time(0));
}

void sang()
{
    for (int i = 2; i <= 1e5 ; ++i) if (!dd[i])
    {
        h[++snt] = i;
        for (int j = i ; j <= 1e5 ; j += i) dd[j] = 1;
    }
}

main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	//make_test();
	freopen(HAN".inp" , "r", stdin);
	freopen(HAN".out" , "w", stdout);
    scanf("%d", &T);
    sang();

    while (T--)
    {
        memset(dem , 0 , sizeof(dem));
        scanf("%lld%lld", &a, &b);
        int q = __gcd(a , b);
        a /= q;
        b /= q;
        int i = 1;
        while (a != 1 && i <= snt)
        {
            while (a != 1 && a % h[i] == 0) dem[h[i]]++, a /= h[i];
            i++;
        }
        i = 1;
        while (b != 1 && i <= snt)
        {
            while (b != 1 && b % h[i] == 0) dem[h[i]]++, b /= h[i];
            i++;
        }
        int d = 1;
        for (int i = 1; i <= snt ; ++i) if (dem[h[i]])
        {
            int x = dem[h[i]]/2;
            if (dem[h[i]] % 2 == 0){
            for (int j = 1 ; j <= x ; ++j) a *= h[i];
            for (int j = 1 ; j <= x ; ++j) b *= h[i];
            }

            else {
                for (int j = 1 ; j <= x ; ++j) a *= h[i];
                for (int j = 1 ; j <= x ; ++j) b *= h[i];
                if (a < b) a *= h[i];
                else b *= h[i];
            }
        }

        int p = __gcd(a , b);
        a /= p;
        b /= p;
        if (a > b) swap(a , b);
        printf("%lld %lld\n", a , b);
    }
}
