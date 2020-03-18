/include<bits/stdc++.h>
using namespace std;
const int maxn = 60;
int n , d = 0;
bool sang[62];
long long  fibo ( int n ){
    return  ( pow( ( 1 + sqrt( 5 ) ) / 2 , n ) - pow( ( 1 - sqrt( 5 ) ) / 2 , n ) ) / sqrt(5);
}

bool find( long long k)
{
    for (long i = 2 ;  i <= sqrt(k) ; i++)
        if (k % i == 0 ) return false;
     return true;
}
void  ss(){
    
     for (long long  i=2 ; i<=maxn ; i++){
         sang[i] = true;
     }
    sang[0] = false;
    sang[1] = false;
     for (long long i = 2 ; i*i <= maxn; i++ ){
         if  ( sang[i] == true ) {
             for( long long  j = i*i ; j <= maxn ; j+=i ){
                 sang[j]=false;
             }
         }
     }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("input.inp","r",stdin);
    freopen("output.txt","w",stdout);
    //freopen("NFIBO.inp","r",stdin);
    //freopen("NFIBO.out","w",stdout);
    cin >> n;
    ss();
    for (int i = 3 ; i <= n ; i++)
    {
        if (sang[i] || i == 4)
        {
            if(find(fibo(i))) d++;
        }
    }
    cout << d;
    cerr << clock() << " ms";
    return 0;
}
#include <bits/stdc++.h>

using namespace std;

vector <int> a{3, 4, 5, 7, 11, 13, 17, 23, 29, 43, 47};
int d[100] = {0};

int main(){
    for (vector<int>::iterator it = a.begin() ; it != a.end(); ++it){
        d[*it] = 1;
    }
    freopen("NFIBO.inp","r",stdin);
    freopen("NFIBO.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++){
        d[i] += d[i - 1];
    }
    cout << d[n];
    //cerr << clock() << " ms";
    return 0;
}