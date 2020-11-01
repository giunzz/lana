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
#define TASK "SEQUENCE"
using namespace std;
typedef pair<int,int> pii;
const int maxn=3010;
void R(int &val)
{
    val=0;char c;
    do{c=getchar();} while(!isdigit(c));
    while(isdigit(c)) {val=val*10+c-48;c=getchar();}
}
int n,m,k;
int a[maxn],b[maxn];
void inp()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen(TASK".inp","r",stdin);
    freopen(TASK".out","w",stdout);
    cin>>n>>m>>k;
    FOR(i,1,n) cin>>a[i];
    FOR(j,1,m) cin>>b[j];
}
vector<int> a1[maxn],b1[maxn];
bool get_bit(int val,int id){return (val>>id)&1;}
void cal()
{
    int n1=(1<<n)-1;
    int m1=(1<<m)-1;
    FOR(i,0,n1){
        int dem=0;
        vector<int> tmp(0);
        FF(j,0,n) if(get_bit(i,j))
            dem++,tmp.pb(a[j+1]);
        if(a1[dem].empty()) a1[dem]=tmp;
        else{
            FF(j,0,dem){
                if(tmp[j]<a1[dem][j]) {a1[dem]=tmp;break;}
                if(tmp[j]>a1[dem][j]) break;
            }
        }
    }
    FOR(i,0,m1){
        int dem=0;
        vector<int> tmp(0);
        FF(j,0,m) if(get_bit(i,j))
            dem++,tmp.pb(b[j+1]);
        if(b1[dem].empty()) b1[dem]=tmp;
        else{
            FF(j,0,dem){
                if(tmp[j]<b1[dem][j]) {b1[dem]=tmp;break;}
                if(tmp[j]>b1[dem][j]) break;
            }
        }
    }
    vector<int> res;
    FOR(i,1,k) res.pb(lmx);
    FOR(len_a,0,n){
        if(k-len_a<=m){
            vector<int> tmp(0);
            int len_b=k-len_a;
            a1[len_a].pb(lmx);
            b1[len_b].pb(lmx);
            int h=1,l1=0,r1=0;
            while(h<=k){
                h++;
                if(a1[len_a][l1]<=b1[len_b][r1]){
                    tmp.pb(a1[len_a][l1]);
                    l1++;
                }
                else{
                    tmp.pb(b1[len_b][r1]);
                    r1++;
                }
            }
            FF(i,0,k) {
                if(tmp[i]<res[i]) {res=tmp;break;}
                if(tmp[i]>res[i]) break;
            }
        }
    }
    FF(i,0,k) cout<<res[i]<<" ";
}
int main()
{
    inp();
    cal();
    return 0;
}
