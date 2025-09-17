// 3. Sum of Digits of a Number

#include<iostream>
using namespace std;

int SumOfDigit(int n){

      if(n == 0)
      return 0;
      return(n%10) + SumOfDigit(n/10);
}

int main(){

      int n;
      cout<<"Enter the number: ";
      cin>>n;

      int result = SumOfDigit(n);
      cout<<"Sum of Digits of "<<n<<" is: "<<result << endl;

      return 0;
}