class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>st;
        unordered_map<string,int>mp;
        mp["+"]++;
        mp["-"]++;
        mp["/"]++;
        mp["*"]++;
        for(int i=0;i<tokens.size();i++)
        {
            if(mp.find(tokens[i])==mp.end())
            {
                st.push(stoi(tokens[i]));
            }
            else
            {
                int b=st.top();
                st.pop();
                if(tokens[i]=="+")
                    st.top()+=b;
                else if(tokens[i]=="-")
                    st.top()-=b;
                else if(tokens[i]=="*")
                    st.top()*=b;
                else
                    st.top()/=b;
            }
        }
        return st.top();
    }
};
