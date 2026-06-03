#include <limits.h>

int earliestFinishTime(int* landStartTime, int landStartTimeSize,
                       int* landDuration, int landDurationSize,
                       int* waterStartTime, int waterStartTimeSize,
                       int* waterDuration, int waterDurationSize)
{
    int bestLandFinish = INT_MAX;
    int bestWaterFinish = INT_MAX;

    // earliest finishing land ride
    for(int i = 0; i < landStartTimeSize; i++)
    {
        int finish = landStartTime[i] + landDuration[i];

        if(finish < bestLandFinish)
        {
            bestLandFinish = finish;
        }
    }

    // earliest finishing water ride
    for(int i = 0; i < waterStartTimeSize; i++)
    {
        int finish = waterStartTime[i] + waterDuration[i];

        if(finish < bestWaterFinish)
        {
            bestWaterFinish = finish;
        }
    }

    int result1 = INT_MAX; // land -> water
    int result2 = INT_MAX; // water -> land

    for(int i = 0; i < waterStartTimeSize; i++)
    {
        int start =
            (bestLandFinish > waterStartTime[i])
            ? bestLandFinish
            : waterStartTime[i];

        int finish = start + waterDuration[i];

        if(finish < result1)
        {
            result1 = finish;
        }
    }

    for(int i = 0; i < landStartTimeSize; i++)
    {
        int start =
            (bestWaterFinish > landStartTime[i])
            ? bestWaterFinish
            : landStartTime[i];

        int finish = start + landDuration[i];

        if(finish < result2)
        {
            result2 = finish;
        }
    }

    return (result1 < result2) ? result1 : result2;
}
