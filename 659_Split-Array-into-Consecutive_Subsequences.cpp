class Solution {
public:
    bool isPossible(vector<int>& nums) {
        if(nums.size()<3)
            return 0;
        unordered_map<int,int>mp;
        int n=nums.size();
        int start=0,end=0;
        for(int i=0;i<n;i++)
        {
            mp[nums[i]]++;
        }
        unordered_map<int,int>m;
        for(int i=0;i<n;i++)
        {
            if(mp[nums[i]]>0)
            {
                if(m[nums[i]-1]>0)
                {
                    m[nums[i]-1]--;
                    m[nums[i]]++;
                    mp[nums[i]]--;
                }
                else if(mp[nums[i]+1]>0&&mp[nums[i]+2]>0)
                {
                    m[nums[i]+2]++;
                    mp[nums[i]+1]--;
                    mp[nums[i]+2]--;
                    mp[nums[i]]--;
                }
                else
                {
                    return false;
                }
            }

        }
        return true;
        
    }
};
