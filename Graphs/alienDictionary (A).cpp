//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  
    vector<int> topoSort(int k, vector<int> adj[]) {
        int indegree[k]={0};
        
        for(int i=0; i<k; i++) {
            for(auto it: adj[i]) {
                indegree[it]++;
            }
        }
        
        queue<int>q;
        for(int i=0; i<k; i++) {
            if(!indegree[i]) q.push(i);
        }
        
        vector<int>topo;
        while(!q.empty()) {
            int u=q.front();
            q.pop();
            topo.push_back(u);
            for(auto it: adj[u]) {
                indegree[it]--;
                if(!indegree[it]) q.push(it);
            }
        }
        return topo;
        
    }
    
    string findOrder(string dict[], int n, int k) {
        // code here
        vector<int>adj[k];
        for(int i=0; i<n-1; i++) {
            string s1=dict[i];
            string s2=dict[i+1];
            int len = min(s1.size(), s2.size());
            for(int ptr=0; ptr<len; ptr++) {
                if(s1[ptr]!=s2[ptr]) {
                    adj[s1[ptr]-'a'].push_back(s2[ptr]-'a');
                    break;
                }
            }
        }
        
        vector<int> topo = topoSort(k, adj);
        string ans="";
        for(auto it: topo) {
            ans=ans+char(it+'a');
        }
        return ans;
        
    }
};

//{ Driver Code Starts.
string order;

bool f(string a, string b) {
    int p1 = 0;
    int p2 = 0;
    for (int i = 0; i < min(a.size(), b.size()) and p1 == p2; i++) {
        p1 = order.find(a[i]);
        p2 = order.find(b[i]);
        //	cout<<p1<<" "<<p2<<endl;
    }

    if (p1 == p2 and a.size() != b.size())
        return a.size() < b.size();

    return p1 < p2;
}

// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        string dict[N];
        for (int i = 0; i < N; i++)
            cin >> dict[i];

        Solution obj;
        string ans = obj.findOrder(dict, N, K);
        order = "";
        for (int i = 0; i < ans.size(); i++)
            order += ans[i];

        string temp[N];
        std::copy(dict, dict + N, temp);
        sort(temp, temp + N, f);

        bool f = true;
        for (int i = 0; i < N; i++)
            if (dict[i] != temp[i])
                f = false;

        if (f)
            cout << 1;
        else
            cout << 0;
        cout << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends
