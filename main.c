#include <stdio.h>
#include <string.h>

#define BUF_MAX_LEN (256)
static const char *prettyName =
    "PRETTY_NAME=\"QUOTE_STRING IN FILE LINE\"";

void getFirstQuotedString(char const *current_line, char *buf, size_t bufLen) {
  char line[BUF_MAX_LEN];
  char *subString; // the "result"

  memset(buf, '\0', BUF_MAX_LEN);
  strncpy(line, current_line, BUF_MAX_LEN);
  subString = strtok(line, "\"");
  subString = strtok(NULL, "\"");

  if (!subString) {
    printf("Not found\n");
    buf[0] = '\0';
  } else {
    printf("the thing in between quotes is '%s'\n", subString);
    (void)strncpy(buf, subString, strlen(subString));
  }
}

int main(int, char **) {
  char buf[BUF_MAX_LEN];
  getFirstQuotedString(prettyName, buf, BUF_MAX_LEN);
  fprintf(stdout, "%d: %s\n", strlen(buf), buf);
}
