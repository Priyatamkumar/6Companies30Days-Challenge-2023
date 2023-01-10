class Solution {
public:
    string longestPrefix(string s) {
        int i=0,j=1;
        int n=s.size();
        vector<int>prefix(n,0);
        while(j<n)
        {
            if(s[i]==s[j])
            {
                i++;
                prefix[j]=i;
                j++;
            }
            else
            {
                if(i==0)
                {
                    j++;
                }
                else
                {
                    i=prefix[i-1];
                    //j++;
                }
            }
        }
        return s.substr(0,i);

    }
};
