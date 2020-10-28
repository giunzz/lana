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

int getlength( giun * head)
{
    int length  = 0 ;
    while (head != NULL) length++;
    return length; 
}

bool xoa (giun* &head , int index)
{
    int length = getlength(head);
    giun * tmp = head;
    if (index > length || length == 0 ) return false;
    if (index == 1)
    {
        head = head -> next;
        return true;
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
    ios_base::sync_with_stdio(0) , cin.tie(0);
    freopen("giun.inp", "r", stdin);
    freopen("giun.out", "w", stdout);

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