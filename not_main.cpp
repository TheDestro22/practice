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
    
}