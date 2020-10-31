#include <bits/stdc++.h>
using namespace std;

#define removeDuplicate(a) sort(a.begin(), a.end()); a.resize(distance(a.begin(), unique(a.begin(), a.end())));


const long long N = 1e6 + 10;
const long long INF = 1e18 + 7;
long long n, k;
long long a[N];
long long s[N];
long long preMax[N], sufMax[N];

long long read ()
{
    char c;
    while (true) { c = getchar(); if (isdigit(c)) break; }
    long long ret = c - '0';
    while (true) { c = getchar(); if (not isdigit(c)) break; ret = ret * 10 + c - '0'; }
    return ret;
}

long long rangeSum (long long l, long long r)
{
    return s[r] - s[l - 1];
}

int main()
{
    #define file "GIFTS"
    freopen(file".inp", "r", stdin); freopen(file".out", "w", stdout);

    n = read(); k = read();
    for (long long i = 1; i <= n; i++)
    {
        a[i] = read();
        s[i] = s[i - 1] + a[i];
    }
    for (long long i = k; i <= n; i++)
    {
        preMax[i] = max(preMax[i - 1], rangeSum(i - k + 1, i));
    }
    for (long long i = n - k + 1; i >= 1; i--)
    {
        sufMax[i] = max(sufMax[i + 1], rangeSum(i, i + k - 1));
    }
    //for (long long i = 1; i <= n; i++) cout << preMax[i] << " "; cout << endl;
    //for (long long i = 1; i <= n; i++) cout << sufMax[i] << " "; cout << endl;
    long long ret = INF;
    for (long long i = 1; i <= n - k + 1; i++)
    {
        ret = min(ret, max(preMax[i - 1], sufMax[i + k]));
    }
    cout << ret;
    return 0;
}

