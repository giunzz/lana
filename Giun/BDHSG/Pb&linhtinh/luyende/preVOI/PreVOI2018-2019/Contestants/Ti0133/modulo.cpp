#include<bits/stdc++.h>
#define maxs 1048581
#define fi first
#define se second
using namespace std;
typedef int64_t lli;
typedef pair<int, int> pairii;

int a, b, n, m1, m2, k, divi;
pairii D2[maxs];
lli x, PO;
int d1, d2, D1[maxs], p[21];

lli power(int x, int y)
{
    if ( y == 1 )
        return x;
    lli r= power(x, y/2);
    r= (r*r)%divi;
    if ( y % 2 == 1 ) r= (r*x)%divi;
    return r;
}
void Try(int u)
{
    if ( u > m1 )
    {
        D1[++d1]= (x*PO)%divi;
        return;
    }
    for (int i=0; i<=1; i++)
    {
        p[u]= i;
        if ( i == 0 ) x= x*10+a;
        if ( i == 1 ) x= x*10+b;
        Try(u+1);
        x/= 10;
    }
}

void Tryagain(int u)
{
    if ( u > m2 )
    {
        d2++;
        D2[d2]= {x%divi, d2};
        return;
    }
    for (int i=0; i<=1; i++)
    {
        p[u]= i;
        if ( i == 0 ) x= x*10+a;
        if ( i == 1 ) x= x*10+b;
        Tryagain(u+1);
        x/= 10;
    }
}

int binarysearch(int x)
{
    int low= 1, high= d2, mid;
    while ( low <= high )
    {
        mid= (high+low)/2;
        if ( D2[mid].fi == x )
            return mid;
        if ( D2[mid].fi < x )
            low= mid+1;
        if ( D2[mid].fi > x )
            high= mid-1;
    }
    return d2+1;
}

void write(int x, int g)
{
    if ( g == 0 )
        return;
    write(x/2, g-1);
    int dig= x%2;
    if ( dig == 0 ) cout<<a;
    if ( dig == 1 ) cout<<b;
}
void Solve()
{
    if ( n == 1 )
    {
        if ( a % divi == k ) cout<<a;
        else
        {
            if ( b % divi == k ) cout<<b;
            else cout<<-1;
        }
        return;
    }
    m1= n/2, m2= n-m1;
    PO= power(10, m2);
    d1= 0, x= 0;
    Try(1);
    d2= 0, x= 0;
    Tryagain(1);

    //for (int i=1; i<=d1; i++) cout<<D1[i]<<" "; cout<<endl;
    //for (int i=1; i<=d2; i++) cout<<D2[i].fi<<" "; cout<<endl;

    int pos1= 0, pos2= 0;
    sort(D2+1, D2+d2+1);
    for (int i=1; i<=d1; i++)
    {

        int x= k-D1[i];
        //cout<<D1[i]<<" "<<x<<endl;
        if ( x > 0 )
        {
            int y= binarysearch(x);
            if ( y != d2+1 )
            {
                pos1= i; pos2= D2[y].se;
                //break;
            }
        }
        x= divi+k-D1[i];
        //cout<<D1[i]<<" "<<x<<endl;
        if ( x > 0 )
        {
            int y= binarysearch(x);
            if ( y != d2+1 )
            {
                pos1= i; pos2= D2[y].se;
                break;
            }
        }
    }
    if ( pos1 == 0 || pos2 == 0 )
    {
        cout<<-1;
        return;
    }
    //cout<<pos1<<" "<<pos2<<endl;
    write(pos1-1, m1);
    //cout<<" ";
    write(pos2-1, m2);
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);  cout.tie(NULL);
    freopen("modulo.inp", "r", stdin);
    freopen("modulo.out", "w", stdout);
    cin>> a>> b;
    cin>> n>> k;

    divi= (1<<n);
    Solve();

    //cout<<endl<<44744777744%divi;

    return 0;
}
