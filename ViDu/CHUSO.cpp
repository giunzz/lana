#include<bits/stdc++.h>
using namespace std;
const string tenfile = "giun";
#define balabalo freopen((tenfile + ".inp").c_str(), "r", stdin); freopen((tenfile + ".out").c_str(), "w", stdout)

string st , t;
int n , m ;

int main()
{
    balabalo;
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> st;
    cin >> n >> m ;
    for (int i = 1 ; i <= n -1 ; i++)
    {
        t = st;
       reverse(t.begin(), t.end()); 
        st += t;
        cerr << st << " ";
    }
    cout << st[m -1];
    cerr <<endl<<  clock() << " ms";
    return 0;
}

