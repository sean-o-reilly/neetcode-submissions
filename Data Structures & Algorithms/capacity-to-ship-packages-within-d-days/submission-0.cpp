class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days)
    {
        int lb = *std::max_element(weights.begin(), weights.end());
        int ub = std::accumulate(weights.begin(), weights.end(), 0);

        int capacity = ub;
        int min = ub;

        while (lb <= ub)
        {
            capacity = (lb + ub) / 2;
            std::cout << lb << " " << ub << " " << capacity << std::endl;
            int sum = 0;
            int boats = 0;
            int i = 0;
            while (i < weights.size())
            {
                int weight = weights.at(i);
                sum += weight;
                if (sum > capacity)
                {
                    ++boats;
                    sum = 0;
                }
                else ++i;
            }
            std::cout << "\t" << sum << std::endl;
            boats += (sum > 0);

            if (boats <= days) // possible, try smaller
            {
                min = std::min(min, capacity);
                ub = capacity - 1;
            }
            else
            {
                lb = capacity + 1; // impossible, try larger
            }
        }

        return min;
    }
};



/*
find lower and upper bound, then binary search for smallest ship capacity

lower bound = max weight
upper bound = sum of weights

days # of partitions each search
logn search, n times -> nlogn

capacity = ub

while lb < ub
    capacity "mid" = (lb + ub) /2
    
    sum = 0
    needed = 1
    for each weight
        if sum + weight <= capacity, # load current ship
            sum += weight
        else # start loading new ship
            needed += 1
            sum = weight

    if needed <= days # try smaller
        ub = mid - 1
    else # try larger
        lb = mid + 1
    
return capacity
    
[2,4,6,1,3,10], days = 4

lb = 10
ub = sum = 26

m = 18
can afford 4 ships with 18 capacity
2,4,6,1,3 fit into one ship, 10 fits into a second ship
this is possible -> ub = m - 1

lb = 10
ub = 17


*/