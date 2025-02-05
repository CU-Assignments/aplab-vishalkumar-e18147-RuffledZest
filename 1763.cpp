class Solution {
    
    
public:
    string longestNiceSubstring(string s) {
        int n = s.size();
        if (n < 2) return "";
        string result = "";
        for (int i = 0; i < n; ++i) {
            unordered_set<char> seen;
            for (int j = i; j < n; ++j) {
                seen.insert(s[j]);
                if (isNice(seen)) {
                    if (j - i + 1 > result.size()) {
                        result = s.substr(i, j - i + 1);
                    }
                }
            }
        }
        return result;
    }
    bool isNice(const unordered_set<char>&seen) {
        for (char c:seen) {
            if (seen.find(tolower(c)) == seen.end() || seen.find(toupper(c)) == seen.end()) {
                return false;
            }
        }
        return true;
    }


};