#include<iostream>
#include<fstream>
#include<bits/stdc++.h>
using namespace std;

class student{
    public:
        char name[10];
        char address[10];
        char div[10];
        int roll;
        student() {}
        void get()
        {
            cout<<"\nEnter student name : "<<endl;
            cin >> name;
            cout << "Enter address : " << endl;
            cin >> address;
            cout << "Enter Division :" << endl;
            cin >> div;
            cout << "Enter Roll number :" << endl;
            cin >> roll;
        }

        void show(){
            cout << name << "  " << address << "  " << div << "  " << roll << "  " << endl;
        }

        void update(){
            cout << "Enter new name ? " << endl;
            cin >> name;
            cout<<"Enter new address ? "<<endl;
            cin >> address;
            cout << "Enter new division ?" << endl;
            cin >> roll;
        }

        friend class database;
};

class database{
    public:
        char fname[20];
        fstream file;
        database(char f[20]) {
            strcpy(fname, f);
            fstream file;
            file.open(fname);
        }
        void writefile(int n)
    {
            student s;
            fstream file;
            file.open(fname, ios::app);
            for(int i=0;i<n;i++){
                s.get();
                file.write((char *)&s, sizeof(s));
            }

            file.close();
    }

    void modification(){
            fstream file;
            student s;
    }
};

int main(){
    
    return 0;
}