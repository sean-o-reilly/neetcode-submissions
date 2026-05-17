class Solution {
public:
    void recurse(int i, std::vector<int> combo, const int target,
        const std::vector<int>& candidates,
        std::vector<std::vector<int>>& results,
        std::unordered_set<int> skipped)
    {
        auto sum = std::accumulate(combo.begin(), combo.end(), 0);

        if (sum > target)
        {
            return;
        }
        else if (sum == target)
        {
            // insert if not already in
            if (std::ranges::find(results.begin(), results.end(), combo) == results.end())
                results.push_back(combo);
            return;
        }

        if (i >= candidates.size()) return;
        // skip
        auto newSkipped = skipped;
        newSkipped.insert(candidates.at(i));

        recurse(i + 1, combo, target, candidates, results, newSkipped);
        
        if (!skipped.contains(candidates.at(i)))
        {
            // keep
            combo.push_back(candidates.at(i));
            recurse(i + 1, combo, target, candidates, results, skipped);
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target)
    {
        std::vector<std::vector<int>> results;
        recurse(0, {}, target, candidates, results, {});
        return results;
    }
};

// if a number is ever skipped, add it to a skipped set and never choose it again

// [1, 4] target 5


/*
void recurse(int i, combo, target, candidates&, result&)
    if i >= candidates.size
        stop

    if sum(combo) > target
        stop
    else if sum == target
        add combo to results
        stop
    
    // recurse (skip)
    recurse(i + 1, combo, ...)

    // recurse (keep)
    combo.pushback (candidates.at(i))
    recurse(i + 1, combo, ...)

main:
    result = []
    recurse(0, {}, target, candidates, result)


--------------------------------------------------------------------- 

recursively branch, generate combos
    choose head, or don't -> "choose" means add it to this branch's combo set
    move on to the rest of the list

positive numbers only

possible combos
[]
[9]
[9, 2, 2, 4, 6, 1, 5]
[9, 2, 4, 1]


*/
