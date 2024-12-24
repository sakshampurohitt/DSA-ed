class Solution {
private:
     vector<int> rowprint(int n){
        int ans = 1;
        vector<int> row;
         row.push_back(ans);
        for(int i = 1; i<n; i++){
            ans = ans*(n-i)/i;
            row.push_back(ans);
        }
        return row;
        }
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> triangle;
        for(int i=1; i<=numRows; i++){
            triangle.push_back(rowprint(i));
        }
        return triangle;
    }
};
