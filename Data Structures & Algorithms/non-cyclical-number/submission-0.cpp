class Solution {
public:
    int sumOfSquares(int num)
    {
        int res = 0;

        std::string digits = to_string(num);
        for (auto ch : digits) // calculate square of each digit in number. could fail at large values of sum
        {
            int toSum = ch - '0';
            if (toSum == 0) continue;
            res += pow(toSum, 2);
        }

        return res;
    }

    bool isHappy(int n) 
    {
        int sum = n;
        std::unordered_set<int> visited;

        while (sum != 1)
        {
            sum = sumOfSquares(sum);

            if (visited.count(sum)) return false; // cycle detected

            visited.insert(sum);
        }

        return true;
    }
};

// 35
// sum of squares = 3^2 + 5^2

// if we keep doing this in an infinite loop and get a 1, return true

// if cycle, return false

// 100
// 1^2 + 0 + 0 = 1, return true, hits 1

// false: cycles
// 101
// 1^2 + 0 + 1^2 
// 1 + 0 + 1 = 2
// 2^2 = 4
    // 4^2 = 16
    // 1^2 + 6^2 = 37
    // 3^2 + 7^2 = 9 + 49
    // 58 
    // 25 + 64 = 89
    // 64 + 81
    // 145
    // 1 + 16 + 25
    // 42
    // 16 + 4 = 20
// 4 + 0 = 4
    // 16
    // 1^2 + 6^2 = 37
    // 3^2 + 7^2 = 9 + 49
    // 58 
    // 25 + 64 = 89
    // 64 + 81
    // 145
    // 1 + 16 + 25
    // 42
    // 16 + 4 = 20
    // 4 
    // 16..


// use a container of unique values, after calculating sum of squares, add the sum to the unique values container
// if we ever calculate the sum of squares and its already in the unque values "visited" container, return false
// if we get 1 at any point, return true

// keep looping until sum != 1
// may fail at unlucky numbers that don't hit cycles. <- but does this ever happen?

// 12908

// 1^2 + 2^2 + 9^2 + 0 + 64
// 5 + 81 + 64
// 150
// 1 + 25
// 26
// 4 + 36
// 40
// 16 + 0 <- will cycle
// 37. <- will cycle

// make this even faster, can we cache numbers that are known to cycle (like 16)?
