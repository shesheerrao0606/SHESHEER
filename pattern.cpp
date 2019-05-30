#include <bits/stdc++.h>
using namespace std;
int main(){

 int n,i,j;
 cout<<"enter the number:";
 cin>>n;
 for(i=1;i<=n;i++){
 cout<<setw(n-i+1)<<setfill('*');
 for(j=1;j<=i;j++){
 cout<<right<<j;
 }
 for(j=1;j<i;j++){
 cout<<left<<j;
 }
 if(i!=n){
 cout<<setw(n-i)<<"*";
 }
 cout<<endl;
 }
 for(i=n;i>=1;i--){
 cout<<setw(n-i+1)<<setfill('*');
 for(j=1;j<=i;j++){
 cout<<right<<j;
 }
 for(j=1;j<i;j++){
 cout<<left<<j;
 }
 if(i!=n){
 cout<<setw(n-i)<<"*";
 }
 cout<<endl;
 }

 return 0;
}