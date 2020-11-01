#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<cstdio>
using namespace std;
#define int long long
#define inf 9223372036854775799
#define mn 100005

int IP[mn*10];
vector <int> pri;
int A, B;
map <int, int> uA, uB;
bool pA=0, pB=0;

main()
{
	freopen("MINSUM.inp", "r", stdin);
	freopen("MINSUM.out", "w", stdout);
	
	for (int i=0; i<mn*10; i++) IP[i]=i;
	
	for (int i=2; i<mn*10; i++) if (IP[i]==i)
	{
		for (int j=i; j*i<10*mn; j++) IP[i*j]=i;
		pri.push_back(i);
	}
	
	int t;
	cin>>t;
	while (t>0)
	{
		t--;
		cin>>A>>B;
		uA.clear();
		uB.clear();
		
		if (pA) 
		{
			pri.pop_back();
			pA=0;
		}
		if (pB)
		{
			pri.pop_back();
			pB=0;
		}
		
		int ptr=0;
		while (ptr<pri.size())
		{
			if (A<mn*10)
			{
				while (A>1)
				{
					if (uA.count(IP[A])==0) uA[IP[A]]=1;
					else uA[IP[A]]++;
					A/=IP[A];
				}
				break;
			}
			else
			{
				while (A%pri[ptr]==0)
				{
					if (uA.count(pri[ptr])==0) uA[pri[ptr]]=1;
					else uA[pri[ptr]]++;
					A/=pri[ptr];
				}
				ptr++;
			}
			
			if (ptr==pri.size()) if (A>1) 
			{
				uA[A]=1;
				pri.push_back(A);
				pA=1;
			}
		}
		
		ptr=0;
		while (ptr<pri.size())
		{
			if (B<mn*10)
			{
				while (B>1)
				{
					if (uB.count(IP[B])==0) uB[IP[B]]=1;
					else uB[IP[B]]++;
					B/=IP[B];
				}
				break;
			}
			else
			{
				while (B%pri[ptr]==0)
				{
					if (uB.count(pri[ptr])==0) uB[pri[ptr]]=1;
					else uB[pri[ptr]]++;
					B/=pri[ptr];
				}
				ptr++;
			}
			
			if (ptr==pri.size()) if (B>1) 
			{
				pri.push_back(B);
				uB[B]=1;
				pA=1;
			}
		}
		
		int a=1, b=1;
		vector <int> q;
		q.clear();
		for (int temp:pri)
		{
			int tmp=0;
			if (uA.count(temp)==1) tmp+=uA[temp];
			if (uB.count(temp)==1) tmp+=uB[temp];
			
			if (tmp%2==1) q.push_back(temp);
		}
		
		a=q.back();
		for (int i=q.size()-2; i>=0; i--) 
		{
			if (a<b) a*=q[i];
			else b*=q[i];
		}
		
		cout<<a<<' '<<b<<"\n";
	}
}
