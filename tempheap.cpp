#include<iostream>
#include<cstdlib>
#include<cmath>
#include<iomanip>
using namespace std;
template<class T>
class min_heap
{
	T *h;
	int capacity;
	int curr_size;
	public:
		min_heap(int x)
		{
			curr_size=0;
			//cout<<"in constructor"<<curr_size<<endl;
			capacity=x;
			h=new T[x];
		}
		~min_heap()
		{
			cout<<setw(3)<<"in desturctor"<<endl;
			delete []h;
		}
		void heapify(T x);
		void swap(T &x,T &y);
		void insert(T x);
		void Delete();
		void levelorder(void);
		void min(void);
};
template<class T>
void min_heap<T>::swap(T &x,T &y)
{
	int temp;
	temp=x;
	x=y;
	y=temp;
}

template<class T>	
void min_heap<T>::insert(T x)
{
	curr_size+=1;
	cout<<capacity<<endl;
	cout<<curr_size<<endl;
	if(curr_size>capacity)
	{
		cout<<setw(3)<<"overflow occured"<<endl;
	}
	else
	{
		h[curr_size-1]=x;
		int i=curr_size-1;
		while(i!=0&&h[(i-1)/2]>x)
		{
			swap(h[i],h[(i-1)/2]);
			i=(i-1)/2;
		}
	}
}
template<class T>
void min_heap<T>::heapify(T i)
{
	int l=2*i+1;
	int r=2*i+2;
	int sm=i;
	if(l<curr_size&&h[l]<h[sm])
		sm=l;
	if(r<curr_size&&h[r]<h[sm])
		sm=r;
	if(sm!=i)
	{	
		//cout<<setw(3)<<"before swapping"<<h[i]<<" "<<h[sm];
		swap(h[i],h[sm]);
		//cout<<setw(3)<<"after swapping"<<h[i]<<" "<<h[sm];
		heapify(sm);
	}
}
template<class T>
void min_heap<T>::Delete()
{
	if(curr_size==0)
		cout<<setw(3)<<"underflow occur"<<endl;
	else if(curr_size==1)
	{
		curr_size--;
		cout<<setw(3)<<"heap having only one element in list:"<<h[0]<<endl;
	}
	else
	{
		int x=h[0];
		h[0]=h[curr_size-1];
		curr_size--;
		heapify(0);
		cout<<setw(3)<<"Deleted element from heap in list:"<<x<<endl;
	}
}
template<class T>
void min_heap<T>::levelorder()
{
	int x=ceil(log2(curr_size));
	int i=0;
	for(int j=0;j<x;j++)
	{	cout<<setw(3)<<"level="<<j<<endl;
		int x=pow(2,j); 
		int c=0;
		do{
		cout<<setw(5)<<"h["<<i<<"]="<<h[i]<<" ";
		i++;
		c++;
		}while(c<x&&i<curr_size);
		cout<<endl;
	}
	//cout<<h[9]<<" "<<h[4]<<endl;
}
template<class T>
void min_heap<T>::min()
{
	cout<<setw(5)<<"minmum is"<<h[0]<<endl;
}


int main()
{	
	cout<<"Enter the size of element to be inserted in heap:";
	int x;
	cin>>x;
	min_heap<int> a(x);
	int i=0;
	//srand(time(0));
	while(i<x)
	{	
		int y;
		cin>>y;
		//int y=rand()%20;
		a.insert(y);
		i++;
	}
	cout<<"different choices for methods"<<endl;
	cout<<"1 for levelorder traversal:"<<endl;
	cout<<"2 for delete operation for minimum element "<<endl;
	
	int ch,y;
	
	do{
		cout<<"Enter your choice for ur operation"<<endl;
		cin>>ch;
		if(ch==1)
			a.levelorder();
		else if(ch==2)
			a.Delete();
		
		cout<<"enter 1 if u want to perform more operation:";
		cin>>y;
	}while(y==1);
	
}
