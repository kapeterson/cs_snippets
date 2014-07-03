#include "matcher.h"
#include <stdio.h>

/**
 * Implementation of your matcher function, which
 * will be called by the main program.
 *
 * You may assume that both line and pattern point
 * to reasonably short, null-terminated strings.
 */
int rgrep_matches(char *line, char *pattern) {

    //
    // TODO put your code here.
    //
	for(int i = 0; pattern[i] != '\0'; i++){
		printf("Checking char %5c\n",pattern[i]);
	}
    return 0;
}
