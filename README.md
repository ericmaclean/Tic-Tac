# Tic-Tac-Toe Game (Terminal Version in C)

This is a command line tic tac toe game implemented in C. The game is played with one player and a computer opponent. The computer makes intelligent moves based on priorities. The player uses the 'X' symbol while the computer uses the 'O' symbol. The order the initial turn is randomized, the user is prompted every turn to enter a row and column to place their symbol. The game ends when either player or the computer has 3 symbols in a row or when the board is filled.   

## Features: 

- Take turns playing against intelligent computer 
- Clean ASCII-based board display
- Easy-to-follow game flow in the terminal

## Computer: 

- Computer makes moves based off of a list of priorities
  1. Attack - if there's a winning move availible, play it
  2. Block - if there's a winning move availible for the player, block it
  3. Fork - if there's a move availible that can lead to two possible winning combinations, play it
  4. Center - Play the center if it is free
  5. Corner - Play the opposite corner of an opponent or a random corner if opponent does not occupy a corner
  6. Random - Play in a random space if no other priorites are met

## Controls:

 - Player is prompted for a row/column number 1-3, a number outside the bounds will be invalid and the player will be prompted again 
 - If the player selects an occupied space the player will be prompted to pick another space 
 
## Prerequisites

- A C compiler (`gcc`, `clang`, etc.)
- A Unix-like terminal (Linux, macOS, or WSL on Windows)

## Build and Run

```bash
git clone https://github.com/yourusername/tictactoe-terminal.git
cd tictactoe-terminal
gcc tictactoe.c -o tictactoe
./tictactoe

