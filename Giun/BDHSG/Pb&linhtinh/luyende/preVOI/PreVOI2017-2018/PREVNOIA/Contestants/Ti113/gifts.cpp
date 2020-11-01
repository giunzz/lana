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
const int N= 1e6+10;
int n,k,a[N];
long v[N];
long Mx[N],My[N];
void input()
{
    read(n); read(k);
    up(i,1,n) read(a[i]);
}

void solve()
{
    up(i,1,k) v[1]+= a[i];
    up(i,2,n-k+1) v[i]= v[i-1]+ a[i+k-1]- a[i-1];
    long res= 1e15;
    up(i,1,n-k+1) Mx[i]= max(Mx[i-1], v[i]);
    down(i,n-k+1,1) My[i]= max(My[i+1], v[i]);
    up(i,1,n-k+1)//cam chon
    {
        long t= 0;
        if (i-k> 0) t= max(t, Mx[i-k]);
        if (i+k<= n-k+1) t= max(t, My[i+k]);
        res= min(res, t);
    }
    cout<<res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    //cin.tie(NULL);


    #define TASK "gifts"
    freopen(TASK".inp","r",stdin);
    freopen(TASK".out","w",stdout);


    input();
    solve();

    return 0;
}
