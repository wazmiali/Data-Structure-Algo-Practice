class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int count = 0;
        int n = intervals.size();
        int left = 0;
        int right = 1;

        while(right < n)
        {
            if(intervals[left][1] <= intervals[right][0]) 
            {
                left = right;
                right+=1;
            }
            else if(intervals[left][1] <= intervals[right][1])
            {
                count+=1;
                right+=1;
            }
            else if(intervals[left][1] >intervals[right][1])
            {
                count+=1;
                left = right;
                right+=1;
            }
        }

        return count;
    }
};