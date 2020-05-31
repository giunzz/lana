#include<bits/stdc++.h>
using namespace std;
const string tenfile = "giun";
#define balabalo freopen((tenfile + ".inp").c_str(), "r", stdin); freopen((tenfile + ".out").c_str(), "w", stdout)
#define giuncute ios_base::sync_with_stdio(0) , cin.tie(0);

int a , b  , sang[(int) 2e5 + 7 ] = {0};

void xaysang()
{
    sang[0] = 1 , sang[1] = 1;
    for (int i = 2 ; i * i <= (int) 2e5 ; i++)
        if ( sang[i] == 0  )
            for (int j = i * 2 ; j <= (int) 2e5 ; j += i ) sang[j] = 1;
}

int main()
{
    //balabalo;
    giuncute;
    cin >> a >> b ;
    xaysang();
    for (int i = a ; i <= b ; i++)
    {
        if (sang[i] == 0 ) 
		{
			//cerr << i << " ";
			cout << i << endl;
		} 
    }
    return 0;
}