/*
Implement function countNumbers that accepts a sorted vector of unique integers and,
efficiently with respect to time used, counts the number of vector elements that are
less than the parameter lessThan.

For example, for vector v containing { 1, 3, 5, 7 }, countNumbers(v, 4) should
return 2 because there are two vector elements less than 4.
*/
#include <vector>
#include <stdexcept>
#include <iostream>
#include <iterator>
#include <algorithm>

using namespace std;
int countNumbers(const vector<int>& sortedVector, int lessThan){
    int n = lessThan;
    vector<int> target;
    return std::lower_bound(sortedVector.begin(), sortedVector.end(), lessThan) - sortedVector.begin();
}
#ifndef RunTests
int main()
{
    std::vector<int> v { 1, 3, 5, 7 };
    std::cout << countNumbers(v, 4);
}
#endif
