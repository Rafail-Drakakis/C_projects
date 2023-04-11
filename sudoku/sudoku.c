#include "sudoku.h"
/* Read a sudoku grid from stdin and return an object Grid_T
   initialized to these values.
*/
Grid_T sudoku_read(void) {
  int i = 0, j = 0, n;
  Grid_T *g = malloc(sizeof(Grid_T));
  grid_set_unique(g);

  while (i < 9) {
    if (j == 9) {
      i++;
      j = 0;
      continue;
    }

    scanf("%d", &n);
    grid_update_value(g, i, j, n);
    j++;
  }

  return (*g);
}

void sudoku_print(FILE *s, Grid_T g) {
  int i, j;

  for (i = 0; i < 9; i++) {
    for (j = 0; j < 9; j++) {
      fprintf(s, "%d ", grid_read_value(g, i, j));
    }
    fprintf(s, "\n");
  }
}

int checkDupl(int row[9], int print) {
  int flags[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, i;

  for (i = 0; i < 9; i++) {
    if (row[i] == 0) {
      if (print) {
        printf(" %d", i);
        continue;
      }
      return 1;
    }
    if (flags[row[i]] == 0) {
      flags[row[i]] = 1;
    } else {
      flags[0] = 1;
      if (print) {
        printf(" %d", i + 1);
      }
    }
  }

  return flags[0];
}

/* Print all row, col, sub-grid errors/conflicts found in puzzle g;
   some errors may be reported more than once. */
void sudoku_print_errors(Grid_T g) {
  int array[9], i, j;

  if (sudoku_is_correct(g)) {
    printf("Sudoku is correct! - no errors found\n");
    return;
  }

  printf("Errors:");

  /* check rows */
  for (i = 0; i < 9; i++) {
    for (j = 0; j < 9; j++) {
      array[j] = grid_read_value(g, i, j);
    }
    if (checkDupl(array, 0)) {
      printf("\nIn row %d and column", i + 1);
      checkDupl(array, 1);
    }
  }

  /* check columns */
  for (j = 0; j < 9; j++) {
    for (i = 0; i < 9; i++) {
      array[i] = grid_read_value(g, i, j);
    }
    if (checkDupl(array, 0)) {
      printf("\nIn column %d and row", j + 1);
      checkDupl(array, 1);
    }
  }

  /* check blocks */
  for (i = 0; i < 9; i += 3) {
    for (j = 0; j < 9; j += 3) {
      grid_readBlock(i, j, g, array);
      if (checkDupl(array, 0)) {
        printf("\nBlock %d", i + 1 + (j / 3));
      }
    }
  }

  printf("\n");
}

int sudoku_is_correct(Grid_T g) {
  int array[9], i, j;

  for (i = 0; i < 9; i++) {
    for (j = 0; j < 9; j++) {
      array[j] = grid_read_value(g, i, j);
    }
    if (checkDupl(array, 0)) {
      return 0;
    }
    for (j = 0; j < 9; j++) {
      array[j] = grid_read_value(g, j, i);
    }
    if (checkDupl(array, 0)) {
      return 0;
    }
  }

  for (i = 0; i < 9; i += 3) {
    for (j = 0; j < 9; j += 3) {
      grid_readBlock(i, j, g, array);
      if (checkDupl(array, 0)) {
        return 0;
      }
    }
  }

  return 1;
}

static void sudoku_init_choices(Grid_T *g) {
  int block[9], i, j, n;

  for (i = 0; i < 9; i++) {
    for (j = 0; j < 9; j++) {
      if (grid_read_value(*g, i, j) != 0) {
        continue;
      }

      grid_readBlock(i, j, *g, block);
      /* suppose all choices are available */
      for (n = 1; n < 10; n++) {
        grid_set_choice(g, i, j, n);
      }
      grid_set_count(g, i, j);
      /* remove the ones that exist in the same block, row, or column */
      for (n = 0; n < 9; n++) {
        grid_remove_choice(g, i, j, grid_read_value(*g, i, n));
        grid_remove_choice(g, i, j, grid_read_value(*g, n, j));
        grid_remove_choice(g, i, j, block[n]);
      }
    }
  }
}

static int sudoku_try_next(Grid_T g, int *row, int *col) {
  int i, j, mincount = 9, n;
  srand(getpid());

  /* start from random row */
  i = rand() % 9;

  for (n = 0; n < 9; n++) {
    for (j = 0; j < 9; j++) {
      /* use only the empty cases */
      if (grid_read_value(g, i, j) != 0) {
        continue;
      }
      /* if it's empty and does not have any possible solutions it's a deadend
       */
      if (grid_read_count(g, i, j) == 0) {
        return 0;
      }
      if (grid_read_count(g, i, j) < mincount) {
        *row = i;
        *col = j;
        mincount = grid_read_count(g, i, j);
      }
    }
    i++;
    if (i == 9) {
      i = 0;
    }
  }
  /* take first choice that is valid */
  for (i = 1; i < 10; i++) {
    if (grid_choice_is_valid(g, *row, *col, i)) {
      return i;
    }
  }
  return 0;
}

static int sudoku_update_choice(Grid_T *g, int i, int j, int n) {
  grid_remove_choice(g, i, j, n);
  grid_update_value(g, i, j, n);
  return grid_read_count(*g, i, j);
}

static void sudoku_eliminate_choice(Grid_T *g, int r, int c, int n) {
  int i, j;

  /* remove choice from row and column */
  for (i = 0; i < 9; i++) {
    grid_remove_choice(g, r, i, n);
    grid_remove_choice(g, i, c, n);
  }

  /* remove choice from block */
  r = r - r % 3;
  c = c - c % 3;

  for (i = 0; i < 3; i++) {
    for (j = 0; j < 3; j++) {
      grid_remove_choice(g, i + r, j + c, n);
    }
  }
}

/* Solve puzzle g and return the solved puzzle; if the puzzle has
   multiple solutions, return one of the possible solutions. */
Grid_T sudoku_solve(Grid_T g) {
  int i = 0, j = 0, n;
  Grid_T temp;

  sudoku_init_choices(&g);

  while (1) {
    n = sudoku_try_next(g, &i, &j);

    /* DeadEnd */
    if (n == 0) {
      return g;
    }

    if (sudoku_update_choice(&g, i, j, n) != 0) {
      temp = sudoku_solve(g);

      if (sudoku_is_correct(temp)) {
        /* if we found the solution and there are still choices,
           there are other solutions */
        if (grid_read_count(temp, i, j) != 0) {
          grid_clear_unique(&temp);
        }

        return temp;
      }

      /* has to be blank again */
      grid_update_value(&g, i, j, 0);
    } else {
      sudoku_eliminate_choice(&g, i, j, n);
    }
  }

  return g;
}

Grid_T sudoku_generate_complete() {
  Grid_T g;
  int i, j;

  for (i = 0; i < 9; i++) {
    for (j = 0; j < 9; j++) {
      grid_update_value(&g, i, j, 0);
    }
  }

  return sudoku_solve(g);
}

/* Generates a Sudoku puzzle with a specified number of empty cells (nelts).
Returns a grid with nelts empty cells. */
Grid_T sudoku_generate(int nelts) {
  Grid_T g;
  int n, i, j;

  g = sudoku_generate_complete();

  for (n = 0; n < 81 - nelts; n++) {
    do {
      i = rand() % 9;
      j = rand() % 9;
    } while (grid_read_value(g, i, j) == 0);

    grid_update_value(&g, i, j, 0);
  }

  return g;
}

/* Main function for the Sudoku program */
int main(int argc, char *argv[]){
  Grid_T g;
  /* if argument is "-c", generate a new puzzle */
  if (argc == 2 && strcmp(argv[1], "-c") == 0) {
    printf("New puzzle:\n");
    g = sudoku_read();
    sudoku_print(stderr, g);
    fprintf(stderr, "Sudoku is ");
    /* check if the puzzle is correct */
    if (!sudoku_is_correct(g)) {
      fprintf(stderr, "not correct\n");
      sudoku_print_errors(g);
    } else {
      printf("correct\n");
    }
  }
  /* if argument is "-g", generate a new puzzle with given number of elements */
  else if (argc == 3 && strcmp(argv[1], "-g") == 0) {
    sudoku_print(stdout, sudoku_generate(atoi(argv[2])));
  }
  /* otherwise, solve the puzzle */
  else {
    printf("New puzzle:\n");
    g = sudoku_read();
    sudoku_print(stderr, g);
    g = sudoku_solve(g);

    /* check if the solved puzzle is correct */
    if (!sudoku_is_correct(g)) {
      sudoku_print_errors(g);
    } else {
      printf("Puzzle has a ");

      /* check if the puzzle has a unique solution */
      if (grid_read_unique(g)) {
        printf("(unique choice) ");
      }

      printf("solution:\n");
      sudoku_print(stdout, g);
      printf("Puzzle solution is correct.\n");
    }
  }
  return 0;
}
