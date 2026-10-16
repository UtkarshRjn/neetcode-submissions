class Solution {
public:

    bool match(const array<int,26>& a1,const array<int,26>& a2){
        
        for(int i=0;i<26;i++){
            if(a1[i] != a2[i]) return false;
        }

        return true;
    }

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        map<array<int, 26>, vector<string>> mp;

        for(auto str: strs){
            array<int, 26> freq{};
            for(auto c: str){
                freq[c - 'a']++;
            }

            mp[freq].push_back(str);
        }

        vector<vector<string>> ans;
        for(auto& elem: mp){
            ans.push_back(elem.second);
        }

        return ans;

    }
};
