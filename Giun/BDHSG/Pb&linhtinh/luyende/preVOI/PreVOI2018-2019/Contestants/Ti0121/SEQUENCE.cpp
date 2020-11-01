#include<bits/stdc++.h>
#define fi first
#define se second
#define pii pair<int ,int>
using namespace std;

int m,n,k;
int sla[3001],nhoa;
int slb[3001],nhob;

pii ansa[3001];
pii ansb[3001];

int kq[3001],q[3001];
int ser=0;

pii a[3001];
pii b[3001];


void IO()
{
    freopen("SEQUENCE.inp","r",stdin);
    freopen("SEQUENCE.out","w",stdout);
}

void reset()
{
    memset(sla,0,sizeof(sla));
    memset(slb,0,sizeof(slb));
    kq[1]=1e9;

}

void read()
{
    cin>>m>>n>>k;
    for(int i=1;i<=m;i++)
        {
            int ai;
            scanf("%d",&ai);
            a[i]={ai,i};
        }
    sort(a+1,a+1+m);

    nhoa=1;
    sla[1]=1;
    for(int i=2;i<=m;i++)
        if(a[i].fi==a[i-1].fi)sla[nhoa]++;
        else
        {
            nhoa++;
            sla[nhoa]=1;
        }

    for(int j=1;j<=n;j++)
    {
        int bi;
        scanf("%d",&bi);
        b[j]={bi,j};
    }

    sort(b+1,b+1+n);

    nhob=1;
    slb[1]=1;
    for(int i=2;i<=n;i++)
        if(b[i].fi==b[i-1].fi)slb[nhob]++;
        else
        {
            nhob++;
            slb[nhob]=1;
        }
}


void solve()
{
    for(int i=1;i<=m;i++)
    {
        int cnt=i,tong=0;
        if(i+n<k)continue;
        for(int j=1;j<=nhoa;j++)
        {
            if(sla[j]<=cnt){cnt-=sla[j];tong+=sla[j];}
            else
            {
                for(int wi=1;wi<=tong;wi++)
                    ansa[wi]={a[wi].se,a[wi].fi};

                int dem=tong;
                for(int wi=tong+sla[j];wi>=tong+sla[j]-cnt;wi--)
                {
                    //cout<<"gan::"<<a[wi].fi<<' '<<a[wi].se<<'\n';
                    ansa[++dem]={a[wi].se,a[wi].fi};
                }
            }
        }


        sort(ansa+1,ansa+1+i);
        //for(int j=1;j<=i;j++)
        //   cout<<ansa[j].se<<' ';
        //cout<<'\n';

        cnt=k-i;
       // cout<<cnt<<'\n';
        tong=0;

        for(int j=1;j<=nhob;j++)
        {
            if(slb[j]<=cnt){cnt-=slb[j];
            for(int wi=tong+1;wi<=tong+slb[j];wi++)
                ansb[wi]={b[wi].se,b[wi].fi};
            tong+=slb[j];
            }
            else
            {
                int dem=tong;
                for(int wi=tong+slb[j];wi>=tong+slb[j]-cnt;wi--)
                {
                    //cout<<"gan::"<<b[wi].fi<<' '<<b[wi].se<<'\n';
                    ansb[++dem]={b[wi].se,b[wi].fi};
                }
            }
        }

        cnt=k-i;

        sort(ansb+1,ansb+1+cnt);
        //for(int j=1;j<=cnt;j++)
        //    cout<<ansb[j].se<<' ';
        //cout<<'\n';

            int per=0;
            for(int j=2;j<=k-i;j++)
            {
                per=0;
                bool ok=false;

                for(int wi=1;wi<j;wi++)
                    q[++per]=ansb[wi].se;
                for(int wi=1;wi<=i;wi++)
                    q[++per]=ansa[wi].se;
                for(int wi=j;wi<=k-i;wi++)
                    q[++per]=ansb[wi].se;

                for(int wi=1;wi<=per;wi++){
                    if(q[wi]==kq[wi])continue;
                    if(q[wi]<kq[wi]){ok=true;break;}
                    if(q[wi]>kq[wi])break;
                }
                if(ok){
                for(int wi=1;wi<=per;wi++)
                    kq[wi]=q[wi];
                }

            }

    }


    for(int i=1;i<=k-1;i++)
        printf("%d ",kq[i]);
    printf("%d\n",kq[k]);
}

int main()
{
    IO();
    reset();
    read();
    solve();
    return 0;
}
