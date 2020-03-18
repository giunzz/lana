#include<bits/stdc++.h>

using namespace std;

long n , ans ,sang[(long)1e7+7] , d = 2 ;

void ss()
{
    long i = 2 , f1 = 1 , f0 = 0 , fi ;
    sang[1]= 1 , sang[0] = 0;
    while (fi <= (long) 1e9)
    {   
        fi = f1 + f0 ;
        sang[i]= fi;
        f0 = f1;
        f1 = fi;
        i++, d++;
    }    
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.inp","r",stdin);
    //freopen("output.txt","w",stdout);
    freopen("vfibo.inp","r",stdin);
    freopen("vfibo.out","w",stdout);
    cin >> n ;
    ss();
    for (long i = 1 ; i <= d ; i++)
    if(sang[i] == n) cout << i << endl;
    //cerr << clock() << " ms";
    return 0;
}