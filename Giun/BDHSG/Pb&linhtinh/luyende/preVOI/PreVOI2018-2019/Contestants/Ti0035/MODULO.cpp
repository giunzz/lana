#include<bits/stdc++.h>

using namespace std;

int A, B, n;
unsigned long long k;
unsigned long long c;
int tt[21];

void check()
{
    unsigned long long sum = 0, l = 1;
    for(int i = 1; i <= n; i++)
        {
        if(tt[i]) sum += l*A;
        else sum += l*B;
        l*=10;
        }
//        cerr << sum <<"\n";
        if(sum%c == k){cout << sum ; exit(0);}
}

void dq(int i)
{
    for(int j = 0; j < 2; j++)
    {
        tt[i] = j;
        if(i == n)check();
        else dq(i+1);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("MODULO.INP", "r", stdin);
    freopen("MODULO.OUT", "w", stdout);
    cin >> A >> B;
     cin >> n >> k;
     c = (1 <<(n));
//     cerr << c <<"\n";
     if(n <= 20)dq(1);
     cout << -1;
}
