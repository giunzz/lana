/**GreenGrass**/
#include <bits/stdc++.h>
#define For(i,a,b) for(int i=a;i<=b;++i)
using namespace std;
template <typename T> inline void read(T &x){char c;bool nega=0;while((!isdigit(c=getchar()))&&(c!='-'));if(c=='-'){nega=1;c=getchar();}x=c-48;while(isdigit(c=getchar()))x=x*10+c-48;if(nega)x=-x;}
template <typename T> inline void writep(T x){if(x>9)writep(x/10);putchar(x%10+48);}
template <typename T> inline void write(T x){if(x<0){putchar('-');x=-x;}writep(x);putchar(' ');}
template <typename T> inline void writeln(T x){write(x);putchar('\n');}
void Min(int &a, int b) {if(a>b) a=b;}
void Max(int &a, int b) {if(a<b) a=b;}
const int N = 1000;
int n, a[N], b[N], ans[N], s, ch[N], top, d;
bool Check(){
    int tr=a[ch[1]];
    For(i,1,top){
        if(abs(tr-a[ch[i]])>d)
            return 0;
        tr=a[ch[i]];
    }
    int run = 1;
    For(i,1,top){
        while(b[run]!=a[ch[i]]&&run<=n) ++run;
        if(run>n) return 0;
        ++run;
    }
    return 1;
}
int main(){
    freopen("Liondance.inp" , "r", stdin);
    freopen("Liondance.out", "w", stdout);
    read(n);read(d);
    For(i,1,n) read(a[i]);
    For(i,1,n) read(b[i]);
    if(n<23){
        For(i,0,(1<<n)-1){
            top=0;
            For(j,0,n-1)
                if((i>>j)&1)
                    ch[++top]=j+1;
            if(Check()){
                if(s<top){
                    s=top;
                    For(j,1,top) ans[j]=ch[j];
                }
            }
        }
        writeln(s);
        For(i,1,s) write(a[ans[i]]);
        return 0;
    }
    
	return 0;
}
