class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int n = s.length();
        vector<int> count(26, 0);
        for (char c : s) {
            count[c - 'a']++;
        }
        int match_len = 0;
        while (match_len < n && count[target[match_len] - 'a'] > 0) {
            count[target[match_len] - 'a']--;
            match_len++;
        }
        for (int i = match_len; i >= 0; i--) {
            if (i < n) {
                char target_char = target[i];
                for (int c = (target_char - 'a') + 1; c < 26; c++) {
                    if (count[c] > 0) {
                        string ans = target.substr(0, i);
                        ans.push_back('a' + c);
                        count[c]--;
                        for (int j = 0; j < 26; j++) {
                            while (count[j] > 0) {
                                ans.push_back('a' + j);
                                count[j]--;
                            }
                        }
                        return ans;
                    }
                }
            }
            if (i > 0) {
                count[target[i - 1] - 'a']++;
            }
        }
        return "";
    }
};
