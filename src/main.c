#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_usage() { printf("Usage: kwed [OPTIONS] [files]...\n\n"); }

char *get_next_option(char ***arg_ptr_ptr) {
  char **arg_ptr = *arg_ptr_ptr;
  if (arg_ptr == NULL || *arg_ptr == NULL) {
    return NULL;
  }
  *arg_ptr_ptr = arg_ptr + 1;
  return *arg_ptr;
}

void main_loop() {}

int main(int argc, char *argv[]) {
  char *current_option;
  get_next_option(&argv);

  while ((current_option = get_next_option(&argv)) != NULL) {
    if (strcmp(current_option, "--help") == 0 ||
        strcmp(current_option, "-h") == 0) {
      print_usage();
      exit(0);
    } else {
      // TODO(emmanuel): Read all filenames and put them in an array
    }
    printf("%s\n", current_option);
  }
  main_loop();
  return 0;
}
