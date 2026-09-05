class Solution {
public:

    void helper(string expression, int start, int end, vector<int>& result)
    {
        if(start > end)
            return;

        bool isNumber = true;
        for(int i=start; i<=end; i++)
        {
            char c = expression[i];
            if(c == '-' || c == '+' || c == '*')
            {
                isNumber = false;
                vector<int> left;
                vector<int> right;
                helper(expression, start, i-1, left);
                helper(expression, i+1, end, right);

                for(auto i : left)
                {
                    for(auto j : right)
                    {
                        if(c == '-')
                            result.push_back(i-j);

                        else if(c == '*')
                            result.push_back(i*j);
                        else
                            result.push_back(i+j);
                    }
                }

            }
        }
        if(isNumber)
        {
            int number = stoi(expression.substr(start, end-start+1));
            result.push_back(number);

        }
    }

    vector<int> diffWaysToCompute(string expression) {
        vector<int> result;

        helper(expression, 0, expression.size()-1, result);
        return result;
        
    }
};