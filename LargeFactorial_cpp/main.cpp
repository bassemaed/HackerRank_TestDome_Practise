#include <bits/stdc++.h>

using namespace std;

#define MAX     500
// Complete the extraLongFactorials function below.
void extraLongFactorials(int n) {
    int ResultArr[MAX] ={0};
    int val = 2;
    int Size = 1;
    int Counter = 0;
    int Num =0;
    ResultArr[0] = 1;
    while(val <= n){
x        Counter = 0;
        while(Counter < Size){
            ResultArr[Counter] = ResultArr[Counter]*val;
            ResultArr[Counter] = ResultArr[Counter] + Num;
            Num =  ResultArr[Counter] /10;
            ResultArr[Counter] = ResultArr[Counter]%10;
            Counter++;
        }
        while(Num !=0){
            ResultArr[Size] = Num%10;
            Num =  Num/10;
            Size++;
        }
        val++;
    }


    for(int i=Size-1;i>=0;i--)
        cout<<ResultArr[i];
}
int main(){
    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    extraLongFactorials(n);
    return 0;
}

