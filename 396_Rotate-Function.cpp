class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
       int ans=INT_MIN,sum=0,tsum=0;
       int n=nums.size();
       for(int i=0;i<n;i++)
       {
           tsum+=nums[i];
           sum+=i*nums[i];
       }
       ans=max(ans,sum);
       for(int i=0;i<n;i++)
       {
           sum+=tsum-n*nums[n-1-i];
           ans=max(ans,sum);
       }
       return ans; 
    }
};
