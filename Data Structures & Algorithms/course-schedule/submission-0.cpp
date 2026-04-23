class Solution
{
public:
    using DepMap = std::unordered_map<int, vector<int>>;

    bool canTakeCourse(DepMap& depMap, std::set<int> used, int currCourse)
    {
        std::cout << "\tSearch " << currCourse << std::endl;
        // base case: no dependencies, can take class
        auto& deps = depMap[currCourse];

        if (deps.empty())
        {
            return true;
        }

        if (used.count(currCourse))
        {
            return false; // Cycle!
        }

        used.insert(currCourse);
        
        for (auto dep : deps)
        {
            if (!canTakeCourse(depMap, used, dep))
            {
                return false;
            }
        }

        return true; // all course can be taken
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites)
    {
        DepMap depMap;

        for (auto vec : prerequisites) depMap[vec[0]].push_back(vec[1]);

        for (auto [key, vertices] : depMap)
        {
            std::cout << key << " : ";
            for (auto vertex : vertices) std::cout << vertex << " ";
            std::cout << std::endl;

            if (!canTakeCourse(depMap, std::set<int>{}, key)) return false;
        }

        return true;
    }
};


/*

"A has dependency B"
0-1
1-2
3-4
4-2
1-3
return true, no circular dependencies

Depedencies:
    0 : 1
    1 : 2, 3
    2 : None
    3 : 4
    4 : 2

------------

Use DFS with cycle detection on all nodes?

Solution:
    Stack of courses

    Build a hashmap of dependencies. This is a directed graph

    For each key in the hashmap
        For each vertex in value
            See if all dependencies can be reached
        
        As we traverse for this key, track which "dependencies" we've used
            So when we're searching 0's dependencies recursively and find 5 needs 0 and 
            0 is in the dependecies, we can return false. Remove dependencies we've found

    Use memoization somewhere to reduce redundant calculations





    0 : 1
    1 : 2, 3
    2 : 4
    3 : None
    4 : 5
    5 : 0

    Is 0 possible?
        1 possible?
            2 possible?
                4 possible?
                    5 possible?
                        0 possible - no, its in our current dependencies, return false 
                            Maybe we cache this result in memo?
            3 possible?

    Is 1 possible?
        2 possible?
            4 possible?
                5 possible?
                    0 possible?
                        1 possible? - no its in our dependencies
    Is 2 possible?
        4 possible?
            5 possible?
                0 possible?
                    1 possible?
                        2 possible? - nope, cycle
    
    Is 3 possible?
        Yes, no dependencies
    
    Is 4 possible?
        5
            0
                1
                    2
                        4 - return false
    
    Is 5 possible?
        0
            1
                2
                    4
                        5 - return false
                3


*/