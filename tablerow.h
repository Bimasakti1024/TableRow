#ifndef TABLEROW_H
#define TABLEROW_H

typedef struct {
  int columnc;
  int *column_width;
  char *row;
  char *column_name;
  const char *delimiter;
  int print_newline;
} TableRow;

TableRow new_tablerow(int columnc, int *column_width, const char *delimiter);
char *tablerow_format(TableRow *tr, char **values);
void tablerow_print(TableRow *tr, char **values);
void tablerow_free(TableRow *tr);

#endif
