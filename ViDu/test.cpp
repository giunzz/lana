#include <cstdio>
using namespace std;
const int maxn = 1e7+7;
long n , t , dd[maxn]={0};
long long bayhoi = 0, ans = 0;
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
  fastscan(n) ; fastscan(t);  
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
