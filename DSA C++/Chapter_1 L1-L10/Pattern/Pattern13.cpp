#include <iostream>
using namespace std;

int main(){

      int n;
      cin>>n;
      
      for(int i=1; i<=n; i++){
            for(int j=1; j<=i; j++){
                  char ch = 'A' + i + j - 2;
                  cout<<ch;
            }
            cout<<"\n";
      }
      return 0;
}

// output 
/*

A
BC
CDE
DEFG
EFGHI

*/