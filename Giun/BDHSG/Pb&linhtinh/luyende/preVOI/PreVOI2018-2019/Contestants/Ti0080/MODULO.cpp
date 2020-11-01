#include<bits/stdc++.h>
using namespace std;
#define fi(i,x,y) for(int i=x; i<=y; ++i)
#define fd(i,x,y) for(int i=x; i>=y; --i)
#define st first
#define nd second
#define BIT(x,i) (x >> i) & 1
#define N 63
#define M 1000006

typedef long long ll;
typedef pair <ll,string> ii;
int n,d[N];
ll a,b,k;
ii t1[M],t2[M];
ll Pow2[64],Pow10[100];

void io()
{
    freopen("MODULO.inp", "r", stdin);
    freopen("MODULO.out", "w", stdout);
}

ll mulmod(ll x,ll y,ll m)
{
    x %= m; y %= m;
    ll q = (long double) x * y / m;
    ll r = ll(x * y - q * m) % (ll)m;
    if (r < 0) r += m;
    return r;
}

void Sub1()
{
    fi(i,0,(1<<n)-1)
    {
        ll S = 0LL;
        fi(j,0,n-1) d[j] = 0;
        fi(j,0,n-1)
        {
            if (BIT(i,j))
            {
                S = (S + mulmod(a,Pow10[n-j-1],Pow2[n])) % Pow2[n];
                d[j] = 1;
            }
            else
            {
                S = (S + mulmod(b,Pow10[n-j-1],Pow2[n])) % Pow2[n];
                d[j] = 0;
            }
        }
        if (S == k)
        {
            fi(j,0,n-1)
                if (d[j] == 1) cout << a;
                else cout << b;
            return;
        }
    }
    cout << "-1";
}

void Sub2()
{
    int s1 = n/2;
    int s2 = n-s1;
    int cnt1=0,cnt2=0;
    fi(i,0,(1<<s1)-1)
    {
        ll S = 0LL;
        cnt1++;
        fi(j,0,s1-1)
        {
            if (BIT(i,j))
            {
                S = (S + mulmod(a,Pow10[n-j-1],Pow2[n])) % Pow2[n];
                t1[cnt1].nd = t1[cnt1].nd + "a";
            }
            else
            {
                S = (S + mulmod(b,Pow10[n-j-1],Pow2[n])) % Pow2[n];
                t1[cnt1].nd = t1[cnt1].nd + "b";
            }
        }
        t1[cnt1].st = S;
    }
    fi(i,0,(1<<s2)-1)
    {
        ll S = 0LL;
        cnt2++;
        fi(j,0,s2-1)
        {
            if (BIT(i,j))
            {
                S = (S + mulmod(a,Pow10[s2-j-1],Pow2[n])) % Pow2[n];
                t2[cnt2].nd = t2[cnt2].nd + "a";
            }
            else
            {
                S = (S + mulmod(b,Pow10[s2-j-1],Pow2[n])) % Pow2[n];
                t2[cnt2].nd = t2[cnt2].nd + "b";
            }
        }
        //cout << t2[cnt2].nd << endl;
        t2[cnt2].st = S;
    }
    sort(t2+1,t2+cnt2+1);
    fi(i,1,cnt1)
    {
        int j = lower_bound(t2+1,t2+cnt2+1,ii(Pow2[n]+k-t1[i].st,"0")) - t2;
        int j1 = lower_bound(t2+1,t2+cnt2+1,ii(k-t1[i].st,"0")) - t2;
        if (t1[i].st + t2[j].st == Pow2[n] + k)
        {
            string s = t1[i].nd+t2[j].nd;
            fi(o,0,n-1)
                if (s[o] == 'a') cout << a;
                else cout << b;
            return;
        }
        if (t1[i].st + t2[j1].st == k)
        {
            string s = t1[i].nd+t2[j1].nd;
            fi(o,0,n-1)
                if (s[o] == 'a') cout << a;
                else cout << b;
            return;
        }
    }
    cout << "-1";
}

int main()
{
    io();
    cin >> a >> b >> n >> k;
    Pow2[0] = 1, Pow10[0] = 1;
    fi(i,1,41) Pow2[i] = Pow2[i-1]*2;
    fi(i,1,100) Pow10[i] = mulmod(Pow10[i-1],(ll)10,Pow2[n]);
    if (n <= 21)
    {
        Sub1();
        return 0;
    }
    if (n <= 40)
    {
        Sub2();
        return 0;
    }
    cout << "-1";
}
