#include <fstream>
#include <algorithm>
using namespace std;
FILE *fi,*fo;
int t,dem,dem1,i;
int64_t a,b,dd[1000006],dd1[1000006],minn,ans,tmp,aa,bb;
int main()
{
    fi=fopen("MINSUM.inp","r");
    fo=fopen("MINSUM.out","w");
    fscanf(fi,"%d",&t);
    while(t--)
    {
        fscanf(fi,"%lld%lld",&a,&b);
        while(1==1)
        {tmp=__gcd(a,b);
        a/=tmp,b/=tmp;
        minn=a+b;aa=a,bb=b;
        dem=0;dem1=0;
        for(i=2;i<=sqrt(a);++i)
        {
            if(a%i==0){dd[++dem]=i;
            if(i!=a/i) dd[++dem]=a/i;
            }
        }
         for(i=2;i<=sqrt(b);++i)
        {
            if(b%i==0){dd1[++dem1]=i;
            if(i!=b/i)
               dd1[++dem1]=b/i;
            }
        }
        for(i=1;i<=dem;++i)
        {   tmp=__gcd(a/dd[i],b*dd[i]);ans=a/dd[i]/tmp+b*dd[i]/tmp;
            if(ans<minn) {minn=ans;aa=a/dd[i]/tmp;bb=b*dd[i]/tmp;}
        }
        for(i=1;i<=dem1;++i)
        {   tmp=__gcd(a*dd1[i],b/dd1[i]);ans=a*dd1[i]/tmp+b/dd1[i]/tmp;
            if(ans<minn) {minn=ans;aa=a*dd1[i]/tmp;bb=b/dd1[i]/tmp;}
        }
        if(aa==a&&bb==b) {
        fprintf(fo,"%lld %lld\n",aa,bb);break;}
        else a=aa,b=bb;
        }
    }
}
