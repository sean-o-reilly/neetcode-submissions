class Solution {
public:
    int lastStoneWeight(const vector<int>& stones) 
    {
        std::priority_queue<int> pq;

        for (auto& num : stones)
        {
            pq.push(num);
        }

        while (pq.size() > 1)
        {
            int stoneA = pq.top();
            pq.pop();
            int stoneB = pq.top();
            pq.pop();

            int leftover = stoneA - stoneB;
            if (leftover > 0) pq.push(leftover);
        }

        if (pq.size()) return pq.top();

        return 0;
    }
};

/*

choose two heaviest stones from container. 
smash them together. if they are same weight, both are destroyed, if they are different weight, one will remain with weight (heavier - lighter)
return weight of last remaining stone or 0 if none left

we want access to a "top k" selection -> min heap / cpp priority_queue is most likely appropriate, or worth thinking about

transfer all stones into a priority queue

while the pq has more than 1 stone:
    take the top two stones: pop twice into two variables A and B
        leftover weight = abs(A - B) ? 
        if leftover > 0, push to pq

if we have a stone remaining, return its weight
else return 0

[2, 3, 6, 2, 4]
sort
[6, 4, 3, 2, 2]

smash 6 4
stone with weight 2 remains. 6 - 4  = 2
[2, 3, 2, 2]
sort
[3, 2, 2, 2]

smash 3 and 2. weight 1 left over

[2, 2, 1]
smash 2 and 2 -> 0

[1] -> continue while we have more than 1 stone in our container

return 1

*/