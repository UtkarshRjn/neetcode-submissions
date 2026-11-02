class Solution {
public:

    int trap(vector<int>& height) {
        
        int n = height.size();
        stack<pair<int,int>> st;
        int ans = 0;
        for(int i=0;i<n;i++){
            
            while(!st.empty() && height[i] > st.top().first) {

                auto pr = st.top();
                st.pop();

                if(st.empty()) break;

                int left = st.top().second;
                int right = i;

                int width = right - left - 1;

                int bounded_height = min(height[left], height[right]) - pr.first;

                ans += width * bounded_height;
            }

            st.push({height[i], i});
            
        } 

        return ans;

    }
};
