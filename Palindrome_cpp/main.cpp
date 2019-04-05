/*
A palindrome is a word that reads the same backward or forward.

Write a function that checks if a given word is a palindrome. Character case should be ignored.

For example, isPalindrome("Deleveled") should return true as character case should be ignored,
resulting in "deleveled", which is a palindrome since it reads the same backward and forward.

*/
#include <string>
#include <stdexcept>
#include <iostream>

using namespace std;
bool isPalindrome(const std::string& word)
{
    size_t len = word.size();
    for (size_t i = 0;i<len;i++){
        if(toupper(word[i]) != toupper(word[len-i-1])) return 0;
    }
    return 1;
}

#ifndef RunTests
int main()
{
    std::cout << isPalindrome("Deleveled");
}
#endif
