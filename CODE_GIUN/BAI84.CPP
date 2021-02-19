#include<cstdio>
#include<algorithm>
#include<climits>
#include<string>
using namespace std;
const string file = "bai84";
#define balabolo(a) freopen((a + ".inp").c_str(), "r", stdin) ,freopen((a + ".out").c_str(), "w", stdout)

int n ;
long a[ (int) 1e5+7], ans = LONG_MIN;
    
/*long BCNN1 (long a , long b )
{
    long x = max(a,b);
    long y = min (a,b);
    long bc=x;
    while ( bc % y !=0 ) bc+=x;
    return bc;
}*/

long UCLN(long x , long y)
{
        long t ;
        while ( y  != 0 ){
            t = x % y ;
            x = y;
            y = t;
        }
        return x;
}

long BCNN (long x , long y ){
        long bc = x*y;
        return bc / UCLN(x,y);
}

int main()
{
    balabolo(file);
    scanf("%d",&n);
    for (int i =1 ; i<= n ; i++) scanf("%ld",&a[i]);

    for (int i=1 ; i<= n-1 ; i++)
    {
        for (int j=i+1 ; j<= n ; j++)
            ans = max(ans , BCNN(a[i],a[j]));
    }
    printf("%ld",ans);
    return 0;
}

/* long UCLN(long x , long y){
        long t ;
        while ( y  != 0 ){
            t = x % y ;
            x = y;
            y = t;
        }
        return x;
}

long BCNN (long x , long y ){
        long bc = x*y;
        return bc / UCLN(x,y);
}

int main(){
int n ;
long a[int (1e5+9)],ans;
long long s = 1;

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("Bai84.inp","r", stdin);
    freopen("Bai84.out","w",stdout);
    cin >> n;
    for (int i =1 ; i < n ; i++) {
            cin >> a[i];
    }
    for (int i=1 ; i<= n-1 ; i++){
        for (int j=i+1 ; j<= n ; j++)
            ans = max(ans , BCNN(a[i],a[j]));
    }
    cout << ans;
    return 0;
}*/





