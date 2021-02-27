#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
// WCat file complete. 
int main(int argc, char *argv[]) {
  if (argc > 0) {
    for (int i = 1; i < argc; i++) {
      // Merely open the file for reading.
      FILE *fp = fopen(argv[i], "r");

      if (fp != NULL) {
        // fseek(fp, 0L, SEEK_END);
        // long buffer_size = ftell(fp);

        char buffer[256];
        // Have to call this to set the pointer to the start of the file
        // again.
        // rewind(fp);

        while (fgets(buffer, 256, fp)) {
          printf("%s", buffer);
        }

        fclose(fp);
      }

      if (fp == NULL) {
        printf("wcat: cannot open file\n");
        return 1;
      }
    }
  }

  return 0;
}
