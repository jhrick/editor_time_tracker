#include <stdio.h>
#include <string.h>
#include <time.h>

#define BUFSIZE 1024
#define DATE_FORMAT "%02d-%02d-%d"

void write_file(double time_activity) {
  char path[] = "../editor_time_logs/";
  char file_name[BUFSIZE];
  FILE *file;
  
  time_t t = time(NULL);
  struct tm tm = *localtime(&t);

  sprintf(file_name, DATE_FORMAT, tm.tm_mday, tm.tm_mon, tm.tm_year + 1900);
  strcat(path, file_name);
  
  file = fopen(path, "w");

  fprintf(file, "time = %.0f seconds", time_activity);  
}

void auxiliary_function(void) {
  // this function is just checking 
  // if the count is working
  
  int i;
  printf("wait...\n");

  i = 0;

  while (i < 2000000000) {
    i++;
  }
}

int main(void) {
  clock_t time_execution;
  double dif;

  time_execution = clock();

  auxiliary_function();

  time_execution = clock() - time_execution;
  dif = ((double)time_execution) / CLOCKS_PER_SEC;

  write_file(dif);

  printf("written. time: %.fs\n", dif);

  return 0;
}
