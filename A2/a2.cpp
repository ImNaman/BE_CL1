#include<iostream>
#include<omp.h>
using namespace std;
int k=0;
class array
{
public:
int partition(int arr[],int lower_index,int higher_index)
{
    int key=arr[lower_index];
    int i,j,temp;
    i=lower_index+1;
    j=higher_index;
    while(1)
    {
    while(key>=arr[i]&&i < higher_index)i++;
    while(key<arr[j])j--;
    if(i<j)
    {
    temp=arr[i];
    arr[i]=arr[j];
    arr[j]=temp;
    }
    else
    {
    temp=arr[lower_index];
    arr[lower_index]=arr[j];
    arr[j]=temp;
    return j;
    }    

    }//while 1
}//partition

void quicksort(int arr[],int lower_index,int higher_index)
    {
    if(lower_index<higher_index)
    {   

        int j=partition(arr,lower_index,higher_index);
        cout<<"Pivot element with index "<<j<<" has been found out by thread "<<k<<"\n";
        #pragma omp parallel sections
        {
             #pragma omp  section
             { k=k+1;
               quicksort(arr,lower_index,j-1);
             }
             #pragma omp  section
             {
                k=k+1;
               quicksort(arr,j+1,higher_index);
             }   
        }    
    }

    }

};//end array


int main()
{
array a;
int arr[1000];
int n;
cout<<"Enter n\n";
cin>>n;
for(int i=0;i<n;i++)
    {
    cin>>arr[i];    
    }

cout<<"Sorting ..\n";
a.quicksort(arr,0,n-1);
  for(int i=0;i<n;i++)
    {
    cout<<arr[i]<<" ";    
    }  
return 0;
}