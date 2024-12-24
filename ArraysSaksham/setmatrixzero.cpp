class Solution {
private:
    void setrow(vector<vector<int>>& matrix, int row, int lim) {
        for (int i = 0; i < lim; i++) {
            matrix[row][i] = 0;
        }
    }

    void setcol(vector<vector<int>>& matrix, int col, int lim) {
        for (int i = 0; i < lim; i++) {
            matrix[i][col] = 0;
        }
    }

public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        
        vector<bool> rows(n, false);
        vector<bool> cols(m, false);

        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == 0) {
                    rows[i] = true;
                    cols[j] = true;
                }
            }
        }

        for (int i = 0; i < n; i++) {
            if (rows[i]) {
                setrow(matrix, i, m);
            }
        }

        
        for (int j = 0; j < m; j++) {
            if (cols[j]) {
                setcol(matrix, j, n);
            }
        }
    }
};
