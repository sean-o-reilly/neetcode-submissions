class KthLargest {
public:

    void printStream()
    {
        for (int i = 0; i < stream.size(); ++i)
        {
            std::cout << stream[i] << " ";
        }
        std::cout << endl;
    }

    vector<int> stream;
    int kTH;

    KthLargest(int k, vector<int>& nums) 
    {
        stream = nums;
        kTH = k;

        if (!stream.size()) return;

        sort(stream.begin(), stream.end(), std::greater<int>());

        while (stream.size() && stream.size() > k)
        {
            stream.pop_back();
        }
        printStream();
    }
    
    int add(int val) // 25, 15, 5
    {
        if (!stream.size())
        {
            stream.push_back(val);
            return val;
        }

        int currLowest = stream.back();
        if (val <= currLowest && stream.size() >= kTH)
        {
            return currLowest;
        }

        // replace and swap sort on near sorted array

        
        stream.push_back(val);
        int i = stream.size() - 1;

        while (i > 0)
        {
            int j = i - 1;

            if (stream[j] < stream[i])
            {
                std::swap(stream[j], stream[i]);
            }
            else
            {
                break;
            }

            --i;
        }

        if (stream.size() > kTH)
        {
            stream.pop_back();
        }

        printStream();
        return stream.back();
    }
};

// k = 3
// 1000 0 -1000
// 1000 2 0

// 1 []


// 40 30 20 10 
// 40 30 20 45
// 40 30 45 20
// 40 45 30 20
// 45 40 30 20 

// Looks like we dont even need to update the pq if less number are added.
// At most we need k numbers in the container then, maybe not even a pq.
// 
// 0 5 15 25 40, k = 3. Initialize with more than enough numbers
// 0 5 15 25 40, we can pop back until we get size == k
// 15 25 40. size == k
// on every call to add, if the number is less or equal to than lowest number, ignore it and return lowest number
// if number is higher than the lowest number, 
// 15 25 35 40 -> 35 has to be inserted in a sorted manner
// pop until size == k, return lowest?
// 25 35 40

// to store the stream:

// needed: sorted container, with easy removals, of k size, supports duplicates 

// vector
// If number is in top k elements: O(k) worst case insertion, container must be sorted.
// If the number is not within the top k element: O(1) runtimes, all you have to do is return lowest element 
// Instead of pop front, just replace first element with new element and swap sort the new element to the right
// 0 15 23, k = 3
// push 19
// 19 15 23
// swap
// 15 19 23, return 15

// linked list
// More intuitive push, bur still O(k) for inserting > k elements
// Easy pop front for less than top k elements case




// to construct stream:
// we need to sort the stream, and trim it down to be k elements large
// O(n log n)

