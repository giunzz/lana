#include<bits/stdc++.h>

using namespace std;
const int maxn = 1e6 + 7;
#define balabolo freopen("giun.inp","r",stdin) , freopen("giun.out","w",stdout);
#define giuncute ios_base::sync_with_stdio(0) , cin.tie(0);
int n , a[maxn] ,  fen[maxn];

void update(int p, int val)
{
    for(int i = p; i <= n; i += i & -i)
        fen[i] += val;
}

int sum(int p) 
{
    int ans = 0;
    for(int i = p; i; i -= i & -i)
        ans += fen[i];
    return ans;
}

int main()
{
    balabolo;
    giuncute;
    cin >> n ; 
    for (int i = 1 ; i <= n ; i++) 
    {   cin >> a[i] ;
        update(i , a[i]);
    }
    for (int i = 1 ; i <= n ; i++) cerr << fen[i] << " ";
    cerr << endl;
    cout << sum(6);

/*
/*long long  sa = 0 , sb = 0 ;


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

int main()
{
    balabolo(file);
    fastscan(n) ; fastscan(t);
    for (int i = 1 ; i <= n ; i++)
    {
        fastscan(a[i]) ; fastscan(b[i]) ;
        sa += a[i];
        sb += b[i];
    }
    for (int i = 0 ; i <= t ; i++) 
    {
        printf("%I64d\n", sa - i * sb);
    }
    return 0;
}*/

}
#include <bits/stdc++.h>
using namespace std;
const string file = "giun";
const int maxn = 1e7+7;
#define balabolo(a) freopen((a + ".inp").c_str(), "r", stdin) ,freopen((a + ".out").c_str(), "w", stdout)
long n , t , dd[maxn]={0}  ;
void fastscan(long &num) 
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

int main()
{
  //balabolo(file);
  fastscan(n) ; fastscan(t);
  long long bayhoi=0,ans=0;
  for (int i = 1 ; i <= n ; i++) 
  {
  	long a,b;
  	fastscan(a) ; 
    fastscan(b);
  	bayhoi+=b; 
    ans+=a;
  	dd[a/b+1]+=(b-(a%b)); 
    dd[a/b+2]+=(a%b);
  }
  printf("%I64d\n",ans);
  for (int i = 1 ; i <= t ; i++) 
  {
  	bayhoi-=dd[i];
  	ans-=bayhoi;
  	printf("%I64d\n",ans);
  }
  return 0;
}



