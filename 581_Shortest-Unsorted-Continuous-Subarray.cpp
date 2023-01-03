class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        
        //method one
        
        
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

        
        
        
        
        //method 2 using stack
        
        
        
        stack<int>st;
        int n=nums.size();
        int l=n;
        st.push(0);
        for(int i=1;i<n;i++)
        {
            if(nums[i]>=nums[i-1])
            {
                st.push(i);
            }
            else
            {
                while(!st.empty()&&nums[st.top()]>nums[i])
                {
                    st.pop();
                    if(st.empty())
                    {
                        l=-1;
                        break;
                    }
                    else
                        l=min(l,st.top());
                }
                st.push(i);
            }
        }
        if(l==n)
            return 0;
        while(!st.empty())
            st.pop();
        int h=0;
        st.push(n-1);
        for(int i=n-2;i>=0;i--)
        {
            if(nums[i+1]>=nums[i])
            {
                st.push(i);
            }
            else
            {
                while(!st.empty()&&nums[st.top()]<nums[i])
                {
                    st.pop();
                    if(st.empty())
                    {
                        h=n;
                        break;
                    }
                    else
                        h=max(st.top(),h);
                }
                st.push(i);
            }
        }
        return h-l>0?h-l-1:0;
    }
};
