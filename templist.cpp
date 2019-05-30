#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ull float

class node{
  public:
     node* link;
     ull data;
};

template <typename T>
class linkedlist{
  public:
     node* head;

     linkedlist(){
        head = NULL;
     }
    
     void insert(ull data){
        node* temp = new node;
        temp->data = data;
        temp->link = head;
        head = temp;
     }
     
     void print(){
        node* temp = head;
        while(temp->link!=NULL){
            cout<<temp->data<<" ";
            temp=temp->link;
        }
        cout<<endl;
     }  
     
     void search(ull value){
        ull pos = 0;
        node* temp = head;
        while(temp->link!=NULL){
           if(temp->data==value){
              pos=1;
           }
           temp = temp->link;
        }
        if(pos==1)
        cout<<"element present"<<endl;
        
        else
        cout<<"not present"<<endl;
     }

     void DELETE(){
        if(head==NULL){
              return;
          }
          node* temp;
          temp=head;
          head=head->link;
          delete(temp);
          cout<<"head deleted"<<endl;       
     }
     
};

int main(){
   
   linkedlist<ull> l;
   ull choice,data;
   cout<<"enter choice 1.insert 2.search 3.printlist 4.delete";
   cin>>choice;
   while(choice!=-1){
       if(choice==1){
          cout<<"enter data:";
          cin>>data;
          l.insert(data);
       }
       else if (choice==2){
          cout<<"enter value u want to search:";
          cin>>data;
          l.search(data);
       }
       else if(choice==3){
          l.print();
       }
       else if(choice==4){
          l.DELETE();
       }
       cout<<"enter next choice:";
       cin>>choice;
   }
   
   return 0;
}