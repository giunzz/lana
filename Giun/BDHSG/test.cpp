#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

int main()
{
    string S, tmp;
    getline(cin, S);

    // Write an answer using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;
    vector<string>ans;
    for(char&c:S){
        if(c==' ') {
            ans.push_back(tmp);
            tmp.clear();
        }
        else{
            tmp.push_back(c);
        }
    }
    reverse(ans.begin(),ans.end());
    for(string&x:ans)cout<<x<<" ";
}