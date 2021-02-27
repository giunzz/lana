/*#include <cstdio>
#include<algorithm>
#include <climits>
#include <ctime>
#define giuncute freopen("input.inp", "r", stdin) , freopen("output.txt", "w", stdout)
#define giun ios_base::sync_with_stdio(0) , cin.tie(0);
using namespace std;
int n , k , a[(int) 1e7+7], ans = 0 ;
int main()
{
    //giun;
    giuncute;
    scanf("%d %d",&n,&k);
    //cin >> n >> k;
    a[0] = 0;
    for (int i = 1; i <= n ; i++)
    {
        //cin >> a[i];
        scanf("%d",&a[i]);
        a[i] = a[i] +a[i-1];
    }
    ans = INT_MIN;
    for (int i = k ; i <= n ; i++) ans = max (ans , a[i] - a[i-k]);
    //cout << ans;
    printf("%d",ans);
    fprintf(stderr, "%dms", clock());
    return 0;
}*/
 

#include <cstdio>
using namespace std;
const int maxn = 1e7 + 7;
int n, k, ans, t = 0;
int a[maxn] = {0};

void fastscan(int &num) 
{  
    bool neg = false; 
    register int c;
    num = 0;  
    c = getchar(); 
    if (c == ' ' || c == '\n') fastscan(num);
    if (c=='-') 
    {  
        neg = true;  
        c = getchar(); 
    }  
    for (; (c>47 && c<58); c=getchar()) 
        num = num *10 + c - 48; 
    if (neg) 
        num *= -1; 
} 

int main(){
    freopen("tongk.inp", "r", stdin);
    freopen("tongk.out", "w", stdout);
    fastscan(n); fastscan(k);
    for (int i = 1; i <= k; i++){
        fastscan(a[i]);
        t += a[i];
    }
    // tính tổng k phần tử đầu tiên
    ans = t;
    //fprintf(stderr,"%d \n",t);
    for (int i = k + 1; i <= n; i++){
        fastscan(a[i]);
        t = t - a[i - k] + a[i];
        //fprintf(stderr,"%d ",t);
        if (t > ans) ans = t;
    }
    printf("%d", ans);
}