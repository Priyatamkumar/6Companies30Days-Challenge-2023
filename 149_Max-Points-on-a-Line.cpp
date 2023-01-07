class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int cnt=0,ans=0;
        if(points.size()<3)
            return points.size();
        for(int i=0;i<points.size()-2;i++)
        {
            for(int j=i+1;j<points.size()-1;j++)
            {
                cnt=2;
                for(int k=j+1;k<points.size();k++)
                {
                    if((points[i][0]-points[j][0])*(points[i][1]-points[k][1])==(points[i][1]-points[j][1])*(points[i][0]-points[k][0]))
                        cnt++;
                }
                
                ans=max(ans,cnt);
            }
        }
        return ans;
    }
};
