#include<bits/stdc++.h>
#define fi "vongdua.inp"
#define fo "vongdua.out"
#define giuncute freopen(fi, "r", stdin) , freopen(fo, "w", stdout)
using namespace std;
int n , a, b,c , bc , uc , ans = -1;

int UCLN(int a , int b)
{    
    int tmp;
    while(b != 0) 
    {
        tmp = a % b;
        a = b;
        b = tmp;
    }
    return a;
}

int main()
{
    giuncute;
    scanf("%d%d%d%d",&n,&a,&b,&c);
    bc = a*b , uc = UCLN(a,b);
    bc = bc / uc; 
    uc = UCLN(bc,c);
    bc = bc*c / uc ;
    if ( bc % n) ans = bc % n;
    printf("%d",ans);
    return 0;
}