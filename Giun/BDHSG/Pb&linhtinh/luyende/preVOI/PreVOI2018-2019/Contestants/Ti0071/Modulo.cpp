/**GreenGrass**/
#include <bits/stdc++.h>
#define For(i,a,b) for(int i=a;i<=b;++i)
using namespace std;
template <typename T> inline void read(T &x){char c;bool nega=0;while((!isdigit(c=getchar()))&&(c!='-'));if(c=='-'){nega=1;c=getchar();}x=c-48;while(isdigit(c=getchar()))x=x*10+c-48;if(nega)x=-x;}
template <typename T> inline void writep(T x){if(x>9)writep(x/10);putchar(x%10+48);}
template <typename T> inline void write(T x){if(x<0){putchar('-');x=-x;}writep(x);}
void Min(int &a, int b) {if(a>b) a=b;}
void Max(int &a, int b) {if(a<b) a=b;}
const int N = 1050000;
int a[2], n;
vector <pair <long long,int>> ch;
long long k, mu[100], mod;
void Write(int m, int bit){
    For(i,0,m-1) write(a[(bit>>i)&1]);
}
void Handle(int m){
    For(bit,0,(1<<m)-1){
        long long res = 0;
        For(i,0,m-1) res=res*10+a[(bit>>i)&1];
        ch.push_back(make_pair(res%mod,bit));
    }
}
int main(){
    freopen("Modulo.inp" , "r", stdin);
    freopen("Modulo.out", "w", stdout);
    read(a[0]), read(a[1]), read(n), read(k);
    mu[0]=1;
    For(i,1,n/2) mu[i]=mu[i-1]*10;
    mod = 1ll<<n;
    int gg=n-n/2;
    Handle(n/2);
    sort(ch.begin(),ch.end());
    For(bit,0,(1<<gg)-1){
        long long res = 0;
        For(i,0,gg-1) res=res*10+a[(bit>>i)&1];
        res*=mu[n/2];
        res%=mod;
        long long temp2 = (k-res+mod)%mod;
        int temp = lower_bound(ch.begin(),ch.end(),make_pair(temp2,0))-ch.begin();
        if(temp==(int)ch.size()) continue;
        if(ch[temp].first==temp2){
            For(i,0,gg-1) write(a[(bit>>i)&1]);
            Write(n/2,ch[temp].second);
            return 0;
        }
    }
    write(-1);
	return 0;
}
