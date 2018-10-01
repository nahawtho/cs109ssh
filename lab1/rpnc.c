#include <stdio.h>

/*
 * Reverse Polish Notation (RPN) Calculator
 *
 * Accepts a single argument in RPN, evaluates it and prints the answer to stdout.
 * 
 * Returns -1 on error, 0 otherwise.
 */
int lines_in_file(char *fname);

int main(int argc, char *argv[]) {
    //int ununsed; // here to fail warnings test, remove it
    int number; // for calculations
    int lines;   
    char *fname = "/afs/cats.ucsc.edu/users/b/nahawtho/cs109/lab1/check.d    at";
    printf("%d lines", lines_in_file(fname));
    return 0;
}


int lines_in_file(char *fname){
    int lines;

    FILE *fp = fopen(fname, "r");
    if (fp) {
	printf("Have fp");
        lines = 0;
        while (!feof(fp)) {
		if (fgetc(fp) == '\n') lines++;
        }
    else {exit(0);}
    }
    fclose(fp);
    return lines;
}
