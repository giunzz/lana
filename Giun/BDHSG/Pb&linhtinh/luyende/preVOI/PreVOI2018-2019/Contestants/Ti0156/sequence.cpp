#include<cstdio>
#include<math.h>
#include<iostream>
#include<algorithm>
using namespace std;
const int oo=INT_MAX;
const int limit=3*1e3+1;
int n,m,k;
int dp[2][limit][limit];
int res[limit],tmp[limit],de[limit];
int a[limit],b[limit],counter[limit][limit];
void in()
{
    scanf("%d%d%d",&n,&m,&k);
    for (int i=1;i<=n;i++) scanf("%d",&a[i]);
    for (int i=1;i<=m;i++) scanf("%d",&b[i]);
    for (int i=1;i<=k;i++) res[i]=oo;
}
void add(bool sec,int len,int val)
{
    dp[sec][len][++counter[sec][len]]=val;
}
void deque(int arr[],int len,int range,bool sec)
{
    int top=0;
    int del=range-len;
    for (int i=1;i<=range;i++)
    {
        while (top && de[top]>arr[i] && del)
        {
            top--;
            del--;
        }
        de[++top]=arr[i];
    }
    for (int i=1;i<=len;i++) add(sec,len,de[i]);
}
void pre()
{
    for (int i=1;i<=n;i++) 
    {
        deque(a,i,n,0);
    }
    for (int i=1;i<=m;i++) 
    {
        deque(b,i,m,1);
    }
}
void update(int len)
{
    int quan=0;
    int pointer=1;
    while (pointer<=counter[1][k-len] && dp[1][k-len][pointer]<=dp[0][len][1]) 
    {
        tmp[++quan]=dp[1][k-len][pointer];
        pointer++;
    }
    for (int i=1;i<=counter[0][len];i++) tmp[++quan]=dp[0][len][i];
    for (int i=pointer;i<=counter[1][k-len];i++) tmp[++quan]=dp[1][k-len][i];
    bool condition=true;
    for (int i=1;i<=k;i++) 
    {
        if (tmp[i]<res[i]) break;
        else if (tmp[i]>res[i])
        {
            condition=false;
            break;
        }
    }
    if (condition) for (int i=1;i<=k;i++) res[i]=tmp[i];
}
void so()
{
    pre();
    int range=min(n,k);
    for (int i=1;i<=range;i++)
    {
        if (k-i<=m) update(i);
    }
    for (int i=1;i<=k;i++) printf("%d ",res[i]);
}
int main()
{
    freopen("sequence.inp","r",stdin);
    freopen("sequence.out","w",stdout);
    in();
    so();

}