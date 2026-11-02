class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        map<char,int> index;
        int n = s.size();
        int size = 0;
        int ans = 0;
        for(int i=0;i<n;i++){
            char c = s[i];
            if(index.find(c) == index.end()) size++;
            else{
                if(size >= i - index[c])
                    size = i - index[c];
                else size++;
            }
            index[c] = i;

            ans = max(ans, size);
        }

        return ans;

    }
};
