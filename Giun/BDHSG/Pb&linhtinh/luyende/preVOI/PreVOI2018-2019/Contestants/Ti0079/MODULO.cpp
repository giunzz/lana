#include <bits/stdc++.h>
using namespace std;
long long a,b,n,k,ok,need,cd,m[8888888];
int cs[8888888],val[8888888];
unordered_map <long long, long long> d;
void inp()
{
    cin >> a >> b;
    cin >> n >> k;
    need = 1;
    for (long long i = 1 ; i <= n ; i++) need *= 2;
}
void sub1(long long cur , long long t)
{
    if (t == n)
    {
        if (cur % need == k) {cout <<cur<<endl; ok = 1;};
        return;
    }
    if (ok == 1) return;
    sub1(cur * 10 + a , t + 1);
    if (ok == 1) return;
    sub1(cur * 10 + b , t + 1);
    if (ok == 1) return;
}
void create(long long cur , long long t , long long now)
{
    if (t == now)
    {
        cd++;
        m[cd] = cur % need;
        cs[cd] = now;
        val[cd] = cur;
        return;
    }
    if (ok == 1) return;
    create(cur * 10 + a , t + 1,now);
    if (ok == 1) return;
    create(cur * 10 + b , t + 1,now);
    if (ok == 1) return;
}
void sub2()
{
    create(0,0,n/2);
    create(0,0,n - n/2);
    long long t = 1;
    for (long long i = 1 ; i <= n-n/2 ; i++) t = t*10 % need;
    for (long long i = 1 ; i <= cd ; i++) if (cs[i] == n - n/2) d[m[i]] = val[i];
    for (long long i = 1 ; i <= cd ; i++)
    {
        if (cs[i] == n/2)
        {
            long long sp = m[i] * t % need;
            long long r = (k - sp + need*5) % need;
            if (d[r] != 0)
            {
                cout <<val[i]<<d[r];
                return;
            }
        }
    }
    cout <<-1;

}
main()
{    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("MODULO.INP","r",stdin);
    freopen("MODULO.OUT","w",stdout);
    inp();
    if (n <= 20)
    {
        sub1(0,0);
        if (ok == 0) cout << -1;
    }
    else if (n <= 50) sub2();
    else cout <<-1;
}
