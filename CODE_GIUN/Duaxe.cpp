#include<iostream>
using namespace std;
int n, v, v1, ans = 0, d;
bool c = 0;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("giun.inp", "r", stdin);
    //freopen("giun.out", "w", stdout);
    cin >> n ;
    cin >> v1 >> v;
    d = v1;
    if (v > v1) ans = v - v1, c = 1, d = v;
    v1 = v;
    for (int i = 1; i < n - 1; i++)
    {
        cin >> v;
        if(v > v1)
        {
            if(!c) c = 1;
            if (v > d) ans += v - v1;
        }
        else if (v < v1) 
        {
            if(c) c = 0 , d = v1;   
        }
        v1 = v;
    }
    cout << ans;
}