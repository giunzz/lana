#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define in() ({ll x=0;int c=getchar(),n=0;for(;!isdigit(c);c=getchar()) n=(c=='-');for(;isdigit(c);c=getchar()) x=x*10+c-'0';n?-x:x;})
#define inchar() ({char c=getchar();while(c==' '||c=='\n') c=getchar();c;})
#define pc putchar
inline void cc(ll x)
{
    if(x<0) pc('-'),x=-x;
    if(x>9) cc(x/10);
    pc(x%10+'0');
}
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define ROF(i,a,b) for(int i=b;a<=i;i--)
#define VEC(i,a) for(auto&i:a)
#define rr(x) " "<<#x<<'='<<x<<" "
#define pb push_back
#define mt make_tuple
#define pi pair<int,int>
#define fi first
#define se second
/////////////////////////////////// PXH612
#define Max(a,b) ((a<b)?b:a)
#define Min(a,b) ((a<b)?a:b)
#define sz(x) (int)z.size()

#define segfirst 1,1,n
#define segl s*2,l,l+(r-l)/2
#define segr s*2+1,l+(r-l)/2+1,r
const int N=4005,NR=8005;
int n,delta;
int a[N],b[N];
pi seg[N][4*NR];
vector<int> v[NR];
int f[N][N],g[N][N];

int RES,RESLEN;

vector<int> rr;int Rr;
int rrac(int x)
{
    return lower_bound(rr.begin(),rr.end(),x)-rr.begin()+1;
}
int rr_up(int x)
{
    return rrac(x);
}
int rr_dw(int x)
{
    return upper_bound(rr.begin(),rr.end(),x)-rr.begin();
}
void RRAC()
{
    FOR(i,1,n) rr.pb(a[i]);
    FOR(i,1,n) rr.pb(b[i]);
    sort(rr.begin(),rr.end());
    rr.erase(unique(rr.begin(),rr.end()),rr.end());
    Rr=rr.size();
}

void UDT(int R,int s,int l,int r,int x,int val)
{
   // if(s==1) cout<<"(update)" rr(R) rr(x) rr(val) "\n";
    if(x<l||r<x) return;
    if(l==r)
    {
        seg[R][s]=max(seg[R][s],{val,x});
        return;
    }
    UDT(R,segl,x,val);
    UDT(R,segr,x,val);
    seg[R][s]=max(seg[R][s*2],seg[R][s*2+1]);
}
pi GET(int R,int s,int l,int r,int u,int v)
{
 //   if(s==1) cout<<rr(R) rr(s) rr(l) rr(r) rr(u) rr(v) "\n";
    if(r<u||v<l) return {0,0};
    if(u<=l&&r<=v) return seg[R][s];
    return max(GET(R,segl,u,v),GET(R,segr,u,v));
}
main()
{
    freopen("liondance.inp","r",stdin);
    freopen("liondance.out","w",stdout);
    n=in(),delta=in();
    FOR(i,1,n) a[i]=in();
    FOR(i,1,n) b[i]=in();
    RRAC();

    FOR(i,1,n) v[rrac(b[i])].pb(i);
   /* FOR(i,1,Rr)
    {
        cout<<i<<": ";
        VEC(j,v[i]) cout<<j<<" ";cout<<"\n";
    }*/

   // cout<<"rr: ";VEC(i,rr) cout<<i<<" ";cout<<"\n";
    ROF(i,1,n)
    {
       // cout<<"=======================" rr(i) "\n";
        int A=rrac(a[i]);
        if(v[A].empty()) continue;

        int AL=Max(0,a[i]-delta);
        int AR=a[i]+delta;

       // cout<<rr(a[i]) rr(A) "\n";
        //cout<<rr(AL) rr(AR) "\n";
        AL=rr_up(AL);
        AR=rr_dw(AR);
        //cout<<rr(AL) rr(AR) "\n";
        ROF(len,2,n)
        {

            int maleft,G;
            tie(maleft,G)=GET(len-1,segfirst,AL,AR);
        //    cout<<rr(len) rr(maleft) "\n";
            if(maleft<=v[A].front()) continue;
            int itleft=lower_bound(v[A].begin(),v[A].end(),maleft)-v[A].begin()-1;
           // cout<<"(here)" rr(len) rr(maleft) rr(itleft) rr(G)"\n";
            itleft=v[A][itleft];

            if(f[A][len]<itleft)
            {
                UDT(len,segfirst,A,itleft);
                f[A][len]=itleft;
                g[A][len]=G;
              //  cout<<rr(g[A][len]) "\n";

                if(RESLEN<len)
                {
                    RESLEN=len;
                    RES=A;
                }
                else if(RESLEN==len) RES=max(RES,A);
            }
        }
        UDT(1,segfirst,A,v[A].back());
    }
    cout<<RESLEN<<"\n";
    ROF(i,1,RESLEN)
    {
        cout<<rr[RES-1]<<" ";
        RES=g[RES][i];
    }
}

