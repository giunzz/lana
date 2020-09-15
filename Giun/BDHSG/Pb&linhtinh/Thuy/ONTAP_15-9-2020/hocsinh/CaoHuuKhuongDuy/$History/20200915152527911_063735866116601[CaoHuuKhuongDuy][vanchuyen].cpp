#include <iostream>
#include <stdio.h>
#include <map>
#include <algorithm>
using namespace std;
struct cap
{
	int w,v;
};
cap a[300009];
bool kt(const cap k,const cap h)
{
	return k.v>h.v;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("vanchuyen.inp","r",stdin);
	freopen("vanchuyen.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for (int i=1;i<=n;i++)
       cin>>a[i].w>>a[i].v;
    sort(a+1,a+1+n,kt);
    map <int,int> m;
    int x;
    for (int i=1;i<=k;i++)
      {
      	cin>>x;
      	m[x]++;
      }
    map <int,int>::iterator it;
    long long s=0;
    for (int i=1;i<=n;i++)
      {
        it=m.lower_bound(a[i].w);
        if (m[(*it).first]!=0) {
        	                     m[(*it).first]--;
        	                     if (m[(*it).first]==0) m.erase((*it).first);
                                 s+=(long long)a[i].v;
                                // cout<<a[i].v<<endl;
                               }
      }
    cout<<s;
	return 0; 
}