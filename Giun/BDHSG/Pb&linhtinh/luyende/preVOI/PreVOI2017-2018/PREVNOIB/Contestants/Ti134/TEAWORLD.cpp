#include <bits/stdc++.h>
using namespace std;
int n,m,k,xs,ys,zs,cs1,cs2,cnt;
struct tdo{
    int x;int y;int z;int r;
    };
tdo put;
vector <tdo> ball,store;
vector <int> block[16],help;
int bo[2001];
long long res;
void Try(int a){
    if(a==n){
        cnt++;
        int csm=0;
        long long tmlk=0;
        for(int i=0;i<help.size();i++){
            tmlk+=store[help[i]].r;
            for(int j=0;j<block[help[i]].size();j++)
                if(bo[block[help[i]][j]]<cnt){
                    bo[block[help[i]][j]]=cnt;
                    csm++;
                }
        }
        if(csm<=k)
            res=max(res,tmlk);
    }
    else{
        Try(a+1);
        help.push_back(a);
        Try(a+1);
        help.pop_back();
    }
}
long long kctb(int a){
    return (ball[a].x-xs)*(ball[a].x-xs)+(ball[a].y-ys)*(ball[a].y-ys);
}
long long kcbs(int a,int b){
    return (ball[a].x-store[b].x)*(ball[a].x-store[b].x)+(ball[a].y-store[b].y)*(ball[a].y-store[b].y);
}
float kcts(int a){
    return (store[a].x-xs)*(store[a].x-xs)+(store[a].y-ys)*(store[a].y-ys);
}
bool check(int a,int b,int c,int d){
    if((a+b<c&&a+b>=d)||(a-b<=c&&a-b>d)||
       (a+b>=c&&a+b<d)||(a-b>c&&a-b<=d))
        return true;
    return false;
}
int main(){
    freopen("TEAWORLD.inp","r",stdin);
    freopen("TEAWORLD.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> m >> n >> k;
    for(int i=0;i<m;i++){
        cin >> put.x >> put.y >> put.z >> put.r;
        cs1=max(cs1,abs(put.z));
        cs2=max(cs2,abs(put.y));
        ball.push_back(put);
    }
    for(int i=0;i<n;i++){
        cin >> put.x >> put.y >> put.z >> put.r;
        cs1=max(cs1,abs(put.z));
        cs2=max(cs2,abs(put.y));
        store.push_back(put);
    }
    cin >> xs>> ys >> zs;
    cs1=max(cs1,abs(zs));
    cs2=max(cs2,abs(ys));
    if(cs1==0){
        if(cs2==0){
            for(int i=0;i<n;i++)
                for(int j=0;j<m;j++)
                    if(check(ball[j].x,ball[j].r,xs,store[i].x)){
                       block[i].push_back(j);
                    }
        }
        else{
            for(int i=0;i<n;i++)
                for(int j=0;j<m;j++){
                    if((ball[j].x-xs)*(ball[j].y-store[i].y)==(ball[j].x-store[i].x)*(ball[j].y-ys)){
                        if(check(ball[j].x,ball[j].r,xs,store[i].x)||check(ball[j].y,ball[j].r,ys,store[i].y)){
                            block[i].push_back(j);
                        }
                    }
                    else{
                        float vt1x=ball[j].x-xs,vt1y=ball[j].y-ys;
                        float vt2x=ball[j].x-store[i].x,vt2y=ball[j].y-store[i].y;
                        if((kctb(j)>ball[j].r*ball[j].r&&kcbs(j,i)<=ball[j].r*ball[j].r)||
                           (kctb(j)<=ball[j].r*ball[j].r&&kcbs(j,i)>ball[j].r*ball[j].r)||
                           ((kctb(j)>ball[j].r*ball[j].r&&kcbs(j,i)>ball[j].r*ball[j].r)&&
                            (((vt1x*vt2y-vt1y*vt2x)*(vt1x*vt2y-vt1y*vt2x)/kcts(i))<=(ball[j].r*ball[j].r))&&
                            (kctb(j)+kcts(i)>kcbs(j,i)&&kcbs(j,i)+kcts(i)>kctb(j)))){
                            block[i].push_back(j);
                            }
                    }
                }
        }
    }
    Try(0);
    cout << res;
}
