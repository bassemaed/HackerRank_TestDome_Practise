#include <bits/stdc++.h>

using namespace std;

// Complete the utopianTree function below.
int utopianTree(int n) {
    int OutH = 1;
    if(n<=0) return OutH;
    else{
        for(int i=1;i<=n;i++){
            if(i%2 ==0) OutH ++;
            else OutH = OutH*2;
        }

    }
    return OutH;
}
int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    for (int t_itr = 0; t_itr < t; t_itr++) {
        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        int result = utopianTree(n);
        fout << result << "\n";
    }
    fout.close();
    return 0;
}
