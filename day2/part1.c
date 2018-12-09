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
    int letterArray[26] = {0};
    int dubsNTripsArray [2];
    int asciiMax = 122;
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
        for (int i = 0; i < strlen(line); i++){
            // 97 - 122 = a - z in ascii
            
            printf("character is %c\n",line[i]);
        }
    }
    return 0;
}
