#include <iostream>
#include <vector>

template<typename T>
void print(std::vector<T> const &v)
{
    for (auto &i: v)
        std::cout << i << ' ';

    std::cout << '\n';
}

// Split a vector into sub-vectors of size n in C++
int main()
{
    // input vector of integers
    std::vector<int> v = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

    // split vector into sub-vectors each of size n
    int n = 4;

    // determine number of sub-vectors of size n
    int size = (v.size() - 1) / n + 1;

    // create array of vectors to store the sub-vectors
    std::vector<int> vec[size];

    // each iteration of this loop process next set of n elements
    // and store it in a vector at k'th index in vec
    for (int k = 0; k < size; ++k)
    {
        // get range for next set of n elements
        auto start_itr = std::next(v.cbegin(), k*n);
        auto end_itr = std::next(v.cbegin(), k*n + n);

        // allocate memory for the sub-vector
        vec[k].resize(n);

        // code to handle the last sub-vector as it might
        // contain less elements
        if (k*n + n > v.size())
        {
            end_itr = v.cend();
            vec[k].resize(v.size() - k*n);
        }

        // copy elements from the input range to the sub-vector
        std::copy(start_itr, end_itr, vec[k].begin());
    }

    // print the sub-vectors
    for (int i = 0; i < size; i++)
    {
        print(vec[i]);
    }

    return 0;
}
