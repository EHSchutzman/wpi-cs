/** Program to demonstrate string reversal
 */

#include <stdio.h>
#include <string.h>
#include <libgen.h>

/** Print usage message
 */
void usage () {
  printf("usage: reversestring \"string with characters to reverse\"\n");
  printf("   OR: reversewords \"string with words to reverse\"\n");
}

/** Reverses all the characters in a string, in place.
 * For example, "hello world" becomes "dlrow olleh"
 */

void reversestring(char* s) {
  int i; // loop counter
  for(i = 0; s[i] != '\0'; i++);
  // now i has the length of the string
  if(i % 2 == 0){ // even number of letters in string
    int j;
    int k;
    char c;
    for(j = 0, k = i-1; j != i/2; j++, k--){
      c = s[j];
      s[j] = s[k];
      s[k] = c;
      }
  }
  else { // odd number of letters
    int j;
    int k;
    char c;
    for(j = 0, k = i-1; j != (i-1)/2; j++, k--){
      c = s[j];
      s[j] = s[k];
      s[k] = c;
    }
  }
}

/** Reverses a single word of a string
 * @param s The string whose word has to be reversed
 * @param start The index where the word starts
 * @param end The index where the word ends
 */
void reversepart(char *s, int start, int end){
  int length;
  length = end -start + 1;

    int j;
    int k;
    char c;
    for(j = start, k = end; j < k; j++, k--){
      c = s[j];
      s[j] = s[k];
      s[k] = c;
      }
}

/** Reverses all the words in a string, in place.
 * For example, "hello world" becomes "world hello"
 */
void reversewords(char* s) {
  reversestring(s);
  int i;
  int j;
  // loop until the end of the string s
  for (i = 0; s[i] != '\0'; i = (j + 1)){
    // loop from start of outer loop to a blank or null character
    for(j = i; s[j] != ' ' && s[j] != '\0'; j++);  
    // j now is past the last letter of the reversed word
    reversepart(s, i, j-1);
  }
}

/** Must take exactly one argument.
 */
int main(int argc, char* argv[]) {

  char* command; // duplicate of command name
  char* basec;    // basename of command
  char* s;       // String to reverse;

  if (argc != 2) { // Check that it was called with exactly one argument
    usage();
    return 1;
  }

  s = strdup(argv[1]); // Sring to reverse

  // See how the command was invoked

  // First strip down to just the basename, no directory prefix
  command = strdup(argv[0]);
  basec = basename(command);

  if (strcmp(basec, "reversestring") == 0) {
    printf("Original string: %s\n", s);
    reversestring(s);
    printf("Reversed string: %s\n", s);
    return 0;
  } else if (strcmp(basec, "reversewords") == 0) {
    //printf("%s\n", s);
    reversewords(s);
    printf("%s\n", s);
    return 0;
  } else { // Those are the only two valid choices
    usage();
    return 1;
  }
}