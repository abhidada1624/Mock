#include<iostream>
#include<string>
#include<cmath>
#include<iomanip>
using namespace std;

class node{
    string key;
    string value;
    node* next;
    friend class Dict;
    public:
    node(string s1,string s2){
        this->key=s1;
        this->value=s2;
        this->next=NULL;
    }
};

class Dict{
    int size;
    node**arr;
    public:
    Dict(int n){
        this->size=n;
        this->arr=new node*[size];
        for(int i=0; i<size; i++){
            arr[i]=NULL;
        }
    }

    int hashcode(string s){
        unsigned int hval=0;
        int p=32;
        for(int i=0; i<s.length(); i++){
           hval=(hval+(s[i]-'a'+1)*pow(p,i));
        }
        return hval%size;
    }

    void insert(string k,string v){
        node* newnode=new node(k,v);
        int h=hashcode(k);
        if(arr[h]==NULL){
            arr[h]=newnode;
        }
        else{
            newnode->next=arr[h];
            arr[h]=newnode;
        }
    }

    void deletestr(string k){
        int h=hashcode(k);
        if(arr[h]->key==k){
            node* store=arr[h]->next;
            delete arr[h];
            arr[h]=store;
        }
        else{
            node* temp=arr[h];
            while(temp->next->key!=k)
            {
                temp=temp->next;
            }
            node*store=temp->next->next;
            delete temp->next;
            temp->next=store;
        }
        cout<<"Key deleted succesfully"<<endl;
    }

    void find(string k){
        int h=hashcode(k);
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
                temp=temp->next;
            }
            cout<<"Key is not present"<<endl;
        }
    }

    void print(){
        int n=5;
        cout<<"Dictionary :"<<endl;
        cout<<endl;
        for(int i=0; i<size; i++){
            cout<<i<<"  : ";
           if(arr[i]==NULL){
            cout<<setw(n)<<"-"<<" : "<<setw(n)<<"-"<<endl;
           }
           else{
              cout<<setw(n)<<arr[i]->key<<" : "<<setw(n)<<arr[i]->value;
              node* temp=arr[i]->next;
              while(temp!=NULL){
                cout<<"   -->  ";
               cout<<setw(n)<<temp->key<<" : "<<setw(n)<<temp->value;
               temp=temp->next;
              }
              cout<<endl;
           }
           cout<<"----------------------------------------------------------"<<endl;
        }
    }
};

int main(){
   Dict d(10);
   int n;
   cout<<"Enter the number of keys : ";cin>>n;
   for(int i=0; i<n; i++){
    string key;
    cout<<"Enter key no."<<i+1<<"     : ";cin>>key;
    string value;
    cout<<"Enter value of key : ";cin>>value;
    d.insert(key,value);
   }
   cout<<endl;
   int opt;
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
        d.print();
        cout<<endl;
        break;
    case 2:
        cout<<"Enter key   : ";cin>>k;
        cout<<"Enter value : ";cin>>v;
        d.insert(k,v);
        cout<<"Key Inserted"<<endl;
        cout<<endl;
        break;
    case 3:
        cout<<"Enter key to find : "; cin>>k;
        d.find(k);
        cout<<endl;
        break;
    case 4:
        cout<<"Enter key to delete : ";cin>>k;
        d.deletestr(k);
        cout<<endl;
        break;
    case 5:
        return 0;

    }
    cout<<endl;
   }
}