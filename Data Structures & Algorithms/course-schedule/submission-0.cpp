class Solution {
private:
    unordered_map<int, vector<int>> mapp;
    unordered_set<int> visit;

    int dfs(int course) {
        if (visit.count(course)) {
            return false;
        }
        if (mapp[course].empty()) {
            return true;
        }
        visit.insert(course);
        for(int preReq : mapp[course]) {
            if (!dfs(preReq)) {
                return false;
            }
        }
        visit.erase(course);
        mapp[course].clear();
        return true;
    }

public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        for (auto& p : prerequisites) {
            mapp[p[0]].push_back(p[1]);
        }
        for(int c = 0; c < numCourses; c++) {
            if (!dfs(c)) {
                return false;
            }
        }
        return true;
    }
};
