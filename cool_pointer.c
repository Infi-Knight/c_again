#include <stdio.h>
int main()
{
  int doses[] = {1, 3, 5, 1000};
  printf("issue dose %i\n", 3[doses]);
  // above code is perfectly fine:
  // 3[doses] == *(3 + doses) == *(doses + 3) == doses[3] :)
  return 0;
}
