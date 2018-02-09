#include <stdio.h>
#include <string.h>
void print_reverse(char *s);

int main()
{
  // an array of pointers
  char *juices[] = {
	  "dragonfruit", "waterberry", "sharonfruit", "uglifruit", 
	  "rumberry", "kiwifruit", "mulberry", "strawberry", "blueberry", "blackberry", "starfruit"
  };

  char *a;    // pointer to a character
  puts(juices[6]);
  print_reverse(juices[7]);
  a = juices[2];    // a now contains the address of the first character of the string "sharonfruit"
  juices[2] = juices[8];    // juices[2] contains the address of the first character of the string "blueberry"
  juices[8] = a;    // juices[8] contains the address of the first character of the string "sharonfruit"
  print_reverse(juices[(18 + 7) / 5]);
  puts(juices[2]);
  print_reverse(juices[9]);
  juices[1] = juices[3];
  puts(juices[10]);
  print_reverse(juices[1]);
  return 0;
}

void print_reverse(char *s)
{
  size_t len = strlen(s);
  char *t = s + len - 1;
  while (t >= s) {
    printf("%c", *t);
    t = t-1;
  }
  printf("\n");
}
