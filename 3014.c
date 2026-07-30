int minimumPushes(char* word) 
{
    int result = 0;

    for (int i = 0; word[i] != '\0'; i++) 
    {
        result += (i / 8) + 1;
    }

    return result;
}
