#include<bits/stdc++.h>
using namespace std;
class obj{
    public:
    int wt;
    int rt;
    obj(){
        this->wt = -1;
        this->rt = -1;
    }

    friend class obst;
};
class obst{
    public:
     public:
    int *key;
    int*freq;
    int size;
    obst(int d){
        this->size = d;
        this->freq = new int[size];
        this->key = new int[size];
    }
    obst(){}
        obj arr[50][50];

        void getelements(){
        cout << "Enter keys in sorted order : " << endl;
        for (int i = 0; i < size;i++){
            cout << "\nEnter key : " << endl;
            cin >> key[i];
            cout << "\nEnter its frequency : " << endl;
            cin >> freq[i];
        }
    }

        int freqsum(int i,int j,int f[]){
        int sum = 0;
        for (int k = i; k <= j;k++){
            sum += f[k];
        }
        return sum;
        }

        int cost(int i, int j , int f[]){
            if(i>j){
            return 0;
            }
            if(i==j){
            arr[i][j].wt = f[i];
            arr[i][j].rt = i;
            }
            if(arr[i][j].wt!=-1){
            return arr[i][j].wt;
            }

            int result = 9999;
            int weight = freqsum(i, j, freq);
            int  resultroot = 0;
            for (int k = i; k <= j;k++){
            int m = cost(i, k - 1, freq) + cost(k + 1, j, freq);
            if(m<result){
                result = m;
                resultroot = k;
            }
            }

            arr[i][j].rt = resultroot;
            arr[i][j].wt = result + weight;
            return arr[i][j].wt;
        }

        void optimalcost(){
            int ans = cost(0, size - 1, freq);
            cout << "\nThe optimal cost of the tree is : " << ans<<endl;
        }
};

int main(){
    int n;
    cout << "\nEnter how many elements ? " << endl;
    cin >> n;
    obst obje(n);
    obje.getelements();
    obje.optimalcost();
}