#include<bits./stdc++.h>
using namespace std;

class node{
    public:
    node*next;
    string key;
    string meaning;
    node(string k, string m){
        this->key = k;
        this->meaning = m;
        this->next = NULL;
    }
    friend class hashclass;
};



class hashclass{
    public:
    int size;
    node **arr;
    hashclass(int n){
        this->size = n;
        this->arr = new node *[size];
        for (int i = 0;i<size;i++){
            arr[i] = NULL;
        }
    }
    int hashcode(string s){
        unsigned int val = 0;
        for (int i = 0;i<s.length();i++){
            val = val + (s[i] - 'a' + 1) * pow(32, i);
        }

        return val % size;
    }
    void insert(string k, string m){
        int h = hashcode(k);
        node*temp = new node(k,m);
        if(arr[h]==NULL){
            arr[h] = temp;
        }
        else{
            temp->next = arr[h];
            arr[h] = temp;
        }
    }

    void find(string s){
        int h = hashcode(s);
        if(arr[h]->key==s){
            cout<<"\nKey is present !!! "<<endl;
        }
        else{
            node *temp = arr[h];
            while(temp!=NULL){
                if(temp->key==s){
                    cout << "\nKey is present !!! " << endl;
                }
               
                temp = temp->next;
            }
            cout << "\nKey is not present !!! " << endl;
        }
    }


    void print(){
        int n = 5;
        cout << "\nDictionary : " << endl;
        for (int i = 0; i < size;i++){
            cout << i << " : ";
            if(arr[i]==NULL){
                cout << setw(n) << " : "
                     << " - " << setw(n) << "  : " << endl;
            }
            else{
                cout << setw(n) << arr[i]->key << " -> " << arr[i]->meaning;
                node *temp = arr[i]->next;
                while(temp!=NULL){
                    cout<< "----> ";
                    cout << setw(n) << temp->key << " : " << setw(n) << temp->meaning ;
                    temp = temp->next;
                }

             
            }
               cout << "\n --------------------------------- " << endl;
        }
    }

    void deletee(string s){
        int h = hashcode(s);
        if(arr[h]->key == s){
               arr[h] = NULL;
               delete arr[h];
        }
        else{
               node *temp = arr[h];
               while(temp->next->key!=s){
                temp = temp->next;
               }
               node *store = temp->next->next;
               delete temp->next;
               temp->next = store;
        }

    }

};


int main(){
        hashclass obj(10);
        obj.insert("ram" ," site");
        obj.insert("sham" ,"kindfg");
        obj.insert("kingf" ,"uio");
        obj.insert("om" ,"get");
        obj.insert("sinw" ,"tre");

        obj.print();
        obj.deletee("kingf");
        cout<<endl;
        obj.print();
}