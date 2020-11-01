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

II c[2010],t[16];
int r[2010],e[16];
II root;
int m,n,k;
vector<int> chan[16];
bool used[2010];
void input()
{
    cin>>m>>n>>k;
    int zz;
    up(i,1,m) cin>>c[i].X>>c[i].Y>>zz>>r[i];
    up(i,1,n) cin>>t[i].X>>t[i].Y>>zz>>e[i];
    cin>>root.X>>root.Y>>zz;
}
int getbit(int x,int k)
{
    return (x>>k) & 1;
}
II operator -(II a,II b)
{
    return {a.X- b.X, a.Y- b.Y};
}
long ch(II a, II b)//ch
{
    return a.X* b.Y- a.Y* b.X;
}
long vh(II a, II b)//vh
{
    return a.X* b.X+ a.Y* b.Y;
}
long sqr(long a)
{
    return a*a;
}
long sqrdist(II a)
{
    return sqr(a.X)+ sqr(a.Y);
}
bool Inside(II a, int j)// point a in circle j?
{
    long R= 1LL* r[j]* r[j];
    return sqrdist(c[j]- a)<= R;
}
bool ok(int i,int j)
{
    // dist from c[j] to (root, t[i])
    if (Inside(root, j) and Inside(t[i], j)) return false;

    long R= 1LL* r[j]* r[j];
    if (vh(root- c[j], t[i]- root)>0) return sqrdist(root- c[j])<= R;
    if (vh(t[i]- c[j], root- t[i])>0) return sqrdist(t[i]- c[j])<= R;
    double d;
    d= abs( ch(root- c[j], t[i]- c[j])) / sqrt(sqrdist(root- t[i]));
    d= d*d;
    return (long)d<= R;
}
void solve()
{

    up(i,1,n)
     up(j,1,m)
      if (ok(i,j)) chan[i].push_back(j);

    long res= 0;
    up(state,0,(1<<n)-1)
    {
        up(i,1,m) used[i]= false;
        int cnt= 0;
        long sume= 0;
        up(i,1,n)
         if (getbit(state, i-1))
          {
              for (int cc: chan[i])
              {
                if (used[cc]== false) cnt++;
                used[cc]= true;
              }
              sume+= e[i];
          }
        if (cnt<= k) res= max(res, sume);
    }

    cout<<res;
}

int main()
{
    ios_base::sync_with_stdio(false);

    cin.tie(NULL);


    #define TASK "teaworld"
    freopen(TASK".inp","r",stdin);
    freopen(TASK".out","w",stdout);


    input();
    solve();

    return 0;
}
