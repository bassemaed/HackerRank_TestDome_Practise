double averageWaitingTime(int** customers, int customersSize, int* customersColSize) {
    double initalTime = customers[0][0];
    double currentTime = initalTime;
    double avgWaitTime = 0.0;
    double waitTime;
    for(int i = 0; i< customersSize; i++)
    {
        if(currentTime<customers[i][0])
        {
            currentTime = customers[i][0] + customers[i][1];
        }
        else
        {
            currentTime = currentTime + customers[i][1];
        }
        waitTime = currentTime - customers[i][0];
        avgWaitTime += waitTime;
    }
    avgWaitTime = avgWaitTime/customersSize;
    return avgWaitTime;
}
