bool threeConsecutiveOdds(int* arr, int arrSize) {
    int counter = 0;
    bool returnVal= false;
    if(arrSize < 3)
    {
        return false;
    }
    for (int i = 0; i < arrSize; i++)
    {
        if((arr[i] % 2) != 0)
        {
            counter++;
            if(counter == 3)
            {
                return true;
            }
        }
        else
        {
            counter = 0;
        }
    }
    return returnVal;
}
