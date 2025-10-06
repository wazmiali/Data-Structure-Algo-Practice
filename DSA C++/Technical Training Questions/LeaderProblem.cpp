// Leader in an Array 
// An element is a leader if it is greater than all elements to its right.

#include <iostream>
using namespace std;

void leader(int arr[], int n)
{
      int currLdr = arr[n - 1];
      cout << currLdr << " ";

      for (int i = n - 2; i >= 0; i--)
      {
            if (currLdr < arr[i])
            {
                  currLdr = arr[i];
                  cout << currLdr << " ";
            }
      }
}
int main(){
      int arr[] = {16, 17, 4, 3, 5, 2};
      int n = sizeof(arr) / sizeof(arr[0]);

      cout<< "Leader is the array are: ";
      leader(arr, n);

      return 0;
}


