#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector <int> a[100009];
long long trace[100009],q[100009],tinh[100009];
long long c[100009];
bool check[100009],check2[100009];
int n;
bool kt(int x,int y)
{
	return a[x].size()>a[y].size();
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("transport.inp","r",stdin);
	freopen("transport.out","w",stdout);
	int x,y,s;
	cin>>n>>s;
	for (int i=1;i<=n-1;i++)
	  {
	  	//cout<<i<<" ";
        cin>>x>>y;
        a[x].push_back(y);
        a[y].push_back(x);
	  }
	int l=0,r=1,d;
	q[r]=s;
	trace[s]=0;
	long long maxx=-1;
	check[s]=true;
	while (l<r) {
                   l++;
                   x=q[l];
                   for (int i=0;i<a[x].size();i++)
                      {
                        tinh[i+1]=a[x][i];
                      }
                   sort(tinh+1,tinh+1+a[x].size(),kt);
                  // if (x==1) for (int i=1;i<=a[x].size();i++)
                  // cout<<tinh[i]<<" "<<check[tinh[i]]<<endl;
                   d=0;
                   for (int i=1;i<=a[x].size();i++)
                   	  if (!check[tinh[i]]) { 
               //    	  	if (x==1) cout<<tinh[i]<<endl;
                                              d++;
                                              trace[tinh[i]]=trace[x]+d;
                                              r++;
                                              c[x]++;
                                              check[tinh[i]]=true;
                                              q[r]=tinh[i];
                   	                       }
	            }
	int z;
	check2[s]=true;
	//sum(s,0);
	for (int i=1;i<=n;i++)
	{
		if (c[i]==0) maxx=max(maxx,trace[i]*(c[i]+1));
		//trace[i]++;
		//cout<<trace[i]<<" "<<c[i]<<endl;
	}
	cout<<maxx;
	return 0;
}