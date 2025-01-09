class Solution {
  public:
      int kthElement(vector<int>& a, vector<int>& b, int k) {
        int n = a.size();
        int m = b.size();
        vector<int> res;
        int i = 0, j = 0;

        while (i < n && j < m) {
            if (a[i] <= b[j]) {
                res.push_back(a[i]);
                i++;
            } else {
                res.push_back(b[j]);
                j++;
            }
        }

        while (i < n) {
            res.push_back(a[i]);
            i++;
        }

        while (j < m) {
            res.push_back(b[j]);
            j++;
        }

        return res[k - 1];
    }
};
