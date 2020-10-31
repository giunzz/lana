#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
int n,MMAX;
const int mod=1e9+9;
int gia[3]={50,100,200};
int m1,m2,m3;
int dem=0;
void input(){
    freopen("ICECREAM.INP","r",stdin);
    freopen("ICECREAM.OUT","w",stdout);
    cin>>n>>MMAX;
    cin>>m1>>m2>>m3;
}
int x[301];
int cnt=0;
void dfs(int i){
    dem++;
    if(dem>=150000000) {
        cout<<cnt;
        exit(0);
    }
    if(i>n){
        int s1=m1,s2=m2,s3=m3;
        for(int j=1;j<=n;j++){
            if(x[j]==50) {
                if(s1==MMAX) return;
                s1++;
            }
            if(x[j]==100){
                if(s1==0) return;
                if(s2==MMAX) return;
                s1--;
                s2++;
            }
            if(x[j]==200){
                if(s3==MMAX) return;
                if(s1==0) return;
                if(s2==0&&s1<3) return;
                if(s1>=1&&s2>=1){
                    s1--;
                    s2--;
                }
                else if(s1<3) return;
                    else {
                        s1-=3;
                    }
                s3++;
            }
        }
        cnt++;
       // for(int j=1;j<=n;j++)
         //   cout<<x[j]<<' ';
       // cout<<endl;
        cnt%=mod;
        return;
    }
    for(int j=0;j<3;j++){
        x[i]=gia[j];
        dfs(i+1);
    }
}
void sub1(){
    dfs(1);
    cout<<cnt;
    exit(0);
}
int main(){
    input();
    sub1();
}

