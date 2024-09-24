#include <iostream>
#include <cmath>
#include <set>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class Node{
public:
    int data;
    Node* next;
    Node(int _data)
    {
        data = _data;
        next=nullptr;
    }
};
void Push(Node*& head, int _data)
{
    Node* p = new Node(_data);
    if(head == nullptr)
        head = p;
    else
    {
        p->next=head;
        head = p;
    }
}
void Pop(Node*& head)
{
    Node* nodeToPop =head;
    if(head == nullptr)
        return;
    else
    {
        
        head=nodeToPop->next;
        nodeToPop->next = nullptr;
        cout<<"Pop stack:"<<nodeToPop->data<<endl;
    }
    delete(nodeToPop);
    
}

void Display(Node* head)
{
    
    Node* current=head;
    while(current != nullptr)
    {
        cout<<current->data<<" ";
        current=current->next;
    }
    cout<<endl;
}


int main() {
    Node* head = nullptr;
    Push(head,12);
    Push(head,15);
    Push(head,17);
    Push(head,18);
    Display(head);
    Pop(head);
    Display(head);


    
    return 0;
}