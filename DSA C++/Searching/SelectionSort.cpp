#include <bits/stdc++.h>
using namespace std;

void selectionSort(vector<int> &arr, int n)
{

      for (int i = 0; i < n - 1; i++)
      {
            int midIndex = i;

            for (int j = i + 1; j < n; j++)
            {
                  if (arr[j] < arr[midIndex])
                        midIndex = j;
            }
            swap(arr[midIndex], arr[i]);
      }
}

int main()
{

      vector<int> arr = {29, 72, 98, 13, 87, 66, 52, 51, 36};
      int n = arr.size();

      selectionSort(arr, n);

      for (int i = 0; i < n; i++)

            cout << arr[i] << " ";
      cout << endl;

      return 0;
}