/**GreenGrass**/
#include <bits/stdc++.h>
#define For(i,a,b) for(int i=a;i<=b;++i)
#define Ford(i,a,b) for(int i=a;i>=b;--i)
using namespace std;
template <typename T> inline void read(T &x){char c;bool nega=0;while((!isdigit(c=getchar()))&&(c!='-'));if(c=='-'){nega=1;c=getchar();}x=c-48;while(isdigit(c=getchar()))x=x*10+c-48;if(nega)x=-x;}
template <typename T> inline void writep(T x){if(x>9)writep(x/10);putchar(x%10+48);}
template <typename T> inline void write(T x){if(x<0){putchar('-');x=-x;}writep(x);putchar(' ');}
template <typename T> inline void writeln(T x){write(x);putchar('\n');}
void Min(int &a, int b) {if(a>b) a=b;}
void Max(int &a, int b) {if(a<b) a=b;}
const int N = 3003;
int n, m, k, r[N][3003], a[N], b[N], ans[N*2], luu[N*2], save[N][N], Temp[N];
void Handle(){
    For(i,1,k){
        if(ans[i]<luu[i]) return;
        if(ans[i]>luu[i]) break;
    }
    For(i,1,k) ans[i]=luu[i];
}
int main(){
    freopen("Sequence.inp" , "r", stdin);
    freopen("Sequence.out", "w", stdout);
    read(n);read(m);read(k);
    For(i,1,k) ans[i]=2e9;
    For(i,1,n) read(a[i]);
    For(i,1,m) read(b[i]);
    For(i,1,3000) r[n+1][i]=n+1;
    Ford(i,n,1){
        For(j,1,3000) r[i][j]=r[i+1][j];
        r[i][a[i]]=i;
    }
    For(i,1,min(n,k)){
        int pos = 0;
        For(j,1,i){
            For(p,1,3000){
                int temp = r[pos+1][p];
                if(n-temp>=i-j){
                    save[i][j]=p;
                    pos=temp;
                    break;            
                }
            }
        }
    }
    For(i,1,3000) r[m+1][i]=m+1;
    Ford(i,m,1){
        For(j,1,3000) r[i][j]=r[i+1][j];
        r[i][b[i]]=i;
    }
    For(i,1,min(m,k)){
        int pos = 0;
        For(j,1,i)
            For(p,1,3000){
                int temp = r[pos+1][p];
                if(m-temp>=i-j){
                    Temp[j]=p;
                    pos=temp;
                    break;            
                }
            }
        int curn = k-i;
        if(curn>n) continue;
        int pos2 = 1;
        pos=1;
        For(j,1,k){
            int temp = ((pos>curn)?2e9:save[curn][pos]);
            int temp2 = ((pos2>i)?2e9:Temp[pos2]);
            if(temp>temp2){
                luu[j]=temp2;
                ++pos2;            
            }else{
                luu[j]=temp;
                ++pos;
            }
        }
        Handle();
        
    }
    For(i,1,k) write(ans[i]);
	return 0;
}
