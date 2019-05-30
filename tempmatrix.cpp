

#include<iostream>
#include<cmath>
using namespace std;
template<class t>

//matrix classs
class matrix
{
	public:
		int row,col;
		t **p;
	public:
		matrix(int a=2,int b=2) //constructor
		{
			row=a;
			col=b;
			p=new t*[row];
			for(int i=0;i<row;i++)
				p[i]=new t[col];
		}
		matrix<t> add(matrix<t>);
		matrix<t> sub(matrix<t>);
		matrix<t> mult(matrix<t>);
		matrix<t> operator+(matrix<t>);   //operator overloading
		matrix<t> operator-(matrix<t>);   //operator overloading
		matrix<t> operator*(matrix<t>);	//operator overloading
		void display(); 		 //display of the matrix
		matrix transpose();
		//friend ostream &operator<<(ostream &output,matrix<t> &m);
		//friend istream &operator>>(istream &input,matrix<t> &m);  //operator >> for input a complex

};

template<class t>
//to add two matrix
matrix<t> matrix<t>::add(matrix<t> m3)
{
	matrix<t> m4(m3.row,m3.col);
	for(int i=0;i<2;i++)
	{
		for(int j=0;j<2;j++)
			m4.p[i][j]=p[i][j]+m3.p[i][j];
	}
	return m4;
}


template<class t>
//adding using operator+
matrix<t> matrix<t>::operator+(matrix<t> m3)
{
	matrix<t> m4(m3.row,m3.col);
	for(int i=0;i<2;i++)
	{
		for(int j=0;j<2;j++)
			m4.p[i][j]=p[i][j]+m3.p[i][j];
	}
	return m4;
}

template<class t>
//to subtract two matrix 
matrix<t> matrix<t>::sub(matrix<t> m3)
{
	matrix<t> m4(m3.row,m3.col);
	//matrix m4;
	for(int i=0;i<m3.row;i++)
	{
		for(int j=0;j<m3.col;j++)
			m4.p[i][j]=p[i][j]-m3.p[i][j];
	}
	return m4;
}

template<class t>
//subtraction using -
matrix<t> matrix<t>::operator-(matrix<t> m3)
{
	matrix<t> m4(m3.row,m3.col);
	//matrix m4;
	for(int i=0;i<m3.row;i++)
	{
		for(int j=0;j<m3.col;j++)
			m4.p[i][j]=p[i][j]-m3.p[i][j];
	}
	return m4;
}

template<class t>
//to multiply two matrix
matrix<t> matrix<t>::mult(matrix<t> m3)
{
	matrix<t> m4(this->row,m3.col);
	for(int i=0;i<this->row;i++)
	{
		for(int j=0;j<m3.col;j++)
		{
			for(int k=0;k<this->col;k++)
				m4.p[i][j]=m4.p[i][j]+this->p[i][k]*m3.p[k][j];
		}
	}
	return m4;
	
}

template<class t>
//multiplication using *
matrix<t> matrix<t>::operator*(matrix<t> m3)
{
	matrix<t> m4(this->row,m3.col);
	for(int i=0;i<this->row;i++)
	{
		for(int j=0;j<m3.col;j++)
		{
			for(int k=0;k<this->col;k++)
				m4.p[i][j]=m4.p[i][j]+this->p[i][k]*m3.p[k][j];
		}
	}
	return m4;
	
}

template<class t>
//to find transpose of square matrix
matrix<t> matrix<t>::transpose()
{
	cout<<"in "<<endl;
	matrix<t> m4(this->col,this->row);
	for(int i=0;i<this->row;i++)
	{
		for(int j=0;j<this->col;j++)
			m4.p[i][j]=this->p[j][i];
	}
	return m4;
}

template<class t>
void matrix<t>::display()
{
	int r=this->row;
	int c=this->col;  //this is by default 
	for(int i=0;i<row;i++)   ///if we do not write this then also it will work
	{
		for(int j=0;j<col;j++)
			cout<<p[i][j]<<" ";		//here also, this is not required 
		cout<<endl;
	}
	cout<<endl;
}

/*
template<class t>
ostream &operator<<(ostream &output,matrix<t> &m)
{
	int r=m.row;
	int c=m.col;
	for(int i=0;i<r;i++)
	{
		for(int j=0;j<c;j++)
			output<<m.p[i][j]<<" ";
		output<<endl;
	}
	//1cout<<endl;
	return output;
}

template<class t>
istream &operator>>(istream &input,matrix<t> &m)
{
	int r=m.row;
	int c=m.col;
	for(int i=0;i<r;i++)
	{
		for(int j=0;j<c;j++)
			input>>m.p[i][j];
	}
	return input;
}
*/

int main()
{
	int r=2,c=2;
	matrix<float> m1(r,c);
	matrix<float> m2(r,c);
	for(int i=0;i<r;i++)
	{
		for(int j=0;j<c;j++)
			cin>>m1.p[i][j];
	}
	for(int i=0;i<r;i++)
	{
		for(int j=0;j<c;j++)
			cin>>m2.p[i][j];
	}
	//cin>>m1;
	//cin>>m2;
	//cout<<m1;
	//cout<<m2;


	cout<<"matrix m1"<<endl;
	m1.display();
	cout<<"matrix m2"<<endl;
	m2.display();
	matrix<float> m3=m1.add(m2);
	cout<<"add matrix m1 and m2"<<endl;
	m3.display();
	/*matrix m6=m1+m2;
	cout<<"addition of matrix using operator; "<<endl;
	m6.display();
	matrix m7=m1-m2;
	cout<<"subtr of matrix using operator; "<<endl;
	m7.display();
	matrix m4=m1.sub(m2);
	cout<<"sub matrix m1 and m2"<<endl;
	m4.display();
	matrix m5=m1.mult(m2);
	cout<<"multiplication matrix m1 and m2"<<endl;
	m5.display();
	matrix m8=m1*m2;
	cout<<"multiplication of matrix using operator; "<<endl;
	m8.display();
	matrix m9=m1.transpose();
	cout<<"Transpose of matrix m1"<<endl;
	m9.display();*/

	
}