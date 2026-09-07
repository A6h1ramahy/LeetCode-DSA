char* getHint(char* secret, char* guess) {
    int s[10] = {0};
    int g[10] = {0};
    int bull = 0;
    int cow = 0;

    for (int i = 0; secret[i] != '\0'; i++) 
    {
        if (secret[i] == guess[i]) 
        {
            bull++;
        } 
        else 
        {
            s[secret[i] - '0']++;
            g[guess[i] - '0']++;
        }
    }

    for (int i = 0; i < 10; i++) 
    {
        if(s[i] < g[i])
        {
            cow += s[i];
        }
        else
        {
            cow += g[i];
        }
    }

    char* result = malloc(20 * sizeof(char));
    sprintf(result, "%dA%dB", bull, cow);

    return result;
}