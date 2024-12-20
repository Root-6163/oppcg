//============================================================================
// Name        : Sample1.cpp
// Author      : Souvik Majumdar
// Version     :
// Copyright   : NOBODY SHOULD COPY THE CODE,ONLY FOR REVIEW BY THE CONCERNED FACULTY
// Description : Hello World in C++, Ansi-style
//============================================================================

#include<iostream>
using namespace std;
template<class T>
void create(T *p,int size)
{

	cout<<"Enter the elements of the array"<<endl;
	for(int i=0;i<size;i++)
	{
		cin>>p[i];
	}

}
template<typename T>
void show(T*p,int size)
{
	cout<<"The elements of the array are:"<<endl;
	for(int i=0;i<size;i++)
	{
         cout<<" "<<p[i];
	}
}


template<typename T>
void sort(T*arr,int size)
{
int j,min;
T temp;
for(int i=0;i<size-1;i++)
{
	min=i;
	for(j=i+1;j<size;j++)
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
int main()
{
	int size,size1;
	cout<<"Enter the size of the array"<<endl;
	cin>>size;
	int arr[size];
	cout<<"With integer array"<<endl;
	create(arr,size);
	show(arr,size);
	cout<<endl;
	cout<<"Selection sort:"<<endl;
	sort(arr,size);
	show(arr,size);
	cout<<endl;
	cout<<"With float array"<<endl;
	cout<<"Enter the size of the float array"<<endl;
	cin>>size1;
	float arr1[size1];
	create<float>(arr1,size1);
	show<float>(arr1,size1);
	cout<<endl;
	cout<<"Selection sort"<<endl;
	sort<float>(arr1,size1);
	show<float>(arr1,size1);
	return 0;
}
