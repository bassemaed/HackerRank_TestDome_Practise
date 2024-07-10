int minOperations(char** logs, int logsSize) {
    int level = 0;
    for (int i=0;i<logsSize;i++)
    {
        if (strcmp(logs[i], "../") == 0)
        {
            if (level<0)
                level+=1;
        }
        else if (strcmp(logs[i], "./") == 0)
            level = level;
        else
            level -=1;
    }
    return (-level);
}
