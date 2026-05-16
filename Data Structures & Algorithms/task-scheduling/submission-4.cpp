class Solution {
public:
    int leastInterval(vector<char>& tasks, int n)
    {
        if (tasks.size() == 1) return 1;
        
        std::priority_queue<int> pq;    
        std::queue<std::pair<int, int>> q;
        
        std::array<int, 26> letterCounts{};
        for (auto c : tasks)
            letterCounts.at(c - 'A')++;
        
        for (auto count : letterCounts)
        {
            if (count > 0)
                pq.push(count);
        }
        
        int time = 0;

        while (!q.empty() || !pq.empty())
        {
            ++time;
            if (!pq.empty())
            {
                std::cerr << "process " << pq.top() << " at " << time << std::endl;
                int val = pq.top();
                pq.pop();
                if (val > 1)
                {
                    --val;
                    q.emplace(val, time + n + 1);
                }
            }

            if (!q.empty() && q.front().second <= time + 1)
            {
                std::cerr << "ready = " << q.front().first << " " << q.front().second << " curr time = " << time << std::endl;
                int val = q.front().first;
                q.pop();
                // if (val > 1)
                {
                    pq.push(val);
                }
                // if (q.empty() && pq.empty()) return time;
            }
        }

        return time;
    }
};

/*
always execute most common task
using pq to track which one is highest priority
use queue to track readiness

time = 0

fill pq with count of each task
add (max of pq - 1) to queue with future ready time

while queue not empty
    if heap non empty, pop max from heap
        decrement the value by 1
        if value greater than 0
            add it to queue with its future ready time
    
    if front of queue ready time >= now, pop from queue
        and bring that element back into the heap
    
    increment time

return time

t = 1
A : 3
B : 1
C : 1
pop A
q [(2, r=1+3+1)]

t = 2
B : 1
C : 1
pop B (random on ties)
q [(2, r=5))]

t = 3
C : 1
pop C
q [(2, r=5))]

t = 4...
t = 5
A : 2
pop A
q [(2, r=5 + 3 + 1)]

t = 6,7,8...
t = 9
A : 1
pop A
done

*/