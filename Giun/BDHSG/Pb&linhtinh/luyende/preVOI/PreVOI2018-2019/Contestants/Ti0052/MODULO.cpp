#include <bits/stdc++.h>

using namespace std;

long long c,M;
int N,K;
int A[5];
bool x[50];

void Try_1(int i)
{
    for(int j=0;j<=1;j++)
    {
        x[i]=j;
        c=c*10+A[j];
        if( i==N )
        {
            if( c%M==K )
            {
                cout << c << "\n";
                exit(0);
            }
        }
        else
            Try_1(i+1);
        c/=10;
    }
}

int main()
{
    freopen("MODULO.INP","r",stdin);
    freopen("MODULO.OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin >> A[0] >> A[1] >> N >> K;
    M= 1 << N;
    if( N<=20 )
        Try_1(1);
    cout << -1;
    return 0;
}
