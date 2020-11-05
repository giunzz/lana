#include<bits/stdc++.h>
using namespace std;
#define giuncute ios_base::sync_with_stdio(0);cin.tie(0);
#define balalololo freopen("f.inp","r",stdin),freopen("f.out","w",stdout);

int d[3007][3007]={{0}};
string s1,s2;

int main()
{
	giuncute;
	balalololo;
	cin >> s1 >> s2;
	for (int i = 0 ; i <= s1.length() , i++)
	{
		for (int j = 0 ; i <= s2.length() , j++)
		{
			if (s1[i] == s2[j]) d[i][j] = d[i-1][j+1]
		}
		
	}
}
