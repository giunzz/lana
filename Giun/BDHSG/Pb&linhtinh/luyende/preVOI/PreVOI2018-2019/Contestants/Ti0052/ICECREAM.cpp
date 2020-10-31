#include <iostream>

using namespace std;

int x[100];
int n,d[100],nmax;
int dd[100];
int dem;

void Try(int i)
{
    for(int j=1;j<=3;j++)
    {
        if( d[j]>=nmax ) continue;
        if( j==2 && d[1]<1 ) return;
        if( j==3 && d[1]<1 ) return;
        if( j==2 ) d[1]--;
        if( j==3 )
        {
            if( d[1]>=3 )
            {
                dd[i]=1;
                d[1]-=3;
            }
            else if( d[1]<=2 && d[2]>=1 )
            {
                dd[i]=2;
                d[1]--;
                d[2]--;
            }
            else if( d[2]==0 ) return;
        }
        x[i]=j;
        d[j]++;
        if( i==n )  dem++;
        else        Try(i+1);
        d[j]--;
        if( j==2 ) d[1]++;
        if( j==3 )
        {
            if( dd[i]==1 )
                d[1]+=3;
            if( dd[i]==2 )
            {
                d[1]++;
                d[2]++;
            }
            dd[i]=0;
        }
    }
}

int main()
{
    freopen("ICECREAM.INP","r",stdin);
    freopen("ICECREAM.OUT","w",stdout);
    cin >> n >> nmax;
    for(int i=1;i<=3;i++)
        cin >> d[i];
    Try(1);
    cout << dem;
    return 0;
}
