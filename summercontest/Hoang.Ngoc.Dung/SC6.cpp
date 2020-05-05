#include<bits/stdc++.h>
using namespace std;
const string tenfile = "SC6";
#define balabalo freopen((tenfile + ".inp").c_str(), "r", stdin); freopen((tenfile + ".out").c_str(), "w", stdout)

int p , n , t , c[31] , s, dd[100]={0};
void print_answer()
{
   cout << s;
   cout << endl;
}

void quaylui(int vt)
{
 if (s % 2 == p || vt == n ) print_answer();
 else 
 {
    for (int i = 1; i <= n; i++)
    {
       if ( c[i] != c[i+1] ) dd[i] = 1   ;
       s++;
       quaylui(vt + 1);
    }
 }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    balabalo;
    cin >> t;
    for (int i = 1 ; i <= t ; i++)
    {
        cin >> n >> p;
        for (int j = 1 ; j <= n ; j++)  cin >> c[i];
        cout << " giun siêu cute , giun bất cần đời" << endl;    
    }
    return 0;
}