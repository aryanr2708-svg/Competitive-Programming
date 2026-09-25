class Solution {
public:
    int i = 0;
    vector<string> braceExpansionII(string expression) {
        set<string> result = parseExpr(expression);
        return vector<string>(result.begin(), result.end());
    }
    set<string> parseExpr(const string& s) {
        set<string> current;
        vector<string> terms;
        while (i < s.size() && s[i] != '}' && s[i] != ',') {
            if (s[i] == '{') {
                i++;
                set<string> inner = parseExpr(s);
                i++;
                current = multiply(current, inner);
            } else {
                string word = "";
                while (i < s.size() && islower(s[i])) {
                    word += s[i++];
                }
                set<string> single = {word};
                current = multiply(current, single);
            }
        }
        set<string> result = current;
        while (i < s.size() && s[i] == ',') {
            i++; // skip ','
            set<string> next = parseExpr(s);
            result.insert(next.begin(), next.end());
        }
        return result;
    }
    set<string> multiply(const set<string>& left, const set<string>& right) {
        if (left.empty()) return right;
        if (right.empty()) return left;
        
        set<string> res;
        for (const string& a : left) {
            for (const string& b : right) {
                res.insert(a + b);
            }
        }
        return res;
    }
};
