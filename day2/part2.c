#include <limits.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#define MYLIMIT 16384

void append(char* s, char c) {
    printf("in append...\n");
    int len = strlen(s);
    printf("%d\n", len);
    s[len] = c;
    s[len+1] = '\0';
    printf("end of append...\n");
}

//append(str, tmp)

char check_id(char * id, char * idToCompare)[]{
    char commonLetters[40];
    memset(commonLetters, '\0', sizeof(commonLetters));
    int misplacedChar = 0;
    for (int i = 0; *id != '\n'; id++,idToCompare++,i++){
        printf("%c\n",*id);
        if (*id == *idToCompare){
            //commonLetters = id;
            //append(commonLetters, *id);
            commonLetters[i] = *id;
            //printf("commonLetters character: %c\n", *commonLetters);
            //printf("commonLetters: %s\n",commonLetters);
            //commonLetters++;
        }
        /*
        else{
            misplacedChar++;
        }
        // check to see if more than one char is misplaced
        if(misplacedChar > 1){
            char * nullCharArray = "a";
            return nullCharArray;
        }
        
        char * nullCharArray = "a";
        return nullCharArray;
        printf("%c\n", *id);
    }
    return commonLetters;*/
    }
    return commonLetters;
    char * nullCharArray = "a";
    return nullCharArray;
}

int main(){
    char *line;
    int line_max;
    FILE *fp = fopen("input.txt", "r");
    // an array of character arrays. each spot in the array points to an 
    // address of a character array
    char **ids = calloc (1000, sizeof(char*)); // assuming there are only 1000 lines in the file
    int lineCount = 0;
    if (LINE_MAX >= MYLIMIT) {
    // Use maximum line size of MYLIMIT. If LINE_MAX is
    // bigger than our limit, sysconf() can't report a
    // smaller limit.
        line_max = MYLIMIT;
    } 
    else {
        long limit = sysconf(_SC_LINE_MAX);
        line_max = (limit < 0 || limit > MYLIMIT) ? MYLIMIT : (int)limit;
    }

    // line_max + 1 leaves room for the null byte added by fgets().
    line = malloc(line_max + 1);
    if (line == NULL) {
    // out of space
        return -1;
    }

    while (fgets(line, line_max + 1, fp) != NULL) {
        // Verify that a full line has been read ...
        // If not, report an error or prepare to treat the
        // next time through the loop as a read of a
        // continuation of the current line.
        ids[lineCount] = line;
        if (!lineCount){
            lineCount++;
            continue;
        }
        for (int i = 0; i < lineCount; i++){
            char * commonLetters = check_id(line, ids[lineCount]);
            return 0;
            if(commonLetters[0] != 'a'){
                printf("%s\n", commonLetters);
                free(ids);
                free(line);
                return 0;
            }
        }
        return 0;
    }
    free(ids);
    free(line);
return 0;
}
