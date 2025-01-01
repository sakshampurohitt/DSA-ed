//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// class implemented
/*
struct Item{
    int value;
    int weight;
};
*/

class Solution {
  public:
    // Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        // Your code here
          int n = val.size();
        vector<pair<double, pair<int, int>>> items; 

        for (int i = 0; i < n; i++) {
            double ratio = (double)val[i] / wt[i];
            items.push_back({ratio, {val[i], wt[i]}});
        }

        sort(items.begin(), items.end(), [](const auto& a, const auto& b) {
            return a.first > b.first;
        });

        double maxValue = 0.0;

        for (auto& item : items) {
            int weight = item.second.second;
            int value = item.second.first;

            if (capacity >= weight) {
                maxValue += value;
                capacity -= weight;
            } else {
                maxValue += (double)value * capacity / weight;
                break;
            }
        }

        return maxValue;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    // taking testcases
    cin >> t;
    cin.ignore(); // to ignore the newline after the number of test cases
    cout << setprecision(6) << fixed;

    while (t--) {
        // Reading the value array
        vector<int> values;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            values.push_back(number);
        }

        // Reading the weight array
        vector<int> weights;
        getline(cin, input);
        stringstream ss2(input);
        while (ss2 >> number) {
            weights.push_back(number);
        }

        // Reading the capacity
        int w;
        cin >> w;
        cin.ignore(); // to ignore the newline after capacity

        // function call
        Solution ob;
        cout << ob.fractionalKnapsack(values, weights, w) << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends
