class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int content=0;

        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int j=0;
        for(int i=0; i<s.size(); i++) {
            if(j>=g.size()) return content;
            if(g[j]<=s[i]) {
                content++;
                j++;
            }
        }
        return content;
    }
};
