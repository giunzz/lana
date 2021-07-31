#include<stdio.h>
#define MAX   250
struct pos
    {
        long x;
        long y;
    };
int k,n,m,r,sum,b;
pos p[MAX];
pos h[MAX];
int s[MAX];
int sou[MAX];
bool c[MAX];
bool go[MAX][MAX];
void init(void)
{
    scanf("%d",&k);
    scanf("%d",&r);
    scanf("%d",&m);
    int i,j;
    for (i=1;i<=m;i=i+1)
        {
            scanf("%ld",&p[i].x);
            scanf("%ld",&p[i].y);
        }
    scanf("%d",&n);
    for (i=1;i<=n;i=i+1)
        {
            scanf("%ld",&h[i].x);
            scanf("%ld",&h[i].y);
            scanf("%d",&s[i]);
        }
    for (i=1;i<=m;i=i+1)
        for (j=1;j<=n;j=j+1)
            {
                if ((p[i].x-h[j].x)*(p[i].x-h[j].x)+(p[i].y-h[j].y)*(p[i].y-h[j].y)<=r*r) go[i][j]=true;
                else go[i][j]=false;
            }
    for (i=1;i<=n;i=i+1) c[i]=false;
    sou[0]=0;
    b=0;
}
void update(void)
{
    if (sum<=b) return;
    b=sum;
}
void btrk(int t)
{
    int i,j,l;
    int tmp[MAX];
    for (i=sou[t-1]+1;i+k-t<=m;i=i+1)
        {
            sou[t]=i;
            l=0;
            for (j=1;j<=n;j=j+1)
                {
                    if ((go[i][j]) && (!c[j]))
                        {
                            l=l+1;
                            c[j]=true;
                            tmp[l]=j;
                            sum=sum+s[j];
                        }
                }
            if (t==k) update();
            else btrk(t+1);
            for (j=1;j<=l;j=j+1)
                {
                    c[tmp[j]]=false;
                    sum=sum-s[tmp[j]];
                }
        }
}
int main(void)
{
    freopen("giun.inp","r",stdin);
    freopen("giun.out","w",stdout);
    init();
    btrk(1);
    printf("%d",b);
}
 