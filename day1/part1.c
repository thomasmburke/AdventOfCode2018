#include <limits.h>
#include <stdio.h>
#include <unistd.h>
#define MYLIMIT 16384


int main(){
    char *line;
    int line_max;
    FILE *fp = fopen("input.txt", "r");
    long int freq = 0;
    long int delta;
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
        delta = strtol(line, NULL, 0);
        freq  += delta;
        printf("line was : %ld  Frequency at : %ld\n", delta, freq);
    }
    free(line);
    return 0;
}
