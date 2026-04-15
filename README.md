# TableRow

A minimal C string formatter to make it looks like a table
Not meant to be a full library, just a small personal project to create a table like string

## Usage

To use this, you should first include the header `tablerow.h`.

### TableRow new_tablerow(int columnc, int *column_width, const char *delimiter)

This function are used to initiate a new TableRow, it takes 3 arguments:

- `columnc`: number of columns
- `column_width`: array specifying the width of each column
- `delimiter`: string used to separate columns

### char *tablerow_format(TableRow *tr, char **values);

This function are used to format strings using the existing column format.
Returns a newly allocated formatted string and must be freed by the caller to avoid memory leak.

### void tablerow_print(TableRow *tr, char **values);

It prints a formatted table like strings.
You can toggle newline output by modifying the `print_newline` field in the `TableRow` struct.

### tablerow_free(TableRow *tr);

This free the `TableRow`.

---

Here are the example usage of TableRow:

```C
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

```

Output:
```
| Id          | First Name  | Last Name   |
| 1           | John        | Doe         |
| 2           | Jane        | Doe         |
```

## Notes
- Currently supports only string (`%s`) formatting
- Not intended as a full-featured library

## License
MIT
