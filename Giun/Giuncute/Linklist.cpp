#include <bits/stdc++.h>
using namespace std;

struct Node{
    int value;
    Node* next;
};

Node* createNode(int data){
    Node* temp = new Node();
    temp -> value = data;
    temp -> next = NULL;
    return temp;
}

void insertNode(int data, Node* &root){
    Node* temp = createNode(data);
    if(root == NULL){
        root = temp;
    }
    else{
        Node* p = root;
        while(p -> next != NULL) p = p -> next;
        p -> next = temp;
    }
}

void printNode(Node* root){
    int k = 0;
    for(Node* p = root; p != NULL; p = p -> next){ 
        cout << "Address " << ++k << ": " << p << endl;
        cout << '\t' << "Data: " << p -> value << endl;
        cout << '\t' << "Next: " << p -> next << endl;
    }
}

int getLength(Node* root){
    int length = 0;
    for(Node* p = root; p != NULL; p = p -> next) ++length;
    return length;
}

int find(Node* root, int index){
    Node* temp = root;
    int length = getLength(root);
    if(length < index) return -1;
    for(int i = 1; i < index; i++) {
        temp = temp -> next;
    }
    return temp -> value;
}

bool delNode(Node* root, int index){
    Node* temp = root;
    int length = getLength(root);
    if(length < index || length == 0) return false;
    int k = 1;
    while(temp -> next -> next != NULL && k != index){
        temp = temp -> next;
    }
    temp -> next = temp -> next -> next;
    return true;
}

int main(){
    freopen("f.inp", "r", stdin);
    freopen("f.out", "w", stdout);
    Node* root = NULL;
    int n, num;
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> num;
        insertNode(num, root);
    }
    printNode(root);
    delNode(root, 4);
    cout << '\n';
    printNode(root);
    // for(int i = 1; i <= n; i++){
    //     cout << find(root, i) << " ";
    // }
    // cout << find(root, 6);
}