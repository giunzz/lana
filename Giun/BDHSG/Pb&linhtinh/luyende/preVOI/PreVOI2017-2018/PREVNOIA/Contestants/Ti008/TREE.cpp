#include <bits/stdc++.h>
using namespace std;

#define removeDuplicate(a) sort(a.begin(), a.end()); a.resize(distance(a.begin(), unique(a.begin(), a.end())));


const long long N = 5005;
const long long INF = 1e9 + 7;
long long n;
long long a[N];
vector<long long> g[N];
vector<long long> tree[N];
long long f[N][N];
long long leafCounter[N];


void dfsBuild (long long foo, long long parent)
{
    for (long long i = 0; i < g[foo].size(); i++)
    {
        long long bar = g[foo][i];
        if (bar == parent) continue;
        dfsBuild(bar, foo);
        tree[foo].push_back(bar);
    }
}

void dfs (long long foo)
{
    if (tree[foo].size() == 0)
        leafCounter[foo] = 1;
    else
        leafCounter[foo] = 0;

    for (long long i = 0; i < tree[foo].size(); i++)
    {
        long long bar = tree[foo][i];
        dfs(bar);
        leafCounter[foo] += leafCounter[bar];
    }
    if (tree[foo].size() == 0)
    {
        f[foo][0] = abs(0 - a[foo]);
        f[foo][1] = abs(1 - a[foo]);
        return;
    }
    if (tree[foo].size() == 1)
    {
        long long leftChild = tree[foo][0];
        for (long long sum = 0; sum <= leafCounter[leftChild]; sum++)
            f[foo][sum] = f[leftChild][sum] + abs(sum - a[foo]);
        return;
    }
    if (tree[foo].size() == 2)
    {
        long long leftChild = tree[foo][0];
        long long rightChild = tree[foo][1];
        for (long long sum = 0; sum <= (leafCounter[leftChild] + leafCounter[rightChild]); sum++)
            f[foo][sum] = INF;

        for (long long leftSum = 0; leftSum <= leafCounter[leftChild]; leftSum++)
            for (long long rightSum = 0; rightSum <= leafCounter[rightChild]; rightSum++)
            {
                long long sum = leftSum + rightSum;
                f[foo][sum] = min(f[foo][sum], f[leftChild][leftSum] + f[rightChild][rightSum] + abs(sum - a[foo]));
            }
    }
}


int main()
{
    #define file "TREE"
    freopen(file".inp", "r", stdin); freopen(file".out", "w", stdout);


    cin >> n;
    for (long long i = 1; i <= n; i++) cin >> a[i];
    for (long long ie = 1; ie < n; ie++)
    {
        long long foo, bar;
        cin >> foo >> bar;
        g[foo].push_back(bar);
        g[bar].push_back(foo);
    }
    dfsBuild (1, 0);
    dfs (1);
    /*for (long long foo = 1; foo <= n; foo++)
    {
        cout << leafCounter[foo] << endl;
    }*/
    long long ret = INF;
    for (long long sum = 0; sum <= leafCounter[1]; sum++)
        ret = min(ret, f[1][sum]);
    cout << ret;
    return 0;
}

