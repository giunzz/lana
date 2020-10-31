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
const int N= 5010;
const int oo= 1e9;
int n;
int a[N][2],f[N][N], maxval;
int val[N];
int best[N];
void input()
{
    cin>>n; maxval= n/2+ 1;
    up(i,1,n) cin>>val[i];
    up(i,1,n-1)
    {
        int u,v;
        cin>>u>>v;
        if (a[u][0]== 0) a[u][0]=v;
        else a[u][1]= v;
    }
}

bool opmin(int &tar, int val)
{
    if (val>= oo) return false;
    if (val< tar)
    {
        tar= val;
        return true;
    }
    return false;
}
void recur(int u,int low, int high, int l, int r)//f[u][low.. high], best= [l,r]
{
    if (low> high) return;
    int mid= (low+ high)/2;
    f[u][mid]= oo;
    best[mid]= l;
    up(k,l,mid )
     if (mid-k>=0)
        if (opmin(f[u][mid], f[a[u][0]][k]+ f[a[u][1]][mid-k]))
         best[mid]= k;

    f[u][mid]+= abs(val[u]- mid);
    if (f[u][mid]>oo) f[u][mid]= oo;
    recur(u, low, mid-1, l, best[mid]);
    recur(u, mid+1, high, best[mid], r);
}
void dfs(int u)
{
    if (a[u][0]== 0)
    {
        f[u][0]= val[u]; f[u][1]= abs(val[u]-1);
        up(j,2,maxval) f[u][j]= oo;
        return;
    }
    dfs(a[u][0]);
    if (!a[u][1])
    {
        up(j,0,maxval)
        {
            f[u][j]= f[a[u][0]][j]+ abs(val[u]- j) ;
            if (f[u][j]> oo) f[u][j]= oo;
        }
    }
    else
    {
        dfs(a[u][1]);
        recur(u, 0, maxval,0, maxval);
        //up(j,0,maxval) cout<<j<<" "<<best[j]<<endl;
    }

}
void solve()
{
    dfs(1);
    int res= oo;
    up(j,0,maxval) opmin(res, f[1][j]);
    cout<<res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    #define TASK "tree"
    freopen(TASK".inp","r",stdin);
    freopen(TASK".out","w",stdout);


    input();
    solve();

    return 0;
}
