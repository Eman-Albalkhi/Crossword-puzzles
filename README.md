# Crossword-puzzles

The crossword puzzle does not contain any black squares, and writing is allowed within all the cells. The program will read the possible horizontally writable words within each row. Each horizontal word is written starting from the first column in that row and extends across the row according to the word's length. Similarly, the program will read the vertically writable words, which are written starting from the first row in that column and extend down the column according to the word's length. A solution is reached when there is no square where the letter of the horizontal word differs from the letter of the vertical word.

name: Label issues
on:
  issues:
    types:
      - reopened
      - opened
jobs:
  label_issues:
    runs-on: ubuntu-latest
    permissions:
      issues: write
    steps:
      - run: gh issue edit "$NUMBER" --add-label "$LABELS"
        env:
          GITHUB_TOKEN: ${{ secrets.GITHUB_TOKEN }}
          GH_REPO: ${{ github.repository }}
          NUMBER: ${{ github.event.issue.number }}
          LABELS: triage

