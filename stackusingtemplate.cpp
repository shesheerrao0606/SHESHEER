#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ull unsigned long long int 

ull top=0;
ull arr[1000];

template<typename T>
class STACK{
   public:
      void insert(int data){
          arr[top] = data;
          top++;
      }
      void DELETE(){
          top--;
      } 
      void showlist(){
          for(ull i=0;i<top;i++){
             cout<<arr[i]<<" ";
             cout<<endl;
          }
      }
};

int main(){

   STACK<ull> s;
   ull choice,data;
   cout<<"enter choice:1.insert  2.showlist z 3.delete:";
   cin>>choice;
   while(choice!=-1){
      if(choice==1){
         cout<<"enter data:";
         cin>>data;
         s.insert(data);
      }
      else if(choice==2){
         s.showlist();
      }
      else if(choice==3){
         s.DELETE();
      }
      cout<<"enter next choice:";
      cin>>choice;
   }
   return 0;
} 