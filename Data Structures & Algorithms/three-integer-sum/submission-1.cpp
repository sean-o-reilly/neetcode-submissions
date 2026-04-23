class Solution {
public:
    // every triplet is unique
    // unordered output
    // repeats allowed in triplet
    // returns a vector of vector, more like a set of tuples
    // answer can be empty
    // can use 3 zeroes
    // array is at least 3 long
    // tuple<int int int> might not work because the ijk values could be in different order

    // brute force:
    //  for each number
    //    for each other number
    //      for each other number that isnt ^
    //         see if these 3 numbers add up to zero
    //           if they add up zero, check if we have added the tuple to output already..
    //    O(n^3)

    // do two sum on subsets. 
    // for each num O(n)
    //   two sum with num as the target^ O(n)
    //   O(n^2) time and space overrall

    // accept O(n^2), try O(1) space, not proportional to size of the array
    //  sorting is an option


    // [-4,-1,-1,0,1,2]
    // sort, 
    // for each target
    //   two pointer to find -target
    //     at -1, does -4 and 2 give us the target of 1? no, it gives us -2, which is less than. move left ptr 
    //     at -1, does -1 and 2 giveu us the target of 1? yes, add to tuple set


    // [-3,-2,0,1,1,5,7]
    //   at -3, target is 3
            // does -2 and 7 give us target of 3, no its more, move right ptr
            // -2 and 5 gives us 3, add to tuple
    // at -2, target is 2
    //      does -3 and 7 give us 2? no its greater, move right ptr down
    //      -3 and 5, target hit, but tuple already in the set
    // 0, target is 0
    //      -3 and 7, more than, move right ptr down
    //      -3 and 5, more than, move right ptr down
    //      -3 and 1, less than, move left up
    //       -2 and 1, less than, move left up, skipping 0
    //        1 and 1, greater than, move right down
    //          left and right hit each other, break

    // [0,0,0]
    // [0, 1, 1]

    // not sure how to compare triplets and ignore their order when comparing? could temporarily convert to a set and compare those
    // triplet [1, 2, 1] to set is [1, 2] which would be same as set [2, 1, 1] -> [2, 1]
    // compare by set

    vector<vector<int>> threeSum(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());

        set<vector<int>> set;

        for (int i = 0; i < nums.size(); ++i) //sorted two sum for each number
        {
            int target = -nums[i];
            cout << target << endl;
            // two ptr

            int left = i + 1;
            int right = nums.size() - 1;

            while (left < right)
            {
                if (left == i) ++left;  //skip over targeted index
                if (right == i) --right;

                int sum = nums[left] + nums[right];

                if (sum == target)
                {
                    // check if triplet is already in set, need fast lookup for this
                    // unordered_map (near O(1)) .. set of ints -> their triplet as a vector. can just check if the key exists in the map
                    // add if not

                    // sort the triplet. all sorted triplets will be the same.
                    // triplets can be a set of sorted vectors

                    vector<int> triplet;
                    triplet.push_back(nums[i]);
                    triplet.push_back(nums[left]);
                    triplet.push_back(nums[right]); // [1,1,0], [0,1,1], sort -> [0,1,1] == [0,1,1]

                    sort(triplet.begin(), triplet.end());

                    set.insert(triplet); // should only allow unique triplets into the set

                    //continue search
                    ++left;
                    -- right;
                }
                else if (sum < target)
                {
                    ++left;
                }
                else if (sum > target)
                {
                    --right;
                }
            }
        }
        
        vector<vector<int>> res;

        for (vector<int> triplet : set)
        {
            res.push_back(triplet);
        }

        return res;
    }
};
