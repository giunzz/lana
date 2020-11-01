#include <bits/stdc++.h>
#define PII pair<int,int>
#define fi first
#define se second
#define mp make_pair

using namespace std;

void pool(){
    freopen("ARRANGE.INP","r",stdin);
    freopen("ARRANGE.OUT","w",stdout);
    return;
}

const int MAXN=1e5+7;
long long n,a[MAXN];
long long tongfull=0;

void ip(){
    cin>>n;
    for (int i=1;i<=n;++i) {cin>>a[i];tongfull+=a[i];}
    return;
}

void NIX(){
    int dau=1;long long cphi=0;
    for (int i=1;i<=n;++i)
    if (a[i]>tongfull/n){
        long long tam=a[i]-tongfull/n;a[i]=tongfull/n;
        while (tam>0){//cout<<i<<" "<<tam<<'\n';
            while (a[dau]>=tongfull/n) ++dau;//cout<<i<<" "<<dau<<'\n';
            if (tam<=tongfull/n-a[dau]) {cphi+=(tam*fabs(i-dau));a[dau]+=tam;tam=0;}
            else {cphi+=((tongfull/n-a[dau])*fabs(dau-i));tam-=(tongfull/n-a[dau]);a[dau]=tongfull/n;}
        }
    }
    cout<<cphi<<'\n';

    return;
}

set<int> mys;
set<int>::iterator it;
PII f[MAXN];
int dem=0;
int tren,duoi;

void NIX2(){
    long long cphi=0;
    duoi=tongfull/n;
    tren=duoi;if (tongfull%n!=0) ++tren;

    int dau=1;
    for (int i=1;i<=n;++i)
    if (a[i]>tren){
        long long tam=a[i]-tren;
        while (tam>0){//cout<<i<<" "<<tam<<'\n';
            int xx=tam;
            while (a[dau]>=duoi&&dau<=n) ++dau;//cout<<i<<" "<<dau<<'\n';
            if (dau==n+1) break;
            //cout<<i<<" "<<dau<<'\n';
            if (tam<=duoi-a[dau]) {cphi+=(tam*fabs(i-dau));a[dau]+=tam;tam=0;}
            else {cphi+=((duoi-a[dau])*fabs(dau-i));tam-=(duoi-a[dau]);a[dau]=duoi;}
            a[i]=a[i]-xx+tam;
        }
    }

    //for (int i=1;i<=n;++i) cout<<a[i]<<" ";

    for (int i=1;i<=n;++i)
    if (a[i]>tren){
        while (a[i]>tren){
        int vt=0,minx=1e9+7;
        for (int j=1;j<=n;++j)
        if (a[j]==duoi&&fabs(i-j)<minx) {minx=fabs(i-j);vt=j;}
        --a[i];++a[vt];
        cphi+=fabs(vt-i);
        }
    }
    else if (a[i]<duoi){
        while (a[i]<duoi){
        int vt=0,minx=1e9+7;
        for (int j=1;j<=n;++j)
        if (a[j]==tren&&fabs(i-j)<minx) {minx=fabs(i-j);vt=j;}
        ++a[i];--a[vt];
        cphi+=fabs(vt-i);
        }
    }

    cout<<cphi;

    return;
}

void NIX3(){
    long long cphi=0;
    duoi=tongfull/n;
    tren=duoi;if (tongfull%n!=0) ++tren;

    int dau=1;
    for (int i=1;i<=n;++i)
    if (a[i]>tren){
        long long tam=a[i]-tren;
        while (tam>0){//cout<<i<<" "<<tam<<'\n';
            int xx=tam;
            while (a[dau]>=duoi&&dau<=n) ++dau;//cout<<i<<" "<<dau<<'\n';
            if (dau==n+1) break;
            //cout<<i<<" "<<dau<<'\n';
            if (tam<=duoi-a[dau]) {cphi+=(tam*fabs(i-dau));a[dau]+=tam;tam=0;}
            else {cphi+=((duoi-a[dau])*fabs(dau-i));tam-=(duoi-a[dau]);a[dau]=duoi;}
            a[i]=a[i]-xx+tam;
        }
    }

    //for (int i=1;i<=n;++i) cout<<a[i]<<" ";
    int yy=0;
    for (int i=1;i<=n;++i) if (a[i]>tren) yy=2;
    else if (a[i]<duoi) yy=1;

    if (yy==1){
        for (int i=1;i<=n;++i) if (a[i]==tren) mys.insert(i);

        for (int i=1;i<=n;++i)
        if (a[i]<duoi){
            while (a[i]<duoi){
                int vt=0,minx=1e9+7;

                if (mys.lower_bound(i)==mys.end()){
                    it=mys.end();--it;
                    vt=*it;
                    mys.erase(vt);
                }
                else{
                    it=mys.lower_bound(i);
                    vt=*it;
                    if (it!=mys.begin()){
                        --it;int tamt=*it;
                        if (vt-i>i-tamt) vt=tamt;
                    }
                    mys.erase(vt);
                }

                ++a[i];--a[vt];
                cphi+=fabs(vt-i);
            }
        }
    }
    else if (yy==2){
        for (int i=1;i<=n;++i) if (a[i]==duoi) mys.insert(i);

        for (int i=1;i<=n;++i)
        if (a[i]>tren){
            while (a[i]>tren){
                int vt=0,minx=1e9+7;

                if (mys.lower_bound(i)==mys.end()){
                    it=mys.end();--it;
                    vt=*it;
                    mys.erase(vt);
                }
                else{
                    it=mys.lower_bound(i);
                    vt=*it;
                    if (it!=mys.begin()){
                        --it;int tamt=*it;
                        if (vt-i>i-tamt) vt=tamt;
                    }
                    mys.erase(vt);
                }

                --a[i];++a[vt];
                cphi+=fabs(vt-i);
            }
        }
    }

    cout<<cphi;

    return;
}

int main()
{
    pool();
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    ip();
    if (tongfull%n==0) NIX();
    else if (n<=2000) NIX2();
    else NIX3();
    //NIX3();

    return 0;
}
