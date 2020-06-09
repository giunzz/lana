#include<bits/stdc++.h>
using namespace std;
#define giuncute ios_base::sync_with_stdio(0) , cin.tie(0)
const string tenfile = "FCAN3";
#define balabalo freopen((tenfile + ".inp").c_str(), "r", stdin); freopen((tenfile + ".out").c_str(), "w", stdout)
#define linh long long 
linh m , dem = 0  , d[400] = {0};

long long linhcute(linh x)
{
    linh sum = 1;
    for (linh i = 1 ; i <= x ; i++) sum *= 3  ;
    return sum;
}

void print_ans()
{
    linh de = 0;
    for (linh i = 0 ; i <= dem ; i++)  de += d[i];
    cout << de << " ";
    for (linh i = 0 ; i <= dem ; i++)
    {
        if (d[i] != 0 ) 
        {
            linh tam = linhcute(i);
            for (linh j = 1 ; j <= d[i] ; j++) cout << tam << " ";
        }
    }
}
void chonn( int chon)
{
    long long t1 = linhcute(chon);
    if ( t1 > m ) {print_ans();}
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

