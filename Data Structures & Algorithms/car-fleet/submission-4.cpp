class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed)
    {
        using Pair = std::pair<int, int>;
        std::vector<Pair> cars;

        for (int i = 0; i < position.size(); ++i)
        {
            cars.push_back({position.at(i), speed.at(i)});
        }

        std::ranges::sort(cars, [](const Pair& a, const Pair& b){return a.first < b.first;});

        std::vector<double> times(position.size(), -1);

        for (int i{}; i < cars.size(); ++i)
        {
            auto& p = cars.at(i);
            times.at(i) = (target - (double)p.first) / (double)p.second;
        }

        for (auto n : times)
            std::cout << n << " ";
        std::cout << std::endl;

        double slowest = 0.0;

        int fleets{};

        for (int i = times.size() - 1; i >= 0; --i)
        {
            if (times.at(i) > slowest)
            {
                slowest = times.at(i);
                ++fleets;
            }
        }

        return fleets;
    }
};


/*

[(0, 1), (1, 2), (4, 2), (7, 1)]



*/