// Last updated: 27/04/2026, 21:45:28
class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {

        for (int i = 0; i < tasks.size(); i++) {
            tasks[i].push_back(i);
        }
        sort(tasks.begin(), tasks.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 return a[0] < b[0];
             });

        vector<int> ans;
        int n = tasks.size();

        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            minh;
        int currentTime = tasks[0][0];
        int i=0;
        while (i < n||!minh.empty()) {
            // currentTime = tasks[i][0];
            while(i<n&&tasks[i][0]<=currentTime) // as the time has moved forwaerd after finifshing a task or CPU was idle for some time we need to add those task which could have entered during that time
            {
                minh.push({tasks[i][1],tasks[i][2]}); // as time has move 
                i++;

            }
            long long  task_finish_time=0;
            

            if(!minh.empty()) //heap not wmpty we have to process the smaller durtaion task and move time foraward
            {
                task_finish_time=minh.top().first;
                int index=minh.top().second;   // we pop out a task as it has been chossen we ll have to process it and move time forward
                minh.pop(); 
                ans.push_back(index);
                
            }
            else //CPU is idle as heap is emoty we have to move time foraward to find new task
            {
                // i++;
                currentTime=tasks[i][0]; // as no task to execute i ll have to move forward
            }


            currentTime=currentTime+task_finish_time;



        }
        return ans;
    }
    };