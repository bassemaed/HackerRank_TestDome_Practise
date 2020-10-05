#include <bits/stdc++.h>
#include <iostream>
#include <string>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

// Complete the dayOfProgrammer function below.
string dayOfProgrammer(int year) {
    string Result;
    Result.resize(17);
    if(year>=1919 && year <2700){
        /* Georgian Calendar */
        if(((year%400)==0) || ((year%4==0)&&(year%100!=0))){
            /*leap year in Georgian Calendar*/
            Result = "12.09.";
            Result.append(to_string(year));
        }
        else{
            /*not a leap year in Georgian Calendar*/
            Result ="13.09.";
            Result.append(to_string(year));
        }
    }
    else if(year>=1700 && year <1918){
        /*Julian Calendar */
        if(year%4 ==0){
            /*leap year in Julian Calendar */
            Result = "12.09.";
            Result.append(to_string(year));
        }
        else{
            /*not a leap year in Julian Calendar*/
            Result = "13.09.";
            Result.append(to_string(year));
        }
    }
    else if(year==1918){
        /*the odd year*/
        Result="26.09.1918";
    }
    else return 0;
    return Result;
}

int main(){
    ofstream fout(getenv("OUTPUT_PATH"));
    string year_temp;
    getline(cin, year_temp);
    int year = stoi(ltrim(rtrim(year_temp)));
    string result = dayOfProgrammer(year);
    fout << result << "\n";
    fout.close();
    return 0;
}

string ltrim(const string &str) {
    string s(str);
    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );
    return s;
}

string rtrim(const string &str) {
    string s(str);
    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );
    return s;
}
