#include<iostream>
using namespace std;

void reverse(int arr[], int n)
{
      int low = 0, high = n -1;
      while(low < high)
      {
            int temp = arr[low];
            arr[low] = arr[high];
            arr[high] = temp;
            
            low++;
            high--;
      }
}
int main(){
      int arr[] = {10, 20, 30, 40};
      int n = sizeof(arr) / sizeof(arr[0]);

      cout<<"Original array.";
      cout<<endl;
      for(int i=0; i<n; i++)
            cout<<arr[i]<<" ";
      cout<<endl;

      reverse(arr, n);

      cout<<"New Array.";
      for(int i=0; i<n; i++)
            cout<<arr[i]<<" ";
      cout<<endl;

}
