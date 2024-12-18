#include "gameboard.h"
#include <iostream>
#include <vector>
#include <limits>
#include <stdlib.h>
#include <time.h>

using namespace std;

void clearScreen () {
    cout << "\033[H\033[2J";
}

void couleur (const unsigned & coul) {
    cout << "\033[" << coul <<"m";
}

void bgCouleur (const unsigned & coul) {
    cout << "\033[" << coul + 10 <<"m";
}

void showMatrix (const vector <vector<char>> & Mat){
    clearScreen();
    couleur(KReset);
    for (size_t y = 0; y < Mat.size(); ++y) {
        for (size_t x = 0; x < Mat[y].size(); ++x){
            switch (Mat[y][x]){
            case (KTokenPacman):
                couleur(KJaune);
                cout << KTokenPacman;
                break;
            case (KTokenGhost):
                couleur(KBleu);
                cout << KTokenGhost;
                break;
            case (KTokenRedGhost):
                couleur(KRouge);
                cout << KTokenGhost;
                break;
            case (KTokenPinkGhost):
                couleur(KMagenta);
                cout << KTokenGhost;
                break;
            case (KTokenBlueGhost):
                couleur(KCyan);
                cout << KTokenGhost;
                break;
            case (KTokenOrangeGhost):
                couleur(KJaune);
                cout << KTokenGhost;
                break;
            case (KWall):
                bgCouleur(KVert);
                cout << ' ';
                break;
            case (KDot):
                couleur(KJaune);
                cout << KDot;
                break;
            case (KGum):
                couleur(KJaune);
                cout << KGum;
                break;
            default :
                cout << ' ';
                break;
            }
            couleur(KReset);
        }
        cout << endl;
    }
    cout << endl;
}

void initMat (vector <vector<char>> & Mat, unsigned nLevel, CPosition & posPlayer,
             CDirection & dirPlayer, vector<ghost> & ghosts)
{
    Mat = {
           {'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'},
           {'#','.','.','.','.','.','.','.','.','.','.','.','.','#','#','.','.','.','.','.','.','.','.','.','.','.','.','#'},
           {'#','.','#','#','#','#','.','#','#','#','#','#','.','#','#','.','#','#','#','#','#','.','#','#','#','#','.','#'},
           {'#','o','#','#','#','#','.','#','#','#','#','#','.','#','#','.','#','#','#','#','#','.','#','#','#','#','o','#'},
           {'#','.','#','#','#','#','.','#','#','#','#','#','.','#','#','.','#','#','#','#','#','.','#','#','#','#','.','#'},
           {'#','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','#'},
           {'#','.','#','#','#','#','.','#','#','.','#','#','#','#','#','#','#','#','.','#','#','.','#','#','#','#','.','#'},
           {'#','.','#','#','#','#','.','#','#','.','#','#','#','#','#','#','#','#','.','#','#','.','#','#','#','#','.','#'},
           {'#','.','.','.','.','.','.','#','#','.','.','.','.','#','#','.','.','.','.','#','#','.','.','.','.','.','.','#'},
           {'#','#','#','#','#','#','.','#','#','#','#','#','_','#','#','_','#','#','#','#','#','.','#','#','#','#','#','#'},
           {'_','_','_','_','_','#','.','#','#','#','#','#','_','#','#','_','#','#','#','#','#','.','#','_','_','_','_','_'},
           {'_','_','_','_','_','#','.','#','#','_','_','_','_','_','_','_','_','_','_','#','#','.','#','_','_','_','_','_'},
           {'_','_','_','_','_','#','.','#','#','_','#','#','#','|','|','#','#','#','_','#','#','.','#','_','_','_','_','_'},
           {'#','#','#','#','#','#','.','#','#','_','#','_','_','_','_','_','_','#','_','#','#','.','#','#','#','#','#','#'},
           {'.','.','.','.','.','.','.','_','_','_','#','_','_','_','_','_','_','#','_','_','_','.','.','.','.','.','.','.'},
           {'#','#','#','#','#','#','.','#','#','_','#','_','_','_','_','_','_','#','_','#','#','.','#','#','#','#','#','#'},
           {'_','_','_','_','_','#','.','#','#','_','#','#','#','#','#','#','#','#','_','#','#','.','#','_','_','_','_','_'},
           {'_','_','_','_','_','#','.','#','#','_','_','_','_','_','_','_','_','_','_','#','#','.','#','_','_','_','_','_'},
           {'_','_','_','_','_','#','.','#','#','_','#','#','#','#','#','#','#','#','_','#','#','.','#','_','_','_','_','_'},
           {'#','#','#','#','#','#','.','#','#','_','#','#','#','#','#','#','#','#','_','#','#','.','#','#','#','#','#','#'},
           {'#','.','.','.','.','.','.','.','.','.','.','.','.','#','#','.','.','.','.','.','.','.','.','.','.','.','.','#'},
           {'#','.','#','#','#','#','.','#','#','#','#','#','.','#','#','.','#','#','#','#','#','.','#','#','#','#','.','#'},
           {'#','.','#','#','#','#','.','#','#','#','#','#','.','#','#','.','#','#','#','#','#','.','#','#','#','#','.','#'},
           {'#','o','.','.','#','#','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','#','#','.','.','o','#'},
           {'#','#','#','.','#','#','.','#','#','.','#','#','#','#','#','#','#','#','.','#','#','.','#','#','.','#','#','#'},
           {'#','#','#','.','#','#','.','#','#','.','#','#','#','#','#','#','#','#','.','#','#','.','#','#','.','#','#','#'},
           {'#','.','.','.','.','.','.','#','#','.','.','.','.','#','#','.','.','.','.','#','#','.','.','.','.','.','.','#'},
           {'#','.','#','#','#','#','#','#','#','#','#','#','.','#','#','.','#','#','#','#','#','#','#','#','#','#','.','#'},
           {'#','.','#','#','#','#','#','#','#','#','#','#','.','#','#','.','#','#','#','#','#','#','#','#','#','#','.','#'},
           {'#','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','#'},
           {'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'},
           };

    posPlayer = CPosition(1,1);
    Mat[posPlayer.first][posPlayer.second] = KTokenPacman;
    dirPlayer = CDirection(0,0);

    const vector<string> KGhostTypes {"red","pink","orange","blue"};
    const vector<unsigned> KGhostCooldowns {1,2,3,4};
    const vector<char> KGhostTokens {KTokenRedGhost, KTokenPinkGhost, KTokenOrangeGhost, KTokenBlueGhost};

    for (unsigned i = 0; i < 4; ++i) {
        ghosts.push_back(ghost());
        ghosts[i].type = KGhostTypes[i];
        ghosts[i].pos = CPosition(14,12+i);
        ghosts[i].dir = CDirection(0,0);
        ghosts[i].cooldown = KGhostCooldowns[i];
        ghosts[i].token = KGhostTokens[i];
        Mat[ghosts[i].pos.first][ghosts[i].pos.second] = ghosts[i].token;
    }
}

/*
void addTeleporter (const pair & KCoords1, const pair & KCoords2, const char & KToken)
{
    return;
}
*/

void movePlayer (vector <vector<char>> & Mat, char move, CPosition & pos,
                CDirection & dir, unsigned & gumTime)
{
    int newY=pos.first, newX=pos.second;
    const char KToken = Mat[pos.first][pos.second];
    Mat[pos.first][pos.second] = KEmpty;

    switch (move) {
    case 'z':
        dir.first = -1;
        dir.second = 0;
        break;
    case 'q':
        dir.first = 0;
        dir.second = -1;
        break;
    case 'd':
        dir.first = 0;
        dir.second = 1;
        break;
    case 's':
        dir.first = 1;
        dir.second = 0;
        break;
    }

    if (newY+dir.first < 0)
        newY = (newY+dir.first)+Mat.size();
    else
        newY = (newY+dir.first)%Mat.size();

    if (newX+dir.second < 0)
        newX = (newX+dir.second)+Mat[0].size();
    else
        newX = (newX+dir.second)%Mat[0].size();

    if (Mat[newY][pos.second] != KWall && Mat[newY][pos.second] != KBarrier)
        pos.first = newY;

    if (Mat[pos.first][newX] != KWall && Mat[pos.first][newX] != KBarrier)
        pos.second = newX;

    if (Mat[pos.first][pos.second] == KGum)
        gumTime = 15;

    Mat[pos.first][pos.second] = KToken;
}

void moveRandom (vector <vector<char>> & Mat, ghost & gh, unsigned & gumTime)
{
    int newY=gh.pos.first, newX=gh.pos.second;

    // On vérifie les chemins disponibles, sauf celui où l'on se retournerait
    vector<CDirection> choiceDir;
    if (newY == 0 || (gh.dir.first != 1 && Mat[(newY-1)][gh.pos.second] != KWall
                      && Mat[(newY-1)][gh.pos.second] != KTokenGhost && Mat[(newY-1)][gh.pos.second] != KBarrier))
        choiceDir.push_back(CDirection (-1, 0));

    if (newY == Mat.size()-1 || (gh.dir.first != -1 && Mat[newY+1][gh.pos.second] != KWall
                                   && Mat[newY+1][gh.pos.second] != KTokenGhost && Mat[newY+1][gh.pos.second] != KBarrier))
        choiceDir.push_back(CDirection (1, 0));

    if (newX == 0 || (gh.dir.second != 1 && Mat[gh.pos.first][newX-1] != KWall
                      && Mat[gh.pos.first][gh.pos.second-1] != KTokenGhost && Mat[gh.pos.first][gh.pos.second-1] != KBarrier))
        choiceDir.push_back(CDirection (0, -1));

    if (newX == Mat[0].size()-1 || (gh.dir.second != -1 && Mat[gh.pos.first][newX+1] != KWall
                                      && Mat[gh.pos.first][gh.pos.second+1] != KTokenGhost && Mat[gh.pos.first][gh.pos.second+1] != KBarrier))
        choiceDir.push_back(CDirection (0, 1));

    switch (choiceDir.size()){
    case 0 :
        gh.dir = CDirection(-1*gh.dir.first,-1*gh.dir.second);
        break;
    case 1 :
        gh.dir = choiceDir[0];
        break;
    default:
        gh.dir = choiceDir[random()%choiceDir.size()];
        break;
    }

    if (newY+gh.dir.first < 0)
        newY = (newY+gh.dir.first)+Mat.size();
    else
        newY = (newY+gh.dir.first)%Mat.size();

    if (newX+gh.dir.second < 0)
        newX = (newX+gh.dir.second)+Mat[0].size();
    else
        newX = (newX+gh.dir.second)%Mat[0].size();

    Mat[gh.pos.first][gh.pos.second] = gh.tokenUnder;
    gh.tokenUnder = Mat[newY][newX];

    gh.pos.first = newY;
    gh.pos.second = newX;

    Mat[gh.pos.first][gh.pos.second] = gh.token;
}

int ppal ()
{
    // Init grille
    vector <vector<char>> Mat;
    pacman player;
    vector <ghost> ghosts;

    initMat(Mat, 1, player.pos, player.dir, ghosts);
    showMatrix(Mat);

    unsigned gumTime = 0;

    while (player.pos != ghosts[0].pos){
        char input;

        cout << "Joueur 1, c'est votre tour!";

        cin >> input;
        movePlayer(Mat, input, player.pos, player.dir, gumTime);

        if (gumTime > 0){
            if (gumTime < 15)
                movePlayer(Mat, ' ', player.pos, player.dir, gumTime);
            --gumTime;
        }

        for (unsigned i = 0; i < ghosts.size(); ++i){
            if (ghosts[i].cooldown == 0)
                moveRandom(Mat, ghosts[i], gumTime);
            else{
                if (ghosts[i].cooldown == 1){
                    Mat[ghosts[i].pos.first][ghosts[i].pos.second] = KEmpty;
                    ghosts[i].pos = CPosition(11,14);
                    ghosts[i].tokenUnder = Mat[11][14];
                    Mat[ghosts[i].pos.first][ghosts[i].pos.second] = ghosts[i].token;
                }
                ghosts[i].cooldown -= 1;
                cout << ghosts[i].cooldown;
            }
        }

        showMatrix(Mat);
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    /*
    if (posPlayer1 == posGhost1)
        cout << "Le joueur " << ((Mat[posPlayer1.first][posPlayer1.second]==KTokenPlayer1) ?
                                     '1' : '2') << " a gagné !" << endl;
    else
        cout << "Aucun vainqueur...";
    */
    return 0;
}

int gameBoard()
{
    srand(time(NULL));
    ppal();
    return 0;
}
