# PathFinder

## Features
- Reads input from a file containing information about the islands and bridges.
- Calculates the shortest path between every pair of islands.
- Outputs the paths and distances in a detailed format.
- Handles multiple types of errors (e.g., invalid input file, duplicate bridges, incorrect format).
- Uses a FIFO (First-In-First-Out) rule for the islands in the standard output.

## Input File Format
The input file should contain:
1. **First line: **An integer representing the number of islands.
2. **Subsequent lines: **Pairs of islands and the distance between them in the format:
    island1,island2,length_of_bridge
 - `island1` and `island2` are the names of the islands (alphabetic characters only).
 - `length_of_bridge` is a positive integer representing the length of the bridge between the two islands.
  
###  Example Input:
    4
    A,B,5
    A,C,3
    B,C,2
    C,D,4
This input file defines 4 islands and the bridges connecting them.

## Output
For each pair of islands, the program prints the shortest path and its length. The output format includes:
- A separator line of 40 `=` characters.
- The starting and destination islands.
- The full route between the islands.
- The total distance of the path.
### Example Output:
```
========================================
Path: A > D
Route: A > C > D
Distance: 3 + 4 = 7
========================================
```
## Error Handling
The program handles errors and prints specific messages to standard error (`stderr`). Here are the possible errors and their corresponding messages:
1. Invalid command-line arguments:
 - `usage: ./pathfinder [filename]`
2. File does not exist:
 - `error: file [filename] does not exist`
3. Empty file:
 - `error: file [filename] is empty`
4. Invalid first line (number of islands):
 - `error: line 1 is not valid`
5. Invalid subsequent lines:
 - `error: line [line_number] is not valid`
6. Mismatch in the number of islands:
 - `error: invalid number of islands`
7. Duplicate bridges:
 - `error: duplicate bridges`
8. Sum of bridge lengths exceeds limit:
 - `error: sum of bridge lengths is too big`

##  How to Run
1. Clone the repository:
```
git clone https://github.com/Corkerro/pathfinder.git
```
2. Compile and run the program:
```
cd pathfinder
make
./pathfinder input.txt
```
