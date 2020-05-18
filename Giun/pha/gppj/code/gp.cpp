#include <iostream>
using namespace std;

int main(){
    string comment;
    cout << "Nhap command: ";
    getline(cin, comment);
    string ham = "git add . && git commit -m \"" + comment + "\" && git push -u origin quang";
    system(ham.c_str());
}