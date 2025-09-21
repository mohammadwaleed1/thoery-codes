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
    friend class circularll;
};
class circularll // list class
{
private:
    node *head;
    node *tail;

public:
    circularll()
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
            tail=newnode;
            tail->ptr=head;
        }
    }
    void addnotefront(int val){
        node* newnode=new node(val);
        if(head==NULL){
            head=tail=newnode;
        }
        newnode->ptr=head;
        tail->ptr=newnode;
        head=newnode;
    }
      void addnoteend(int val){
        node* newnode=new node(val);
        if(head==NULL){
            head=tail=newnode;
            return;
        }
        tail->ptr=newnode;
        newnode->ptr=head;
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
        newnode->ptr=temp->ptr;
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
        newnode->ptr=temp->ptr;
        temp->ptr=newnode;

    }
    void print()
    {
        node *temp = head;
        do{
            cout<<temp->data;
            temp=temp->ptr;
        }
        while (temp != head);
        cout<<"back to head ;)";
    }
    void deletenode(int pos){ //deleting start node
        if(head==NULL){ // empty list
            return;
        }
        //case1 if pos is 0 means removing head node
        if(pos==0){
            if(head==tail){ //if it have only 1 node
                delete head;
                head=tail=NULL;
            }
            else{
                node*temp=head;
                head=head->ptr;
                tail->ptr=head;
                delete temp;
            }
            return;
        }
        // case 2 removing on any pos
        node*temp=head;
        node*curr;
        for(int i=0;i<pos-1;i++){
            temp=temp->ptr;
        }
        curr=temp->ptr;
        temp->ptr=temp->ptr->ptr; //making connection with the node after the node getting removed
        delete curr;
    }

};
int main()
{
circularll ll;
ll.makelist(1);
ll.makelist(2);
ll.makelist(3);
ll.makelist(4);
ll.print();
ll.deletenode(3);
ll.print();
    

};
