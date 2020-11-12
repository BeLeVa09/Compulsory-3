#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <ctime>
#include <conio.h>
#include <string>
#include <windows.h>
#include "Variables.h"

void game();
int letterToNumber(char);
void login();
void drawLock(char lock[4][4]);
void readFromFile();
int main();
void menu();
void changePassword();
void shoot();



int letterToNumber(char letter) // only big letters
{ 
    return static_cast<int>(letter)-65; 
}

void login() {
    char lock[4][4];
    int failCounter{ 0 };
    readFromFile();

    do {
        int currentX{ 0 };
        int currentY{ 0 };
        int correct{ 0 };
        int counter{ 0 };
        char combination[10]{ 'A', '-', '-', '-', '-', '-', '-', '-', '-', '-' };

        // Initializing the grid
        for (int i{ 0 }; i < 4; ++i) {
            for (int j{ 0 }; j < 4; ++j) {
                lock[i][j] = i * 4 + j + 65; // i*3 to get the values 456 and 789 in correct positions since all numbers are values of j
            } // + 49 since this is a char array and I need ascii values of numbers to be put in
        }
        lock[currentY][currentX] = '*'; // Starting position

        system("cls");

        std::cout << "Move with WASD, you have three tries\n";
        drawLock(lock);
        std::cout << "\n\t [" << combination[0] << "][" << combination[1] << "][" << combination[2] << "][" << combination[3] << "][" << combination[4] << "][" << combination[5] << "][" << combination[6] << "][" << combination[7] << "][" << combination[8] << "][" << combination[9] << "]\n";

        do {
            char input = _getch();
            system("cls");

            lock[currentY][currentX] = currentY * 4 + currentX + 65;
            if (toupper(input) == 'S' && currentY != 3) {
                currentY += 1;
            }
            else if (toupper(input) == 'W' && currentY != 0) {
                currentY -= 1;
            }
            else if (toupper(input) == 'A' && currentX != 0) {
                currentX -= 1;
            }
            else if (toupper(input) == 'D' && currentX != 3) {
                currentX += 1;
            }

            ++counter;
            combination[counter] = lock[currentY][currentX];
            lock[currentY][currentX] = '*';
            drawLock(lock);

            std::cout << "\n\t [" << combination[0] << "][" << combination[1] << "][" << combination[2] << "][" << combination[3] << "][" << combination[4] << "][" << combination[5] << "][" << combination[6] << "][" << combination[7] << "][" << combination[8] << "][" << combination[9] << "]\n";

        } while (counter < 9);

        for (int i{ 0 }; i < 10; ++i) {
            if (combination[i] == correctCombination[i]) {
                ++correct;
            }
        }
        if (correct == 10) {
            menu();
            failCounter = 3;
        }
        else {
            ++failCounter;
        }
    } while (failCounter < 3);
}

void drawLock(char lock[4][4]) {

    std::cout << "\n\t\t    ";
    for (int i{ 0 }; i < 4; ++i) {
        for (int j{ 0 }; j < 4; ++j) {

            std::cout << lock[i][j] << ' ';

            if (j == 3 && i != 3) {
                std::cout << "\n\t\t    ";
            }
        }
    }
}

void changePassword() {
    std::fstream File("Password.txt", std::ios::out);
    char lock[4][4];
    int failCounter{ 0 };

    int currentX{ 0 };
    int currentY{ 0 };
    int correct{ 0 };
    int counter{ 0 };
    char combination[10]{ 'A', '-', '-', '-', '-', '-', '-', '-', '-', '-' };

    // Initializing the grid
    for (int i{ 0 }; i < 4; ++i) {
        for (int j{ 0 }; j < 4; ++j) {
                lock[i][j] = i * 4 + j + 65; // i*3 to get the values 456 and 789 in correct positions since all numbers are values of j
        } // + 49 since this is a char array and I need ascii values of numbers to be put in
    }
    lock[currentY][currentX] = '*'; // Starting position

    system("cls");
        
    std::cout << "Move with WASD\n";
    drawLock(lock);
    std::cout << "\n\t [" << combination[0] << "][" << combination[1] << "][" << combination[2] << "][" << combination[3] << "][" << combination[4] << "][" << combination[5] << "][" << combination[6] << "][" << combination[7] << "][" << combination[8] << "][" << combination[9] << "]\n";

    do {
        char input = _getch();
        system("cls");

        lock[currentY][currentX] = currentY * 4 + currentX + 65;
        if (toupper(input) == 'S' && currentY != 3) {
            currentY += 1;
        }
        else if (toupper(input) == 'W' && currentY != 0) {
            currentY -= 1;
        }
        else if (toupper(input) == 'A' && currentX != 0) {
            currentX -= 1;
        }
        else if (toupper(input) == 'D' && currentX != 3) {
            currentX += 1;
        }

        ++counter;
        combination[counter] = lock[currentY][currentX];
        lock[currentY][currentX] = '*';
        drawLock(lock);

        std::cout << "\n\t [" << combination[0] << "][" << combination[1] << "][" << combination[2] << "][" << combination[3] << "][" << combination[4] << "][" << combination[5] << "][" << combination[6] << "][" << combination[7] << "][" << combination[8] << "][" << combination[9] << "]\n";
        std::cout << "Remember this password\n";

    } while (counter < 9);

    for (int i{ 0 }; i < 10; ++i) {
        File << combination[i];
    }
}

void menu() {
    bool quit{ 0 };

    do {
        system("cls");
        std::cout << "        ____        __  __  __    _____ __    _\n";
        std::cout << "       / __ )____ _/ /_/ /_/ /__ / ___// /_  (_)___ \n";
        std::cout << "      / __  / __ `/ __/ __/ / _ \\\\__ \\/ __ \\/ / __ \\\n";
        std::cout << "     / /_/ / /_/ / /_/ /_/ /  __/__/ / / / / / /_/ /\n";
        std::cout << "    /_____/\\__,_/\\__/\\__/_/\\___/____/_/ /_/_/ .___/\n";
        std::cout << "                                           /_/\n\n";
        std::cout << "\t\t 1. Change Password\n";
        std::cout << "\t\t 2. Play BattleShip\n";
        std::cout << "\t\t      3. Exit\n";

        switch (_getch()) {
        case '1':
            changePassword();
            break;

        case '2':
            game();
            break;

        case '3':
            quit = 1;
            break;

        default:
            break;
        }
    } while (!quit);
}

void readFromFile() {
    std::fstream File("Password.txt", std::ios::in);
    if (File.is_open()) {
        while (!File.eof()) {
            for (int i{ 0 }; i < 10; ++i) {
                File >> correctCombination[i];
            }
        }
    }
    else {
        perror("Password.txt");
    }
    File.close();
}

void shoot() {
    std::string coords = "";
    int X{ 0 };
    int Y{ 0 };

        std::cout << "We've got " << shots << " shots ready!\n";
        std::cout << "Coordinates, captain? (Ex. A1): ";
        std::cin >> coords;

        for (int i{ 0 }; i < coords.length(); ++i) {
            if (i == 0) {
                X = letterToNumber(toupper(coords[i]));
            }
            else {
                Y = coords[i] - 49;
            }
        }
        if (AIBoard[Y][X] == SHIP) {
            playerBoard[Y][X] = HIT;
            ++numberOfHits;
            ++numberOfShots;
        }
        else {
            playerBoard[Y][X] = MISS;
            ++numberOfShots;
        }
        --shots;
}

void game() {
	char letter{ 65 };
	int number{ 1 };
    bool xDir{ 1 };
    bool yDir{ 0 };
    int shipSize{ 5 };
    int clear{ 0 };

	// initialization
	for (int i{ 0 }; i < boardHeight; ++i) {
		for (int j{ 0 }; j < boardWidth; ++j) {
			board[i][j] = BLANK;
            playerBoard[i][j] = BLANK;
            AIBoard[i][j] = BLANK;
		}
	}

        system("cls");
        
        // placing ships
        int rX{ 0 };
        int rY{ 0 };
        for (int i{ 0 }; i < numberOfShips * 2; ++i) {
            do {
                clear = 0;
                do {
                    // Direction
                    xDir = rand() % 2;
                    yDir = !xDir;

                    // Choose source
                    rX = rand() % (boardWidth - shipSize * xDir);
                    rY = rand() % (boardHeight - shipSize * yDir);

                    // Checks if ship is on the grid
                } while ((rX < 0 || rY < 0) && (rX > boardWidth || rY > boardHeight));

                if (i < numberOfShips) {
                    // Checks for horizontal ship overlapping
                    if (xDir) {
                        for (int j{ 0 }; j < shipSize; ++j) {
                            if (board[rY][rX] != SHIP) {
                                ++clear;
                            }
                            ++rX;
                        }
                    }
                    else { // Checks for vertical ship overlapping
                        for (int j{ 0 }; j < shipSize; ++j) {
                            if (board[rY][rX] != SHIP) {
                                ++clear;
                            }
                            ++rY;
                        }
                    }
                }
                else {
                    // Checks for horizontal ship overlapping
                    if (xDir) {
                        for (int j{ 0 }; j < shipSize; ++j) {
                            if (AIBoard[rY][rX] != SHIP) {
                                ++clear;
                            }
                            ++rX;
                        }
                    }
                    else { // Checks for vertical ship overlapping
                        for (int j{ 0 }; j < shipSize; ++j) {
                            if (AIBoard[rY][rX] != SHIP) {
                                ++clear;
                            }
                            ++rY;
                        }
                    }
                }

            } while (clear != shipSize);
            if (i < numberOfShips) {
                if (xDir) {
                    for (int j{ 0 }; j < shipSize; ++j) {
                        board[rY][rX] = SHIP;
                        --rX;
                    }
                }
                else {
                    for (int j{ 0 }; j < shipSize; ++j) {
                        board[rY][rX] = SHIP;
                        --rY;
                    }
                }
            }
            else {
                if (xDir) {
                    for (int j{ 0 }; j < shipSize; ++j) {
                        AIBoard[rY][rX] = SHIP;
                        --rX;
                    }
                }
                else {
                    for (int j{ 0 }; j < shipSize; ++j) {
                        AIBoard[rY][rX] = SHIP;
                        --rY;
                    }
                }
            }
            
            if (i == 2 || i == 7) {
                ++shipSize;
            }
            --shipSize;
            if (shipSize == 1) {
                shipSize = 5;
            }
        }


        do { // Game loop ||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
            for (int k{ 0 }; k < maxShots; ++k) {

                if (shots == 0) {
                    // AI phase |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
                    int AIX{ 0 };
                    int AIY{ 0 };

                    for (int i{ 0 }; i < maxShots; ++i) {
                        do {
                            AIX = rand() % boardWidth;
                            AIY = rand() % boardHeight;
                        } while (board[AIY][AIX] == HIT || board[AIY][AIX] == MISS);
                        if (board[AIY][AIX] == SHIP) {
                            board[AIY][AIX] = HIT;
                        }
                        else {
                            board[AIY][AIX] = MISS;
                        }
                    }

                    shots = maxShots;
                }

                system("cls");
                // printing
                number = 1;
                for (int i{ 0 }; i < boardHeight; ++i) {
                    std::cout << " " << number << "\t";
                    for (int j{ 0 }; j < boardWidth; ++j) {
                        std::cout << "|" << playerBoard[i][j];
                    }
                    std::cout << "|\n";
                    ++number;
                }

                std::cout << "\n\t";
                letter = 65;
                for (int i{ 0 }; i < boardWidth; ++i) {
                    std::cout << " " << letter;
                    ++letter;
                }
                std::cout << "\n\n";

                // printing
                number = 1;
                for (int i{ 0 }; i < boardHeight; ++i) {
                    std::cout << " " << number << "\t";
                    for (int j{ 0 }; j < boardWidth; ++j) {
                        std::cout << "|" << board[i][j];
                    }
                    std::cout << "|\n";
                    ++number;
                }

                shoot();
            }

        } while (numberOfHits < 17);
}

int main() {
	srand(time(NULL));
    login();
}