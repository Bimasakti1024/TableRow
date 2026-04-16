#include "tablerow.h"
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

TableRow new_tablerow(int columnc, int *column_width, char delimiter) {
  TableRow tr = {0};

  // assign other values
  tr.column_width = malloc(columnc * sizeof(int));
  if (!tr.column_width)
    return tr;
  memcpy(tr.column_width, column_width, columnc * sizeof(int));
  tr.columnc = columnc;
  tr.delimiter = delimiter;
  tr.print_newline = 1;

  return tr;
}

char *tablerow_format(TableRow *tr, char **values) {
  int total_len = 1;

  // count total length
  for (int i = 0; i <= tr->columnc; i++) {
    total_len += tr->column_width[i] + 2;
    if (tr->delimiter && i < tr->columnc - 1)
      total_len++;
  }

  char *buffer = malloc(total_len + 1);
  if (!buffer)
    return NULL;

  int offset = 0;

  for (int i = 0; i < tr->columnc; i++) {
    int remaining = total_len - offset + 1;

    int written = snprintf(buffer + offset, remaining, "%c %-*s", tr->delimiter,
                           tr->column_width[i], values[i]);

    if (written < 0 || written >= remaining) {
      free(buffer);
      return NULL;
    }

    offset += written;
    if (tr->delimiter && i == tr->columnc - 1) {
      remaining = total_len - offset + 1;

      written = snprintf(buffer + offset, remaining, "%c", tr->delimiter);

      if (written < 0 || written >= remaining) {
        free(buffer);
        return NULL;
      }

      offset += written;
    }
  }

  buffer[offset] = '\0';
  return buffer;
}

char *tablerow_line(TableRow *tr) {
  int total_len = 0;

  // count total length (+2 for padding)
  for (int i = 0; i <= tr->columnc; i++) {
    total_len += tr->column_width[i] + 2;
  }

  char *buffer = malloc(total_len);
  if (!buffer)
    return NULL;

  int pos = 0;

  // iterate each column
  for (int i = 0; i < tr->columnc; i++) {
    for (int j = 0; j <= tr->column_width[i] + 1; j++) {
      // write + for the first character and - for the rest
      buffer[pos] = j == 0 ? '+' : '-';
      pos++;
    }
  }

  // write the last +
  buffer[pos] = '+';
  buffer[total_len] = '\0';
  return buffer;
}

void tablerow_print(TableRow *tr, char **values) {
  char *buffer = tablerow_format(tr, values);
  printf("%s", buffer);
  if (tr->print_newline)
    putchar('\n');
  free(buffer);
}

void tablerow_print_line(TableRow *tr) {
  char *buffer = tablerow_line(tr);
  printf("%s", buffer);
  if (tr->print_newline)
    putchar('\n');
  free(buffer);
}

void tablerow_free(TableRow *tr) { free(tr->column_width); }
