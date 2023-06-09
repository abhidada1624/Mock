#include<iostream>
#include<math.h>
#include<iomanip>
using namespace std;

class node{
    public:
        node *link;
        string key;
        string meaning;
        node(string k,string m){
            this->key =k;
            this->meaning = m;
            this->link = NULL;
        }
        friend class hashh;
};

class hashh{
    public:
        node **arr;
        int size;
        hashh(int d){
            this->size=d;
            this->arr = new node *[size];
            for (int i = 0; i < size;i++){
                arr[i] = NULL;
            }
        }

        int hashfunction(string s){
            int t = 0;
            for (int i = 0; i < s.length();i++){
                t = t + (s[i] -'a'+1) * pow(32, i);
            }
            return t % size;
        }

        void insert(string s,string m){
            int k = hashfunction(s);
            node *temp = new node(s, m);
            if(arr[k]==NULL){
                arr[k] = temp;
            }
            else{
                temp->link = arr[k];
                arr[k] = temp;
            }
        }

        void deletion(string s){
            int h = hashfunction(s);
            if(arr[h]->key==s){
                node *store = arr[h]->link;
                delete arr[h];
                arr[h] = store;
            }
            else{
                node *temp = arr[h];
                while(temp->link->key!=s){
                    temp = temp->link;
                }
                node *Store = temp->link->link;
                delete temp->link;
                temp->link = Store;
            }
        }

        void find(string k){
        int h=hashfunction(k);
        if(arr[h]->key==k){
            cout<<"Key is present"<<endl;
        }
        else{
            node*temp=arr[h];
            while(temp!=NULL){
                if(temp->key==k){
                    cout<<"Key is present"<<endl;
                    return;
                }
                temp=temp->link;
            }
            cout<<"Key is not present"<<endl;
        }
    }

    void print(){
        int n = 5;
        for (int i = 0; i < size;i++){
              if(arr[i]==NULL){
                cout << i;
                cout << setw(n) << "-"
                     << " : " << setw(n) << "-" << endl;
           }
           else{
            cout << arr[i]->key << setw(n) << arr[i]->meaning << endl;
            node *temp = arr[i]->link;
            while (temp!=NULL)
            {
                cout << "--->";
                cout << temp->key << setw(n) << temp->meaning << endl;
                temp = temp->link;
            }
           }
            cout << "-----------------------------------------------" << endl;
        }
    }
};



int main(){
    int opt,n;
    hashh obj(10);
    int ch = -1;
//     cout<<"Enter the number of keys : ";cin>>n;
//    for(int i=0; i<n; i++){
//     string key;
//     cout<<"Enter key no."<<i+1<<"     : ";cin>>key;
//     string value;
//     cout<<"Enter value of key : ";cin>>value;
//     obj.insert(key,value);
//    }
    while(true){
    cout<<"Choose the option "<<endl;
    cout<<"1.Print Dictionary"<<endl;
    cout<<"2.Insert new key"<<endl;
    cout<<"3.Find key"<<endl;
    cout<<"4.Delete a key"<<endl;
    cout<<"5.Exit"<<endl;
    cout<<"Enter option : "; cin>>opt;
    cout<<endl;
    string k,v;
    switch (opt)
    {
    case 1:
        obj.print();
        cout<<endl;
        break;
    case 2:
        cout<<"Enter key   : ";cin>>k;
        cout<<"Enter value : ";cin>>v;
        obj.insert(k,v);
        cout<<"Key Inserted"<<endl;
        cout<<endl;
        break;
    case 3:
        cout<<"Enter key to find : "; cin>>k;
        obj.find(k);
        cout<<endl;
        break;
    case 4:
        cout<<"Enter key to delete : ";cin>>k;
        obj.deletion(k);
        cout<<endl;
        break;
    case 5:
        return 0;

    }
    cout<<endl;
   }
   
    
}