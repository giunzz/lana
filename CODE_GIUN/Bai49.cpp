#include<bits/stdc++.h>
using namespace std;
const string tenfile = "giun";
#define balabalo freopen((tenfile + ".inp").c_str(), "r", stdin); freopen((tenfile + ".out").c_str(), "w", stdout)
#define giuncute ios_base::sync_with_stdio(0) , cin.tie(0);

string x[20] , s , ans , c[1000] ;
int n , m = 0 , dd[300] ={0};

bool kt( string ans)
{
    for (int i = 0; i < m ; i++) 
    {
        if (c[i]== ans) return false;
    }
    return true;
}

void print_ans()
{
    string ans ="";
    for (int i = 0 ; i < n ;i++) ans += x[i];
    if (  kt(ans) == true ) 
    {
        cout << ans << endl;
        m++;
        c[m] = ans;
    }

}

void chon(int vt)
{
    for (int i = 0 ; i < n; i++)
    {
        if ( dd[i] == 0 )
        {
            x[vt] = s[i];
            dd[i] = 1;
        }
        if ( vt == n - 1 ) print_ans();
        else chon(vt+1);
        dd[i] = 0;
    }    
}
int main()
{
    balabalo;
    giuncute;
    cin >> s;
    n = s.length();
    chon(0);
}