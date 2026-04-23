/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intervals) 
    {
        if (intervals.size() <= 1) return true;

        auto cmp = [](Interval& A, Interval& B)
        {
            return A.start < B.start;
        };
        sort(intervals.begin(), intervals.end(), cmp);

        for (int i = 0; i < intervals.size() - 1; ++i) // find overlap
        {
            auto intr = intervals[i];
            std::cout << intr.start << std::endl;
            auto nextInt = intervals[i + 1];

            if (nextInt.start < intr.end) 
            {
                return false;
            }
        }

        return true;
    }
};

// brute force O(n^2) solution:
//  for each interval, check every other interval for overlap


// requires sorting by start times: O(nlogn), then O(n) check for overlap
// for each interval i, 
//  does interval i + 1 start at or after interval i's end?

// (0, 30) - (30, 45) - (5, 10)
// (0, 30) - (5, 10) - (15, 20)
// (30, 45) - (5, 10)
// (0, 15) - (15, 30) - (30, 45)
// (0, 10) - (5, 10) - (6, 11)



