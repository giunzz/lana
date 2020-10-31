#include <bits/stdc++.h>
#define pii pair<int,int>
#define st first
#define nd second

using namespace std;
ifstream fi("sequence.inp");
ofstream fo("sequence.out");
int m,n,K;
int a[3001],b[3001];
vector <int> da[3001];
vector <int> db[3001];
struct cmp
{
    bool operator () (pii x,pii y)
    {
        return (x.st>y.st || (x.st==y.st && x.nd>y.nd));
    }
};
priority_queue <pii,vector<pii>,cmp> pq;
vector <int> kq,tg;
void sosanh()
{
    for (int k=0;k<K;k++)
    {
        if (kq[k]>tg[k])
        {
            for (int k=0;k<K;k++)
                kq[k]=tg[k];
            return;
        }
        if (kq[k]<tg[k]) break;
    }
}
void xuli(int dai)
{
    if (K-dai<0 || K-dai>n) return;
    int ct=0;
    tg.clear();
    if (da[dai][0]<=db[K-dai][0])
    {
        while (da[dai][ct]<=db[K-dai][0] && ct<dai)
            tg.push_back(da[dai][ct]),ct++;
        for (int k=0;k<db[K-dai].size();k++)
            tg.push_back(db[K-dai][k]);
        for (int k=ct;k<da[dai].size();k++)
            tg.push_back(da[dai][k]);
        sosanh();
    }
    ct=0;
    tg.clear();
    if (db[K-dai][0]<=da[dai][0])
    {
        while (da[dai][0]>=db[K-dai][ct] && ct<K-dai)
            tg.push_back(db[K-dai][ct]),ct++;
        for (int k=0;k<da[dai].size();k++)
            tg.push_back(da[dai][k]);
        for (int k=ct;k<db[K-dai].size();k++)
            tg.push_back(db[K-dai][k]);
        sosanh();
    }
}
int main()
{
    fi>>m>>n>>K;
    for (int i=1;i<=m;i++)
        fi>>a[i];
    for (int j=1;j<=n;j++)
        fi>>b[j];
    pii tg,tg2;
    int moc,lf;
    vector <int> temp;
    for (int dai=1;dai<=m;dai++)
    {
        while (!pq.empty()) pq.pop();
        for (int i=1;i<=m;i++)
           pq.push(make_pair(a[i],i));
        moc=0;
        lf=dai;
        temp.clear();
        while (!pq.empty())
        {
            tg=pq.top();
            pq.pop();
            if (tg.nd<moc) continue;
            lf--;
            if (m-tg.nd>lf)
            {
                da[dai].push_back(tg.st);
                moc=tg.nd;
            }
            else
            {
                while (m-tg.nd<lf)
                {
                    tg2=pq.top();
                    if (tg2.nd>moc && tg2.nd<tg.nd) temp.push_back(tg2.nd),lf--;
                    pq.pop();
                }
                sort (temp.begin(),temp.end());
                for (int k=0;k<temp.size();k++)
                    da[dai].push_back(a[temp[k]]);
                for (int i=tg.nd;i<=m;i++)
                    da[dai].push_back(a[i]);
                break;
            }
            if (lf==0) break;
        }
    }
    for (int dai=1;dai<=n;dai++)
    {
        while (!pq.empty()) pq.pop();
        for (int i=1;i<=n;i++)
           pq.push(make_pair(b[i],i));
        moc=0;
        lf=dai;
        temp.clear();
        while (!pq.empty())
        {
            tg=pq.top();
            pq.pop();
            if (tg.nd<moc) continue;
            lf--;
            if (n-tg.nd>lf)
            {
                db[dai].push_back(tg.st);
                moc=tg.nd;
            }
            else
            {
                while (n-tg.nd<lf)
                {
                    tg2=pq.top();
                    pq.pop();
                    if (tg2.nd>moc && tg2.nd<tg.nd) temp.push_back(tg2.nd),lf--;
                }
                sort (temp.begin(),temp.end());
                for (int k=0;k<temp.size();k++)
                    db[dai].push_back(b[temp[k]]);
                for (int i=tg.nd;i<=n;i++)
                    db[dai].push_back(b[i]);
                break;
            }
            if (lf==0) break;
        }
        //for (int k=0;k<db[dai].size();k++)
           // fo<<db[dai][k]<<" ";
        //fo<<endl;
    }
    for (int k=0;k<K;k++)
        kq.push_back(1e9+1);
    for (int i=0;i<=m;i++)
        xuli(i);
    for (int k=0;k<kq.size();k++)
        fo<<kq[k]<<" ";
    return 0;
}
