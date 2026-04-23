class Solution {
public:
    using MsIter = std::multiset<int>::iterator;

    void printHeap(std::multiset<int>& heap)
    {
        std::cout << "Heap: ";
        for (auto num : heap) std::cout << num << " ";
        std::cout << std::endl;
    }

    void printWindow(std::list<MsIter> window)
    {
        std::cout << "Window: ";
        for (MsIter iter : window)
        {
            std::cout << *iter << " ";
        }
        std::cout << std::endl << std::endl;
    }

    std::vector<int> maxSlidingWindow(std::vector<int>& nums, int k)
    {
        std::multiset<int> ms;
        std::list<MsIter> window;

        for (int i = 0; i < k; ++i)
        {
            auto newNum = ms.insert(nums[i]);
            window.push_back(newNum);
        }

        printHeap(ms);
        printWindow(window);

        std::vector result = {*ms.rbegin()};

        for (int i = k; i < nums.size(); ++i)
        {
            // add number to multiset, 
            auto newNum = ms.insert(nums[i]);

            // store reference to number's location in multiset in the window list
            window.push_back(newNum);

            // pop front of the list while removing its referenced corresponding value from multiset
            MsIter toRemove = window.front();
            window.pop_front();

            ms.erase(toRemove);

            // add top of pq (max element) to result
            result.push_back(*ms.rbegin());
        }
        
        return result;
    }
};

/*

std::list window

add first k numbers to multiset, add multiset iterators to the window list

multiset = 2, 1, 1
list = reference to 1, reference to 2, reference to 1

result = []
add max of multiset to result

for number in numbers:
    add number to multiset, 
    store reference to number's location in multiset in the window list
    pop front of the list while removing its referenced corresponding value from multiset
    add top of pq (max element) to result

return result

*/

/*

std::list (the window) contains references to numbers stored in a priority queue
this lets us know in O(1) what the max number is
this lets us pop numbers in order from the priority queue

logn deletion from heap
O(n) traversal

window: 1 2 1
pq: 2 1 1

window: 2 1 0
pq: 2 1 0 (1 was removed in logn time)

window: 1 0 4
pq: 4 1 0 (2 went out of window, was removed from pq, 4 was added to pq)

window 0 4 2
pq: 4 2 0 (1 went out of window, removed from pq, 2 added to pq) in O(logn) + O(logn) time

*/