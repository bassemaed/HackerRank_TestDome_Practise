class Solution:
    def averageWaitingTime(self, customers: List[List[int]]) -> float:
        initialTime = customers[0][0]
        currentTime = initialTime
        avgWaitTime = 0
        for customer in customers:
            if(currentTime<customer[0]):
                currentTime = customer[0] + customer[1]
            else:
                currentTime = currentTime + customer[1]
            waitTime = currentTime - customer[0]
            avgWaitTime += waitTime
        avgWaitTime = avgWaitTime/(len(customers))
        return avgWaitTime
