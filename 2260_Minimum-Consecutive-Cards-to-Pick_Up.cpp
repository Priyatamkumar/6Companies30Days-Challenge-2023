class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        unordered_map<int,int>mp;
        int ans=cards.size()+1;
        int begin=0;
        for(auto it:cards)
        {
            
            if(mp[it]>0)
            {
                while(cards[begin]!=it||mp[it]>1)
                {
                    mp[cards[begin]]--;
                    if(mp[cards[begin]]==0)
                        mp.erase(cards[begin]);
                    begin++;
                }
                int cnt=mp.size();
                ans=min(ans,cnt+1);
            }
            mp[it]++;
        }
        return ans<=cards.size()?ans:-1;
    }
};
