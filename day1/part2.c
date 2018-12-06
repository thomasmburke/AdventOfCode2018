#include <limits.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#define MYLIMIT 16384

int is_repeat(long int check, long int *vals, int lim){
  int res = 0;

  for(int i = 0; ((res == 0) && (i < lim)); i++)
    res += (check == vals[i]) ? 1 : 0;

  return res;
}


int main(){
    char *line;
    int lineMax;
    FILE *fp = fopen("input.txt", "r");
    long int freq = 0;
    long int delta;
    //ssize_t currentLine;
    short int isRepeat = 0;
    long int fList[640000];
    int fCount = 1; // where to write next in f_list
    if (LINE_MAX >= MYLIMIT) {
    // Use maximum line size of MYLIMIT. If LINE_MAX is
    // bigger than our limit, sysconf() can't report a
    // smaller limit.
        lineMax = MYLIMIT;
    } 
    else {
        long limit = sysconf(_SC_LINE_MAX);
        lineMax = (limit < 0 || limit > MYLIMIT) ? MYLIMIT : (int)limit;
    }

    // lineMax + 1 leaves room for the null byte added by fgets().
    line = malloc(lineMax + 1);
    if (line == NULL) {
    // out of space
        return -1;
    }

    while (!isRepeat){
        // Verify that a full line has been read ...
        // If not, report an error or prepare to treat the
        // next time through the loop as a read of a
        // continuation of the current line.
        //currentLine = fgets(line, lineMax + 1, fp);
        if (fgets(line, lineMax + 1, fp) == NULL){
            // return to the beginning of the file
            fseek(fp, 0, SEEK_SET);
            fgets(line, lineMax + 1, fp);
        }
        delta = strtol(line, NULL, 0);
        freq  += delta;
        printf("line was : %ld  Frequency at : %ld\n", delta, freq);
        if (is_repeat(freq, fList, fCount)){
            printf("Duplicate is %ld items in list %d\n", freq, fCount);
            isRepeat = 1;
        }
        else{
            fList[fCount++] = freq;
        }
    }
    free(line);
    return 0;
}
