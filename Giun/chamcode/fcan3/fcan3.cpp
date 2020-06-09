#include<bits/stdc++.h>
using namespace std;
#define giuncute ios_base::sync_with_stdio(0) , cin.tie(0)
const string tenfile = "fcan3";
#define balabalo freopen((tenfile + ".inp").c_str(), "r", stdin); freopen((tenfile + ".out").c_str(), "w", stdout)
#define linh long long 
long long m , dem = 0  , d[300] = {0};


void print_ans()
{
    int de = 0;
    for (int i = 0 ; i <= dem ; i++)  de += d[i];
    cout << de << " ";
    for (int i = 0 ; i <= dem ; i++)
    {
        if (d[i] != 0 ) 
            for (int j = 1 ; j <= d[i] ; j++) cout << (linh)pow(3,i) << " ";
    }
}

void chonn( int chon)
{
    if ( (linh ) pow(3, chon) > m ) {print_ans();}
    else 
    {
        if (chon == 0) d[0] = m;
        else 
        {
            d[chon] = d[chon - 1 ] / 3;
            d[chon - 1] = d[chon - 1] % 3; 
            dem ++;
        }
        chonn(chon+1);
    }
}

int main()
{
    balabalo;
    giuncute;
    cin >> m ;
    chonn(0);
}