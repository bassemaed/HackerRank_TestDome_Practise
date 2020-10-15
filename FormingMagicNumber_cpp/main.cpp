#include <bits/stdc++.h>

using namespace std;
int MagicMat[8][3][3] = {
    {{8, 1, 6}, {3, 5, 7}, {4, 9, 2}},
    {{6, 1, 8}, {7, 5, 3}, {2, 9, 4}},
    {{4, 9, 2}, {3, 5, 7}, {8, 1, 6}},
    {{2, 9, 4}, {7, 5, 3}, {6, 1, 8}},
    {{8, 3, 4}, {1, 5, 9}, {6, 7, 2}},
    {{4, 3, 8}, {9, 5, 1}, {2, 7, 6}},
    {{6, 7, 2}, {1, 5, 9}, {8, 3, 4}},
    {{2, 7, 6}, {9, 5, 1}, {4, 3, 8}},
};
// Complete the formingMagicSquare function below.
int formingMagicSquare(vector<vector<int> > s) {
    int CostArr[8] = {0,0,0,0,0,0,0,0};
    int i = 0;
    int j= 0;
    int k = 0;
    int Result = 0;
    for(i=0;i<8;i++){
        for(j=0;j<3;j++){
            for(k=0;k<3;k++){
                CostArr[i] += abs(MagicMat[i][j][k] - s[j][k]);
            }
        }
    }
    int n = sizeof(CostArr)/sizeof(CostArr[0]);
    sort(CostArr, CostArr+n);
    return CostArr[0];
}
int main(){
    ofstream fout(getenv("OUTPUT_PATH"));
    vector<vector<int>> s(3);
    for (int i = 0; i < 3; i++) {
        s[i].resize(3);
        for (int j = 0; j < 3; j++) {
            cin >> s[i][j];
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    int result = formingMagicSquare(s);
    fout << result << "\n";
    fout.close();
    return 0;
}

