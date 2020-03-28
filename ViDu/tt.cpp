/*#include<iostream>
#include<string>
#define giuncute freopen("input.inp", "r", stdin) , freopen("output.txt", "w", stdout)
using namespace std;
int n , k ;
int xxx (int h , int c)
{
	int cheo = h+c-1;
	int s = 0;
	for (int i = 1 ; i < cheo ; i++) s += i;
	if (cheo % 2 == 0 ) s += h;
	else s += c;
	return s;
}

int meo (int h , int c)
{
	int cheo = h+c-1;
	int t = 0;
	if (cheo <= n ) t = xxx(h,c);
	else
	{
		int chenhlech = cheo - n ;
		cheo = n - chenhlech;
		if (h == c || c== n)
		{
			if( h == n ) h = 1 , c = n-chenhlech;
			if( c == n ) c = 1 , h = n-chenhlech;
		}
		else c = n-chenhlech , h = cheo - c +1 ;
		t = (n * n + 1) - xxx(h , c); 
	}
	return t;	
}

int main()
{
	giuncute;
	int h = 1 , c = 1;
	string ch;
	long long t = 0 , sum = 1;
	scanf("%d%d%s",&n , &k);
	

	for (int i = 0 ; i < k ; i++)
	{
		if(ch[i]=='D'||ch[i]=='d')	t=meo(++h,c);
		else if(ch[i]=='R'||ch[i]=='r')t=meo(h,++c);
		else if(ch[i]=='L'||ch[i]=='l')	t=meo(h,--c);
		else if(ch[i]=='U'||ch[i]=='u')	t=meo(--h,c);
		sum += t;
		t = 0;		
	}
	printf("%lli",sum);
	return 0;
}*/

#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 7;
int n, k, a[maxn];

void enter(){
	char c;
	cin.ignore();
	for (int i = 1; i <= k; i++){
		cin >> c;
	}
}

void init(){
	for (int i = 1; i <= n; i++){
		a[i] = 
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	freopen("input.inp", "r", stdin);
	freopen("output.txt", "w", stdout);
	cin >> n >> k;
	init();
	enter();
}