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
                head->ptr2=NULL;
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
        if(curr->ptr!=NULL){
        curr->ptr->ptr2=temp; //making connection with the node after the node getting removed
        temp->ptr=curr->ptr;
        delete curr;}
        else{
            temp->ptr=NULL;
            temp->ptr2=NULL;
            delete curr;

        }
    }
};
int main()
{
doublyll ll;
ll.makelist(1);
ll.makelist(2);
ll.makelist(3);
ll.makelist(4);
ll.makelist(5);
ll.print();
ll.deletenode(3);
ll.print();

};
