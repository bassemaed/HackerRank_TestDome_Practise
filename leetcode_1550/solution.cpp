class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int counter = 0;
        bool returnVal= false;
        if(arr.size() < 3)
        {
            return false;
        }
        for (auto it = arr.begin(); it != arr.end()-2; ++it)
        {
            if((*it % 2 == 1) && (*(it+1) % 2 == 1) && (*(it+2) % 2 == 1))
               return true;
        }
        return false;
    }
};
