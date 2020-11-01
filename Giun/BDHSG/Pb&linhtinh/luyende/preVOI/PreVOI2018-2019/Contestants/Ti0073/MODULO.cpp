#include<iostream>
#include<fstream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>
#include<deque>
#include<set>
#include<map>
#include<bitset>
#include<ctime>
#include<queue>
using namespace std;
#define int long long
#define mn 100005
#define inf 4444444444444444444
#define FLN "MODULO"
#define pii pair <int, int>
#define XX first
#define YY second

int n, k, a, b, mod;
map <int, string> M;
string ans="";

void brute1(string S, int md)
{
	if (S.size()==n/2) 
	{
		M[md]=S;
		return;
	}
	
	brute1(S+(char)(a+48), (md*10+a)%mod);
	brute1(S+(char)(b+48), (md*10+b)%mod);
}

void brute2(int u, string S, int md)
{
	if (u==n)
	{
		for (int i=0; i<n/2; i++) md=(md*10)%mod;
		int t=(mod+k-md)%mod;
		if (M.count(t)==1) ans=S+M[t];
		return;
	}
	
	if (ans.size()>0) return;
	brute2(u+1, S+(char)(a+48), (md*10+a)%mod);
	brute2(u+1, S+(char)(b+48), (md*10+b)%mod);
	
}

signed main()
{
#ifdef FLN
	freopen(FLN".inp", "r", stdin);
	freopen(FLN".out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>a>>b>>n>>k;
	if ((a+b)%2==0)
	{
		if ((a+k)%2==1) 
		{
			cout<<-1;
			return 0;
		}
	}
	mod=(1<<n);
	brute1("", 0);
	brute2(n/2, "", 0);
	if (ans.size()==0) cout<<-1;
	else cout<<ans;
	
}

// PLEASE REMOVE "cout" AND "cerr" DEBUG LINES BEFORE SUBMITTING PROBLEMS
// Code by low_
// Contact me via mail: dung.totuan01@gmail.com
// ...or codeforces: www.codeforces.com/profiles/low_
// ...or if you're interested in food: www.instagram.com/lowie_review/

