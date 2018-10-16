#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

#define TEST_COUNT 3 
/* TODO:
   random words
 */

char words[TEST_COUNT][64] = {"ALAKAZAM!!", "OZUMANDIOUS", "TILTOWAIT!!", "hoge", "piyo"};
int current_test_index = 0;



char* get_word() 
{
  char* word = words[current_test_index];
  current_test_index += 1;
  return word;
}

void type_and_check(char* word)
{
  char typed[256];
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

int main()
{
  time_t start_time, end_time, elapsed_time;
  time_t min, sec;
  int i;
  
  for (i = 0; i < TEST_COUNT; i++) {
  time(&start_time);
  type_and_check(get_word());
  time(&end_time);
  } 

  elapsed_time = end_time - start_time;
  printf("> Check end. \n");
  min = elapsed_time / 60;
  sec = elapsed_time % 60;
  printf("> Elapsed %ldmin %ldsec.\n", min, sec);
  
  return 0; 
}
