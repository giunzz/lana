#include <bits/stdc++.h>
#define m_p make_pair
#define maxn 10000
#define pii pair<int,int>
using namespace std;
int t,A,B,x,y,sum=1;
vector<int> nt,kq;
vector<pii> res1,res2,res;

/*
bool danhdau[maxn];
void sangnt(){
    for(int i=2;i<10000;i++){
        if(danhdau[i]==false){
            nt.push_back(i);
            for(int j=i ;j<10000;j+=i){
                danhdau[j]=true;
            }
        }
    }
}*/
int main()
{
    freopen("MINSUM.INP","r",stdin);
    freopen("MINSUM.OUT","w",stdout);
    cin>>t;
    while(t--){
        kq.clear();
        res.clear();res1.clear();res2.clear();
        cin>>A>>B;
        x=y=1;
        for(int i=2;i*i<=A;i++){
            if(A%i==0){
                res1.push_back(m_p(i,0));
            }
            while(A%i==0){
                res1.back().second++;
                A/=i;
            }
        }
        if(A>1){
                res1.push_back(m_p(A,1));
            }
        for(int i=2;i*i<=B;i++){
            if(B%i==0){
                res2.push_back(m_p(i,0));
            }
            while(B%i==0){
                res2.back().second++;
                B/=i;
            }
        }
        if(B>1){
                res2.push_back(m_p(B,1));
            }
        bool ok=false;
        for(int i=0;i<res1.size();i++){
            ok=false;
            for(int j=0;j<res2.size();j++){
                if(res1[i].first== res2[j].first){
                    res.push_back(m_p(res1[i].first, res1[i].second+res2[j].second));
                    ok=true;
                }
            }
            if(ok==false){ res.push_back(res1[i]);}
        }
        for(int i=0;i<res2.size();i++){
            ok=false;
            for(int j=0;j<res1.size();j++){
                if(res2[i].first== res1[j].first){
                    ok=true;
                }
            }
            if(ok==false){ res.push_back(res2[i]);}
        }
        for(int i=0;i<res.size();i++){
            if(res[i].second%2==1){
                kq.push_back(res[i].first);
            }
        }
        for(int i=0;i<kq.size();i++){
            sum*=kq[i];
        }
        if(kq.size()==0){
            cout<<1<<' '<<1<<'\n';
        }
        else if(kq.size()==1){
            cout<<1<<' '<<kq[0]<<'\n';
        }
        else if(kq.size()==2){
            if(1+ kq[0]*kq[1]< kq[0]+kq[1]){
                cout<<1<<' '<<kq[0]*kq[1]<<'\n';
            }
            else{
                cout<<kq[0]<<' '<<kq[1]<<'\n';
            }
        }
        else if(kq.size()==3){
            y=sum;
            if(x+y> kq[0]*kq[1] +kq[2]){
                x=kq[2];
                y=kq[0]*kq[1];
            }
            if(x+y> kq[0]*kq[2] +kq[1]){
                x=kq[1];
                y=kq[0]*kq[2];
            }
            if(x+y> kq[2]*kq[1] +kq[0]){
                x=kq[0];
                y=kq[2]*kq[1];
            }
            cout<<x<<' '<<y<<'\n';
        }
        else if(kq.size()>=4){
            y=sum;
            for(int i=0;i<kq.size();i++){
                if(x+y> kq[i]+ sum/kq[i]){
                    x=kq[i];
                    y=sum/kq[i];
                }
            }
            for(int i=0;i<kq.size()-1;i++){
                for(int j=i+1;j<kq.size();j++){
                     if(x+y> kq[i]*kq[j]+ sum/(kq[i]*kq[j])){
                        x=kq[i]*kq[j];
                        y=sum/(kq[i]*kq[j]);
                    }
                }
            }
            cout<<x<<' '<<y<<'\n';
        }

    }
    return 0;
}
