#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5+5;

int n;
int a[maxn];
long long res = 0, sum = 0, s[maxn];
stack <int> st, stn;
bool ok = true;

int main()
{
    freopen("Arrange.inp", "r", stdin);
    freopen("Arrange.out", "w", stdout);
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    cin >> n;
    for (int i=1; i<=n; i++)
    {
        cin >> a[i];
        sum += a[i];
    }
    if (sum % n == 0)
    {
        //long long s = 0;
        sum = sum / n;
        for (int i=1; i<=n; i++)
            if (a[i] > sum)
            {
                res += a[i] - sum;
                a[i+1] += (a[i] - sum);
            }
            else if (a[i] < sum)
            {
                res += sum - a[i];
                a[i+1] -= (sum - a[i]);
            }
        cout << res;
    }
    else
    {
    sum = sum / n;
    for (int i=n; i>=1; i--)
    {
        if (a[i] > sum) stn.push(i);
        s[i] = s[i+1] + a[i];
    }
    for (int i=1; i<=n; i++)
    {
        if (a[i] > sum)
        {
            stn.pop();
            st.push(i);
            a[i+1] += (a[i]-sum-1);
            s[i+1] += (a[i]-sum-1);
            a[i] = sum+1;
            res += a[i] - sum - 1;
        }
        else if (a[i] < sum)
        {
            while (st.size() and s[i] < (n-i+1)*sum and a[i] < sum)
            {
                s[i] += 1;
                int t = st.top();
                res += i - t;
                st.pop();
            }
            int t = stn.top();
            a[t] -= (sum - a[i]);
            if (a[t] <= sum) stn.pop();
            for (int j=i+1; j<=t; j++) s[j] -= (sum - a[i]);
            res += sum - a[i];
            a[i] = sum;
        }
        //cout << a[i] << ' ' << res << '\n';
    }
        cout << res;
    }
}
