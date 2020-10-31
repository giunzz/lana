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
#define TASK "LIONDANCE"
using namespace std;
typedef pair<int,int> pii;
const int maxn=4010;
void R(int &val)
{
    val=0;char c;
    do{c=getchar();} while(!isdigit(c));
    while(isdigit(c)) {val=val*10+c-48;c=getchar();}
}
int n,delta,d;
int l[maxn],r[maxn];
void inp()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen(TASK".inp","r",stdin);
    freopen(TASK".out","w",stdout);
    cin>>n>>delta;
    FOR(i,1,n) cin>>l[i];
    FOR(i,1,n) cin>>r[i];
}
vector <int> a;
vector <int> s;
void cnkl(){
    int n1=a.size();
    if(a.size()>s.size()) s=a;
    else if(a.size()==s.size())
        FF(i,0,n1)
            if(a[i]>s[i]) s=a;
}
void Try(int i){
    FORE(j,1,0){
        if(j&&abs(l[i]-r[d])<=delta){
            int tmp=d;
            FOR(k,d+1,n) if(r[k]==l[i]){
                d=k;a.push_back(l[i]);
                if(i==n) cnkl();
                else if(a.size()+n-i>=s.size()) Try(i+1);
                a.pop_back();
                d=tmp;
            }
        }
        else{
            if(i==n) cnkl();
            else if(a.size()+n-i>=s.size()) Try(i+1);
        }
    }
}
void cal()
{
    Try(1);
    cout<<s.size()<<"\n";
    for(auto i:s) cout<<i<<" ";
}
int main()
{
    inp();
    cal();
    return 0;
}
