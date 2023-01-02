class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int>v;
        v=nums;
        sort(v.begin(),v.end());
        if(v==nums)
            return 0;
        int i=0;
        while(v[i]==nums[i] && i<nums.size())
        {
            i++;
        }
        int j=nums.size()-1;
        while(v[j]==nums[j] && j>=0)
        {
            j--;
        }
        return (j-i+1)>=0?(j-i+1):0;
    }
};
