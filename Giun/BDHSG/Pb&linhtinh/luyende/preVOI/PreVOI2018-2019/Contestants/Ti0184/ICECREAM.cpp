#include<bits/stdc++.h>
#define ll long long 
#define pb push_back
#define II pair<int, int>
#define x first
#define y second
#define mp make_pair
using namespace std;
ll mod = 1e9 + 9, n, Max, m_50, m_1, m_2;
void add(ll &a, ll b)
{
	a += b;
	a %= mod;
}
ll dp_sub1[20][15][15][15], res_sub1;
void sub1()
{
	dp_sub1[0][m_50][m_1][m_2] = 1;
	for(int i = 0; i < n; i ++)
		for(int cnt_50 = 0; cnt_50 <= Max; cnt_50 ++)
			for(int cnt_1 = 0; cnt_1 <= Max; cnt_1 ++)
				for(int cnt_2 = 0; cnt_2 <= Max; cnt_2 ++){
					ll tmp = dp_sub1[i][cnt_50][cnt_1][cnt_2];

					add(dp_sub1[i + 1][cnt_50 + 1][cnt_1][cnt_2], tmp);

					if(cnt_50 >= 1) add(dp_sub1[i + 1][cnt_50 - 1][cnt_1 + 1][cnt_2], tmp);
					
					if(cnt_50 >= 1 && cnt_1 >= 1) add(dp_sub1[i + 1][cnt_50 - 1][cnt_1 - 1][cnt_2 + 1], tmp);
						else if(cnt_50 >= 3) add(dp_sub1[i + 1][cnt_50 - 3][cnt_1][cnt_2 + 1], tmp);
				}
	for(int cnt_50 = 0; cnt_50 <= Max; cnt_50 ++)
		for(int cnt_1 = 0; cnt_1 <= Max; cnt_1 ++)
			for(int cnt_2 = 0; cnt_2 <= Max; cnt_2 ++) add(res_sub1, dp_sub1[n][cnt_50][cnt_1][cnt_2]);
	cout << res_sub1;
}
ll dp_sub2[2][205][105][55], res_sub2;
void sub2()
{
	int id = 0;
	dp_sub2[0][150][50][0] = 1;
	for(int i = 0; i < n; i ++){
		memset(dp_sub2[id ^ 1], 0, sizeof dp_sub2[id ^ 1]);
		for(int cnt_50 = 150 - 3 * i; cnt_50 <= 200; cnt_50 ++)
			for(int cnt_1 = 50 - i; cnt_1 <= 100; cnt_1 ++)
				for(int cnt_2 = 0; cnt_2 <= 50; cnt_2 ++){
					ll tmp = dp_sub2[id][cnt_50][cnt_1][cnt_2];
					int real_50 = cnt_50 - 150 + m_50, real_1 = cnt_1 - 50 + m_1, real_2 = cnt_2 - 0 + m_2;
					if(real_50 < 0 || real_50 > Max || real_1 < 0 || real_1 > Max || real_2 < 0 || real_2 > Max) continue;
					if(real_50 + 1 <= Max) 
						add(dp_sub2[id ^ 1][cnt_50 + 1][cnt_1][cnt_2], tmp);
					if(real_1 + 1 <= Max && real_50 >= 1 && cnt_50 >= 1)
						add(dp_sub2[id ^ 1][cnt_50 - 1][cnt_1 + 1][cnt_2], tmp);
					if(real_2 + 1 <= Max){
						if(real_50 >= 1 && real_1 >= 1 && cnt_50 >= 1 && cnt_1 >= 1)
							add(dp_sub2[id ^ 1][cnt_50 - 1][cnt_1 - 1][cnt_2 + 1], tmp);
						else if(real_50 >= 3 && cnt_50 >= 3)
							add(dp_sub2[id ^ 1][cnt_50 - 3][cnt_1][cnt_2 + 1], tmp);
					}
				}
		id ^= 1;
	} 
	for(int cnt_50 = 0; cnt_50 <= 200; cnt_50 ++)
		for(int cnt_1 = 0; cnt_1 <= 100; cnt_1 ++)
			for(int cnt_2 = 0; cnt_2 <= 50; cnt_2 ++){
				int real_50 = cnt_50 - 150 + m_50, real_1 = cnt_1 - 50 + m_1, real_2 = cnt_2 - 0 + m_2;
				if(real_50 < 0 || real_50 > Max || real_1 < 0 || real_1 > Max || real_2 < 0 || real_2 > Max) continue;
				add(res_sub2, dp_sub2[id][cnt_50][cnt_1][cnt_2]);
			}
	cout << res_sub2;
}
int main()
{
	freopen("ICECREAM.inp", "r", stdin);
	freopen("ICECREAM.out", "w", stdout);
	cin >> n >> Max >> m_50 >> m_1 >> m_2;
	if(n <= 15 && Max <= 10) sub1();	
	else sub2();
}