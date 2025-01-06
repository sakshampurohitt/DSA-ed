class Solution {
  public:
    // Function to find the maximum number of meetings that can
    // be performed in a meeting room.
    int maxMeetings(vector<int>& start, vector<int>& end) {
        // Your code here
        int n=start.size();
        vector<pair<int, int>>meetings;
        for(int i=0; i<n; i++) {
            meetings.push_back({end[i], start[i]});
        }
        
        sort(meetings.begin(), meetings.end());
        
        int count=0;
        int lastEnd=-1;
        for(auto& meeting: meetings) {
            if(meeting.second > lastEnd) {
                count++;
                lastEnd=meeting.first;
            }
        }
        return count;
    }
};
