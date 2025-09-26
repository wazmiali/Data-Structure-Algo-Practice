// Array Deletion or Insert and sort 

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
      vector<int> v = {10, 2, 1, 5, 4};

      cout<<"Original Array: ";
      for(int x : v)
            cout<< x << " ";
      cout<<endl;

      v.erase(v.begin() + 3); // delete element of index of 3

      v.insert(v.begin() + 4, 22); // Insert a new element in the position id index 4

      sort(v.begin(), v.end()); // Sort a array in ascending order

      cout << "After Deletion of a Array: ";
      for (int x : v)
            cout << x << " ";
}