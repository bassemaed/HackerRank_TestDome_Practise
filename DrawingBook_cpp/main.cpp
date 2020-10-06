#include <bits/stdc++.h>

using namespace std;

int pageCount(int n, int p) {
    long Result= 0;
    long flipfront = 0;
    long flipback = 0;
    bool lastpagepair = 0;
    long pagepairs=0;
    if(p==1 || p==n){
        Result = 0;
        return Result;
    }
    else{
        if((n%2)==0){
           pagepairs = (long)((n/2.0)+1);
            lastpagepair = 0;
        }
        else{
            pagepairs = (long)(((n-1)/2)+1);
            lastpagepair = 1;
        }
        if((p==n-1) && lastpagepair){
            flipback = 0;
            flipfront =pagepairs-1;
        }
        else if((p==n-1) && !lastpagepair){
                flipback =1;
                flipfront = pagepairs;
        }
        else{
            if(p%2 ==0)flipfront = (long)(p/2.0);
            else flipfront = (long)((p-1)/2.0);
            flipback = pagepairs - flipfront-1;
        }
        if(flipback<flipfront)
            Result = int(flipback);
        else if(flipfront<flipback)
            Result = int(flipfront);
        else
            Result = int(flipback);
        return Result;
    }
}
int main(){
    ofstream fout(getenv("OUTPUT_PATH"));
    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    int p;
    cin >> p;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    int result = pageCount(n, p);
    fout << result << "\n";
    fout.close();
    return 0;
}
