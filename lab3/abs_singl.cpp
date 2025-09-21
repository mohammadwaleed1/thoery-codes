#include <iostream>
using namespace std;
class ll;

class node{ // node class
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
class absfunction{
    protected:
    virtual void insert(int val,int pos)=0;
   // virtual void popf()=0;
    virtual void reverse()=0;
};
class ll: protected absfunction{// list class
private:
    node *head;
    node *tail;

public:
    ll()
    {
        head = NULL;
        tail = NULL;
    }

    void makelist(int val)// using this func to add value to linked list.
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
    void insert(int val,int pos)override{
        node*newnode= new node(val);
        node *temp=head;
        for(int i=0;i<pos-1;i++){
            temp=temp->ptr;
        }
        newnode->ptr=temp->ptr;
        temp->ptr=newnode;
    }
    // void popend(){
    //     node*temp=head;
    //     while(temp->ptr->ptr!=NULL){
    //         temp=temp->ptr;
    //     }
    //     delete temp->ptr;
    //     temp->ptr=NULL;
    //     tail=temp;
    //     // delete tail;
    //     // tail=temp;
    // }
    // void popmid(int pos){
    //     node*temp=head;
    //     node*curr;
    //     for(int i=0;i<pos-1;i++){
    //         temp=temp->ptr;
    //         curr=temp->ptr;
    //     }
    //     temp->ptr=curr->ptr;
    //     delete curr;
    // }
    // void popf()override{
    //     node*temp=head;
    //     temp=temp->ptr;
    //     delete head;
    //     head=temp;
    // }
    void reverse()override{
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
        temp->ptr=curr->ptr; //making connection with the node after the node getting removed
        delete curr;
    }
};
int main()
{
    ll list1;
    list1.makelist(1);
    list1.makelist(2);
    list1.makelist(3);
    list1.makelist(4);
    cout << "original list: ";
    list1.print();
    list1.deletenode(3);
    list1.print();
   
//    ;//list1.reverse();
//    list1.insert(5,2);
//    list1.print()
   
    

}
