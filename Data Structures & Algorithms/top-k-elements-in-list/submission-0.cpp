class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        map<int,int> freq;

        for(auto &e: nums){
            freq[e]++;
        }

        vector<pair<int,int>> v(freq.begin(), freq.end());

        sort(v.begin(), v.end(), [](const auto& a, const auto& b){
            if(a.second != b.second)
                return a.second > b.second;
            
            return a.first > b.first;
        });

        vector<int> ans;
        for(int i=0;i<k;i++){
            ans.push_back(v[i].first);
        }

        return ans;
    }
};
