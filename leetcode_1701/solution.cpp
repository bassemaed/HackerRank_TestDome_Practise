class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        double initialTime{0};
        double currentTime {initialTime};
        double avgWaitTime {0};
        double waitTime {0};
        for (auto& inner_vec : customers)
        {
            if(currentTime<inner_vec[0])
            {
                currentTime = inner_vec[0] + inner_vec[1];
            }
            else
            {
                currentTime += inner_vec[1];
            }
            avgWaitTime += (currentTime - inner_vec[0]);
        }
        avgWaitTime = avgWaitTime/customers.size();
        return avgWaitTime;
    }
};
