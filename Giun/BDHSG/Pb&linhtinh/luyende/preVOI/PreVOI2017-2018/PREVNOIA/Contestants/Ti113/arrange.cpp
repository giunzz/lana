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
const int N= 1e5+10;
int n,a[N];
int part;
queue<int> q;
void input()
{
    cin>>n;
    up(i,1,n) cin>>a[i];
}

void solve()
{
    long sum= 0;
    up(i,1,n) sum+= a[i];
    part= sum/n;

    long res= 0;
    up(i,1,n)
    {
        if (a[i]< part) q.push(i);
        else if (a[i]> part)
        {
            while (!q.empty())
            {
                int u= q.front();
                if (a[i]- part>= part- a[u])
                {
                    q.pop();
                    res+= 1LL* (i-u)* (part- a[u]);
                    a[i]-= part- a[u];
                }
                else
                {
                    res+= 1LL* (i-u)* (a[i]- part);
                    a[u]+= a[i]- part;
                    break;
                }
            }
        }
    }

    cout<<res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    #define TASK "arrange"
    freopen(TASK".inp","r",stdin);
    freopen(TASK".out","w",stdout);


    input();
    solve();

    return 0;
}
