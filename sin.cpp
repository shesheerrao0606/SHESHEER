#include<iostream>
#include<iomanip>
#include<math.h>

using namespace std;

 void fun1(){

 float i,j,k;


for(i=0;i<=6.28;i=(i+0.1))
{
	j=20*sin(i);
	
	if(j>=0)
	{
	cout<<setw(36)<<"|";
	for(k=36;k<=36+j;k++)
	{	
	cout<<"*";
	}
	cout<<endl;
	}
	else
	{
	cout<<setw(36+j);
	for(k=36+j;k<36;k++)
	{
	cout<<"*";
	}
	cout<<"|";
	cout<<endl;
	}
}
}

void fun2(){

 float i,j,k;


for(i=0;i<=6.28;i=(i+0.1))
{
	j=20*cos(i);
	
	if(j>=0)
	{
	cout<<setw(36)<<"|";
	for(k=36;k<=36+j;k++)
	{	
	cout<<"*";
	}
	cout<<endl;
	}
	else
	{
	cout<<setw(36+j);
	for(k=36+j;k<36;k++)
	{
	cout<<"*";
	}
	cout<<"|";
	cout<<endl;
	}
}
}

int main(){
 int n,m;

cout<<"Enter no of loops:";
cin>>n;
cout<<"press 1.sin \n 2.cos:";
cin>>m;
if(m==1)
	{
	while(n--)
	{
       fun1();
	}
	}
else
	{
	while(n--)
	{
	fun2();
	}
	}

return 0;
}

