#include<bits/stdc++.h>
#define mod 1000000009
using namespace std;
int n,mmax,M50,M1,M2,ans=0,x[305];
void xuli()
{
    int m50=M50, m1=M1, m2=M2;
    int c=m50+m1+m2;
    for(int i=1;i<=n;i++) {
        if(x[i]==0&&c==mmax) return ;
        if(x[i]==1&&m50==0) return ;
        if(x[i]==2&&(m50==0&&m1==0)) return ;
        if(x[i]==0) m50++;
        if(x[i]==1) m1++, m50--;
        if(x[i]==2) {
            m2++;
            if(m1>0) m1--, m50--;
            else {
                if(m50<3) return ;
                m50-=3;
            }
        }
        c=m50+m1+m2;
    }
    ans++;
}
void thu(int k)
{
    if(k>n) {xuli(); return ;}
    for(int i=0;i<=2;i++) {
        x[k]=i;
        thu(k+1);
    }
}
#define LO "ICECREAM"
int main ()
{
    freopen(LO".inp","r",stdin);
    freopen(LO".out","w",stdout);
    scanf("%d%d",&n,&mmax);
    scanf("%d%d%d",&M50,&M1,&M2);
    thu(1);
    printf("%d",ans);
}
