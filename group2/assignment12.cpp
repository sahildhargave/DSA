/*  Title  :-    Write a C++ program to store the monthly salary of an employee in an array. Sort array of numbers in
                 ascending order using Quick sort and Display details of top five employees with the highest salary.

    Author :-    Sahil Dhargave


*/

#include<iostream>
using namespace std;
#define SIZE 10
class Quick
{
float arr[SIZE];
public:
int get_data();
void quicksort(int, int);
int partition( int,int);
void swap(int, int);
void display(int);
};

int Quick::get_data()
{
int i,n;
cout<<"Enter total number of elements:";
      cin>>n;
      cout<<"Enter the percentage marks of each student:";
      for(i=0;i<n;i++)
     { cin>>arr[i];}
return n;
}

void Quick:: quicksort(int p,int q)
{
  int j;
  if(p<q)
  {
          j=partition(p,q+1);
          quicksort(p,j-1);
          quicksort(j+1,q);
		
  }
}
//Function for partitioning array
int Quick:: partition(int m,int p)
{
     int i=m,j=p; 
     float pivot =arr[m];
     do
     {
        do
          {
            i++;
           }while(arr[i]<pivot);
        do
         {
            j--;
         }while(arr[j]>pivot);

             if(i<j)
                swap(i,j);
       }while(i<j);
                swap(m,j);
       //arr[m]=arr[j];
       //arr[j]=pivot;
     return j;   
}

void Quick:: swap(int i, int j)
{
float temp;
temp=arr[i];
arr[i]=arr[j];
arr[j]=temp;
}

 void Quick :: display(int n)
{
cout<<"\ndetails of top five employees with the highest salary\n";
for(int i=n-1;i>=n-5;i--)
cout<<" "<<arr[i];
}

int main()
{
Quick obj;
int n;
cout<<"\n Quicksort Method \n";
n=obj.get_data();
obj.quicksort(0,n-1);
obj.display(n);
 return 0;    
}
