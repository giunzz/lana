#include <bits/stdc++.h>
using namespace std;

ifstream fi("TEAWORLD.INP");
ofstream fo("TEAWORLD.OUT");

typedef pair<double,double> dd;
int64_t m,n,k,X,Y,res=0,sum=0,X1[2005],Y1[2005],R[2005],X2[20],Y2[20],E[20],x[20];
bool Free[2005];

bool Inside(int64_t u,int64_t v,int64_t i)
{
    return ((u-X1[i])*(u-X1[i])+(v-Y1[i])*(v-Y1[i])<=R[i]*R[i]);
}

dd Solve(int64_t a1,int64_t b1,int64_t c1,int64_t a2,int64_t b2,int64_t c2)
{
    double XX,YY;
    if(a1!=0)
    {
        YY=double(c1*a2-c2*a1)/double(b1*a2-b2*a1);
        XX=double(c1-b1*YY)/double(a1);
    }
    else
    {
        XX=double(c1*b2-c2*b1)/double(a1*b2-a2*b1);
        YY=double(c1-a1*XX)/double(b1);
    }
    return dd(XX,YY);
}

void Check()
{
    for(int64_t i=1; i<=m; i++)
        Free[i]=false;
    for(int64_t i=1; i<=n; i++)
        if(x[i]==1)
            for(int64_t j=1; j<=m; j++)
                if(Free[j]==false)
                {
                    if((Inside(X,Y,j)==true&&Inside(X2[i],Y2[i],j)==false)||(Inside(X,Y,j)==false&&Inside(X2[i],Y2[i],j)==true))
                        Free[j]=true;
                    else
                    if(Inside(X,Y,j)==false&&Inside(X2[i],Y2[i],j)==false)
                    {
                        int64_t a1=Y2[i]-Y;
                        int64_t b1=X-X2[i];
                        int64_t c1=a1*X+b1*Y;
                        int64_t a2=X-X2[i];
                        int64_t b2=Y-Y2[i];
                        int64_t c2=a2*X1[j]+b2*Y1[j];
                        dd point=Solve(a1,b1,c1,a2,b2,c2);
                        if(min(X,X2[i])<=point.first&&point.first<=max(X,X2[i])&&min(Y,Y2[i])<=point.second&&point.second<=max(Y,Y2[i]))
                        {
                            double dist=double(point.first-X1[j])*double(point.first-X1[j])+double(point.second-Y1[j])*double(point.second-Y1[j]);
                            if(dist<=R[j])
                                Free[j]=true;
                        }
                    }
                }
    int64_t Count=0;
    for(int64_t i=1;i<=m;i++)
        Count+=Free[i];
    if(Count<=k)
        res=max(res,sum);
}

void Try(int64_t i)
{
    for(int64_t j=0; j<=1; j++)
    {
        x[i]=j;
        sum+=E[i]*j;
        if(i==n)
            Check();
        else
            Try(i+1);
        sum-=E[i]*j;
    }
}

int main()
{
    fi>>m>>n>>k;
    int64_t z;
    for(int64_t i=1; i<=m; i++)
        fi>>X1[i]>>Y1[i]>>z>>R[i];
    for(int64_t i=1; i<=n; i++)
        fi>>X2[i]>>Y2[i]>>z>>E[i];
    fi>>X>>Y>>z;
    Try(1);
    fo<<res;
}
