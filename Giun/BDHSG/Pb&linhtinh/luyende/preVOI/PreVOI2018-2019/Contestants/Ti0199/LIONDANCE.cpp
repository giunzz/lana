#include <bits/stdc++.h>
using namespace std;
const int MAX = 3001;
int a[MAX],b[MAX],ar[MAX],v[MAX];
int len,change;
int n,k,u,idx = 1;
int best = -1;
vector <int> ans[MAX];

void cre()
{
	u = 1;
	for(int i=1;i<=n;i++)
	{
		if(ar[i] == 1)
		{
			v[u] = a[i];
			u++;
		}
	}
	len = u-1;
}

bool appear()
{
	u = 1;
	for(int i=1;i<=n;i++)
	{
		if(b[i] == v[u])
		{
			u++;
		}
	}
	
	if(u == len+1)
	{
		return true;
	}
	
	else
	{
		return false;
	}
}

bool check()
{
	int sai = 0;
	for(int f=1;f<=len;f++)
	{
		if(abs(v[f] - v[f-1]) > change)
		{
			sai = 1;
			break;
		}
	}
	
	if(sai == 1) return false;
	else return true;
}

void show()
{
	for(int i=1;i<=len;i++)
	{
		cout<<v[i]<<" ";
	}
	cout<<endl;
}

void back(int i)
{
	if(i == n+1)
	{
		
		cre();
//		show();
		if(appear() == true && check() == true)
		{
//			show();
			if(best <= len)
			{
//				show();
				for(int i=1;i<=len;i++)
				{
					ans[idx].push_back(v[i]);
				}
				
				idx++;
				best = len;
			}
		}
	}
	
	else
	{
		ar[i] = 1;
		back(i+1);
		ar[i] = 0;
		back(i+1);
	}
}

int main()
{
	
	freopen("LIONDANCE.INP","r",stdin);
	freopen("LIONDANCE.OUT","w",stdout);
	
	int stt;
	cin>>n>>change;
	
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	
	for(int i=1;i<=n;i++)
	{
		cin>>b[i];
	}
	
	back(1);

	for(int i=1;i<=idx-1;++i)
	{
		for(int j=1;j<=idx-1;j++)
		{
			if(i != j)
			{
				for(int k=0;k<=best-1;k++)
				{
					if(ans[i].size() == best && ans[j].size() == best)
					{
						if(ans[i][k] < ans[j][k])
						{
							stt = j;
							break;
						}
						else if(ans[i][k] > ans[j][k])
						{
							stt = i;
							break;
						}
					}
				}
			}
		}
	}
	cout<<best<<endl;
//	cout<<ans[stt].size();

	for(int i=0;i<=best-1;i++)
	{
		cout<<ans[stt][i]<<" ";
	}
}
