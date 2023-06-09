#include <iostream>
#include <fstream>
#include<string>
#include<cstring>
using namespace std;

class Student
{
    int rollno;
    char name[10];
    char div[5];
    char address[10];
    friend class Database;

public:
    void input()
    {
        cout << "Enter the roll no. of student : ";
        cin >> rollno;
        cout << "Enter the name of student : ";
        cin >> name;
        cout << "Enter divison : ";
        cin >> div;
        cout << "Enter the address : ";
        cin >> address;
    }

    void show(){
        cout<<rollno<<"\t"<<name<<"\t"<<div<<"\t"<<address<<endl;
    }

    void modification(){
        cout<<"Enter the new name : "; cin>>name;
        cout<<"Enter the new divison : "; cin>>div;
        cout<<"Enter new address : "; cin>>address;

    }
};

class Database
{
    char Fname[20];
public:
    Database(char F[])
    {
        strcpy(Fname,F);
        fstream File;
        File.open(Fname);
    }

    void add(int n){
        ofstream File;
            Student s;
            File.open(Fname,ios::app);
        for(int i=0; i<n; i++){
            s.input();
            File.write((char*)&s,(sizeof(s)));
            
        }
        File.close();
    }

    void display(){
        ifstream File;
        Student s;
        File.open(Fname,ios::in);
        while(File.read((char*)&s,(sizeof(s)))){
            s.show();   
            cout<<endl;
        }
        File.close();
    }

    void dele(int rn){
        ifstream File1;
        ofstream File2;
        int flag=0;
        File1.open(Fname,ios::in);
        File2.open("temp.txt",ios::out);
        Student s;
        while(File1.read((char*) &s,(sizeof(s)))){
            if(s.rollno!=rn){
               File2.write((char*)&s,(sizeof(s))); 
            }
            else if(s.rollno==rn){
                flag=1;
            }
        }
        if(flag==0){
            cout<<"Roll no is not present "<<endl;
        }
        File1.close();
        File2.close();
        remove(Fname);
        rename("temp.txt",Fname);
    }

    void modify(int rn){
     ifstream File1;
        ofstream File2;
        int flag=0;
        File1.open(Fname,ios::in);
        File2.open("temp.txt",ios::out);
        Student s;
        while(File1.read((char*)&s,(sizeof(s)))){
            if(s.rollno==rn){
                cout<<"Enter the new data : "<<endl;
                s.modification();
                flag=1;
            }
             File2.write((char*)&s,(sizeof(s))); 
        }
        if(flag==0){
            cout<<"Roll no is not present "<<endl;
        }
        File1.close();
        File2.close();
        remove(Fname);
        rename("temp.txt",Fname);
    }

    void Search(int rn){
      ifstream File;
        int flag=0;
        File.open(Fname,ios::in);
        Student s;
        while(File.read((char*)&s,(sizeof(s)))){
            if(s.rollno==rn){
                cout<<"Record Present in databse"<<endl;
                s.show();
                flag=1;
            } 
        }
        if(flag==0){
            cout<<"Record is not present "<<endl;
        }
        
    }
};

int main()
{
    char fname[20];
    cout << "Enter the name of file : ";
    cin >> fname;
    Database d(fname);
    int n;
    while(true){
        cout<<"Choose the following "<<endl;
        cout<<"1. Add student info"<<endl;
        cout<<"2. Delete student info"<<endl;
        cout<<"3. Modify student info"<<endl;
        cout<<"4. Search record"<<endl;
        cout<<"5. Display data"<<endl;
        cout<<"6. Exit"<<endl;
        int opt;
        cout<<"Enter the option :"; cin>>opt;
        switch (opt)
        {
        case 1:
            cout<<"Enter the no. of students : "; cin>>n;
            d.add(n);
            cout<<"Information added successfully"<<endl;
            cout<<endl;
            break;
        case 2:
            cout<<"Enter the Roll no. of student : "; cin>>n;
            d.dele(n);
            cout<<"Information deleted successfully"<<endl;
            cout<<endl;
            break;
        case 3:
            cout<<"Enter the Roll no. of student : "; cin>>n;
            d.modify(n);
            cout<<"Information modified successfully"<<endl;
            cout<<endl;
            break;
        case 4:
            cout<<"Enter the Roll no. of student : "; cin>>n;
            d.Search(n);
            cout<<endl;
            break;
        case 5:
            d.display();
            cout<<endl;
            break;
        case 6:
            return 0;
        }
    }
}