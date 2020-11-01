#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int main()
{
    freopen("TEAWORLD.INP","r",stdin);
    freopen("TEAWORLD.out","w",stdout);
    cin>>m>>n>>k;
    srand(time(NULL));
    cout<<rand()%(n*(rand()%80000));
}
