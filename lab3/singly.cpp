#include <iostream>
using namespace std;
class ll;
class node // node class
{
private:
    int data;
    node *ptr;

public:
    node(int val)
    {
        data = val;
        ptr = NULL;
    }
    friend class ll;
};
class ll // list class
{
private:
    node *head;
    node *tail;

public:
    ll()
    {
        head = NULL;
        tail = NULL;
    }

    void makelist(int val) // using this func to add value to linked list.
    {
        node *newnode = new node(val);
        if (head == NULL) // checking whether the list is empty or not if empty then head point to newnode
        {
            head = newnode;
            tail = newnode;
        }
        else
        {
            newnode->ptr = head;
            head = newnode;
        }
    }
    void print()
    {
        node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " -> ";
            temp = temp->ptr;
        }
        cout << "NULL" << endl;
    }
    void insert(int val,int pos){
        node*newnode= new node(val);
        node *temp=head;
        for(int i=0;i<pos-1;i++){
            temp=temp->ptr;
        }
        newnode->ptr=temp->ptr;
        temp->ptr=newnode;
    }
    void popf(){
        node*temp=head;
        temp=temp->ptr;
        delete head;
        head=temp;
    }
    void reverse(){
        node*pre=NULL;
        node*curr=head;
        node*next;
        while(curr!=NULL){
            next=curr->ptr;
            curr->ptr=pre;
            pre=curr;
            curr=next;
        }
        head=pre;
    }
};
int main()
{
    ll list1;
    list1.makelist(1);
    list1.makelist(2);
    list1.makelist(3);
    cout << "original list: ";
    list1.print();
//    ;//list1.reverse();
//    list1.insert(5,2);
//    list1.print()
   
    

}
