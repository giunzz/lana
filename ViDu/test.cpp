#include<iostream>
#include<string>
#define giuncute freopen("input.inp", "r", stdin) , freopen("output.txt", "w", stdout)
using namespace std;
int n,k;
int xx( int h, int c)
{
	int cheo = h+c-1;
	int s = 0;
	for(int i=1; i < cheo; i++) s+=i;
	if(cheo % 2 == 0) s+=h;
	else s+=c;
	return s;
}
int meo(int h, int c)
{
	int cheo=h+c-1;
	int t=0;
	if(cheo<=n)	{
		t=xx(h,c);
	}
	else
	{
		int chenhlech=cheo-n;
		cheo=n-chenhlech;
		
		if(h==n ||c==n)
		{
			if(h==n) h=1,c=n-chenhlech;	
			if (c==n) c=1,h=n-chenhlech;	
		}
		else c=h-chenhlech,h=cheo-c+1;
		t=(n*n+1)-xx(h,c);
	}
	return t;	
}
int main()
{
    giuncute;
    ios::sync_with_stdio(0);
	cin.tie(0);

	int h=1,c=1;
	string ch;
	cin >> n >> k >> ch;
	long long t=0,sum=1;
	for(int i = 0; i < k ; i++)
	{
		if(ch[i]=='D'||ch[i]=='d')	t=meo(++h,c);
		else if(ch[i]=='R'||ch[i]=='r')t=meo(h,++c);
		else if(ch[i]=='L'||ch[i]=='l')	t=meo(h,--c);
		else if(ch[i]=='U'||ch[i]=='u')	t=meo(--h,c);
		sum+=t;
		t=0;		
	}	
	cout<<sum;
}

