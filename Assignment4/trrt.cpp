#include<iostream>
#include<string.h>
using namespace std;


class hashing{
public:
	long long int key;
	char name[20];
	friend class hashclass;
};

class hashclass{
public:
	hashing h[10];
	hashclass(){
		for(int i=0;i<10;i++){
			h[i].key = -1;
			strcpy(h[i].name, "NULL");
		}
	}

	void insert_with(){

		char ans,n[10],ntemp[10];
		        long k,temp;
		        int v, hi, cnt = 0, flag = 0, i;
		        do{
		            if(cnt>10){
		                cout<<"hashTable is full"<<endl;
		                break;
		            }
		            cout<<"enter a telephone number"<<endl;
		            cin>>k;
		            cout<<"enter client name"<<endl;
		            cin>>n;
		            hi = k%10;
		            if(h[hi].key ==-1){
		                h[hi].key = k;
		                strcpy(h[hi].name,n);
		            }
		            else{
		                if(h[hi].key %10 !=hi){
		                    temp = h[hi].key;
		                    strcpy(ntemp,h[hi].name);
		                    h[hi].key = k;
		                    strcpy(h[hi].name,n);
		                    for(int i=hi+1;i<10;i++){
		                        if(h[i].key==-1){
		                            h[i].key = temp;
		                            strcpy(h[i].name,ntemp);
		                            flag =1;
		                            break;
		                        }
		                    }
		                    for(int i=0;i<hi &&flag==0;i++){
		                        if(h[i].key==-1){
		                            h[i].key = temp;
		                            strcpy(h[i].name,ntemp);
		                            flag =1 ;
		                            break;
		                        }
		                    }
		                }
		                else{
		                    for(int i =hi+1;i<10 &&flag==0;i++){
		                        if(h[i].key ==-1){
		                            h[i].key = k;
		                            strcpy(h[i].name,n);
		                            flag =1;
		                            break;
		                        }
		                    }

		                    for(int i=0;i<hi && flag==0;i++){
		                        if(h[i].key ==-1){
		                            h[i].key = k;
		                            strcpy(h[i].name,n);
		                            flag =1;
		                            break;
		                        }
		                    }

		                }
		            }

		            flag =0;
		            cnt++;
		            cout<<"\nDo you want to insert more keys"<<endl;
		            cin>>ans;
		        }while(ans=='y');
		    }




	void insert_without(){
		 int k,flag;
		        char n[10];
		        cout<<"Enter key to insert"<<endl;
		        cin>>k;
		        cout<<"Enter name to be assigned"<<endl;
		        cin>>n;
		        int hi = k%10;
		        if(h[hi].key==-1){
		            h[hi].key = k;
		            strcpy(h[hi].name,n);
		        }
		        else{
		                for(int i=hi+1;i<10;i++){
		                    if(h[i].key==-1){
		                        h[i].key =k;
		                        strcpy(h[i].name,n);
		                        flag =1;
		                        break;
		                    }
		                }

		                  for(int i=0;i<hi&&flag==0;i++){
		                    if(h[i].key==-1){
		                        h[i].key =k;
		                        strcpy(h[i].name,n);
		                        flag =1;
		                        break;
		                    }
		                }



		        }
		        flag = 0;

	}


		    int search(long long int k){
		        int i;
		        for(i=0;i<10;i++){
		            if(h[i].key==k){
		                cout<<"key is found after"<< i <<"Comparisons..."<<endl;

		                return i;
		            }
		        }
		        if(i==10){
		            return -1;
		        }

	}

		    int del(long k){
		          int index = search(k);
		          if(index==-1){
		              cout<<"key not found"<<endl;
		          }
		          else{
		              h[index].key = -1;
		              strcpy(h[index].name , "NULL");
		              cout<<"\n key is deleted Successfully"<<endl;
		          }

		      }



	void display(){
		cout<<"\n\th[x]"<<"\n\t\t Key "<<"\t\t"<<"Name"<<endl;
		for(int i=0;i<10;i++){
			cout<<"\n\th["<<i<<"]\t"<<h[i].key<<"\t\t"<<h[i].name<<endl;
		}
	}
};

int main(){
	  long long int ch,index,choice;
	   long  long int k;
	    char ans;
	    hashclass obj;
	    do{
	        cout<<"1. Enter 1 for With Replacement"<<endl;
	        cout<<"2. Enter 2 for Without Replacement"<<endl;
	        cout<<"3. Break" <<endl;
	        cout<<" Enter your Choice "<<endl;
	        cin>>choice;
	        switch(choice){
	        case 1:
	        	do{
	        		cout<<"\n ****** MENU FOR WITH REPLACEMENT"<<endl;
	        		cout<<"1. Insert(with Replacement) "<<endl;
	        		cout<<"2. Display (With Replacement)"<<endl;
	        		cout<<"3. Delete "<<endl;
	        		cout<<"4. Search(comparison) "<<endl;
	        		cout<<"5. Break "<<endl;
	        		cout<<" Enter Your Choice "<<endl;
	        		cin>>ch;
	        		switch(ch){
	        		case 1:
	        			obj.insert_with();
	        			break;
	        		case 2:
	        			obj.display();
	        			break;
	        		case 3:
	        			cout<<"Enter the key do you want to delete"<<endl;
	        			cin>>k;
	        			obj.del(k);
	        			break;
	        		case 4:
	        		cout<<"Enter the key do you want to search"<<endl;
	        		cin>>k;
	        		index = obj.search(k);
	        		if(index==-1){
	        			cout<<"\n Key Not Found"<<endl;
	        		}
	        		break;
	        		case 5:
	        			break;
	        		}
	        		cout<<"Do you Want to Remain in this menu Only"<<endl;
	        		cin>>ans;
	        	}while(ans=='y');

	        	break;
	        case 2:
	        	do{
	        		cout<<"\n********MENU FOR WITHOUT REPLACEMENT "<<endl;

	        		cout<<"1. Insert"<<endl;
	        		cout<<"2. Display "<<endl;
	        		cout<<"3. Delete "<<endl;
	        	    cout<<"4. Search(comparison) "<<endl;
	        		cout<<"5. Break "<<endl;
	        		cout<<" Enter Your Choice "<<endl;
	        		cin>>ch;
	        		switch(ch){
	        		case 1:
	        	    obj.insert_without();
	        	    break;
	        		case 2:
	        	    obj.display();
	        		break;
	        		case 3:
	        	    cout<<"Enter the key do you want to delete"<<endl;
	        		cin>>k;
	        	    obj.del(k);
	        		break;
	        	    case 4:
	        	    cout<<"Enter the key do you want to search"<<endl;
	        	    cin>>k;
	        	    index = obj.search(k);
	        		if(index==-1){
	        		cout<<"\n Key Not Found"<<endl;
	        		}
	        		break;
	        	    case 5:
	        		break;
	        		}
	        		cout<<"Do you Want to Remain in this menu Only"<<endl;
	        		cin>>ans;
	        		}while(ans=='y');
	        		break;
	        }


	    }while(true);

}