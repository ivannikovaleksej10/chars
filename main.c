#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

char *randstring(int length);

int main(int argc, char *argv[]) {
    if(argc<=1) {
        printf("You did not feed me arguments, I will die now :( ...\n");
        return 1;
     } 
     int arg1 = atoi(argv[1]);

     printf("%s\n", randstring(arg1));
}

char *randstring(int length) {    
    int mySeed = rand() % 20;
    char *string = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789,.-#'?!";
    size_t stringLen = strlen(string);        
    char *randomString = NULL;

    srand(time(NULL) * length + ++mySeed);

    if (length < 1) {
        length = 1;
    }

    randomString = malloc(sizeof(char) * (length +1));

    if (randomString) {
        short key = 0;

        for (int n = 0;n < length;n++) {            
            key = rand() % stringLen;          
            randomString[n] = string[key];
        }

        randomString[length] = '\0';

        return randomString;
    }
    else {
        printf("No memory");
        exit(1);
    }
    free(randomString);
    return 0;
}