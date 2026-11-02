class Solution {
public:
    int maxArea(vector<int>& heights) {
        
        int i = 0;
        int j = heights.size() - 1;

        int ans = INT_MIN / 2;
        while(i < j){
            int width = j - i;
            ans = max(width * min(heights[i], heights[j]), ans);

            if(heights[i] < heights[j]){
                i++;
            }else{
                j--;
            }
        }

        return ans;

    }
};
