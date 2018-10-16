#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <stdlib.h>
#include "rapid_typing.h"

#define N 256

/* TODO:
   random words
 */

char words[N][N];
int current_test_index = 0;

//TODO: 
int read_source(char words[N][N])
{
  FILE *fp;
  char *filename = "/Users/kato.gn/work/c/RapidTyping/RapidTyping/source.txt";
  char readline[N] = {'\0'};
  int index = 0;
  
  if ((fp = fopen(filename, "r")) == NULL) {
    fprintf(stderr, "Open file %s was failed.\n", filename);
    return EXIT_FAILURE;
  }
  
  while (fgets(readline, N, fp) != NULL ) {
    strcpy(words[index], readline);
    index += 1;
  }
  
  return EXIT_SUCCESS;
}

char* get_word() 
{
  char* word = words[current_test_index];
  current_test_index += 1;
  return word;
}

void type_and_check(char* word)
{
  char typed[N];
  bool is_ok = false;

  printf("Type. : %s\n", word);
  while (!is_ok) {
    scanf("%s", typed);
    if (strcmp(word, typed) == 0) {
      printf("> OK\n");
      is_ok = true;
    } else {
      printf("> NG!!\n");
    }
  }
}
