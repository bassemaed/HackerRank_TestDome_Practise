#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

int countingValleys(int steps, string path) {
    int CurrLvl = 0;
    int i = 0;
    int Result = 0;
    for(i=0;i<steps;i++){
        switch(path[i]){
            case ('U'):
                CurrLvl = CurrLvl+1;
                break;
            case ('D'):
                if(CurrLvl ==0)
                    Result++;
                CurrLvl = CurrLvl-1;
                break;
            default:
               cout<<"Wrong Input"<<endl;
                break;
        }
    }
    return Result;
}

int main(){
    ofstream fout(getenv("OUTPUT_PATH"));
    string steps_temp;
    getline(cin, steps_temp);
    int steps = stoi(ltrim(rtrim(steps_temp)));
    string path;
    getline(cin, path);
    int result = countingValleys(steps, path);
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
