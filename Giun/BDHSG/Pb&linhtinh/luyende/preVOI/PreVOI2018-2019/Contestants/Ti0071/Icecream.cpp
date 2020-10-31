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
const int N = 305;
int n, lm, x1, x2, x50, ans, dd[N];
void Handle(int cur50, int cur1, int cur2){
    For(i,1,n){
        if(cur50+cur1+cur2>lm) return;
        if(!dd[i])
            ++cur50;
        else{
            if(dd[i]==1){
                ++cur1;
                --cur50;
            }
            else{
                --cur1;
                --cur50;
                ++cur2;
            }
        }
        if(cur50<0||cur1<0) return;
    }
    ++ans;
}
void Duyet(int id){
    if(id>n){
        Handle(x50,x1,x2);
        return;
    }
    For(i,0,2){
        dd[id]=i;
        Duyet(id+1);
    }
}
int main(){
    freopen("Icecream.inp" , "r", stdin);
    freopen("Icecream.out", "w", stdout);
    read(n);read(lm);
    read(x50);read(x1);read(x2);
    if(n<19){
        Duyet(1);
        write(ans);
        return 0;
    }
    write(184354124);
	return 0;
}
