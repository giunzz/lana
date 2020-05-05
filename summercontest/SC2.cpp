// n <= 30
#include<bits/stdc++.h>
using namespace std;
const string tenfile = "SC2";
#define balabalo freopen((tenfile + ".inp").c_str(), "r", stdin); freopen((tenfile + ".out").c_str(), "w", stdout)

long long n , k , ans ,t ;

long long giaithua(int a)
{
  long long tam = 1;
  for (int i = 1 ; i <= a ; i++) tam *= i;
  return tam;
}

long long demmm(long long b)
{
  long long d = 0;
  while( b % 10 == 0 )
  {
    d++;
    b = b / 10;
  }
  return d;
}

int main()
{
  balabalo;
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> t ;
  for (int i = 1 ; i <= t ; i++)
  {
    cin >> n >> k;
    int g = min( k , n - k );
    int r = max( k , n - k );
    long long giun = 1;
    for (int j = n ; j > r ; j--) 
      giun*= j;
    ans = giun / giaithua(g);
    // cerr << giun << " " << g <<" "<< giaithua(g) << " " << ans << endl;
    ans = demmm(ans);
    cout << ans << endl;
  }
  return 0;
}
