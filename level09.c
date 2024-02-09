#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  FILE *fptr = fopen("/home/user/level09/token", "r");
  char token[256];
  fgets(token, 256, fptr);
  char res[2048] = "a";
  int i = 0;
  while (res[i] < 127) {
    FILE *fp;
    char path[1035];
    char commandwitharg[2048];
    bzero(commandwitharg, 2048);
    sprintf(commandwitharg, "/home/user/level09/level09 '%s'", res);
    fp = popen(commandwitharg, "r");
    if (fp == NULL) {
      printf("Failed to run command\n");
    }
    fgets(path, sizeof(path), fp);
    if (token[i] == path[i]) {
      res[++i] = 33;
    } else
      res[i]++;
    printf("res=%s\n", res);
    pclose(fp);
  }
  return 0;
}