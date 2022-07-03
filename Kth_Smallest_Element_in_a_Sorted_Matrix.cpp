class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
    
        priority_queue<pair<int,pair<int,int>>,vector<pair<int, pair<int,int>>>,greater<pair<int, pair<int,int>>>> pq;
        int n=matrix.size();
        for(int i=0;i<n;i++)
            pq.push({matrix[i][0],{i,0}});
        int ans;
        int len=0;
        while(len<k)
        {
            pair<int,pair<int,int>>top=pq.top();
            ans=top.first;
            int row=top.second.first;
            int col=top.second.second;
            pq.pop();
            len++;
            if(col<n-1)
                pq.push({matrix[row][col+1],{row,col+1}});
        }
        return ans;
    }
};