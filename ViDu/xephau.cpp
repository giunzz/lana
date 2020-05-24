#include<bits/stdc++.h>
using namespace std;
const string tenfile = "XEPHAU";
#define balabalo freopen((tenfile + ".inp").c_str(), "r", stdin); freopen((tenfile + ".out").c_str(), "w", stdout)
#define giuncute ios_base::sync_with_stdio(0) , cin.tie(0);

const int maxn = 30;
int  C[maxn] =  {0} , CP[maxn] = {0} , CC[maxn] ={0} , ans[maxn] , n , ok = 1 ; 

int heloooo(int a) {return a+n;}

bool DieuKien(int i, int j)
{
    return (!C[j] && !CC[heloooo(i-j)] && !CP[i+j]);
}

void print_ans()
{
    for (int i = 1 ; i <= n ; i++ ) cout << ans[i] << " " ;
    cout << endl;
    ok = 0 ;
}

void Giun(int i)
{
    for (int j = 1 ; j <= n ; j++ )
    {
        if (DieuKien(i,j)) 
        {
			ans[i] = j;
			C[j] = 1;
			CC[heloooo(i-j)] = 1;
			CP[i+j] = 1;
			if (i == n ) print_ans();
			else Giun(i+1);
			C[j] = 0;
			CC[heloooo(i-j)] = 0;
			CP[i+j] = 0 ;
		}
	}  
}

int main()
{
    balabalo;
    giuncute;
    cin >> n;
	Giun(1);
	if (ok == 1) cout << -1;
	return 0;
}