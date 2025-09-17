// count the any number in the given value 

#include <iostream>
using namespace std;

void print(int n){
      //base case 
      if(n == 0){
            return ;

      }
      // Recursion relation 
      // Head recursion 

      print(n-1);
      cout <<n <<endl;
}   

int main()
{
      int n;
      cin>>n;

      cout<<endl;

      print(n);

return 0;
}