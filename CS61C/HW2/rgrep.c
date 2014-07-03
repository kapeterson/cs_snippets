/**
 * Restricted version of grep, as defined in the CS61C Spring 2014
 * course website for homework #2.
 *
 * You must not change this file.
 */

#include <stdio.h>
#include "matcher.h"

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <PATTERN>\n", argv[0]);
        return 2;
    }

    /* we're not going to worry about long lines */
    char buf[4096];

    while (!feof(stdin) && !ferror(stdin)) {
	if (!fgets(buf, sizeof(buf), stdin)) {
            break;
        }
	printf("OK do0d the line is: %-30s \n",buf);
        if (rgrep_matches(buf, argv[1])) {
            fputs(buf, stdout);
            fflush(stdout);
        }
    }

    if (ferror(stdin)) {
        perror(argv[0]);
        return 1;
    }
	char *ptrn = argv[1];
	int thesize = sizeof(ptrn);
	printf("Regex size is %-5d\n",thesize);
	printf("STring is %-15s\n",ptrn);
    return 0;
}
