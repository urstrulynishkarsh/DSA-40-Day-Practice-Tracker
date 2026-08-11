#include<iostream>
#include<vector>
using namespace std;

class Heap{
    public:
    int *arr;
    int capacity;
    int index;

    Heap(int capacity)
    {
        this->capacity=capacity;
        arr=new int[capacity];
        this->index=0;
    }

    void print()
    {
        cout<<"Printing the heap: ";
        for(int i=1;i<=index;i++)
        {
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
    void insert(int value)
    {
        if(index>=capacity-1)
        {
            cout<<"Overflow"<<endl;
            return;
        }
        index=index+1;
        arr[index]=value;
        int i=index;
        while(i>1)
        {
            int parentindex=i/2;
            if(arr[i]>arr[parentindex])
            {
                swap(arr[i],arr[parentindex]);
                i=parentindex;
            }
            else{
                break;
            }
        }
    }
    void deletefromheap()
    {
        if(index==0)
        {
            cout<<"underflow"<<endl;
            return;
        }
        swap(arr[1],arr[index]);
        index--;
        heapify(arr,index,1);
    }

    void heapify(int *arr, int n, int currentindex)
    {
        int i=currentindex;
        int leftindex=2*i;
        int rightindex=2*i+1;
        int largestkaindex=i;

        if(leftindex<=n && arr[leftindex]>arr[largestkaindex])
        {
            largestkaindex=leftindex;
        }
        if(rightindex<=n && arr[rightindex]>arr[largestkaindex])
        {
            largestkaindex=rightindex;
        }
        if(largestkaindex!=i)
        {
            swap(arr[i],arr[largestkaindex]);
            i=largestkaindex;
            heapify(arr,n,i);
        }
    }

    void buildheap(int *arr, int n)
    {
        for(int i=n/2;i>0;i--)
        {
            heapify(arr,n,i);
        }
    }

    void heapsort(int *arr, int n)
    {
        while(n>1)
        {
            swap(arr[1],arr[n]);
            n--;
            heapify(arr,n,1);
        }
    }
};

int main()
{
    Heap h(10);

    h.insert(50);
    h.insert(30);
    h.insert(40);
    h.insert(10);
    h.insert(20);
    h.insert(60);

    cout<<"After insertion:"<<endl;
    h.print();

    h.deletefromheap();
    cout<<"After deletion:"<<endl;
    h.print();

    h.heapsort(h.arr, h.index);

    cout<<"After Heap Sort:"<<endl;
    h.print();


}