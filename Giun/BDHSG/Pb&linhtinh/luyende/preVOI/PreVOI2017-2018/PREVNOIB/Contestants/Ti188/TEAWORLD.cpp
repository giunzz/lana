#include <bits/stdc++.h>
#define PDD pair<double,double>
#define fi first
#define se second
#define mp make_pair

using namespace std;

void pool(){
    freopen("TEAWORLD.INP","r",stdin);
    freopen("TEAWORLD.OUT","w",stdout);
    return;
}

struct tdo{
    double x,y,z,r;
};
/*struct tdo2{
    double x,y,z;
    int gtr;
};*/

const int MAXN=20;
const int MAXM=2005;
tdo cau[MAXM];
tdo a[MAXN];
int m,n,k;
tdo goc;

void ip(){
    cin>>m>>n>>k;
    for (int i=1;i<=m;i++) cin>>cau[i].x>>cau[i].y>>cau[i].z>>cau[i].r;
    for (int i=1;i<=n;i++) cin>>a[i].x>>a[i].y>>a[i].z>>a[i].r;
    cin>>goc.x>>goc.y>>goc.z;
    return;
}

bool ok[MAXM];
int sl=0;

double tc(PDD AB,PDD AC){
    //PDD AB,AC;
    //AB.fi=B.fi-A.fi;AB.se=B.se-A.se;
    //AC.fi=C.fi-A.fi;AC.se=C.se-A.se;
    //cout<<AB.fi<<" "<<AB.se<<" "<<AC.fi<<" "<<AC.se<<'\n';
    return (AB.fi*AC.se-AB.se*AC.fi);
}

double kc(PDD A,PDD B){
    return sqrt((A.fi-B.fi)*(A.fi-B.fi)+(A.se-B.se)*(A.se-B.se));
}

bool check(int ch,int qc){
    double xa;
    PDD AB=mp(a[ch].x-cau[qc].x,a[ch].y-cau[qc].y);
    PDD BA=mp(-a[ch].x+cau[qc].x,-a[ch].y+cau[qc].y);

    PDD cpAB=mp(-AB.se,AB.fi);
    PDD cpBA=mp(-BA.se,BA.fi);

    PDD tam=mp(cau[qc].x-goc.x,cau[qc].y-goc.y);
    PDD tam2=mp(cau[qc].x-a[ch].x,cau[qc].y-a[ch].y);

    if (tc(cpAB,tam)*tc(cpAB,AB)<0) xa=kc(mp(goc.x,goc.y),mp(cau[qc].x,cau[qc].y));
    else if (tc(cpBA,tam2)*tc(cpBA,BA)<0) xa=kc(mp(a[ch].x,a[ch].y),mp(cau[qc].x,cau[qc].y));
    else xa=fabs(tc(tam,AB))/kc(mp(goc.x,goc.y),mp(a[ch].x,a[ch].y));

    //cout<<xa<<'\n';
    if (xa<=cau[qc].r) return 1;
    return 0;
}

void danhdau(int pp){
    for (int i=1;i<=m;i++)
    if (ok[i]==0){
        if (check(pp,i)){
            ++sl;//cout<<pp;
            ok[i]=1;
        }
    }

    return;
}

void NIX(){
    double maxx=0;
    int p=(1<<n)-1;
    for (int i=1;i<=p;i++){
        double tong=0;
        sl=0;
        for (int j=1;j<=m;j++) ok[j]=0;
        for (int j=0;j<n;j++) if ((i>>j)&1)
        tong+=a[j+1].r;

        for (int j=0;j<n;j++) if ((i>>j)&1)
        danhdau(j+1);
        if (sl<=k) maxx=max(maxx,tong);//cout<<tong<<" "<<i<<'\n';
    }
    cout<<maxx<<'\n';

    return;
}

int main()
{
    pool();
    ip();
    NIX();

    return 0;
}
