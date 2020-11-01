#include<bits/stdc++.h>

using namespace std;

#define X   first
#define Y   second

const int   N   = 3002;

typedef pair<int,int>   ii;

int n, m, k;
int a[N];
int b[N];
ii  f1[N][N];
ii  f2[N][N];

int main()  {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	freopen("SEQUENCE.inp","r",stdin);
	freopen("SEQUENCE.out","w",stdout);
	
	cin >> n >> m >> k;
	
	for(int i = 1 ; i <= n ; ++i)   cin >> a[i];
	for(int i = 1 ; i <= m ; ++i)   cin >> b[i];
	
	for(int i = 1 ; i <= max(n,m) ; ++i)
	for(int j = i ; j <= max(n,m) ; ++j)    {
		if (j == i) {
			f1[i][i] = ii(a[i],i);
			f2[i][i] = ii(b[i],i);
		}
		else    {
			f1[i][j] = min(f1[i][j - 1],ii(a[j],j));
			f2[i][j] = min(f2[i][j - 1],ii(b[j],j));
		}
	}
	
	a[0] = b[0] = 1e9 + 7;
	
	int p1 = 0, p2 = 0;
	
	for(int L = 1 ; L <= k ; ++L)   {
		int x = f1[p1 + 1][min(n,n + m + L - k - p2)].Y;
		int y = f2[p2 + 1][min(m,n + m + L - k - p1)].Y;
		if (a[x] <= b[y])   cout << a[x] << " ", p1 = x;
		else                cout << b[y] << " ", p2 = y;
	}
}
