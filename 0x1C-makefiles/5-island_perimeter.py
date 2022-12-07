#!/usr/bin/python3
"""
Defines a function island_perimeter
"""


def island_perimeter(grid):
    """ Returns the primeter of the island described in grid
    Args:
        grid - a list of list of integers in which:
        0 - reps a water zone and
        1 - reps a land zone
    Description:
        One cell is a square with side length 1
        Grid cells are connected horizonatlly/vertically (not diagonally)
        Grid is rectangular, width and height don't eceed 100
        Grid is completely surrounded by water, and there's only one
        island (or nothing)
        The island does not have 'lakes' 9water inside that isn't connected
        to the water around the island
    """
    # check that grid is not empty (has a len and width)
    if 100 > len(grid) < 1 or len(grid[0]) < 1:
        return 0
    # for each row (list in list)
    # for each col(cell) in row, check if the cell has neighbours:
    # to the left, right, top and bottom and increment perimeter as necessary
    perimeter = 0
    length, height = len(grid[0]), len(grid)
    for r, row in enumerate(grid):
        for c, cell in enumerate(row):
            if cell == 1:
                # check that the cell isn't in first/last row
                # check that the cell isn't in first or last column
                if c == 0:  # first cell in row
                    perimeter += 1  # no prev
                    if not row[c + 1]:  # no next
                        perimeter += 1

                elif c == length - 1:  # last cell in row
                    perimeter += 1  # no next_

                    if not row[c - 1]:  # no prev
                        perimeter += 1

                else:
                    prev, next_ = row[c - 1], row[c + 1]
                    if not prev:
                        perimeter += 1

                    if not next_:
                        perimeter += 1

                if r == 0:  # a first row cell
                    perimeter += 1  # no top

                    if not grid[r + 1][c]:  # no bottom
                        perimeter += 1

                elif r == height - 1:  # a last row cell
                    perimeter += 1  # no bottom

                    if not grid[r - 1][c]:  # no top
                        perimeter += 1

                else:
                    top, bottom = grid[r - 1][c], grid[r + 1][c]
                    if not top:
                        perimeter += 1

                    if not bottom:
                        perimeter += 1

    return perimeter
