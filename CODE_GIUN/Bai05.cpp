/*#include<bits/stdc++.h>
using namespace std;
vector<int> a; 
int n ,  ans ,  s = 0 , b[1009] = {0};
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("input.inp","r",stdin);
    freopen("output.txt","w",stdout);
    //freopen("bai05.inp","r",stdin);
    //freopen("bai05.out","w",stdout);    
    cin >> n ;
    for (int i = 1 ; i <= n ; i++)
    {
        cin >> b[i];
    }
    for (int i = 1 ; i <= n ; i++)
    {
        if (b[i] <= 0) 
        {   s = b[i];
            while (b[i+1] <= 0 && i <= n)
            {
                s += b[++i];    
            }
            a.push_back(s) ;
        }
        else a.push_back(b[i]);
    }
    int t = a.size();
    if (a[0] < 0 && a[t-1] < 0 && t > 1) a[0] += a[t-1] ;
    ans = INT_MAX;
    for (int i = 0 ; i < t; i++)
    {
        //cerr << a[i] << " ";
        ans = min(ans , a[i]);
    }
    cout << ans << endl;
    return 0;    
}*/

#include <bits/stdc++.h>

using namespace std;

const string task = "task";
const int N = 1e4 + 10;
const int oo = 1e9 + 7;

#define FileOpen freopen ("bai05.inp", "r", stdin);	freopen ("bai05.out", "w", stdout);

int n, a[N], ans = oo;

int main() {
    FileOpen;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = n + 1; i <= 2 * n; i++) a[i] = a[i - n];
    for (int len = 1; len <= n; len++) {
        for (int i = 1; i <= n; i++) {
            int j = i + len - 1;
            int s = 0;
            for (int k = i; k <= j; k++) {
                s += a[k];
            }
            ans = min(ans, s);
        }
    }
    cout << ans << endl;
}
