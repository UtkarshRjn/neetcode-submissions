class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {

        int prod = 1;
        int cnt = 0;
        int prod_without_zero = 1;
        for(auto num: nums){
            prod *= num;
            if(num == 0) cnt++;
            else prod_without_zero *= num;
        }

        vector<int> ans;
        for(auto num: nums){
            if(num == 0 && cnt == 1) ans.push_back(prod_without_zero);
            else if(num == 0 && cnt > 1) ans.push_back(0);
            else ans.push_back(prod / num);
        }

        return ans;

    }
};
