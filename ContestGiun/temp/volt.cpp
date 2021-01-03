#include<bits/stdc++.h>
#define ll long long
#define giuncute ios_base::sync_with_stdio(0),cin.tie(0);
using namespace std;
ll n , a , b , I , x , r , c ;
vector<double> rtd;
int main()
{
    giuncute;
    rtd.push_back(0);
    freopen("giun.inp","r",stdin);
    freopen("g.out","w",stdout);
    cin >> n >> a >> b >> I;
    for (int i = 1 ; i < n ; i++)
    {
        cin >> x;
        if (x < 2) 
        {
            cin >> r >> c ;
            rtd.push_back(r*c);
        }
        else 
        {
            double t = 0;
            for (int j = 1 ; j <= x ; j++)
            {
                cin >> r >> c;
                t += 1.0/(double)(r*c);
            }
            rtd.push_back(1.0/(double)t);
        }
    }
    for (int i = 1 ; i < (ll) rtd.size() ; i++) cerr << rtd[i] << " ";
    double rt = 0;
    for (int i = a ; i < b ; i++) rt += rtd[i];

    cout << (ll)(I*rt);
}