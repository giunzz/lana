#include <bits/stdc++.h>
using namespace std;

ifstream fi("MINSUM.INP");
ofstream fo("MINSUM.OUT");

const int64_t MAX=32000;
int64_t T,A,B,c1,c2,id1,id2,C1[4000],C2[4000];
bool Free[32005];
vector<int64_t> P,V;

void Try(int64_t i)
{
    for(int64_t j=0;j<=1;j++)
    {
        if(j==0)
            c1*=V[i];
        else
            c2*=V[i];
        if(i==V.size()-1)
        {
            if(c1+c2<id1+id2)
            {
                id1=c1;
                id2=c2;
            }
        }
        else
            Try(i+1);
        if(j==0)
            c1/=V[i];
        else
            c2/=V[i];
    }
}

int main()
{
    for(int64_t i=2;i<=MAX;i++)
        if(Free[i]==false)
        {
            P.push_back(i);
            for(int64_t j=2*i;j<=MAX;j+=i)
                Free[j]=true;
        }
    fi>>T;
    int64_t A,B;
    while(T--)
    {
        fi>>A>>B;
        for(int64_t i=0;i<P.size();i++)
        {
            C1[i]=0;
            C2[i]=0;
        }
        for(int64_t i=0;i<P.size();i++)
        {
            while(A%P[i]==0)
            {
                C1[i]++;
                A/=P[i];
            }
            while(B%P[i]==0)
            {
                C2[i]++;
                B/=P[i];
            }
        }
        V.clear();
        for(int64_t i=0;i<P.size();i++)
            if(abs(C1[i]-C2[i])%2==1)
                V.push_back(P[i]);
        if(A>1&&A!=B)
            V.push_back(A);
        if(B>1&&A!=B)
            V.push_back(B);
        if(V.size()==0)
            fo<<1<<' '<<1<<"\n";
        else
        {
            id1=1e18;
            id2=1e18;
            c1=1;
            c2=1;
            Try(0);
            fo<<id1<<' '<<id2<<"\n";
        }
    }
}
