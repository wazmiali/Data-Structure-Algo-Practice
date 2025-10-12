class Solution {
public:
    int fib(int n) {
        int num1=0;
        int num2=1;
        if(n==0)return num1;
        if(n==1)return num2;
        int temp;
        for(int i=2;i<=n;i++){
            temp=num1+num2;
            num1=num2;
            num2=temp;
        }return num2;
        
    }
};