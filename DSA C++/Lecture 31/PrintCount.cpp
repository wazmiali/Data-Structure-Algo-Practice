#include<iostream>
using namespace std;

void print(int n)
{
      if(n == 0)
      {
            return;
      }

      // tail recursion
      // cout<< n << endl;

      print(n-1);

      // Head Recursion
      cout<< n << endl;
}

int main(){

      int n;
      cin>>n;
      cout<<endl;

      print(n);

      return 0;
}

// Date: 22/09/2025