class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int>s;
        vector<int>left(heights.size()),right(heights.size());
        for(int i=0;i<heights.size();i++)
        {
            if(s.empty())
                left[i]=-1;
            else
            {
                while(!s.empty() and heights[i]<=heights[s.top()])
                    s.pop();
                if(s.empty())
                    left[i]=-1;
                else
                    left[i]=s.top();
            }
            s.push(i);
        }
        while(!(s.empty()))
            s.pop();
        for(int i=heights.size()-1;i>=0;i--)
        {
            if(s.empty())
                right[i]=heights.size();
            else
            {
                while(!s.empty() and heights[i]<=heights[s.top()])
                    s.pop();
                if(s.empty())
                    right[i]=heights.size();
                else
                    right[i]=s.top();
            }
            s.push(i);
        }
        int ans=INT_MIN;
        for(int i=0;i<heights.size();i++)
            ans=max(ans,heights[i]*(right[i]-left[i]-1));
        return ans;
    }
};