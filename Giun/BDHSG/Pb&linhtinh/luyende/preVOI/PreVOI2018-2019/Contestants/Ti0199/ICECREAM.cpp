#include <bits/stdc++.h>
#define int long long
using namespace std;
const int MAX = 1e6+7;
int ar[MAX];
int n,mmax,a,b,c;
int dem0;
int cnt = 0;
int sai;
/*
a - m50
b - m1
c - m2
*/
void show()
{
	for(int i=1;i<=n;i++)
	{
		cout<<ar[i]<<" ";
	}
	cout<<endl;
} 

bool check()
{
	int x = a,y = b,z = c;
	sai = 0;
	for(int i=1;i<=n;i++)
	{
		if(ar[i] == 50)
		{
			x++;
		}
		
		else if(ar[i] == 100) 
		{
			x--;
			y++;
		}
		else if(ar[i] == 200)
		{
			if(y >= 1)
			{
				x--;
				y--;
			}
			else
			{
				x = x-3;
			}
			
			z++;
		}
//			cout<<x<<" "<<y<<" "<<z<<endl;
			
			if(x < 0 || y < 0 || z < 0)
			{
				sai = 1;
				break;
			}
			
			else if(x > mmax || y > mmax || z > mmax)
			{
				sai = 1;
				break;
			}
		
	}
//	cout<<x<<" "<<y<<" "<<z<<endl;
//	cout<<sai<<endl;
//	cout<<mmax<<endl;
	
	if(sai == 1) return false;
	
	else return true;
}
void back(int i)
{
	if(i == n+1)
	{
		
		if(check() == true)
		{
//			show();
			cnt++;
		}
	}
	
	else
	{
		ar[i] = 50;
		back(i+1);
		
		ar[i] = 100;
		back(i+1);
		
		ar[i] = 200;
		back(i+1);
	}
}
signed main()
{
	freopen("ICECREAM.INP","r",stdin);
	freopen("ICECREAM.OUT","w",stdout);
	cin>>n>>mmax>>a>>b>>c;
	back(1);
	cout<<cnt;
}
