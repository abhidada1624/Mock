#include<bits/stdc++.h>
using namespace std;

class heap{
    public:
    heap(){}

    void heapify(int arr[],int n,int i){
        int large = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        if(n>left && arr[left]>arr[large]){
            large = left;
        }
        if(n>right && arr[right]>arr[large]){
            large = right;
        }
        if(large!=i){
            swap(arr[i], arr[large]);
            heapify(arr, n, large);
        }
    }

    void heapsort(int arr[],int n){
        for (int i = n / 2 - 1; i >= 0;i--){
            heapify(arr, n, i);
        }
        for (int i = n - 1; i >= 0;i--){
            swap(arr[0], arr[i]);
            heapify(arr, i, 0);
        }
    }

    void print(int arr[],int n){
        for (int i = 0; i < 5;i++){
            cout << arr[i] << " ";
        }
    }

    void deleteRoot(int arr[], int n)
{
    // Get the last element
    int lastElement = arr[n - 1];
 
    // Replace root with last element
    arr[0] = lastElement;
 
    // Decrease size of heap by 1
    int k = n - 1;
    n = k;
    // heapify the root node
    heapify(arr, n, 0);
}
};

int main(){
    heap obj;
    int arr[5] = {23, 11, 5, 44, 78};
    obj.print(arr, 5);
    cout << endl;
    obj.heapsort(arr, 5);
    obj.print(arr, 5);
    obj.deleteRoot(arr, 5);
    cout << endl;
    obj.print(arr, 4);
    return 0;
}