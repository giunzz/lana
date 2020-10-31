#include <bits/stdc++.h>

using namespace std;
#define ii pair<int,int>
#define f first
#define s second
#define ll long long
#define TASK "ICECREAM"
const int mod = 1e9+7 ;
int n,mmax,m5,m1,m2,t5,t1,t2 ;
ll cnt = 0 ;
void Input()
{
    cin >> n >> mmax  ;
    cin >> m5 >> m1 >> m2 ;
    t5=m5 ;
    t1=m1;
    t2=m2 ;
    return ;
}
void Try(int i)
{
    for(int j=0;j<=2;j++)
    {
        bool flag  = 0 ;
        bool flag1 = 0 ;
        if(j == 0 && t5 < mmax)
        {
            flag = 1 ;
            t5++ ;
        }
        if(j == 1 && t1 <mmax && t5 > 0)
        {
            flag = 1 ;
            t1++ ;
            t5-- ;
        }
        if(j == 2)
        {
            if(t2 < mmax && t1 > 0 && t5 >0 )
            {
                flag=1 ;
                flag1=1 ;
                t2++ ;
                t5--;
                t1-- ;
            }
            if(t2 < mmax && t5 >= 3 && flag1 == 0)
            {
                t2++ ;
                t5-=3 ;
                flag=1 ;
            }
        }
        if(flag == 0) continue ;
        if(i == n)
            ++cnt ;
        else
            Try(i+1) ;
        if(j == 0)
            t5-- ;
        if(j == 1)
        {
            t1-- ;
            t5++ ;
        }
        if(j == 2)
        {
            if(flag1 == 1)
            {
                t2-- ;
                t5++ ;
                t1++ ;
            }
            else
            {
                t2-- ;
                t5+=3 ;
            }
        }
    }
}
int main()
{
    freopen(TASK".INP","r",stdin) ;
    freopen(TASK".OUT","w",stdout) ;
    ios_base::sync_with_stdio(0) ;
    cin.tie(NULL) ;
    Input() ;
    Try(1) ;
    cout << cnt%mod  ;
    return 0;
}
