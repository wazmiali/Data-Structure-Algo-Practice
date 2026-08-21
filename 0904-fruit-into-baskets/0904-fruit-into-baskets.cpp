
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> count;
        int left = 0;
        int maxFruits = 0;
        
        for (int right = 0; right < fruits.size(); right++) {
            // add the fruit at 'right' to the window
            count[fruits[right]]++;
            
            // if more than 2 distinct types, shrink from the left
            while (count.size() > 2) {
                count[fruits[left]]--;
                if (count[fruits[left]] == 0) {
                    count.erase(fruits[left]);
                }
                left++;
            }
            
            // update the max window size
            maxFruits = max(maxFruits, right - left + 1);
        }
        
        return maxFruits;
    }
};