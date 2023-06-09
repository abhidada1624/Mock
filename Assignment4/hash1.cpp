#include <iostream>
#include <string.h>
using namespace std;

class hashing
{
public:
    char meaning[10];
    int key;
    friend class hashclass;
};

class hashclass
{
public:
    hashing h[10];
    hashclass()
    {
        for (int i = 0; i < 10; i++)
        {
            h[i].key = -1;
            strcpy(h[i].meaning, "NULL");
        }
    }


    void insert_without(){
        char name[10];
        int k,flag;
        flag = 0;
        cout << "\nEnter key to be inserted  ? " << endl;
        cin>>k;
        cout << "\nEnter name to be assigned ? " << endl;
        cin >> name;
        int hi = k % 10;
        if(h[hi].key==-1){
            h[hi].key = k;
            strcpy(h[hi].meaning, name);
        }
        else{
          
            for (int i = hi + 1; i < 10;i++){
                if(h[i].key==-1){
                h[i].key = k;
                strcpy(h[i].meaning, name);
                flag = 1;
                break;
                }
            }

             for (int i = 0; i < hi && flag==0;i++){
                if(h[i].key==-1){
                    h[i].key = k;
                    strcpy(h[i].meaning, name);
                    flag = 1;
                    break;
                }
            }
            
        }
        flag = 0;
    }


    void insert(){
        int key;
        int temp;
        char n[10];
        char ntemp[10];
        int flag = 0;
        cout << "\nEnter data do you want to insert  ? " << endl;
        cin >> key;
        cout << "\nEnter its meaning ? " << endl;
        cin >> n;

        int hi = key % 10;
        if(h[hi].key==-1){
            h[hi].key = key;
            strcpy(h[hi].meaning, n);
        }
        

        else if(h[hi].key%10!=hi){
            temp = h[hi].key;
            strcpy(ntemp, h[hi].meaning);
            h[hi].key = key;
            strcpy(h[hi].meaning, n);
            for (int i = hi + 1; i < 10 && flag == 0;i++){
                if(h[i].key==-1){
                h[i].key = temp;
                strcpy(h[i].meaning, ntemp);
                flag = 1;
                break;
                }
            }

            for (int i = 0; i < hi && flag == 0;i++){
                if(h[i].key==-1){
                h[i].key = temp;
                strcpy(h[i].meaning, ntemp);
                flag = 1;
                break;
                }
            }
        }

      


    else if(key%10 == hi){
            for (int i = hi + 1; i < 10;i++){
                if(h[i].key==-1){
                    h[i].key = key;
                    strcpy(h[i].meaning, n);
                    flag =1 ;
                    break;
                }
            }

            for (int i = 0; i < hi &&flag==0;i++){
                if(h[i].key==-1){
                    h[i].key = key;
                    strcpy(h[i].meaning, n);
                    flag = 1;
                    break;
                }
            }
        }

        flag = 0;
}



    void print()
    {
        cout << "\t \t KEY"<< "\t"<< "  Meaning" << endl;
        for (int i = 0; i < 10; i++)
        {
            cout << "\n\t  " << "h["<<i<<"]"<<"\t"<< h[i].key << " \t " << h[i].meaning << " ";
        }
    }
};

int main()
{
    hashclass h;
    int cj;
    while(true){
        cout << "1.Enter 1 for insertion 2 for print"<<endl;
        cin >> cj;
if(cj==1){
        h.insert();
}
else{
        h.print();
}
    }
}