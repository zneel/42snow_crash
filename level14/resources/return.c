#include <stdio.h>
#include <string.h>
#include <sys/types.h>
char *ft_des(char *flag)

{
  char cVar1;
  char *flagcopy;
  uint uVar2;
  char *pcVar3;
  char f;
  uint c;
  int x;
  int j;
  int i;

  f = 0;
  flagcopy = strdup(flag);
  x = 0;
  c = 0;
  do {
    uVar2 = 0xffffffff;
    pcVar3 = flagcopy;
    do {
      if (uVar2 == 0)
        break;
      uVar2 = uVar2 - 1;
      cVar1 = *pcVar3;
      pcVar3 = pcVar3 + (uint)f * -2 + 1;
    } while (cVar1 != '\0');
    if (~uVar2 - 1 <= c) {
      return flagcopy;
    }
    if (x == 6) {
      x = 0;
    }
    if ((c & 1) == 0) {
      if ((c & 1) == 0) {
        for (i = 0; i < "0123456"[x]; i = i + 1) {
          flagcopy[c] = flagcopy[c] + -1;
          if (flagcopy[c] == '\x1f') {
            flagcopy[c] = '~';
          }
        }
      }
    } else {
      for (j = 0; j < "0123456"[x]; j = j + 1) {
        flagcopy[c] = flagcopy[c] + '\x01';
        if (flagcopy[c] == '\x7f') {
          flagcopy[c] = ' ';
        }
      }
    }
    c = c + 1;
    x = x + 1;
  } while (1);
}

int main() {
  char s[] = "g <t61:|4_|!@IF.-62FH&G~DCK/Ekrvvdwz?v|";
  char *res = ft_des(s);
  printf("%s\n", res);
  return 0;
}