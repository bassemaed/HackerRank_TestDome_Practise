#include <bits/stdc++.h>

using namespace std;

// Complete the findDigits function below.

int findDigits(int n) {
    int CurrNum = n;
    int InNum = n;
    int Result = 0;
    while (InNum) {
        CurrNum = InNum%10;
        InNum /= 10;
        if(CurrNum != 0){
            if((n % (int)CurrNum) == 0) Result++;
        }
    }
    return Result;
}
int main(){
    ofstream fout(getenv("OUTPUT_PATH"));
    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    for (int t_itr = 0; t_itr < t; t_itr++) {
        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        int result = findDigits(n);
        fout << result << "\n";
    }
    fout.close();
    return 0;
}
