class Solution {
public:
    void setZeroes(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();

        vector<bool>x(n,false);
        vector<bool>y(m,false);

        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(mat[i][j]==0) {
                    x[i]=true;
                    y[j]=true;
                }
            }
        }

        for(int i=0; i<n; i++) {
            if(x[i]==true) {
                for(int j=0; j<m; j++) {
                    mat[i][j]=0;
                }
            }
        }
        for(int j=0; j<m; j++) {
            if(y[j]==true) {
                for(int i=0; i<n; i++) {
                    mat[i][j]=0;
                }
            }
        }
    }
};
