class Solution {
public:
    vector<vector<int>>ans;
    void solve(int k,int n,vector<int>& v,int i,vector<int>& temp)
    {
        if(n<0)
            return;
        if(n==0)
        {
            if(temp.size()==k)
                ans.push_back(temp);
            return;
        }
        if(i==v.size())
            return;
        if(v[i]<=n)
        {
            temp.push_back(v[i]);
            solve(k,n-v[i],v,i+1,temp);
            temp.pop_back();
            solve(k,n,v,i+1,temp);
        }
        else 
            return;
        //solve(k,n,v,i+1,temp);

    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>v;
        for(int i=1;i<10;i++)
            v.push_back(i);
        vector<int>temp;
        solve(k,n,v,0,temp);
        return ans;
    }
};
