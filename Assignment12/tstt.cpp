#include<iostream>
#include<fstream>
using namespace std;
char buffer[40];
class employee{
    public:
 //   char buffer[40];
        string name;
        int empID;
        int location;
        string address;
        employee(){
            this->empID = 0;
            this->location = -1;
            this->address = "\0";
            this->name = "\0";
        }
        friend class hashing;
};

class hashing{
    public:
  //  char buffer[40];
        employee h[10];
        char fname[10];
        fstream filee;
        hashing(){
            for (int i = 0; i < 10;i++){
                h[i].empID = 0;
                h[i].location = -1;
            }
        }
    
    void getfilename(){
            cout << "\nEnter file name" << endl;
            cin >> fname;
    }

    int hashfunction(int key){
            return key % 10;
    }

    void insert(int emp,int loc,string addes,string nam)
    {
            int index = hashfunction(emp);
            if(h[index].empID==-1){
                h[index].empID = emp;
                h[index].location = loc;
                h[index].address = addes;
                h[index].name = nam;
            }
            else{
                bool flag = 0;
                for (int i = index+1; i < 10;i++){
                if(h[i].empID==0){
                h[i].empID = emp;
                h[i].location = loc;
                h[i].address = addes;
                h[i].name = nam;
                flag = 1;
                break;
            }
        }

        for (int j = 0; j < index&&flag==0;j++){
            if(h[j].empID==0){
                h[j].empID = emp;
                h[j].location = loc;
                h[j].address = addes;
                h[j].name = nam;
                flag = 1;
                break;
            }
        }
        flag = 0;
    }
}

    void writefile(){
            filee.open(fname, ios::app);
            int emp, loc;
            string addresss;
            if(!filee){
                cout << "\nError !!!" << endl;
            }
            else{
            int n;
            cout << "\nEnter how many keys ? " << endl;
            cin >> n;
            string s;
            for (int i = 0; i < n;i++){
                cout << "Enter Name ? " << endl;
                cin >> s;
                cout << "Enter employee id :" << endl;
                cin >> emp;
                cout << "Enter address : " << endl;
                cin >> addresss;
                loc = hashfunction(emp);
                insert(emp, filee.tellp(), addresss,s);
                filee << emp << " " << s << " " << addresss << " "<<endl;
            }
        }
        filee.close();
    }

    void showHashtable(){
        for (int i = 0; i < 10;i++){
            cout << i << h[i].name << h[i].address << " " << h[i].empID << " " << h[i].location << " " << endl;
        }
    }

    void deltercord(){
        
        fstream temp;
        temp.open("tmp.txt",ios::out);
        filee.open(fname,ios::in);
        int iid;
        if(!filee){
            cout << "Error" << endl;
            return;
        }
        int flag = 0;
        //int iid;
        cout << "Enter id to delete ? " << endl;
        cin >> iid;
     //   iid = iid % 10;
       // string convert = to_string(iid);
        
            while (!filee.eof()){
            filee.getline(buffer, 40);
            int comp = int(((buffer[0] - 48)*10 + (buffer[1] - 48) ));
            if (comp == iid){
                cout << "Record deleted successfully" << endl;
                flag = 1;
            }
            else{
                temp << buffer << endl;
            }
        }
        filee.close();
        temp.close();
        remove(fname);
        rename("tmp.txt", fname);
    }
};

int main(){
    hashing fil;
    fil.getfilename();
    int ch = -1;
    while(ch){
        cout << "1.write ? " << endl;
        cout << "2.delete ? " << endl;
        cout << "Enter your choice : " << endl;
        cin >> ch;
        switch(ch){
            case 1:fil.writefile();
            break;
            case 2:
            fil.deltercord();
            break;
            default:
            break;
        }
    }
    
    
 //   cout << "\n****** H A S H -- T A B L E--" << endl;
    // fil.showHashtable();
    return 0;
}