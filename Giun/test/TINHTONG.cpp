#include<bits/stdc++.h>
using namespace std;
#define giuncute ios_base::sync_with_stdio(0) , cin.tie(0)
const string tenfile = "tinhtong";
#define balabalo freopen((tenfile + ".inp").c_str(), "r", stdin); freopen((tenfile + ".out").c_str(), "w", stdout)

vector<int> v1 , v2 , v3;
string s1 , s2;
int d = 0;
void remove0( vector<int> &v)
{
    while (v[v.size() - 1] == 0 && v.size() > 1)
    {
        v.pop_back();
    }
}
void addnit(string a , vector<int> &v)
{
    for (int i = a.length()-1; i >= 0 ; i--)
    {
        if (a[i] =='-') d++;
        else v.push_back(a[i] -'0');
    }
    remove0(v);
}

void print_ans( vector<int> v)
{
    for (int i = v.size() - 1 ; i >= 0 ; i--) cout << v[i] ;
}

void cong ( vector<int> v1 , vector<int> v2 , vector<int> &v3 )
{
    v3.clear();
    int l = v1.size() > v2.size() ? v1.size() : v2.size();
    v1.resize(l) , v2.resize(l);
    int nho = 0 , t ;
    for (int i = 0 ; i < l ; i++)
    {
        t = v1[i] + v2[i] + nho;
        v3.push_back( t % 10 );
        nho = t / 10;
    }
    if (nho > 0 ) v3.push_back(t);
}

// v1 > v2
void tru ( vector<int> v1 , vector<int> v2 , vector<int> &v3 )
{
    v3.clear();
    int l = v1.size();
    v2.resize(l);
    int nho = 0 ;
    for (int i = 0 ; i < l ; i++)
    {
        if ( v1[i] < v2[i] + nho )
        {
            v3.push_back(v1[i] - v2[i] - nho + 10);
            nho = 1;
        }
        else 
        {
            v3.push_back(v1[i] - v2[i] - nho);
            nho = 0;
        }
        remove0(v3);
    }
}
int main()
{
        int ds1 = 0 , ds2 = 0;
        giuncute;
        balabalo;
        cin >> s1 >> s2;
        if (s1[0] =='-') ds1 = 1;
        if (s2[0] =='-') ds2 = 1;
        addnit( s1 , v1);
        addnit( s2 , v2);
        //print_ans(v1) ; cout << endl;
        //print_ans(v2) ; cout << endl;
        if ( d == 2) 
        {
            cong( v1 , v2 , v3);
            cout <<'-';
            print_ans(v3);
        }
        else if (d == 1 )
        {
            if  ( (v1[v1.size() -1 ]) <  (v2[v2.size() -1 ]) )
            {
                    if (ds1 == 1 )
                    {
                        tru(v2 , v1 , v3); 
                        print_ans(v3);
                    }
                    else 
                    {
                        tru(v2 , v1 , v3);
                        cout<<'-';
                        print_ans(v3);
                    }
            }
            else
            {
                if (ds2 == 1)
                {
                    tru(v1 , v2 , v3); 
                    print_ans(v3);
                }
                else 
                {
                    tru(v1 , v2 , v3);
                    cout<<'-';
                    print_ans(v3);
                }
            } 
        }
        else 
        {
            cong( v1 , v2 , v3);
            print_ans(v3);
        }       
        return 0;
    
}