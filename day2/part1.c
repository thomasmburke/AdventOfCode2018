#include <limits.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#define MYLIMIT 16384

int main(){
    char *line;
    int line_max;
    FILE *fp = fopen("input.txt", "r");
    int letterArray[26] = {0}, c = 0;
    int doubles = 0, triples = 0, doubleFlag = 0, tripleFlag = 0, total;
    int asciiConversion = 'a'; // 97

    if (line_max >= MYLIMIT) {
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
    while (fgets(line, line_max + 1, fp) != NULL) {
        // Verify that a full line has been read ...
        // If not, report an error or prepare to treat the
        // next time through the loop as a read of a
        // continuation of the current line.
        while (line[c] != '\n') {
            // 97 - 122 = a - z in ascii
            // increment array holding character counts
            letterArray[line[c] - asciiConversion]++;
            //printf("character is %c\n",line[c]);
            // increment character indexer
            c++;
        }
        //iterate through letter array in search for doubles and triples
        for (int i = 0; i < sizeof(letterArray); i++){
            if (!doubleFlag && letterArray[i] == 2){
                // increment doubles count
                doubles++;
                // set doubles boolean
                doubleFlag++;
            }
            if (!tripleFlag && letterArray[i] == 3){
                // increment triples count
                triples++;
                // set triples boolean
                tripleFlag++;
            }
            if (doubleFlag && tripleFlag){
                break;
            }

        }
        // Reset double and triple booleans
        doubleFlag = tripleFlag = 0;
        // Reset Array to all zeros for the next line
        memset(letterArray, 0, sizeof(letterArray));
        // Reset character index to 0
        c = 0;
    }
    free(line);
    total = doubles * triples;
    printf("checksum is %i\n", total);
    return 0;
}
