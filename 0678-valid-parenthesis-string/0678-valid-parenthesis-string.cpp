class Solution {
public:
    bool checkValidString(string s) {
        vector<int> ob;
        vector<int> st;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                ob.push_back(i);
            } else if (s[i] == '*') {
                st.push_back(i);
            } else {
                if (!ob.empty()) {
                    ob.pop_back();
                } 
                else if (!st.empty()) {
                    st.pop_back();
                }
                else {
                    return false;
                }
            }
        }
        while (!ob.empty() && !st.empty()) {
            if (ob.back() > st.back()) {
                return false;
            }
            ob.pop_back();
            st.pop_back();
        }
        return ob.empty();
    }
};
