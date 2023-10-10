## Ways of allocation of items in array:
- Row major order
  - Row is stored sequentially
  - Address for array[i][j] = B + W((i-LR)N + (j-LC))
    N equals `Upperbound - Lowerbound + 1` for column
- Column major order
  - Column is stored sequentially
  - Address for array[i][j] = B + W((i-LR) + (j-LC)N)
    N equals `Upperbound - Lowerbound + 1` for the row
