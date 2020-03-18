#include<stdio.h>
#include<iostream>
#include<algorithm>

using namespace std;

int  n , d = 0 , a[(int) 1e3 + 6];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
   // freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
   freopen("dembs.inp","r",stdin);
   freopen("dembs.out","w",stdout);

   cin >> n ; 
   for (int i = 1 ; i <= n ; i++) cin >> a[i];
   sort ( a + 1 , a + 1 + n);
   //for (int i = 1 ; i <= n ; i++) cerr << a[i] << " ";

   for (int i = 1 ; i <= n - 1 ; i++){
       for (int j = i + 1 ; j <= n ; j++)
            if (a [j] % a[i] == 0 ) d ++;
   }
   cout << d;
   //cerr << clock() << " ms";
   return 0;
}