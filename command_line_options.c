/*
  getopt(), each time you call it, it returns the next 
  option it finds on the command line.

  rocket_to -e 4 -a Brasilia Tokyo London
  This program needs one option that will take a value (-e = engines) 
  and another that is simply on or off (-a = awesomeness)
  
  You will need to include this header:

        #include <unistd.h>
        ...
        while ((ch = getopt(argc, argv, "ae:")) != EOF)
         switch(ch) {
          ...
          case 'e':
          engine_count = optarg;
          ...
        }

        argc -= optind; 
        argv += optind;

  The string ae: tells the getopt() function that a and e are valid options. 
  The e is followed by a colon to tell getopt() that the -e needs to be 
  followed by an extra argument. 
  getopt() will point to that argument with the optarg variable.

  When the loop finishes, you tweak the argv and argc variables to skip past 
  all of the options and get to the main command-line arguments. 

  optind stores the number of strings read from the command line to 
  get past the options.

  That will make your argv array look like this:
    Brasilia(argv[0]) Tokyo(argv[1]) London(argv[2])

  After processing the arguments, the 0th argument will no longer be
  the program name. argv[0] will instead point to the first command-line
  argument that follows the options.
*/

#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
  char ch;
  char *delivery = "";
  int thick = 0;

  while((ch = getopt(argc, argv, "d:t")) != EOF) {
    switch(ch) {
      case 'd':
        delivery = optarg;
        break;
      case 't':
        thick = 1;
        break;
      default:
        fprintf(stderr, "Unknown option %s\n", optarg);
        return 1;
    }
  }

  argc -= optind;
  argv += optind;

  if (thick)
    puts("Thick crust.");
  if (delivery[0])
    printf("To be delivered %s.\n", delivery);

  puts("Ingredients:");

  for (int count = 0; count < argc; count++)
    puts(argv[count]);

  return 0;
}
