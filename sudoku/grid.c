#include "grid.h"

void grid_update_value(Grid_T *g, int i, int j, int n) {
  g->elements[i][j].val = n;
}

int grid_read_value(Grid_T g, int i, int j) { return g.elements[i][j].val; }

/* set (to 1) or clear (to 0) choice n for elt i,j */
void grid_set_choice(Grid_T *g, int i, int j, int n) {
  g->elements[i][j].choices.num[n] = 1;
}

void grid_clear_choice(Grid_T *g, int i, int j, int n) {
  g->elements[i][j].choices.num[n] = 0;
}

int grid_choice_is_valid(Grid_T g, int i, int j, int n) {
  return g.elements[i][j].choices.num[n] == 1;
}

void grid_remove_choice(Grid_T *g, int i, int j, int n) {
  if (grid_choice_is_valid(*g, i, j, n)) {
    g->elements[i][j].choices.count--;
  }
  grid_clear_choice(g, i, j, n);
}

int grid_read_count(Grid_T g, int i, int j) {
  return g.elements[i][j].choices.count;
}

void grid_set_count(Grid_T *g, int i, int j) {
  g->elements[i][j].choices.count = 9;
}

void grid_clear_count(Grid_T *g, int i, int j) {
  g->elements[i][j].choices.count = 0;
}

int grid_read_unique(Grid_T g) { return g.unique; }

void grid_set_unique(Grid_T *g) { g->unique = 1; }

void grid_clear_unique(Grid_T *g) { g->unique = 0; }

void grid_readBlock(int i, int j, Grid_T g, int array[9]) {
  int r = 0;
  int c = 0;
  int n = 0;
  i = i - i % 3;
  j = j - j % 3;

  for (r = 0; r < 3; r++) {
    for (c = 0; c < 3; c++) {
      array[n++] = grid_read_value(g, i + r, j + c);
    }
  }
}
