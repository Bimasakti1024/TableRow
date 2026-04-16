#include "tablerow.h"

int main() {
  // Initalizes TableRow
  TableRow tr = new_tablerow(3, (int[]){12, 12, 12}, '|');

  // Print some row and line
  tablerow_print_line(&tr);
  tablerow_print(&tr, (char *[]){"Id", "First Name", "Last Name"});
  tablerow_print_line(&tr);
  tablerow_print(&tr, (char *[]){"1", "John", "Doe"});
  tablerow_print(&tr, (char *[]){"2", "Jane", "Doe"});
  tablerow_print_line(&tr);

  // Free TableRow
  tablerow_free(&tr);
  return 0;
}
