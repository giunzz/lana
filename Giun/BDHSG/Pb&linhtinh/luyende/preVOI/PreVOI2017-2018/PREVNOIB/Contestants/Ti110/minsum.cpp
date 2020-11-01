#include<bits/stdc++.h>
using namespace std;
#define int long long
int T;
map<int,int> f, f2;
vector<int> one;
vector<int> two;
void solve(int cur)
{
    int N = cur;
    for(int i = 2 ; i * i <= N ; i++)
    {
        int kt = 0;
        while(N % i == 0)
        {
            N /= i;
            kt = 1;
            f[i]++;
        }
        if (kt == 1) one.push_back(i);
    }
    if (N > 1)
    {
        one.push_back(N);
        f[N]++;
    }
}

void init(int cur)
{
    int N = cur;
    for(int i = 2 ; i * i <= N ; i++)
    {
        int kt = 0;
        while(N % i == 0)
        {
            N /= i;
            kt = 1;
            f2[i]++;
        }
        if (kt == 1) two.push_back(i);
    }
    if (N > 1)
    {
        two.push_back(N);
        f2[N]++;
    }
}

main()
{

    freopen("minsum.inp","r",stdin);
    freopen("minsum.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    while(T--)
    {
        one.clear();
        two.clear();
        f.clear();
        f2.clear();
        int x, y;
        cin >> x >> y;
        solve(x);
        init(y);
        for(int i = 0 ; i < one.size() ; i++)
        {
            int res = one[i];
            if (f[res] && f2[res])
            {
                if (f[res] % 2 == 0 && f2[res] % 2  == 0)
                {
                    f[res] = 0;
                    f2[res] = 0;
                }
                else if (f[res] % 2 == 1 && f2[res] % 2 == 1)
                {
                    f[res] = 0;
                    f2[res] = 0;
                }
                else if (f[res] % 2 == 0 && f2[res] % 2 == 1)
                {
                    f[res] = 0;
                    f2[res] = 1;
                }
                else if (f[res] % 2 == 1 && f2[res] % 2 == 0 )
                {
                    f2[res] = 0;
                    f[res] = 1;
                }
            }
            else if (f[res] && f2[res] == 0)
            {
                f[res] = f[res] % 2;
            }
        }
        for(int i = 0 ; i < two.size() ; i++)
        {
            int res = two[i];
            f2[res] = f2[res] % 2;
        }

        int val1 = 1, val2 = 1;
        for(int i = 0 ; i < one.size() ; i++)
            for(int j = 1 ; j <= f[one[i]] ; j++)
                val1 *= one[i];
        for(int i = 0 ; i < two.size() ; i++)
            for(int j = 1 ; j <= f2[two[i]] ; j++)
                val2 *= two[i];
        if (val2 > val1) {
        for(int i = two.size() - 1 ; i >= 0 ; i--)
            if (f2[two[i]] == 1) {
                int v2 = val2 / two[i];
                int v1 = val1 * two[i];
                if (v2 + v1 < val2 + val1) {
                    val2 = v2;
                    val1 = v1;
                }
            }
        }
        else if (val1 > val2){
            for(int i = one.size() - 1 ; i >= 0 ; i--)
            if (f[one[i]] == 1) {
                int v2 = val2 * one[i];
                int v1 = val1 / one[i];
                if (v1 + v2 < val1 + val2) {
                    val2 = v2;
                    val1 = v1;
                }
            }
        }
        cout << val1 << " " << val2 << "\n";
    }
    return 0;
}
