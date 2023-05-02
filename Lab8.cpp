#include <iostream>
using namespace std;


void heapify(int arr[], int n, int root)
{
    int max = root; 
    int left = 2*root + 1; 
    int right = 2*root + 2; 


    if (left < n && arr[left] > arr[max])
        max = left;

    if (right < n && arr[right] > arr[max])
        max = right;

    if (max != root)
    {
        swap(arr[root], arr[max]);

        heapify(arr, n, max);
    }
}

void heapSort(int arr[], int n)
{
    for (int i =( n / 2) - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i=n-1; i>=0; i--)
    {
        swap(arr[0], arr[i]);

    
        heapify(arr, i, 0);
    }
}

void displayArray(int arr[], int n)
{
    for (int i=0; i<n; ++i)
        cout << arr[i] << " ";
    cout << "\n";
}


int main()
{
   int heap_arr[] = {4,17,3,12,9,6};
   int n = sizeof(heap_arr)/sizeof(heap_arr[0]);
   cout<<"Input array"<<endl;
   displayArray(heap_arr,n);
  
   heapSort(heap_arr, n);
  
   cout << "Sorted array"<<endl;
   displayArray(heap_arr, n);
}
