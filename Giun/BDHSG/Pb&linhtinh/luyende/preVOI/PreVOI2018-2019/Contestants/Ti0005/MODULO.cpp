#include <bits/stdc++.h>

using namespace std;
ifstream fi ("MODULO.INP");
ofstream fo ("MODULO.OUT");

const int maxn=310;

char A1,B1;
int N;
string K1;
vector <string> M2;

void Input()
{
    fi>>A1>>B1;
    fi>>N>>K1;
}

char Num_to_char(int x)
{
    return char(x+'0');
}

string Num_to_string(int x)
{
    string S;
    while (x>0)
    {
        S=Num_to_char(x%10)+S;
        x=x/10;
    }
    return S;
}

int Char_to_num(char a)
{
    return a-'0';
}

string Plus(string A, string B)
{
    string S,S1;
    while (A.size()<B.size())
    {
        A='0'+A;
    }
    while (A.size()>B.size())
    {
        B='0'+B;
    }
    int rmb=0;
    int s=A.size();
    for (int i=s-1; i>=0; i--)
    {
        int a=Char_to_num(A[i]);
        int b=Char_to_num(B[i]);
        int k=a+b+rmb;
        if (k>=10)
        {
            rmb=1;
            S+=Num_to_char(k%10);
        }
        else
        {
            rmb=0;
            S+=Num_to_char(k);
        }
    }
    if (rmb==1)
        S+="1";
    for (int i=S.size()-1; i>=0; i--)
        S1+=S[i];
    return S1;
}

string Small_Multi(string A, char B)
{
    string S,S1;
    int a=A.size();
    int rmb=0;
    for (int i=a-1; i>=0; i--)
    {
        int x=Char_to_num(A[i]);
        int y=Char_to_num(B);
        int k=x*y+rmb;
        if (k>=10)
        {
            S+=Num_to_char(k%10);
            rmb=k/10;
        }
        else
        {
            rmb=0;
            S+=Num_to_char(k);
        }
    }
    if (rmb>0)
        S+=Num_to_char(rmb);
    for (int i=S.size()-1; i>=0; i--)
        S1+=S[i];
    return S1;
}

string Multi(string A, string B)
{
    string S="0",S1;
    int a=A.size();
    int b=B.size();
    int cnt=-1;
    for (int i=a-1; i>=0; i--)
    {
        cnt++;
        S1=Small_Multi(B,A[i]);
        for (int i=1; i<=cnt; i++)
            S1=S1+"0";
        S=Plus(S1,S);
    }
    return S;
}

bool Check(string S)
{
    for (int i=0; i<S.size(); i++)
        if (S[i]!=A1 && S[i]!=B1) return false;
    return true;
}


void Process()
{
    string two="2";
    M2.push_back("1");
    M2.push_back("2");
    for (int i=2; i<=63; i++)
    {
        string temp=Multi(M2[i-1],two);
        M2.push_back(temp);
    }
//    for (int i=0; i<=63; i++)
//        fo<<i<<" "<<M2[i]<<endl;
    int i=0;
    string S;
    while(1)
    {
        string I=Num_to_string(i);
        S=Plus(K1,Multi(M2[N],I));
        if (S.size()>N)
        {
            fo<<"-1"<<endl;
            break;
        }
        if (Check(S))
        {
            fo<<S<<endl;
            break;
        }
        else
        {
            i++;
        }
    }
}

int main()
{
    Input();
    Process();
    return 0;
}
