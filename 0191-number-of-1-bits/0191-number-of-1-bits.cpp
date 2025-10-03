class Solution {
public:
    int hammingWeight(int n) {

        int cout = 0;
        while(n!=0){

            if(n&1){
                cout++;

            }
            n = n>>1;
        }
        return cout;
    }
};