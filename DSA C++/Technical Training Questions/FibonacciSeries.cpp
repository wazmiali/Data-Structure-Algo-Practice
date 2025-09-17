// 2. Fibonacci Series

#include<iostream>

using namespace std;

int fibonacci(int n){

      if(n <= 1)
      return n;
      return fibonacci(n-1) + fibonacci(n-2);
}

int main(){
      
      int n;
      cout<<"Enter the number: ";
      cin>>n;

      cout<<"Fibonacci series "<<n <<" is "<<endl;

      for(int i = 0; i<n; i++){
            cout<<fibonacci(i)<<" ";
      }
      cout<<endl;
      
      return 0;

}