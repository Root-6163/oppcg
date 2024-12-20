//sorting cpp program
//============================================================================
// Name        : Sorting.cpp
// Author      : Souvik Majumdar
// Version     :
// Copyright   : NOBODY SHOULD COPY THE CODE,ONLY FOR REVIEW BY THE CONCERNED FACULTY
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

template<class T,int n>
class Sorting
{
private:T arr[n];
public:
void accept()
{
	cout<<"Enter the elements of the array"<<endl;
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
}
void display()
{
cout<<"displaying the elements of the array"<<endl;
for(int i=0;i<n;i++)
{
	cout<<" "<<arr[i];
}
}
void sort()
{
	int i,j,min,temp;
	for(i=0;i<(n-1);i++)
	{
		min=i;
	for(j=i+1;j<n;j++)
	{
		if(arr[j]<arr[min])
		{
			min=j;
		}
	}
	temp=arr[i];
	arr[i]=arr[min];
	arr[min]=temp;
}
}
};
int main()
{
cout<<"Working with integer array"<<endl;
int limit;


	Sorting<int,5>a;
	a.accept();
	a.display();
	cout<<endl;

	a.sort();
	cout<<"After sort"<<endl;
	a.display();
	cout<<endl;
cout<<"working with float arrays"<<endl;
Sorting<float,5>b;
b.accept();
b.display();

b.sort();
cout<<"After sort"<<endl;
b.display();
	return 0;
}
