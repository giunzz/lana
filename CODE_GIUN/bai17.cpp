#include<stdio.h>
#include<math.h>
#include<algorithm>
using namespace std;

int   n , x , y;
int d[(int)105];
int dodai(int o1,int p1 )
{
    return (sqrt( pow(o1-0,2) + pow (p1-0,2)));
}

int main()
{ 
    //freopen("input.inp","r",stdin);
    //freopen("output.txt","w",stdout);
    freopen("bai17.inp","r",stdin);
    freopen("bai17.out","w",stdout);
    scanf("%d",&n);
    for(int i = 1 ; i <= n ; i++) {
        scanf("%d%d",&x,&y);
        d[i] = dodai(x,y);
    }
    sort(d+1 , d+n+1);
    //for (int i = 1 ; i <= n ; i++) cerr << d[i] << " ";
    int v = (n+1) / 2;
    long s = 0;
    for (int i = 1 ; i <= n ; i++) 
    {
        s += abs(d[i] - d[v]);
    }
    //cerr << clock() << " ms";
    printf("%ld",s);
    return 0 ;
}