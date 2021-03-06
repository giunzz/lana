#include<bits/stdc++.h>
using namespace std;
int  m , x , cnt = 0 ;
int main()
{
    freopen("giun.inp","r",stdin);
    freopen("giun.out","w",stdout);
    cin >>  m;
	if (m == 1) 
	{
		cin >> x;
		if (x == 1) cout << "YES";
		else cout << "NO";
	}
	else 
	{
		for (int i = 1 ; i <= m ; i++)
    	{
			cin >> x;
			if (x == 1 ) cnt ++;
    	}
	if (cnt == m-1 ) cout << "YES";
	else cout << "NO";
	}
}


