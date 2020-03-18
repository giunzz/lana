/*#include<iostream>
#include<cstdio>
#include<ctime>
#include<algorithm>*/
#include<bits/stdc++.h>
using namespace std;
const long maxn = 1e8+9;
long n,x,a[maxn]={0};

long timkiem (long d , long c , long x){
			long l=d ,r=c;
			while ( l <= r){
				long m = (l+r)/2;
				if (a[m] == x) {
                        return m ;
				}
				else if ( a[m] > x  ) r = m-1;
					else l = m+1 ;
			}
			return 0;
		}

int main(){
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   //freopen("BSEARCH.INP","r",stdin);
   //freopen("BSEARCH.OUT","w",stdout);
   freopen("input.txt","r",stdin);
   freopen("output.txt","w",stdout);
   
   scanf("%ld%ld",&n,&x);
   for (long i=1 ; i<= n ; i++){
            scanf("%ld",&a[i]);
   }
   sort(a+1,a+n+1);
   printf("%ld", timkiem( 1, n,x));
   cerr << clock() << " ms";
   return 0;
}

