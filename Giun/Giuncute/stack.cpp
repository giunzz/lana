#include<iostream>
using namespace std;

struct giun
{
    int data;
    giun* next; 
};

void themvao(giun* &head , int val)
{   
    giun* a = new giun();
    a -> data = val;
    a -> next = NULL;
    if (head == NULL) head = a;
    else 
    {
        giun* b = head;
        while (b-> next != NULL)
        {
            b = b -> next;
        }
        b-> next = a;
        
    }
}

void ra(giun * head)
{
    giun* b = head;
    while (b != NULL)
    {
        cout << b-> next << " " << b -> data << endl;
        b = b -> next;
    }
}

int n ;
int main()
{
    giun* r = NULL;
    cin >> n ;   
    int num;
    for (int i = 1 ; i <= n ; i++)
    {
        cin >> num;
        themvao(r,num);
    }
    ra(r);
}