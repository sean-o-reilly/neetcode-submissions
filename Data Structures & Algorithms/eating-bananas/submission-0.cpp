class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h)
    {
        auto canFill = [&piles, h](int speed){
            int hoursNeeded = std::accumulate(piles.begin(), piles.end(), 0,
                [=](int acc, int pile) { return acc + std::ceil(pile * 1.0 / (double)speed);
            });
            return hoursNeeded <= h;
        };

        auto max = *std::max_element(piles.begin(), piles.end());
        
        int lb = 1;
        int ub = max;
        int mid = (max + lb) / 2;

        int best = max;

        while (lb <= ub)
        {
            if (canFill(mid)) // move down
            {
                ub = mid - 1;
                best = std::min(best, mid);
            }
            else { // move up
                lb = mid + 1;
            }

            mid = (lb + ub) / 2;
        }

        return best;
    }
};

/*
upper bound for k = max pile size
you never need to eat faster than the size of a pile, since h >= #piles

lower bound is always 1, you want to eat as slow as possible ([10, 20, 30] h = 999999999)

binary search:
start at mid of range lb->ub to determine each speed
for each mid, check if speed is possible
go lower if its possible, go higher if its impossible

[15, 16, 4, 2, 8, 9], h = 7


brute force:
test with each speed i, 
    where 1 <= lb <= i <= ub

for each possible speed
    hours_needed = 0
    for each pile
        hours_needed += ceiling(pile_size / speed)
    if hours_needed <= h, done
    else continue search


*/
