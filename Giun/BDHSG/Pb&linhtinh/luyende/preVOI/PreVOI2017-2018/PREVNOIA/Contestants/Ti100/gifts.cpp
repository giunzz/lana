#include<iostream>
#include<cstdio>

const int maxN = 1e6 + 5;
#define For(i,a,b) for(int i=a;i<=b;i++)
#define Ford(i,a,b)for(int i=a;i>=b;i--)
#define ll        long long

using namespace std;

int n, k, a[maxN], x, st, en, cnt = 0;
ll s[maxN], m = 0, m2 = 0;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("gifts.inp", "r", stdin);
    freopen("gifts.out", "w", stdout);
    cin >> n >> k;
    For(i, 1, n) cin >> a[i];
    For(i, 1, k) s[1] += a[i];
    st = 1;
    en = k;
    m  = s[1];
    cnt = 1;
    For(i, k + 1, n)
    {
        cnt++;
        s[cnt] = s[cnt - 1] - a[i - k] + a[i];
        if(s[cnt] > m)
        {
            st = i - k + 1;
            m  = s[cnt];
            en = i;
        }
    }
    For(i, 1, cnt)
    {
        if(s[i] >= m2)
        {
            if(i + k - 1 < st || i > en) m2 = s[i];
        }
    }
    cout << m2;
    return 0;
}
