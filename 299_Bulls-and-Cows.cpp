class Solution {
public:
    string getHint(string secret, string guess) {
        unordered_map<int,int>mp;
        int b=0,c=0;
        for(int i=0;i<10;i++)
        {
            mp[i]=0;
        }
        for(int i=0;i<guess.size();i++)
        {
            if(secret[i]==guess[i])
                b++;
            else
            {
                int num=guess[i]-'0';
                int sec=secret[i]-'0';
                if(mp[num]>0)
                {
                    c++;
                }
                mp[num]--;
                if(mp[sec]<0)
                {
                    c++;
                }
                mp[sec]++;
            }
        }
        string str;
        str+=to_string(b);
        str+="A";
        str+=to_string(c);
        str+="B";
        return str;
    }
};
