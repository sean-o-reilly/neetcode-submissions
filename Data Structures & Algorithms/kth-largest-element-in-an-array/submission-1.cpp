class Solution {
public:
    int findKthLargest(vector<int>& nums, int k)
    {
        std::multiset<int> set;

        for (int num : nums)
        {
            if (set.size() >= k)
            {
                // Only add num if its greater than set's min
                if (num > *set.begin())
                {
                    set.insert(num);
                    
                    // If set has grown past K, remove min
                    if (set.size() > k)
                    {
                        set.erase(set.begin());
                    }
                }
            }
            else
            {
                set.insert(num);
            }

        }

        return *set.begin();
    }
};


/*
Sorting solution:
    Sort nums greatest to least
    Return kth - 1 index of nums

O(n * logn) solution, nlogn sort followed by O(1) index access


Without sorting:
    Possibly better than O(n logn)?

    O(n) solution
        Use of binary trees or heap would not work here since those both involve logn operations n times

    Traverse container and use a k elements container O(n logk):
        Track only the top k elements as we traverse
        Maybe use a MULTISET for this, which would be O(n logk) complexity instead of nlogn

        For each element, only add the element to the container if its greater than the min,
            pop min element if container grows to > k size

        After that, pop the max until the queue only has one element left. This element is the kth largest


*/