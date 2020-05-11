#include<bits/stdc++.h>
using namespace std;
const string tenfile = "giun";
#define balabalo freopen((tenfile + ".inp").c_str(), "r", stdin); freopen((tenfile + ".out").c_str(), "w", stdout)
#define giuncute ios_base::sync_with_stdio(0) , cin.tie(0);
// bài 1
/*double d;

int main()
{
    balabalo;
    giuncute;
    cin >> d;
    if ( d < 5) cout << " xep loai yeu";
    if ( d >= 5 && d < 7) cout << " xep loai trung binh";
    if ( d >= 7 && d < 9) cout << " xep loai kha";
    if ( d >= 9 ) cout << " xep loai gioi";
    return 0;
}*/

// bài 4

/*int u , v , x, y;

double dodai(int o1,int p1 )
{
    return (sqrt( pow(o1-0,2) + pow (p1-0,2)));
}

int main()
{
    balabalo;
    giuncute;
    cin >> x >> y >> u >> v;
    double m1 = dodai(x,y) ;
    int ans1 = x , ans2 = y;
    if ( m1 < dodai(u , v)) ans1 = u , ans2 = v;
    cout << ans1 << " " << ans2;
    return 0;
}*/

// bài 2

/*int a ;
double b1 = 1.484 , b2 = 1.533 , b3 = 1.786 , b4 = 2.242 , b5 = 2.503 , b6 = 2.399;
double ans = 0;
int main()
{
    balabalo;
    giuncute;
    cin >> a;
    if ( a < 50 )  ans = (50 - a ) * b1;
    else ans += 50 * b1;
    if ( a < 100 )  ans = (100 - a) * b2;
         else ans += 50 * b2;
    if ( a < 200 )  ans = ( 200 - a ) *b3;
        else ans += 50 * b3;

    if ( a < 300 )  ans = ( 300 - a ) *b4;
        else ans += 50 * b4;
    
    if ( a < 400 )  ans = ( 400 - a) * b5;
    else ans += 50 * b5;

    if ( a >= 400 ) ans = (a - 400) *b6;
    cout << ans;
    return 0;
}*/

// bài 6

/*int n ,   giun = 0; ;
void kt (int n )
{
   
    for (int i = 1 ; i * i <= n ; i++ )
    {
        if ( i * i == n ) 
        {
            giun = 1;
            break;
        }
    }  
}

int main()
{
    balabalo;
    giuncute;
    cin >>  n ;
    kt (n);
    if ( giun == 1 ) cout << " YES";
    else cout << "NO"; 
}*/

// bài 9

/*int n , a = 0 , b = 0 , mi = INT_MAX, j , i = 1;

int main()
{
    balabalo;
    scanf("%d", & n);
    if (n % 2 == 0 ) j = n - 1;
    else j = n ;
    while ( j >= i  )
    {
        if (i + j == n && j - i < mi) 
        {
            mi = j - i;
            a = j ;
            b = i;
        }
        i += 2 , j -= 2;
    }
    if ( a == 0 && b == 0 ) printf("%d",-1) ;
    else printf("%d %d", a, b);
    cerr << clock() << " ms";
    return 0;
}*/

// bài 10

/*int m , n , ans;

int main()
{
    balabalo;
    cin.tie(0);
    cin >> m >> n;
    if (n % 2 == 0 ) ans = n*2;
    else ans = (n - 1) * 3;
    cout << ans;
    return 0;  

}*/

// bai 13
/*long a1,a2,b1,b2,c1,c2;
int main()
{
    cin >> a1 >> b1 >> c1;
    cin >> a2 >> b2 >> c2;
    if(a1 > b1) swap(a1 , b1); if ( a2 > b2 ) swap(a2,b2);
    if(b1 > c1) swap(b1 , c1); if ( b2 > c2 ) swap(b2,c2);
    if (c2 > c1) cout<< a1 + a2 + b1 + b2 + (c2-c1);
    else cout<< a2 + a1 + b1 + b2 + (c1-c2)<<endl;
    return 0;
}*/

// bai 12

int n , ans ;

int main()
{
    balabalo;
    giuncute;
    cin >> n ;
    cerr << n % 2 << " " << n / 2 ;
    if ( n % 2 == 0 )
    {
        if ( n % 3 == 0 ) ans = min ( n / 2 + n - ( n / 6 );
        else ans = min ((n - 1)  / 2, n / 2 + 3 ); 
    }
    else ans = min( n % 2 + (n - ( n % 2) ) / 2 ) 
}


