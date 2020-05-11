#include<bits/stdc++.h>
using namespace std;
const string tenfile = "BAI42QL";
#define balabalo freopen((tenfile + ".inp").c_str(), "r", stdin); freopen((tenfile + ".out").c_str(), "w", stdout)
#define giuncute ios_base::sync_with_stdio(0) , cin.tie(0);

int a[11] ={0}, n ;

void print_ans()
{
    for (int i = 1 ; i <= n ; i++)
    {
        cout << a[i] ;
    }
    cout << endl;
}

void lalalolo(int vt)
{
    if ( vt  == n + 1) print_ans();
    else 
    {
        for (int i = 0 ; i <= 1 ; i++)
        {
            a[vt] = i;
            lalalolo(vt + 1 );
        }
    }
}
int main()
{
    balabalo;
    giuncute;
    cin >> n ;
    lalalolo(1);
    return 0;
}