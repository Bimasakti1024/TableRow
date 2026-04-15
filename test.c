#include "tablerow.h"

int main() {
  // Initalizes TableRow
  TableRow tr = new_tablerow(3, (int[]){12, 12, 12}, "|");

  // Print some row
  tablerow_print(&tr, (char *[]){"Id", "First Name", "Last Name"});
  tablerow_print(&tr, (char *[]){"1", "John", "Doe"});
  tablerow_print(&tr, (char *[]){"2", "Jane", "Doe"});

  // Free TableRow
  tablerow_free(&tr);
  return 0;
}
