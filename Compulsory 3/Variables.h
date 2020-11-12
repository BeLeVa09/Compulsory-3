#pragma once

char correctCombination[10];
int boardWidth{ 6 };
int boardHeight{ 6 };
const char BLANK = ' ';
const char SHIP = 'S';
const char MISS = 'M';
const char HIT = 'H';
int shots{ 3 };
int maxShots{ 3 };
int numberOfHits;
int numberOfShots;
int numberOfShips{ 5 };
std::vector <std::vector <char>> board(boardHeight, std::vector <char>(boardWidth));
std::vector <std::vector <char>> playerBoard(boardHeight, std::vector <char>(boardWidth));
std::vector <std::vector <char>> AIBoard(boardHeight, std::vector <char>(boardWidth));
