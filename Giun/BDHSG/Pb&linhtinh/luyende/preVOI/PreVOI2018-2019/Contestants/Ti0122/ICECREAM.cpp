#include <bits/stdc++.h>
#define FOR(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)
#define FORE(i,a,b) for(int (i)=(a);(i)>=(b);(i)--)
#define FF(i,a,b) for(int (i)=(a);(i)<(b);(i)++)
#define FFE(i,a,b) for(int (i)=(a);(i)>(b);(i)--)
#define F first
#define S second
#define TT top()
#define FR front()
#define pb push_back
#define sz size()
#define reset(x,n,a) fill((x),(x)+(n)+1,(a))
#define mp make_pair
#define mt make_tuple
#define minimize(a,b) if(a>b) a=b;
#define maximum(a,b) if(a<b) a=b;
#define sc scanf
#define pr printf
#define ll long long
#define llmx 9223372036854775807
#define llmn -9223372036854775808
#define lmx 2147483647
#define lmn -2147483648
#define TASK "ICECREAM"
using namespace std;
typedef pair<int,int> pii;
const int maxn=310;
const int mod=1e9+9;
void R(int &val)
{
    val=0;char c;
    do{c=getchar();} while(!isdigit(c));
    while(isdigit(c)) {val=val*10+c-48;c=getchar();}
}
int n,MMAX;
int res;
int c50,c1,c2;
void inp()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen(TASK".inp","r",stdin);
    freopen(TASK".out","w",stdout);
    cin>>n>>MMAX;
    cin>>c50>>c1>>c2;
}
void Try(int i){
    FOR(j,0,2){
        if(j==0){
            if(c50<MMAX) c50++;
            else continue;
            if(i==n) res++;
            else Try(i+1);
            c50--;
        }
        if(j==1){
            if(c50&&c1<MMAX){
                c1++;c50--;
                if(i==n) res++;
                else Try(i+1);
                c50++;c1--;
            }
            else continue;
        }
        if(j==2){
            if(c2==MMAX) continue;
            if(c50&&c1){
                c50--;c1--;c2++;
                if(i==n) res++;
                else Try(i+1);
                c50++;c1++;c2--;
            }
            else if(c50==3){
                c50-=3;c2++;
                if(i==n) res++;
                else Try(i+1);
                c50+=3;c2--;
            }
        }
    }
    res%=mod;
}
void cal()
{
    Try(1);
    cout<<res;
}
int main()
{
    inp();
    cal();
    return 0;
}
