// 4. Power of a Number (xⁿ)

#include<iostream>
using namespace std;

int power(int x, int n){
      if(n == 0)
      return 1;
      return x * power(x, n - 1);
}

int main(){

      int x, n;
      cout<<"Enter base (x): ";
      cin>>x;

      cout<<"Enter exponent (n): ";
      cin>>n;

      int result = power(x, n);
      cout<<x <<" raised to the power "<< n << " is: "<< result<<endl;

      return 0;

}