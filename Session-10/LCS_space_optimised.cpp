class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int a = text1.length();
        int b = text2.length();

        vector<int> prev(b + 1, 0);
        vector<int> curr(b + 1, 0);

        for (int i = 1; i <= a; i++) {
            for (int j = 1; j <= b; j++) {
                if (text1[i - 1] == text2[j - 1]) curr[j] = 1 + prev[j - 1];
                else curr[j] = max(curr[j - 1], prev[j]);
            }
        prev = curr;
        }

        return prev[b];
    }
};
