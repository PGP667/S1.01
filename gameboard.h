#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include <vector>

using namespace std;


const char kTokenPlayer1 = 'O';
const char kTokenPlayer2 = 'X';
const char kWall         = '#';
const char kEmpty        = '.';

const unsigned KReset = 0;
const unsigned KVert  = 32;
const unsigned KJaune = 33;
const unsigned KBleu  = 34;


typedef pair<unsigned, unsigned> CPosition;


void clearScreen();
void couleur(const unsigned &coul);
void bgCouleur(const unsigned &coul);

void showMatrix1(const vector<vector<char>> &Mat);
void showMatrix2(const vector<vector<char>> &Mat);

void initMat(vector<vector<char>> &Mat, unsigned nLevel, CPosition &posPlayer1, CPosition &posPlayer2);
void moveToken(vector<vector<char>> &Mat, char move, CPosition &pos);

int ppal();
int gameBoard();

#endif
