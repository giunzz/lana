#include<bits/stdc++.h>
using namespace std;

long long n , t;
vector<long long > p;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("power3.inp","r",stdin);
    freopen("power3.out","w",stdout);
    for (long long i = 0 ; i <= 1e6  ; i++) p.push_back(i*i*i);
    cin >> t;
    while (t--)
    {
        cin >> n ;
        bool ok = binary_search(p.begin(), p.end(), n);
        cerr << ok << " ";
        if (ok == 1) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}