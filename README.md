# Crossword-puzzles

The crossword puzzle does not contain any black squares, and writing is allowed within all the cells. The program will read the possible horizontally writable words within each row. Each horizontal word is written starting from the first column in that row and extends across the row according to the word's length. Similarly, the program will read the vertically writable words, which are written starting from the first row in that column and extend down the column according to the word's length. A solution is reached when there is no square where the letter of the horizontal word differs from the letter of the vertical word.

## input 
The program reads two numbers N and M representing the number of lines and columns of the board. What follows is N lines, each line of which initially contains a number K representing the number of possible words in this line, then K words representing the words possible to be written in this line. The first line represents the words that can be written within the first line, and the second line represents the words that can be written within the second line, and so on.. What follows is M lines, each of which initially contains a number K representing the number of possible words in this column, then K represents the words that can be written in This column.

## output 
Solution patch printing. When there are cells that are not filled with a horizontal word or a vertical word, they are filled with the # symbol.
If there is no verification patch, only the word IMPOSSIBLE is printed.

## Complexity
The most time-consuming operations in the program are when selecting the correct row and column words, with the complexity of selecting the correct row words being of order n^3 due to the presence of three nested loops, and the complexity of selecting the correct column words being of order n^2 due to the presence of two nested loops... Thus, the overall complexity would be n^3 in the worst case.



