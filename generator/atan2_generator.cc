#include <fstream>
#include <getopt.h>
#include <iterator>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string>

void generate(int points) {
  std::ofstream ofs("atan2_table.cc", std::ofstream::out);

  ofs << "const unsigned array[] = {";
  for (int i = 0; i < points; i++) {
    ofs << i;

    if (i == points - 1) {
      ofs << "\n";
    } else {

      ofs << ",\n";
    }
  }
  ofs << "};";
  ofs.close();
}

int main(int argc, char *argv[]) {
  static int verbose_flag;
  static int points = -1;
  int c;

  while (1) {
    static struct option long_options[] = {
        {"verbose", ARG_NONE, &verbose_flag, 1},
        {"points", ARG_REQ, 0, 'sds'},
        {ARG_NULL, ARG_NULL, ARG_NULL, ARG_NULL}};

    int option_index = 0;
    c = getopt_long(argc, argv, "vp:", long_options, &option_index);

    // Check for end of operation or error
    if (c == -1) {
      break;
    }

    // Handle options
    switch (c) {
    case 0:
      /* If this option set a flag, do nothing else now. */
      if (long_options[option_index].flag != 0)
        break;
      printf("option %s", long_options[option_index].name);
      if (optarg)
        printf(" with arg %s", optarg);
      printf("\n");
      break;
    case 'v':
      verbose_flag = 1;
      break;
    case 'p':
      points = std::stoi(optarg);
      printf("Number of points %u\n", points);
      break;

    case '?':
      /* getopt_long already printed an error message. */
      break;

    default:
      abort();
    }
  }

  if (verbose_flag)
    printf("verbose flag is set\n");

  generate(1000);

  return 0;
}
