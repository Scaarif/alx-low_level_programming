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
    for r, row in enumerate(grid):
        for c, cell in enumerate(row):
            if cell == 1:
                prev, next_ = row[c -1 ], row[c + 1]
                top, bottom = grid[r -1][c], grid[r + 1][c]
                if not prev:
                    perimeter += 1
                if not next_:
                    perimeter += 1
                if not top:
                    perimeter += 1
                if not bottom:
                    perimeter += 1
    return perimeter

