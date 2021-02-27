#include <bits/stdc++.h>
using namespace std;

int n;
string s;
map <string,int> a; 
vector <int> b(20,0);

void check()
{
	string s1="";
	for (int i=0;i<n;i++) if (b[i]) s1+=s[i];
	if (!a[s1]&&s1!="") cout << s1 << endl;
	a[s1]++;
}

void backtr(long long i)
{
	for (int j=0;j<=1;j++)
	{
		b[i]=j;
		if (i==n-1) check();
		else backtr(i+1);
	}
}

int main()
{
	ios::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
    freopen("bai46ql.inp","r",stdin);
    freopen("bai46ql.out","w",stdout);
	cin >> s;
	n=s.size();
	backtr(0);
	return 0;
}
