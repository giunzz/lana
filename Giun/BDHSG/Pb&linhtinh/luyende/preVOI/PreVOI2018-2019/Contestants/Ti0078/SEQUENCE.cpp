#include<bits/stdc++.h>
using namespace std;

int m,n,k,pos[7000],a[3500],b[3500],res[7000],linkaf[7000],link[7000],linkne[7000],st1,st2;

int Reduce()
{
    int ptr=0;

    while(ptr<=m+n)
    {
        int p=ptr;
        ptr=linkne[ptr];

        if(ptr>m+n)break;

        if(res[p]>res[ptr])
        {
            int prep=link[p];
            linkne[prep]=ptr;
            link[ptr]=prep;

            return 1;
        }
    }
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("SEQUENCE.INP","r",stdin);
    freopen("SEQUENCE.OUT","w",stdout);

    cin>>m>>n>>k;

    for(int i=1;i<=m;++i)cin>>a[i];

    for(int i=1;i<=n;++i)cin>>b[i];

    int del=m+n-k;

    int ptr1=1;
    int ptr2=1;

    a[m+1]=(int)1e9;
    b[n+1]=(int)1e9;

    for(int i=1;i<=m+n;++i)
    {
        if(a[ptr1]<=b[ptr2])
        {
            res[i]=a[ptr1];
            ++ptr1;
            pos[i]=1;
        }
        else
        {
            res[i]=b[ptr2];
            ++ptr2;
            pos[i]=2;
        }

        link[i]=i-1;
        linkne[i-1]=i;
    }
    linkne[m+n]=m+n+1;
    link[m+n+1]=m+n;

    int pre1=0;
    int pre2=0;

    while(true)
    {
        int chk=Reduce();

        if(chk)
        {
            --del;
            if(del==0)break;
        }
        else break;
    }

    while(del>0)
    {
        int last=m+n+1;
        int p=link[last];
        int prep=link[p];

        linkne[prep]=last;
        link[last]=prep;
        --del;
    }

    int ptr=0;

    int bf1=0;
    int bf2=0;

    while(ptr<=m+n)
    {
        ptr=linkne[ptr];
        if(pos[ptr]==1)
        {
            if(bf1==0)
            {
                st1=ptr;
                bf1=ptr;
            }

            else
            {
                linkaf[bf1]=ptr;
                bf1=ptr;
            }
        }
        if(pos[ptr]==2)
        {
            if(bf2==0)
            {
                st2=ptr;
                bf2=ptr;
            }

            else
            {
                linkaf[bf2]=ptr;
                bf2=ptr;
            }
        }
    }

    res[0]=(int)1e9;
    res[m+n+1]=(int)1e9;

    ptr1=st1;
    ptr2=st2;

    for(int i=1;i<=k;++i)
    {
        if(res[ptr1]<=res[ptr2])
        {
            cout<<res[ptr1]<<" ";
            ptr1=linkaf[ptr1];
        }

        else
        {
            cout<<res[ptr2]<<" ";
            ptr2=linkaf[ptr2];
        }
    }
}
