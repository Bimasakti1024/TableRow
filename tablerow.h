#ifndef TABLEROW_H
#define TABLEROW_H

typedef struct {
  int columnc;
  int *column_width;
  char *row;
  char *column_name;
  char delimiter;
  int print_newline;
} TableRow;

TableRow new_tablerow(int columnc, int *column_width, char delimiter);
char *tablerow_format(TableRow *tr, char **values);
char *tablerow_line(TableRow *tr);
void tablerow_print(TableRow *tr, char **values);
void tablerow_print_line(TableRow *tr);
void tablerow_free(TableRow *tr);

#endif
