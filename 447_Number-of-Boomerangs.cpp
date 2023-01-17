class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        int n=points.size();
        int ans=0;
        for(int i=0;i<n;i++)
        {
            unordered_map<int,int>mp;
            for(int j=0;j<n;j++)
            {
                int dist=abs((points[j][0]-points[i][0])*(points[j][0]-points[i][0]))+abs((points[j][1]-points[i][1])*(points[j][1]-points[i][1]));
                mp[dist]++;
            }
            for(auto it:mp)
            {
                ans+=it.second*(it.second-1);
            }
        }
        return ans;
    }
};
