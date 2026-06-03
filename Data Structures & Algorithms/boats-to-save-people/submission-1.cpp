class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit)
    {
        std::ranges::sort(people);
        int boats = 0;

        int left = 0;
        int right = people.size() -1;

        while (left <= right)
        {
            if (left == right)
            {
                ++boats;
                break;
            }
            
            if (people.at(left) + people.at(right) > limit)
            {
                ++boats;
                std::cerr << people.at(right) << std::endl;
                --right;
            }
            else
            {
                ++boats;
                std::cerr << people.at(left) << " " << people.at(right) << std::endl;
                ++left;
                --right;
            }
        }
        
        return boats;
    }
};

/*
sort then two ptr from left and right end

boats():
    sort people

    boats = 0
    left = 0, right = people.size - 1

    while left < right
        if at(left) + at(right) > limit
            ++boats
            --right # move to left
        else
            ++boats
            --right
            ++left

    return boats + (people is odd)

*/

/*
two ptr:
    two start frmo beginning
    start from left and right ends

    modify data in place with 0 or -1
    avoid O(n^2)

store compliments in map?
limit = 6
have a 1 -> need something <=5 but as close to 5 as possible
have a num == limit, ++boats needed
have a 2 -> need <=4


sorting wont work with pairing frmo start
use left and right end pointers
[1,2,4,5] should return 2

[5,1,4,2], limit = 6
pair 5 and 1
pair 4 and 2
return 2

[5,1,2,4,2,3,3,3]
[1,2,2,3,3,3,4,5]

[1,3,2,3,2], limit = 3
[1,2,2,3,3]
pair 1 and 2
leave 3 alone
leave 3 alone
leave 2 alone
return 4

[1,1,1,1,1,10,10,10,...10,10,9,9,9,9,9] limit = 10]


*/