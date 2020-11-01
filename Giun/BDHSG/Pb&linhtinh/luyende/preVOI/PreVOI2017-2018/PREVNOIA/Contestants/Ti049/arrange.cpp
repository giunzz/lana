#include<bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define int long long
#define endl '\n'
#define pi acos(-1)
#define pque priority_queue
#define N 1000000
#define lmax LONG_LONG_MAX
#define cin fi
#define cout fo
ifstream fi("arrange.inp");
ofstream fo("arrange.out");
typedef pair < int, int > ii;
typedef vector < int > vi;
typedef vector < vi > vii;
int mod = 1000000007;
int n, sum, num, a[100009], ans, pos[100009];
stack < int > st;
signed main()
{
	ios_base::sync_with_stdio(0);
	cin >> n;
	for(int i = 1; i <= n; i ++)
		cin >> a[i], sum += a[i];
	num = sum / n;
	for(int i = 1; i <= n; i ++)
	{
		while(a[i] > num)
		{
			if(st.empty() || a[st.top()] > num)
			{
				st.push(i);
				break;
			}
			int k = st.top();
			if(num - a[k] <= a[i] - num)
			{
				ans += (i - k) * (num - a[k]);
				a[i] -= (num - a[k]);
				a[k] = num;
				st.pop();
			}
			else
			{
				ans += (i - k) * (a[i] - num);
				a[k] += (a[i] - num);
				a[i] = num;
			}
		}
		while(a[i] < num)
		{
			if(st.empty() || a[st.top()] < num)
			{
				st.push(i);
				break;
			}
			int k = st.top();
			if(a[k] - num <= num - a[i])
			{
				ans += (i - k) * (a[k] - num);
				a[i] += (a[k] - num);
				a[k] = num;
				st.pop();
			}
			else
			{
				ans += (i - k) * (num - a[i]);
				a[k] -= (num - a[i]);
				a[i] = num;
			}
		}
	}
	for(int i = 1; i <= n; i ++)
		a[i] -= num;
	int cur = 0;
	for(int i = 1; i <= n; i ++)
		for(int j = 1; j <= a[i]; j ++)
			cur ++, pos[cur] = i;
	int f[n + 1][cur + 1];
	for(int i = 0; i <= n; i ++)
		for(int j = 0; j <= cur; j ++)
			f[i][j] = 1e18;
	f[0][0] = 0;
	for(int i = 1; i <= n; i ++)
		for(int j = 0; j <= min(cur, i); j ++)
			f[i][j] = min(f[i - 1][j], f[i - 1][j - 1] + abs(i - pos[j]));
	cout << ans + f[n][cur];
}

