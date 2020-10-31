#include<bits/stdc++.h>
using namespace std;

const int max_digit=100;
typedef int big_int [max_digit+1];

char A,B;
long long n,k;
map<long long , string >r;
big_int a;

long long power_ten[18];

void cong(big_int a,big_int b,big_int c){
    int nho=0;
    for(int i=max_digit;i>=1;i--){
        int t=a[i]+b[i]+nho;
        c[i]=t%10;
        nho=t/10;
    }
}

void tru(big_int a,big_int b,big_int c){
    int nho=0;
    for(int i=max_digit;i>=1;i--){
        c[i]=a[i]-b[i]-nho;
        if(c[i]<0){
            c[i]+=10;
            nho=1;
        }
        else
            nho=0;
    }
}

void nhan(big_int a,big_int b,big_int c){
    fill(c,c+max_digit+1,0);
    for(int i=max_digit;i>=1;i--){
        big_int t;
        int nho=0;
        fill(t+1,t+1+max_digit,0);
        for(int j=max_digit;j>=1;j--){
            if(i+j<=max_digit)continue;
            int k=b[i]*a[j]+nho;
            t[i+j-max_digit]=k%10;
            nho=k/10;
        }
        big_int d;
        cong(c,t,c);
    }
}

int so_sanh(big_int a,big_int b){
    for(int i=1;i<=max_digit;i++)
        if(a[i]<b[i])return -1;
        else
            if(a[i]>b[i])return 1;
    return 0;
}

void chia(big_int a,big_int b,big_int t,big_int d){
    fill(t+1,t+1+max_digit,0);
    fill(d+1,d+1+max_digit,0);
    for(int i=1;i<=max_digit;i++){
        for(int j=1;j<=max_digit-1;j++)
            d[j]=d[j+1];
    d[max_digit]=a[i];
        while(so_sanh(d,b)>=0){
            t[i]++;
            tru(d,b,d);
        }
    }
}

void ghi(big_int a){
    int i;
    for(i=1;i<=max_digit-1;i++)
        if(a[i]!=0)break;
    for(int j=i;j<=max_digit;j++)cout<<a[j];
}

long long doi_so(big_int a)
{
    long long cow=0;
    int i;
    for(i=1;i<=max_digit-1;i++)
        if(a[i]!=0)break;
    for(int j=i;j<=max_digit;j++){
        //cout<<a[j]<<'\n';
        cow+=power_ten[max_digit-j+1]*a[j];
    }

    return cow;

}

void IO(){
    freopen("MODULO.inp","r",stdin);
    freopen("MODULO.ans","w",stdout);
}

void read()
{
    cin>>A>>B>>n>>k;
}

void reset()
{
    big_int b,c;
    fill(a+1,a+1+max_digit,0);
    fill(b+1,b+1+max_digit,0);
    a[max_digit]=2;b[max_digit]=2;

    for(int i=2;i<=n;i++){
        nhan(a,b,c);
        for(int j=0;j<=max_digit;j++)
            a[j]=c[j];
    }

    power_ten[1]=1;
    for(int i=2;i<=18;i++)
        power_ten[i]=power_ten[i-1]*10;

}

void solve()
{
    reset();

    int mid=n/2;
    for(int i=0;i<=(1<<mid)-1;i++)
    {
        string nho="";

        char ci='0';
        for(int j=1;j<=n-mid;j++)
            nho+=ci;

        for(int j=0;j<mid;j++)
        {
            int bit_j=(i>>j)&1;
            //cout<<bit_j<<'\n';
            if(bit_j==1)nho+=A;
            else
                nho+=B;
        }
        //cout<<nho<<'\n';

        int e=max_digit+1;

        big_int cnt,ri,pi;
        fill(cnt+1,cnt+1+max_digit,0);
        for(int j=0;j<nho.size();j++){
            int ki_tu=nho[j]-'0';
        //cout<<ki_tu<<'\n';
            cnt[--e]=ki_tu;
        }


        chia(cnt,a,pi,ri);

        //ghi(a);
        //cout<<'\n';

        //ghi(ri);
        //cout<<'\n';

        long long wi = doi_so(ri);

        //cout<<"so_du::"<<wi<<'\n';

        r[wi]=nho;

    }

    mid=n-mid;

    for(int i=0;i<=(1<<mid)-1;i++)
    {
        string nho="";
        for(int j=0;j<mid;j++)
        {
            int bit_j=(i>>j)&1;
            //cout<<bit_j<<'\n';
            if(bit_j==1)nho+=A;
            else
                nho+=B;
        }
        //cout<<nho<<'\n';
        int e=max_digit+1;

        big_int cnt,ri,pi;
        fill(cnt+1,cnt+1+max_digit,0);
        for(int j=0;j<nho.size();j++){
            int ki_tu=nho[j]-'0';
            cnt[--e]=ki_tu;
        }

        chia(cnt,a,pi,ri);

        long long wi = doi_so(ri);

        //cout<<wi<<'\n';

        string rong="";

        if(r[abs(k-wi)]!=rong)
        {
            for(int ki=mid;ki<n;ki++)
                cout<<r[abs(k-wi)][ki];
            cout<<nho;
            exit(0);
        }

    }

    cout<<-1;


}

int main()
{
    IO();
    read();
    solve();
    return 0;
}
