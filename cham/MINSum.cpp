#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<ctime>
using namespace std; 
int n , m ;
int  a[(int) 1e5+7] , b[(int) 1e5+7] , mi1 , mi2 , mi11 = (int) 1e8+2 , mi12 = (int) 1e8+2  ;


int timkiem (int d , int c , int x)
{
    if (d == c) return b[d]; 
    //if (x == -1) cerr << d << " " << c << endl;
			int l=d ,r=c;
			while ( l < r)
            {
                if (r - l == 1){
                    return ((abs(b[l] - x) < abs(b[r] - x)) ? b[l] : b[r]);
                }
				int k = (l+r)/2;
				if (b[k] == x) return b[k];
				else if ( b[k] > x  ) r = k-1;
					else l = k+1 ;
			}
            return -1;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    //freopen("minsum.inp","r",stdin);
    //freopen("minsum.out","w",stdout);
    cin >> m >> n ;
    for (int i = 1 ; i <= m ; i ++) cin >> a[i];
    sort(a+1,a+1+m);
    for (int i = 1 ; i <= n ; i++) cin >> b[i];
    sort(b+1,b+1+n);
    int f = 0;
    for(int i = 1 ; i <= n ; i++) 
    {
        if (b[i] >= 0) break;
        f = i;
    }
    //cerr << f;
    int ans = INT_MAX, t = 0;
    for (int i = 1; i <= m; i++)
    {
        //cerr << f << endl;
        if (a[i] >= 0)
        { 
            if (f != n) ans = min(ans , abs(a[i] + b[f + 1]));
            if (f != 0) ans = min(ans, abs(a[i] + timkiem(1, f, a[i] * (-1))));
            //cerr << timkiem(1, f, a[i] * (-1)) << " ";
            //cerr << ans << endl;
        }
        else 
        { 
            if (f != 0) ans = min(ans , abs(a[i] + b[f]));
            if (f != n) ans = min(ans, abs(a[i] + timkiem(f + 1, n, a[i] * (-1))));
        }
        //cerr << ans << endl;
    }
    cout << ans;
    //cerr << clock() << " ms";
    return 0;
}
