#include<bits/stdc++.h>
#define task "arrange"
#define ll long long
#define ff(i,a,b) for(int i=a; i<=b; ++i)
#define fd(i,a,b) for(int i=a; i>=b; --i)
#define rr(i,a,b) for(int i=a; i<b; ++i)
#define rd(i,a,b) for(int i=a; i>b; --i)
#define pb push_back
#define mp make_pair
using namespace std;

const int maxn=1E5+10;
const ll oo=1E15+7;
struct node {
	ll val; int id;
	node(){}
	node(ll v, int ii) {val=v, id=ii;}
} Max[maxn*8], Min[maxn*8];
int pos[maxn];
ll res, a[maxn], gg, gg_; 
int sm, bg, n; 

void maximize(node &a, node b, node c) {
	(b.val>=c.val) ? a=b : a=c;
}

void minimize(node &a, node b, node c) {
	(b.val<=c.val) ? a=b : a=c;
}

void build(int k, int l, int r)
{
	if(l==r)
	{
		Max[k]=node(a[l], l);
		Min[k]=node(a[l], l);
		pos[l]=k;
	} else
	{
		int mid=(l+r)/2;
		build(k*2, l, mid);
		build(k*2+1, mid+1, r);
		maximize(Max[k], Max[k*2], Max[k*2+1]);
		minimize(Min[k], Min[k*2], Min[k*2+1]);
	}
}

void READ()
{
	scanf("%d",&n);
	ff(i, 1, n)scanf("%d",&a[i]);
}

void INIT()
{
	build(1, 1, n);
	ll s=0;
	ff(i, 1, n)s+=1ll*a[i];
	gg=s/n; gg_=s/n+1; 		//cout<<gg<<" "<<gg_<<endl;
	/*
	 gg*x + gg_*y == s
	 x+y == n => x=n-y
	 gg*(n-y) + gg_*y == s
	 gg*n - gg*y + gg_*y == s
	 gg*n + (gg_ - gg)*y == s 
	 => gg*n + y == s
	*/
	bg = s-gg*n;
	sm = n-bg; 				//cout<<sm<<" "<<bg<<endl;
	ff(i, 1, n)
	{
		if(a[i]==gg)sm--;
		if(a[i]==gg_)bg--;
	} //cout<<sm<<" "<<bg<<endl;
}

node getMax(int k, int l, int r, int L, int R)
{
	if(l>R || r<L) return node(-oo, 0);
	if(L<=l && r<=R) return Max[k]; 
	int mid=(l+r)/2;
	node res; maximize(res, getMax(k*2, l, mid, L, R), getMax(k*2+1, mid+1, r, L, R));
	return res;
}

node getMin(int k, int l, int r, int L, int R)
{
	if(l>R || r<L)return node(oo, 0);
	if(L<=l && r<=R) return Min[k]; 
	int mid=(l+r)/2;
	node res; minimize(res, getMin(k*2, l, mid, L, R), getMin(k*2+1, mid+1, r, L, R));
	return res;
}

void update(int x)
{
	int k=pos[x]; 
	Max[k] = node(a[x], x);
	Min[k] = node(a[x], x);
	k/=2;
	while(k>0)
	{
		maximize(Max[k], Max[k*2], Max[k*2+1]);
		minimize(Min[k], Min[k*2], Min[k*2+1]);
		k/=2;
	}
}

ll cost(int x, int y, ll w) {
	ll s=abs(1ll*x-y)*w;
	return s;
}

void optimize(node &it, int x)
{
	if(it.id<x)
	{
		int l=it.id, r=x-1, mid, res=-1;
		while(l<=r)
		{
			mid=(l+r)/2;
			if(getMin(1, 1, n, mid, x-1).val==it.val)
			{
				res=mid;
				l=mid+1;
			} else r=mid-1;
		}
		if(res!=-1) it=node(it.val, res);
	} else
	{
		int l=x+1, r=it.id, mid, res=-1;
		while(l<=r)
		{
			mid=(l+r)/2;
			if(getMin(1, 1, n, x+1, mid).val==it.val)
			{
				res=mid;
				r=mid-1;
			} else l=mid+1;
		}
		if(res!=-1) it=node(it.val, res);
	}
}

void SOLVE()
{
	while(sm!=0 || bg!=0)
	{
		node maxVal = getMax(1, 1, n, 1, n);  //cout<<maxVal.val<<" "<<maxVal.id<<endl;
		node minValL = getMin(1, 1, n, 1, maxVal.id-1), minValR=getMin(1, 1, n, maxVal.id+1, n);
		if(minValL.id!=0)optimize(minValL, maxVal.id);
		if(minValR.id!=0)optimize(minValR, maxVal.id);
		//cout<<minValL.val<<" "<<minValL.id<<"         "<<minValR.val<<" "<<minValR.id<<endl;
		int ind;
		if(minValL.val==minValR.val)
		{
			if(minValL.id>0 && minValR.id>0) 
			{
				int distL, distR;
				distL=maxVal.id-minValL.id;
				distR=minValR.id-maxVal.id;
				if(distL<=distR)ind=minValL.id; else ind=minValR.id;
			}else
			if(minValL.id>0) ind=minValL.id; else
			if(minValR.id>0) ind=minValR.id;
		} else
		{
			if(minValL.id>0 && minValR.id>0) 
			{
				if(minValL.val<=minValR.val)ind=minValL.id; else
					ind=minValR.id;
			} else
			if(minValL.id>0) ind=minValL.id; else
			if(minValR.id>0) ind=minValR.id;
		}
		//cout<<ind<<endl;
		if(sm>0)
		{
			ll need = gg-a[ind];
			res+=cost(maxVal.id, ind, need);
			a[ind]+=need; update(ind); sm--;
			if(a[maxVal.id]==gg_)bg++; else
			if(a[maxVal.id]==gg)sm++;
			a[maxVal.id]-=need; update(maxVal.id);
			if(a[maxVal.id]==gg_)bg--; else
			if(a[maxVal.id]==gg)sm--;
		} else
		if(bg>0)
		{
			ll need = gg_-a[ind];
			res+=cost(maxVal.id, ind, need);
			if(a[ind]==gg)sm++; a[ind]+=need; update(ind); bg--;
			if(a[maxVal.id]==gg_)bg++; else
			if(a[maxVal.id]==gg)sm++;
			a[maxVal.id]-=need; update(maxVal.id);
			if(a[maxVal.id]==gg_)bg--; else
			if(a[maxVal.id]==gg)sm--;
		} 
		//cout<<"          "<<sm<<" "<<bg<<endl;
	}
	cout<<res;
}

int main()
{
	freopen(task".inp","r",stdin);
	freopen(task".out","w",stdout);
	READ();
	INIT();
	SOLVE();
	return 0;
}
