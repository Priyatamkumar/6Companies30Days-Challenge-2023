class Solution {
public:
    int helper(int ind, int prev, int n, vector<int>& nums, vector<vector<int>>&dp)
    {
        if(ind==n)
            return 0;
        if(dp[ind][prev+1]!=-1)return dp[ind][prev+1];
        int len=0;
        if(prev==-1||nums[ind]%nums[prev]==0)
            len=max(1+helper(ind+1,ind,n,nums,dp),helper(ind+1,prev,n,nums,dp));
        return dp[ind][prev+1]=max(len,helper(ind+1,prev,n,nums,dp));
    }
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n=nums.size();
        vector<int>hash(n+1,0),dp(n+1,0);
        int maxi=0;
        int lastIndex=0;
        for(int i=1;i<n;i++)
        {
            hash[i]=i;
            for(int prev=0;prev<i;prev++)
            {
                if(nums[i]%nums[prev]==0&& 1+dp[prev]>dp[i])
                {
                    hash[i]=prev;
                    dp[i]=1+dp[prev];
                }
            }
            if(dp[i]>maxi)
            {
                maxi=dp[i];
                lastIndex=i;
            }
        }
        vector<int>res;
        res.push_back(nums[lastIndex]);
        while(hash[lastIndex]!=lastIndex)
        {
            lastIndex=hash[lastIndex];
            res.push_back(nums[lastIndex]);
        }
        return res;
    }
};
