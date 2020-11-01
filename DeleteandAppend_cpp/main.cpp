#include <bits/stdc++.h>

using namespace std;

// Complete the appendAndDelete function below.
string appendAndDelete(string s, string t, int k) {
    string Result;
    int mymoves = 0;
    int OutLen = t.length();
    int InLen = s.length();
    bool DEL = 0;
    bool APP = 0;
    int lowindex = 0;
    int i=0, j=0, p=0;
    if(s.compare(t) ==0){
        mymoves = 1;
        DEL =1;
    }
    else{
        if(OutLen==InLen){
            /* Both are equal */
            lowindex = InLen;
            for(i = OutLen-1;i>=0;i--){
                if(t[i]!=s[i])
                    lowindex = i;
            }
            if(lowindex ==0) DEL=1;
            if(lowindex == InLen) APP = 1;
            mymoves += (InLen - lowindex);
            mymoves += (OutLen - lowindex);
        }
        else if(OutLen > InLen){
            /*Output String is larger*/
            lowindex = InLen-1;
            for(i = InLen-1;i>=0;i--){
                if(t[i]!=s[i])
                    lowindex = i;
            }
            if(lowindex==InLen-1){
                cout<<"here" <<endl;
            }
            mymoves += (InLen - lowindex);
            mymoves += (OutLen - lowindex);
        }
        else{
            /* The Input string is larger */
            lowindex = OutLen;
            for(i = OutLen-1;i>=0;i--){
                if(t[i]!=s[i])
                    lowindex = i;
            }
            DEL=1;
            mymoves += (InLen - lowindex);
            mymoves += (OutLen -lowindex);
        }

    }
    cout<<"low index: "<<lowindex<<endl;
    cout<<"moves needed: "<<mymoves<<endl;

    if(mymoves==k)
        Result = "Yes";
    else if(mymoves<k && (DEL||APP))
        Result = "Yes";
    else
        Result = "No";
    return Result;
}

int main(){
    ofstream fout(getenv("OUTPUT_PATH"));
    string s;
    getline(cin, s);
    string t;
    getline(cin, t);
    int k;
    cin >> k;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    string result = appendAndDelete(s, t, k);
    fout << result << "\n";
    fout.close();
    return 0;
}
