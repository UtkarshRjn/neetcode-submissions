class Solution {
public:

    string encode(vector<string>& strs) {

        if(strs.size() == 0) return "";

        string ans = to_string(strs[0].size()) + "$" + strs[0];
        for(int i=1;i<strs.size();i++){
            ans += to_string(strs[i].size()) + "$" + strs[i];
        }

        return ans;

    }

    vector<string> decode(string s) {

        vector<string> ans;

        int i = 0;

        while(i < s.size()) {
            // Find the '#'
            int j = i;
            while(s[j] != 36) {
                j++;
            }

            // Get the length
            int len = stoi(s.substr(i, j - i));

            // Move past '#'
            j++;

            // Extract exactly 'len' characters
            ans.push_back(s.substr(j, len));

            // Move to the beginning of the next encoded string
            i = j + len;
        }

        return ans;

    }
};
