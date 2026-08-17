class Solution {
public:
    bool isValid(string s) {
        list<char> b;
        unordered_map<char, char> bmap = {
            {')', '('},
            {'}', '{'},
            {']', '['}
        };
        for (char ch : s) {
            if (bmap.find(ch) != bmap.end()) { //bmap.find(ch) checks keys of bmap 
                char topElement = b.empty() ? '#' : b.back();
                if (topElement == bmap[ch]) {
                    b.pop_back();
                } else {
                    return false;
                }
            } else {
                b.push_back(ch);
            }
        }
        return b.empty();
    }
};