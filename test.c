#include<stdio.h>
#include<stdlib.h>

#define N 256


int read_source(char* words[]);

int main()
{
  char* readed[N];
  int i = 0;

  if ( read_source(&readed) == EXIT_SUCCESS ) {
    for (i = 0; i < 3; i++) {
      printf("result %s\n", readed[i]);
    } 
  } else {
    printf("Oooooooooops\n");
  }

  return 0;
}

int read_source(char* words[])
{
  FILE *fp;
  char *filename = "source.txt";
  char readline[N] = {'\0'};
  int index = 0;

  if ((fp = fopen(filename, "r")) == NULL) {
    fprintf(stderr, "Open file %s was failed.\n", filename);
    return EXIT_FAILURE;
  }

  while ( fgets(readline, N, fp) != NULL ) {
    words[index] = readline;
  }

  return EXIT_SUCCESS;
}
