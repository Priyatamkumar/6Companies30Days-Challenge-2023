class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& numsDivide) {
        sort(nums.begin(),nums.end());
        sort(numsDivide.begin(),numsDivide.end());
        if(numsDivide[0]<nums[0])
            return -1;
        map<int,int>mp;
        for(int i=0;i<nums.size();i++)
        {
            mp[nums[i]]++;
        }
        for(auto it:mp)
        {
            cout<<it.first<<" "<<it.second<<endl;
        }
        int ans=0;
        for(auto it:mp)
        {
            int cnt=0;
            for(auto itr:numsDivide)
            {
                if(itr%it.first!=0)
                {
                    cnt++;
                    ans+=it.second;
                    break;
                }
            }
            if(cnt==0)
                return ans;
        }
        return -1;
    }
};
