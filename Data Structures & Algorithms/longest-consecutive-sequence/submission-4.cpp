class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        if(nums.size() == 1) return 1;

        sort(nums.begin(), nums.end());

        int n = nums.size();
        map<int,int> count;
        for(int i=0;i<n;i++){
            if(count.find(nums[i]-1) != count.end()){
                count[nums[i]] = max(count[nums[i]] , count[nums[i]-1] + 1);
            }else{
                count[nums[i]] = 1;
            }
        }

        int ans = 0;
        
        for(auto e: count){
            ans = max(ans, e.second);
        }
        
        return ans;

    }
};
