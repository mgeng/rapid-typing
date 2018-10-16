#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "test.h"

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

int test()
{
  char words[N][N];
  if (read_source(words) == EXIT_SUCCESS) {
    for (int i = 0; strlen(words[i]) > 0 ; i++) {
      printf("test %s", words[i]);
    }
  } else {
    printf("Oooooooooops\n");
  }

  return 0;
}

