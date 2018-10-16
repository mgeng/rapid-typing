//
//  main.c
//  RapidTyping
//
//  Created by 加藤 源 on 2018/10/16.
//  Copyright © 2018年 gkato. All rights reserved.
//

#include "rapid_typing.h"
#include "time.h"
#include <stdio.h>
#include "test.h"


int main(int argc, const char * argv[])
{
  time_t start_time = 0, end_time = 0, elapsed_time = 0;
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
