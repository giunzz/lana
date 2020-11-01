#include <bits/stdc++.h>
using namespace std;
int a,b,t,res,A,B;
map <int,int> cntrem;
int era[31700],mu[3500],apr[3500];
vector <int> ngto,ext;
vector <int> pick;
void Try(int i){
    if(i==pick.size()){
        if(res>(A+B)){
            a=A;
            b=B;
            res=A+B;
        }
    }
    else{
        A*=pick[i];
        Try(i+1);
        A/=pick[i];
        B*=pick[i];
        Try(i+1);
        B/=pick[i];
    }
}
int main(){
    freopen("MINSUM.inp","r",stdin);
    freopen("MINSUM.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    for(int i=2;i<31700;i++)
    if(era[i]==0){
        ngto.push_back(i);
        for(int j=i+i;j<31700;j+=i)
            era[j]=1;
    }
    cin >> t;
    for(int x=0;x<t;x++){
        cin >> a>> b;
        int n=0;
        A=1;B=1;res=2000000001;pick.clear();ext.clear();
        for(int i=0;i<3500;i++)
            mu[i]=0;
        while(a>1&&ngto[n]<=sqrt(a)&&n<ngto.size()){
            if(a%ngto[n]==0){
                apr[n]=x+1;
                ext.push_back(n);
                while(a%ngto[n]==0){
                    mu[n]++;
                    a/=ngto[n];
                }}
                n++;}
        n=0;
        while(b>1&&ngto[n]<=sqrt(b)&&n<ngto.size()){
            if(b%ngto[n]==0){
                if(apr[n]!=x+1)
                    ext.push_back(n);
                while(b%ngto[n]==0){
                    mu[n]++;
                    b/=ngto[n];
                }}
                n++;}
        for(int i=0;i<ext.size();i++)
            if(mu[ext[i]]%2==1)
                pick.push_back(ngto[ext[i]]);
        if(a>1||b>1){
            if(a>1&&b>1){
                if(a!=b){
                    pick.push_back(a);
                    pick.push_back(b);
                }
            }
            else
                if(a>1)
                    pick.push_back(a);
                else
                    pick.push_back(b);
        }
        Try(0);
        cout << a << " " << b << '\n';
    }
}
