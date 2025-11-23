#include<iostream>
using namespace std;
void heapify(int i,int arr[],int n){// descending order use min heap
while (true) {
            int left = 2 * i + 1;
            int right = 2 * i + 2;
            int largest = i;

            // check left child
            if (left < n && arr[left] < arr[largest])
                largest = left;

            // check right child
            if (right < n && arr[right] < arr[largest])
                largest = right;

            // if parent already largest → stop
            if (largest == i)
                break;

            // swap parent with largest child
            int temp = arr[i];
            arr[i] = arr[largest];
            arr[largest] = temp;

            // move down
            i = largest;
        }
}
void heapSort(int arr[],int size)
{
    for(int i=(size/2)-1;i>=0;i--){
        heapify(i,arr,size);
    }
}
int printHeap(int arr[],int size) {
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
void sort(int arr[],int size){
    for(int i=size-1;i>0;i--){
    int temp=arr[0];
    arr[0]=arr[i];
    arr[i]=temp;
    heapify(0,arr,i);
    }
}   
int main(){
    int arr[5]={1,4,2,5,3};
    heapSort(arr,5);
    printHeap(arr,5);
    cout<<endl;
    sort(arr,5);
    printHeap(arr,5);
}