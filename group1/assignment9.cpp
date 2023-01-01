/*      Title   :-              Write a C++ program to store the monthly salary of an employee in an array. Sort array of numbers in ascending order using Merge sort and
                      Display details of top five employees with the highest salary.


       Author          :-     Sahil Dhargave
       
       
       */
       
       
       
#include <iostream>
using namespace std;

void merge(int a[], int beg, int mid, int end)    
{    
    int i, j, k;  
    int n1 = mid - beg + 1;    
    int n2 = end - mid;    
     
    int LeftArray[n1], RightArray[n2];
     
     
    for (int i = 0; i < n1; i++)    
    LeftArray[i] = a[beg + i];    
    for (int j = 0; j < n2; j++)    
    RightArray[j] = a[mid + 1 + j];    
     
    i = 0;
    j = 0;
    k = beg;
     
    while (i < n1 && j < n2)    
    {    
        if(LeftArray[i] <= RightArray[j])    
        {    
            a[k] = LeftArray[i];    
            i++;    
        }    
        else    
        {    
            a[k] = RightArray[j];    
            j++;    
        }    
        k++;    
    }    
    while (i<n1)    
    {    
        a[k] = LeftArray[i];    
        i++;    
        k++;    
    }    
     
    while (j<n2)    
    {    
        a[k] = RightArray[j];    
        j++;    
        k++;    
    }    
}  

void merege_sort(int a[],int beg,int end){
    if(beg<end){
        int mid = (beg+end)/2;
        merege_sort(a,beg,mid);
        merege_sort(a,mid+1,end);
        merge(a,beg,mid,end);
    }
   
}



int main()
{
    int n;
    cout<<"Enter number of emplyee";
    cin>>n;
    int a[n];

    cout<<"Enter monthly salary of the employee";
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    
    merege_sort(a,0,n-1);
    
    cout<<"salary of top 5 employee with highest salary"<<endl;
    for(int i=n-1;i>=n-5;i--){
        cout<<" "<<a[i];
    }

    return 0;
}
