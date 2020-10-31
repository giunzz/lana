#include <bits/stdc++.h>
#define long long long
#define up(i,a,b) for (int i=a; i<=b; i++)
#define down(i,a,b) for (int i=a; i>=b; i--)
#define endl '\n'
#define X first
#define Y second
#define II pair<int, int>
#define debug(X) cerr<< #X << "=" <<X << endl
#define debug2(X,Y)  cerr<< #X << "=" <<X << ", " << #Y << "=" <<Y << endl
#define show(X,a,b) {cerr << #X << " = "; up(__,a,b) cerr << X[__] << ' '; cerr << endl;}
#define gc getchar
#define pc putchar
using namespace std;

inline void read(int &x)
{
    register int c = gc();
    x = 0;
    int neg = 0;
    for (;((c<48 || c>57) && c != '-') ;c = gc());
    if(c=='-') {neg=1;c=gc();}
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
    if(neg) x=-x;
}
inline void writeln(int x){

         char buffor[21];
         register int i=0;
         int neg=0; if (x<0) {neg=1; x= -x;}
         do{
               buffor[i++]=(x%10)+'0';
               x/=10;
            } while(x);
           i--;
           if (neg) pc('-');
           while(i>=0) pc(buffor[i--]);
           pc('\n');
       }

long a,b;
void input()
{
    cin>>a>>b;
}
long pt(long a)
{
    int s= (int)sqrt(a);
    up(i,2,s)
    {
        int cnt= 0;
        while (a%i== 0) a/= i, cnt++;
        if (cnt%2== 1) a*= i;
    }
    return a;
}
void solve()
{
    a= pt(a); b= pt(b);
    long res= 1e18;
    II r;

    long c= __gcd(a,b);
    a/= c; b/= c;
    up(i,1,(int)sqrt(a))
     if (a%i== 0)
     {
         long t= a/i+ b*i;
         if (t< res) res= t, r= II(a/i, b*i);
         t= a/ (a/i)+ b* (a/i);
         if (t< res) res= t, r= II(a/ (a/i), b* (a/i));
     }
   up(i,1,(int)sqrt(b))
     if (b%i== 0)
     {
         long t= b/i+ a*i;
         if (t< res) res= t, r= II(a*i, b/i);
         t= b/ (b/i)+ a* (b/i);
         if (t< res) res= t, r= II(a*(b/i), b/ (b/i));
     }
   //cout<<res<<endl;
   cout<<r.X<<" "<<r.Y<<endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #define TASK "minsum"
    freopen(TASK".inp","r",stdin);
    freopen(TASK".out","w",stdout);

    int test;
    cin>>test;
    up(i,1,test)
    {
        input();
        solve();
    }
    return 0;
}
