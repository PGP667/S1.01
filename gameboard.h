#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include <vector>

using namespace std;

typedef pair   <unsigned, unsigned> CPosition; // un type représentant une coordonnée dans la grille
typedef pair   <int, int> CDirection; // un type représentant le vecteur trajectoire du joueur

struct pacman
{
    CPosition pos;
    CDirection dir;
    char move;
    CDirection nextDir;
    char nextMove;
};

struct ghost
{
    string type;
    CPosition spawn;
    CPosition pos;
    CDirection dir;
    char token;
    char tokenUnder;        // Decrit à quel charactère le fantome à pris la place sur le plateau (ex: le fantome est sur un point)
    unsigned cooldown = 0;
};

const char KTokenPacman         = 'O';
const char KTokenGhost          = 'X';
const char KTokenRedGhost       = 'R';
const char KTokenPinkGhost      = 'P';
const char KTokenOrangeGhost    = 'Y';
const char KTokenBlueGhost      = 'B';
const char KWall                = '#';
const char KBarrier             = '|';
const char KDot                 = '.';
const char KGum                 = 'o';
const char KEmpty               = '_';

const unsigned KGumDuration = 25;
const unsigned KCooldownDuration = 25;

const unsigned KReset   (0);
const unsigned KNoir    (30);
const unsigned KRouge   (31);
const unsigned KVert    (32);
const unsigned KJaune   (33);
const unsigned KBleu    (34);
const unsigned KMagenta (35);
const unsigned KCyan    (36);

void clearScreen();
void couleur(const unsigned &coul);
void bgCouleur(const unsigned &coul);

void showMatrix(const vector<vector<char>> &Mat);

void initMat (vector <vector<char>> & Mat, unsigned nLevel, CPosition & posPlayer, CDirection & dirPlayer, vector<ghost> & ghosts);
void movePlayer (vector <vector<char>> & Mat, char move, CPosition & pos, CDirection & dir, unsigned & gumTime);

void moveRandom (vector <vector<char>> & Mat, ghost & gh, unsigned & gumTime);

int ppal();
int gameBoard();

#endif
