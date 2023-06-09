#include<iostream>
using namespace std;


class heap{
    public:
          int arr[50];
          int n;
          heap(){
              this->n = n;
          }
        void getelements(){  
            cout<<"\nEnter how many elements  ?"<<endl;
            cin >> n;
            for (int i = 0; i < n;i++){
                cout << "\nEnter element " << i + 1 << " : ";
                cin >> arr[i];
            }
        }

        void insert(){
            cout << "\nEnter total number to add  ? " << endl;
            int k;
            cin >> k;
            for (int i = n; i <n+k;i++){
                cout << "Enter : ";
                cin >> arr[i];
            }
            n = n + k;
        }

        void heapify(int arr[],int n , int i){
            int large = i;
            int left = 2 * i + 1;
            int right = 2 * i + 2;
            if(left<n && arr[left] > arr[large]){
                large = left;
            }
            if(right<n && arr[right] > arr[large]){
                large = right;
            }
            if(large!=i){
                swap(arr[i],arr[large]);
                cout << endl;
                heapify(arr, n, large);
            }
        }

        void heapsort(int arr[], int n){
            for (int i = n/2-1;i>=0;i--){
                heapify(arr, n, i);
            }
            for (int i = n - 1; i >= 0;i--){
                swap(arr[0], arr[i]);
                heapify(arr, i, 0);
            }
        }

        void print(int arr[],int n){
            for (int i = 0; i < n;i++){
                cout << arr[i] << " ";
            }
        }

        
};

int main(){
        heap obj;
        obj.getelements();
        obj.heapsort(obj.arr,obj.n);
        obj.print(obj.arr, obj.n);
        obj.insert();
        cout << "\nafter inserting : " << endl;
        obj.heapsort(obj.arr, obj.n);
        obj.print(obj.arr, obj.n);
        
}