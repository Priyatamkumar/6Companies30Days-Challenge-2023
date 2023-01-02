class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        int l1=INT_MAX,l2=INT_MAX,h1=INT_MIN,h2=INT_MIN;
        long area=0;
        set<string>st;
        for(int i=0;i<rectangles.size();i++)
        {
            l1=min(rectangles[i][0],l1);
            l2=min(rectangles[i][1],l2);
            h1=max(rectangles[i][2],h1);
            h2=max(rectangles[i][3],h2);
            area+=(long)abs(rectangles[i][2]-rectangles[i][0])*(long)abs(rectangles[i][3]-rectangles[i][1]);
            string s1=to_string(rectangles[i][0])+" "+to_string(rectangles[i][1]);
            string s2=to_string(rectangles[i][0])+" "+to_string(rectangles[i][3]);
            string s3=to_string(rectangles[i][2])+" "+to_string(rectangles[i][1]);
            string s4=to_string(rectangles[i][2])+" "+to_string(rectangles[i][3]);
            if(st.find(s1)!=st.end())
            {
                st.erase(s1);
            }
            else
                st.insert(s1);
            if(st.find(s2)!=st.end())
                st.erase(s2);
            else
                st.insert(s2);
            if(st.find(s3)!=st.end())
                st.erase(s3);
            else
                st.insert(s3);
            if(st.find(s4)!=st.end())
                st.erase(s4);
            else
                st.insert(s4);
        }
        if (st.find(to_string(l1) + " " + to_string(l2)) == st.end() || st.find(to_string(l1) + " " + to_string(h2)) == st.end() || st.find(to_string(h1) + " " + to_string(l2)) == st.end() || st.find(to_string(h1) + " " + to_string(h2)) == st.end() || st.size() != 4)
        {
            return false;
        }
        return area==((long)abs(h1-l1)*(long)abs(h2-l2));
    }
};
