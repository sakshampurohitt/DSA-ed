https://leetcode.com/problems/course-schedule/description/
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adjList(numCourses);
        vector<int> inDegree(numCourses, 0);
        
        for (auto& pre : prerequisites) {
            adjList[pre[1]].push_back(pre[0]);
            inDegree[pre[0]]++;
        }

        queue<int> q;
        for (int i = 0; i < numCourses; ++i) {
            if (inDegree[i] == 0) {
                q.push(i);
            }
        }

        int coursesTaken = 0;
        while (!q.empty()) {
            int course = q.front();
            q.pop();
            coursesTaken++;

            for (int nextCourse : adjList[course]) {
                inDegree[nextCourse]--;
                if (inDegree[nextCourse] == 0) {
                    q.push(nextCourse);
                }
            }
        }

        return coursesTaken == numCourses;
    }
};
