#include <bits/stdc++.h>
#define x first
#define y second
#define mp make_pair
#define ii pair<int, int>
#define mod 1e9+7;
#define HANH "MINSUM"
using namespace std;
long long A, B, T, a, b;
stack <int> q;
int main()
{
    ios_base::sync_with_stdio(0);
    freopen(HANH".inp", "r", stdin);
    freopen(HANH".out", "w", stdout);
    cin >>T;
    q.push(1);
    for(int k=1; k<=T; ++k)
    {
        cin >>A >>B;
        int xx=__gcd(A, B); A/=xx; B/=xx;
        for(int i=2; i<40000; ++i)
        {
            if(A%(i*i)==0) A/=i*i;
            if(B%(i*i)==0) B/=i*i;
            if(A%i==0) { A/=i; q.push(i); }
            if(B%i==0) { B/=i; q.push(i); }
        }
        if(q.size()==1) { cout <<A <<" " <<B <<"\n"; continue; }
        a=b=1;
        if(A>B) swap(A, B);
        while(q.size()>1)
        {
            int uu=q.top(); q.pop();
            if(B>uu)
            {
                if(a+1ll*b*B>b+1ll*a*B) a*=1ll*B;
                else b*=1ll*B;
            }
            if(A>uu)
            {
                if(a+1ll*b*A>b+1ll*a*A) a*=1ll*A;
                else b*=1ll*A;
            }
            if(a+1ll*b*uu>b+1ll*a*uu) a*=1ll*uu;
            else b*=1ll*uu;
        }
        cout <<a <<" " <<b <<"\n";
    }
}
