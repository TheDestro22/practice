#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>

std::vector<int> unique_sorted(std::vector<int> v)
{
    std::sort(v.begin(), v.end());
    v.erase(std::unique(v.begin(), v.end()), v.end());
    return v;
}

void print_vec(const std::vector<int> &v)
{
    for (size_t i = 0; i < v.size(); ++i)
    {
        if (i)
            std::cout << ' ';
        std::cout << v[i];
    }
    std::cout << '\n';
}

int main(int argc, char **argv)
{
    // If no command-line ints are provided, demonstrate with sample data.
    if (argc <= 1)
    {
        std::vector<int> sample{5, 3, 7, 3, 2, 5, 9};
        std::cout << "Sample input: ";
        print_vec(sample);
        auto out = unique_sorted(sample);
        std::cout << "Unique sorted: ";
        print_vec(out);
        return 0;
    }

    // Parse command-line arguments as integers.
    std::vector<int> values;
    for (int i = 1; i < argc; ++i)
    {
        std::istringstream iss(argv[i]);
        int x;
        if (!(iss >> x))
        {
            std::cerr << "Warning: skipping non-integer argument \"" << argv[i] << "\"\n";
            continue;
        }
        values.push_back(x);
    }

    if (values.empty())
    {
        std::cerr << "No valid integers provided.\n";
        return 1;
    }

    auto result = unique_sorted(values);
    std::cout << "Result (unique sorted): ";
    print_vec(result);
    return 0;
}