/*
  ./categorize2 mermaid mermaid.csv Elvis elvises.csv the_rest.csv
  arg[0] = categorize
  arg[1] = mermaid is the word to filter for
  arg[2] = all the mermaid data will be stored in mermaid.csv
  arg[3] = This means you want to check for Elvis.
  arg[4] = All the Elvis sightings will be stored in elvises.csv
  arg[5] = Everything else goes into the_rest.csv
*/

#include <stdio.h>
#include <string.h>

/*
  The argc value is a count of the number of elements in the array.
  The first argument is actually the name of the program being run.
*/
int main(int argc, char const *argv[])
{
  char line[80];

  if (argc != 6) {
    fprintf(stderr, "You need to give 5 arguments\n");
    return 1;
  }

  FILE *in;
  if (!(in = fopen("spooky.csv", "r"))) {
    fprintf(stderr, "Can't open the file.\n\n");
    return 1;
  }

  FILE *file1 = fopen(argv[2], "w");
  FILE *file2 = fopen(argv[4], "w");
  FILE *file3 = fopen(argv[5], "w");
  while (fscanf(in, "%79[^\n]\n", line) == 1) {
    if (strstr(line, argv[1])) 
      fprintf(file1, "%s\n", line);
    else if (strstr(line, argv[3])) 
      fprintf(file2, "%s\n", line);
    else
      fprintf(file3, "%s\n", line);
  } 
  fclose(file1); 
  fclose(file2); 
  fclose(file3);

  return 0;
}
