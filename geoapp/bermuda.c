// filter the data from a csv file by printing coordinates 
// inside the bermuda rectangle
// you can use the pipe operator to create the final json output
// e.g (./bermuda | ./geo_csv_to_json) < gpsdata.csv > bermuda.json 2>errors.txt

// If several processes are connected together with pipes and then I use > and <
// to redirect the Standard Input and Output,
// which processes will have their input and output redirected?
// ANSWER:
// The < will send a file’s contents to the first process in the pipeline.
// The > will capture the Standard Output from the last process in the pipeline.
#include <stdio.h>
int main()
{
  float latitude;
  float longitude;
  char info[80];

  while(scanf("%f,%f,%79[^\n]", &latitude, &longitude, info) == 3) {
    if ((latitude > 26) && (latitude < 34))
      if ((longitude > -76) && (longitude < -64)) 
        printf("%f,%f,%s\n", latitude , longitude , info );
  }
  return 0;
}
