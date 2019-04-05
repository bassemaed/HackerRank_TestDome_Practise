/*
Implement the unique_names method. When passed two vectors of names, it will
return a vector containing the names that appear in either or both vectors.
The returned vector should have no duplicates.

For example, calling unique_names(std::vector<std::string>{"Ava", "Emma", "Olivia"}, std::vector<std::string>{"Olivia", "Sophia", "Emma"})
should return a vector containing Ava, Emma, Olivia, and Sophia in any order.
*/

#include <iostream>
#include <vector>

using namespace std;

std::vector<std::string> unique_names(/*const*/ std::vector<std::string>& names1, /*const*/ std::vector<std::string>& names2){
    int flag = 0;
    int flag2 = 0;
    int flag3 = 0;
    std::vector<std::string>::iterator it, it2, it3;   
    std::vector<std::string> result;
    for (it = names1.begin() ; it != names1.end(); ++it){
        flag2=0;
        for(it3 = it;it3 != names1.end();++it3){
            if(*it != *it3) flag2 ++;
        }
        if(flag2== (names1.end()-it-1))
        result.push_back(*it);
    } /*push all elements in string 1*/

    for (it2 = names2.begin() ; it2 != names2.end(); ++it2){
        flag = 0;
        flag3 = 0;
        for(it = names1.begin();it != names1.end();++it){
            if(*it2 !=*it) flag ++;
        }
        for(it3 = it2;it3 != names2.end();++it3){
            if(*it2 != *it3) flag3 ++;
        }
        if(flag==names1.size() && flag3== (names2.end()-it2-1)) result.push_back(*it2);
    }
    return result;
}

#ifndef RunTests
int main()
{
    std::vector<std::string> names1 = {"Ava", "Emma", "Olivia"};
    std::vector<std::string> names2 = {"Olivia", "Sophia", "Emma"};

    std::vector<std::string> result = unique_names(names1, names2);
    for(auto element : result)
    {
        std::cout << element << ' '; // should print Ava Emma Olivia Sophia
    }
}
#endif
