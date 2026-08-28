#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    string lexPalindromicPermutation(string s, string target) {
        int n = s.length();
        vector<int> count(26, 0);
        for (char c : s) count[c - 'a']++;
        int odd_count = 0;
        char odd_char = 0;
        for (int i = 0; i < 26; i++) {
            if (count[i] % 2 != 0) {
                odd_count++;
                odd_char = i + 'a';
            }
        }
        if (odd_count > 1) return "";
        vector<int> half_count(26, 0);
        for (int i = 0; i < 26; i++) {
            half_count[i] = count[i] / 2;
        }

        int half_len = n / 2;

        auto make_pali = [&](const string& h) {
            string full = h;
            if (n % 2 != 0) full += odd_char;
            for (int i = half_len - 1; i >= 0; i--) {
                full += h[i];
            }
            return full;
        };
        bool can_form_exact = true;
        vector<int> exact_count(26, 0);
        for (int i = 0; i < half_len; i++) {
            exact_count[target[i] - 'a']++;
        }
        for (int i = 0; i < 26; i++) {
            if (exact_count[i] > half_count[i]) {
                can_form_exact = false;
                break;
            }
        }
        if (can_form_exact) {
            string h_exact = target.substr(0, half_len);
            string candidate = make_pali(h_exact);
            if (candidate > target) return candidate;
        }
        vector<int> current_count(26, 0);
        for (int cp_len = half_len - 1; cp_len >= 0; cp_len--) {
            fill(current_count.begin(), current_count.end(), 0);
            bool prefix_valid = true;
            for (int i = 0; i < cp_len; i++) {
                int idx = target[i] - 'a';
                current_count[idx]++;
                if (current_count[idx] > half_count[idx]) {
                    prefix_valid = false;
                    break;
                }
            }
            if (!prefix_valid) continue;
            int target_char_idx = target[cp_len] - 'a';
            for (int choice = target_char_idx + 1; choice < 26; choice++) {
                if (half_count[choice] - current_count[choice] > 0) {
                    string h_next = target.substr(0, cp_len);
                    h_next += (char)('a' + choice);
                    
                    current_count[choice]++;
                    for (int i = 0; i < 26; i++) {
                        int rem = half_count[i] - current_count[i];
                        if (rem > 0) {
                            h_next.append(rem, 'a' + i);
                        }
                    }
                    return make_pali(h_next);
                }
            }
        }
        return "";
    }
};
