class Solution {
public:
    void search(int currIdx, int currCost, const vector<int>& stairs, vector<int>& cheapest)
    {
        if (currIdx >= stairs.size()) // end search
        {
            cheapest.back() = std::min(cheapest.back(), currCost);
            return;
        }
        
        if (currCost >= cheapest[currIdx]) // redundant search
        {
            return;
        }

        // recurse
        cheapest[currIdx] = std::min(currCost, cheapest[currIdx]);

        int nextCost = currCost + stairs[currIdx];

        search(currIdx + 2, nextCost, stairs, cheapest);
        search(currIdx + 1, nextCost, stairs, cheapest);
    }

    int minCostClimbingStairs(const vector<int>& cost)
    {
        std::vector<int> cheapest(cost.size() + 1, std::numeric_limits<int>::max());

        search(0, 0, cost, cheapest);
        search(1, 0, cost, cheapest);

        return cheapest.back();
    }
};

/*

pseudocode:
    searching for cheapest prices of indices

    void helper(currIdx, currCost, stairs, cheapest) 
        end case: 
            currIdx >= stairs.size, we're past the end
            set the last element of cheapest to the new min
            end search
    
        redundant case:
            currCost is greater than cheapest at this idx
            end search

        recursive case:
            cheapest[currIdx] = min of currCost and cheapest[currIdx]

            nextCost = currCost + stairs[currIdx], the cost it takes to move on

            probably faster to try longer jump first
            helper(currIdx + 2, nextCost, stairs, cheapest) 
            helper(currIdx + 1, nextCost, stairs, cheapest)

    int minCost(stairs)
        store an array of cheapest paths to all indices
            array cheapest[stairs.size + 1]
                set cheapest to max values
        
        try starting from 0 or 1
            helper(0, 0, stairs, cheapest)
            helper(1, 0, stairs, cheapest)

        return cheapest[stairs.size] 

Decision tree

[1, 2]
    choose 1:
        go to 2
            go to end w cost 3
        go to end w cost 1
    choose 2:
        go to end w cost 2

[1, 2, 3]
    choose 1:
        go to 2
            go to end w cost 3
            go to 3
                go to end w cost 6
    choose 2:
        go to 3
            go to end w cost 5
        go to end w cost 2

lowest cost is 2
O(2^n) runtime, can maybe be optimized with memoization


maybe we store the cheapest cost to get to any given index
[1, 2, 3]

starting off, we know
    cheapest path to 1 is 0
    cheapest path to 2 is 0
so why would we ever start at 1 and jump to 2? its more expensive than just starting at 2

lets say we try starting at 1, we know the cheapest cost to get to 3 is 1
    so we have no reason to go from 2 to 3, because that cost would be 2. no reason to continue down that path at all

to get to end index, lets start at our cheapest paths
    1
        skip 2, its too expensive
        go to 3, cost is 1

        3
            go to end with a cost of 4
    2 
        skip 3, because its cheaper to start at 1 and go to 3

        our min cost of getting to the end is 4, 
            but here we can go to the end with cost of 2
    

[1, 2, 3]

cheapest = [inf, inf, inf, inf]

    start at 2: (cost is 0)
        go to 3
            cost to get to 3 was 2, new min
        go to end
            cost to get to end was 2, new min

    start at 1: (cost is 0)
        go to 2
            cost to get here was more than the min, end search
                NO REDUNDANT 3 OR REDUNDANT END
        go to 3
            cost to get here was 1, new min
                go to end
                    cost to get here was more than min, end search
        

*/