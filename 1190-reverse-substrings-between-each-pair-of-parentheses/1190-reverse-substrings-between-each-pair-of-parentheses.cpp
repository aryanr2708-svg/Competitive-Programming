class Solution {
public:
    string reverseParentheses(string s) {
        stack<string> st;
        string l;
        for (char c : s) {
            if (c == '(') {
                st.push(l);
                l.clear();
            }
            else if (c == ')') {
                reverse(l.begin(), l.end());
                l = st.top() + l;
                st.pop();
            }
            else {
                l += c;
            }
        }
        return l;
    }
};