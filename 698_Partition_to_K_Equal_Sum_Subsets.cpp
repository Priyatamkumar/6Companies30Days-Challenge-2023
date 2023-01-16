class Solution {
public:
    bool helper(vector<int>& nums,int k,int sum,int ind,int cur_sum,vector<int>& vis)
    {
        if(ind==nums.size()||cur_sum>sum)
            return false;
        if(k==1)
            return true;
        if(sum==cur_sum)return helper(nums,k-1,sum,0,0,vis);
        for(int i=ind;i<nums.size();i++)
        {
            if(vis[i]==1)continue;
                vis[i]=1;
            if(helper(nums,k,sum,i+1,cur_sum+nums[i],vis))
                return true;
            vis[i]=0;
        }
        return false;
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum=0;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
        }
        vector<int>vis(n,0);
        if(sum%k!=0||k>n||nums[n-1]>(sum/k))return false;
        if(helper(nums,k,sum/k,0,0,vis))
            return true;
        return false;

    }
};
