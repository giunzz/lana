/*#include<bits/stdc++.h>
using namespace std;
const string tenfile = "SC4";
#define balabalo freopen((tenfile + ".inp").c_str(), "r", stdin); freopen((tenfile + ".out").c_str(), "w", stdout)

long long  t , n ,m , x , s ;
double k;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    balabalo;
    cin >> t;
    for (int i = 1 ; i <= t ; i++)
    {
        cin >> x >> n >> m ;
        k =  pow( x , n+1 ) -1  ;
        s = k / ( x-1 );
        cout << s % m << endl; 
    }
    return 0;
}*/

#include <iostream>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("SC4.inp","r",stdin);
	freopen("SC4.out","w",stdout);
	unsigned long long x,m,s2,s;
	int test,n;
	cin>>test;
	for (int k=1;k<=test;k++)
	  {
	    cin>>x>>n>>m;
	    s=1%m;
	    s2=s;
	    for (int i=2;i<=n+1;i++)
	      {
            s=(s*(x%m))%m;
            s2+=s;
	      }
	    cout<<s2%m<<endl;
	  }  
	return 0;
}