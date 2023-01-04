class Solution {
public:
    long long res;
    int dif=0;
    void mergesort(int start,int mid,int end,vector<int>&nums)
    {
        vector<int> temp(end - start + 1);
        int i = start; 
        int j = mid + 1;
        int idx = 0;
        
        while(i <= mid && j <= end){
            if(nums[i] <= dif + nums[j]){      
                res += end - j + 1;      
                i++;
            }
            else j++;
        }
        i = start;
        j = mid + 1;
        while(i <= mid && j <= end){
            if(nums[i] <= nums[j]) temp[idx++] = nums[i++];
            else temp[idx++] = nums[j++];
        } 
        while(i <= mid)temp[idx++] = nums[i++];
        while(j <= end)temp[idx++] = nums[j++];
        idx = 0;
        for(int itr = start; itr <= end ; itr++, idx++)nums[itr] = temp[idx];    
    }
    void merge(int start,int end,vector<int>& nums)
    {
        if(start>=end)
            return;
        int mid=start+(end-start)/2;
        merge(start,mid,nums);
        merge(mid+1,end,nums);
        mergesort(start,mid,end,nums);
    }
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int diff) {
        int n=nums1.size();
        dif=diff;
        vector<int>nums(n,0);
        for(int i=0;i<n;i++)
        {
            nums[i]=nums1[i]-nums2[i];
        }
        merge(0,n-1,nums);
        return res;
    }
};
