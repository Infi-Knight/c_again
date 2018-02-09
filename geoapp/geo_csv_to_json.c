#include <stdio.h>

// use ./a.out < gpsdata.csv > output.json for I/O redirection in unix
// he operating system creates the Standard Error at the same time and, 
// like the Standard Output, the Standard Error is sent to the display by default.
// That means that if someone redirects the Standard Input and Standard Output so 
// they use files, the Standard Error will continue to send data to the display.

// printf() function is just a version of a more general function called fprintf():
// printf("I like Turtles!"); OR fprintf(stdout, "I like Turtles!");
// The fprintf() function allows you to choose where you want to send text to. 
// You can tell fprintf() to send text to stdout (the Standard Output) 
// or stderr (the Standard Error).

// > redirects the Standard Output. But 2> redirects the Standard Error.
// So I could write geo2json 2> errors.txt
// OR ./geo_csv_to_json < gpsdata.csv >output.json 2>errors.txt

int main()
{
  float latitude;
  float longitude;

  char info[80];
  int started = 0;
  puts("data=[");
  // %79[^\n] means read everything till we encounter a new line
  while(scanf("%f, %f, %79[^\n]", &latitude, &longitude, info) == 3) {
    if (started)
      printf(",\n");
    else 
      started = 1;

    // validate the latitudes and the longitudes
    if ((latitude < -90.0) || (latitude > 90.0)) {
      fprintf(stderr, "Invalid latitude: %f\n", latitude);
      return 2; 
    }
    if ((longitude < -180.0) || (longitude > 180.0)) {
      fprintf(stderr, "Invalid longitude: %f\n", longitude);
      return 2; 
    }

    printf("{latitude: %f, longitude: %f, info: '%s'}", latitude, longitude, info);
  }
  puts("\n]");
  return 0;
}
