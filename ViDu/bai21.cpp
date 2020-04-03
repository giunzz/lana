/*
Bài 21: Cho xâu S có N ký tự chữ số. Hãy xóa đi K ký tự để xâu còn lại biểu diễn một số bé nhất.
Ví dụ: S='869357495356872', K=9 thì xâu còn lại là S='335672'
Input
+Dòng đầu tiên chứa xâu S
+ Dòng thứ 2 chứa số k 
Ouput: Xâu tìm được
*/

/*#include<bits/stdc++.h>
using namespace std;
const string file = "bai21";
#define balabolo(a) freopen((a + ".inp").c_str(), "r", stdin) ,freopen((a + ".out").c_str(), "w", stdout)
#define giuncute ios_base::sync_with_stdio(0) , cin.tie(0)

int main()
{
    string st;
    int k , xoa = 1 , dem = 0;
    giuncute;
    balabolo(file);
    cin >> st >> k;
    while ( dem != k)
    {
    for (unsigned int j = 0 ; j <= st.length(); j++)
    {
            if ( st[j] > st[j+1] ) 
            {
                st.erase( j , 1 );
                xoa = 0;
                dem++;
                break;
            }
        }

    }
    if (xoa == 1) st.erase(st.length() ,1); 
    cout << st ;
    return 0;
}*/

#include<bits/stdc++.h>
using namespace std;
const string file = "bai21";
#define balabolo(a) freopen((a + ".inp").c_str(), "r", stdin) ,freopen((a + ".out").c_str(), "w", stdout)
#define giuncute ios_base::sync_with_stdio(0) , cin.tie(0)

int main()
{
    string st , ans;
    char mi ; 
    int k , vt ;
    giuncute;
    balabolo(file);
    cin >> st >> k;
    mi = st[0] , vt = 0;
    k = st.length() - k;
    while ( !(st.empty() || !k))
    {
        for (int i = 0 ; i < (int) st.length() - k + 1 ; i++)
       {
           if ( mi > st[i] ) mi = st[i] , vt =  i;
       }
       ans.push_back(mi) , st = st.substr(vt+1);
       --k, mi = 'Z';
    }
    cout << ans;
    return 0;
}



