/*
Write a function that, when passed a list and a target sum, returns, efficiently with
respect to time used, two distinct zero-based indices of any two of the numbers,
whose sum is equal to the target sum. If there are no two numbers, the function should return (-1, -1).

For example, findTwoSum({ 3, 1, 5, 7, 5, 9 }, 10) should return a std::pair<int, int> containing any of the following pairs of indices:

    0 and 3 (or 3 and 0) as 3 + 7 = 10
    1 and 5 (or 5 and 1) as 1 + 9 = 10
    2 and 4 (or 4 and 2) as 5 + 5 = 10
*/

#include <stdexcept>
#include <iostream>
#include <vector>
#include <utility>

#define SOL_1 /* delete if Solution 2 is the desired option */

using namespace std;

#ifdef SOL_1

/* This Solution takes time */

typedef struct{
    int sum;
    int iter1;
    int iter2;
}mystruct;

pair<int, int> findTwoSum(const vector<int>& list, int sum){
    int iter = 0;
    vector<mystruct> myvector;
    pair<int, int> result;
    for(int i=0;i<list.size();i++){
        for( int j=i+1;j<list.size();j++){
            myvector.push_back ({list[i]+list[j], i, j});
            iter++;
        } 
    }
    for(int i=0;i<iter;i++){
        if(myvector[i].sum == sum) {
            result.first = myvector[i].iter1;
            result.second = myvector[i].iter2;
            return result;
        }
    }
    result.first = -1;
    result.second = -1;
    return result;
}
/*end of Solution 1 */
#elif
pair<int, int> findTwoSum(const vector<int>& list, int sum){
    unordered_map<int,int> SumMap;
    size_t listsize = list.size();
    for(size_t i=0;i< listsize;i++){
        auto SumMapiterator = SumMap.find(sum-list[i]);
        if(SumMapiterator != SumMap.end())
            return make_pair(i,SumMapiterator->second);
        SumMap[list[i]] = i;
    }
    return make_pair(-1,-1);
}

#endif

#ifndef RunTests
int main()
{
    std::vector<int> list = {3, 1, 5, 7, 5, 9};
    std::pair<int, int> indices = findTwoSum(list, 10);
    std::cout << indices.first << '\n' << indices.second;
}
#endif
