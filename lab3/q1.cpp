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
            tail->ptr = newnode;
            tail = newnode;
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
    void rearrange()
    {
        if (head == NULL)
        { // to check whether the list is empty or not if then func end no use...
            return;
        }
        node *oddtemp = new node(0); // just temp node to hold address of first odd node
        node *eventemp = new node(0);  // just temp node to hold address of first even node
        node *curr = head;
        node *eventail = eventemp;
        node *oddtail = oddtemp;

        while (curr != NULL)
        {
            if (curr->data % 2 == 0)
            {
                eventail->ptr = curr;
                eventail = eventail->ptr;
            }
            else
            {
                oddtail->ptr = curr;
                oddtail = oddtail->ptr;
            }
            curr = curr->ptr;
        }
        eventail->ptr = oddtemp->ptr; // using this to join even list tail to odd list head inshort joinig both list
        oddtail->ptr = NULL;
        head = eventemp->ptr; // assigning head
        delete oddtemp;
        delete eventemp;
    }
};
int main()
{
    ll list1;
    int n;
    cout << "enter number of nodes";
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        list1.makelist(arr[i]);
    }
    cout << "original list: ";
    list1.print();
    cout << "arranged list: ";
    list1.rearrange();
    list1.print();
}
