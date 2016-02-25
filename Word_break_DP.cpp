#include<iostream>
#include<vector>
#include<unordered_set>
#include<string>
using namespace std;

    /**
     * @param s: A string s
     * @param dict: A dictionary of words dict
     */
    bool wordBreak(string s, unordered_set<string> &dict) {
        // write your code here
        vector<bool> dp(s.length() + 1, false);
        dp[0] = true;
        int min_len = INT_MAX, max_len = INT_MIN;
        for (auto &ss : dict) {
            min_len = min(min_len, (int)ss.length());
            max_len = max(max_len, (int)ss.length());
        }
        for (int i = 0; i < s.length(); ++i) if(dp[i]) {
            for (int len = min_len; i + len <= s.length() && len <= max_len; ++len) {
                if (dict.find(s.substr(i, len)) != dict.end()) 
                    dp[i + len] = true;
            }
            if (dp[s.length()]) return true;
        }
        return dp[s.length()];
    }

     int main()
    {

        /* code */
        return 0;
    }


