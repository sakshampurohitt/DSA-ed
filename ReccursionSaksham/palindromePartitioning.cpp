class Solution {
private:
    bool isPalin(string s) {
        int n = s.size() - 1;
        int i = 0;
        while (i <= n) {
            if (s[i] != s[n]) return false;
            i++;
            n--;
        }
        return true;
    }

    void backtrack(string& s, int start, vector<string>& part, vector<vector<string>>& res) {
        if (start == s.size()) {
            res.push_back(part);
            return;
        }

        for (int i = start; i < s.size(); i++) {
            string substr = s.substr(start, i - start + 1);
            if (isPalin(substr)) {
                part.push_back(substr);
                backtrack(s, i + 1, part, res);
                part.pop_back(); 
            }
        }
    }

public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> part;
        backtrack(s, 0, part, res);
        return res;
    }
};
 
