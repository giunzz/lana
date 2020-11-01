#include <bits/stdc++.h>
using namespace std;
int a,b,n;
typedef long long ll;
ll k;

ll sub1(){
    queue<int>q1,q2;
    ll base=pow(2,n);
    q1.push(a);q1.push(b);
    q2.push(1);q2.push(1);
    while(!q1.empty() && q2.front()<=18){
        if(q1.front()%base==k){
            return q1.front();
        }
        if(q2.front()<18){
            q1.push(q1.front()*10+a);
            q1.push(q1.front()*10+b);
            q2.push(q2.front()+1);
            q2.push(q2.front()+1);
            q1.pop();q2.pop();
        }
        else q1.pop(),q2.pop();
    }
    return -1;
}

void sub2(){
    ll base=pow(2,n),tmp;
    int A[20];
    for(int i=0;i<=n;i++){
        for(int j=1;j<=i;j++) A[j]=a;
        for(int j=i+1;j<=n;j++) A[j]=b;
        do{
            tmp=0;
            for(int j=1;j<=n;j++){
                tmp=tmp*10+A[j];
            }
            if(tmp%base==k){
                cout<<tmp;
                return;
            }
        }while(next_permutation(A+1,A+n+1));
    }
    cout<<-1;
}

int main(){
    freopen("MODULO.INP","r",stdin);
    freopen("MODULO.OUT","w",stdout);
    cin>>a>>b>>n>>k;
    if(a%2==1 && b%2==1 && k%2==0){
        cout<<-1;
        return 0;
    }
    if(a>b) swap(a,b);
    if(n<=20){
        sub2();
        return 0;
    }
    else{
        ll tmp=sub1();
        if(tmp==-1) cout<<-1;
        else{
            string s;
            while(tmp){
                s=s+(char)(tmp%10+'0');
                tmp/=10;
            }
            while(s.length()<n) s=(char)(a+'0')+s;
            cout<<s;
        }
    }
    return 0;
}
