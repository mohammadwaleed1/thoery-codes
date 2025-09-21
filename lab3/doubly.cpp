#include <iostream>
using namespace std;
class ll;
class node // node class
{
private:
    int data;
    node *ptr;
    node *ptr2;

public:
    node(int val)
    {
        data = val;
        ptr = NULL;
        ptr2=NULL;
    }
    friend class doublyll;
};
class doublyll // list class
{
private:
    node *head;
    node *tail;

public:
    doublyll()
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
            tail->ptr = newnode;
            newnode->ptr2=tail;
            tail = newnode;
        }
    }
    void addnotefront(int val){
        node* newnode=new node(val);
        if(head==NULL){
            head=tail=newnode;
        }
        newnode->ptr=head;
        head->ptr2=newnode;
        head=newnode;
    }
      void addnoteend(int val){
        node* newnode=new node(val);
        if(head==NULL){
            head=tail=newnode;
            return;
        }
        tail->ptr=newnode;
        newnode->ptr2=tail;
        tail=newnode;
    }
    void addonindex(int val,int pos){//before the pos
        node* newnode=new node(val);
        node*temp=head;
        if(head==NULL){
            head=tail=newnode;
            return;
        }
        for(int i=0;i<pos-1;i++){
            temp=temp->ptr;
        }
        newnode->ptr=temp->ptr;;
        newnode->ptr2=temp;
        temp->ptr->ptr2=newnode;
        temp->ptr=newnode;

    }
    void addonindex2(int val,int pos){//after the pos
        node* newnode=new node(val);
        node*temp=head;
        if(head==NULL){
            head=tail=newnode;
            return;
        }
        for(int i=0;i<pos;i++){
            temp=temp->ptr;
        }
        newnode->ptr=temp->ptr;;
        newnode->ptr2=temp;
        temp->ptr->ptr2=newnode;
        temp->ptr=newnode;

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

};
int main()
{
doublyll ll;
ll.makelist(1);
ll.makelist(2);
ll.makelist(3);
ll.makelist(4);
ll.addnoteend(5);
ll.print();
// ll.addonindex2(6,2);
// ll.print();
    

};
