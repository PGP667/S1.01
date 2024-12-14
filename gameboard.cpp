#include "gameboard.h"
#include <iostream>
#include <vector>
#include <limits>
#include <fstream>
#include <unistd.h>

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

void showMatrix1 (const vector <vector<char>> & Mat){
    clearScreen();
    couleur(KReset);
    bgCouleur(KVert);
    for (size_t i = 0; i < Mat[0].size()*2 + 1; ++i)
        cout << ' ';
    couleur(KReset);
    cout << endl;
    for (size_t y = 0; y < Mat.size(); ++y) {
        bgCouleur(KVert);
        cout << ' ';
        couleur(KReset);
        for (size_t x = 0; x < Mat[y].size(); ++x){
            if (Mat[y][x] == kTokenPlayer1){
                couleur(KJaune);
                cout << kTokenPlayer1;
            }
            else if (Mat[y][x] == kTokenPlayer2){
                couleur(KBleu);
                cout << kTokenPlayer2;
            }
            else {
                cout << kEmpty;
            }
            bgCouleur(KVert);
            cout << ' ';
            couleur(KReset);
        }
        cout << endl;
        bgCouleur(KVert);
        for (size_t i = 0; i < Mat[y].size()*2 + 1; ++i)
            cout << ' ';
        couleur(KReset);
        cout << endl;
    }
}

void showMatrix2(const vector<vector<char>> &Mat) {
    clearScreen();
    couleur(KReset);
    // bgCouleur(KVert); // Commenté pour supprimer la bordure
    // for (size_t i = 0; i < Mat[0].size() + 2; ++i)
    //     cout << ' ';
    couleur(KReset);
    cout << endl;
    for (size_t y = 0; y < Mat.size(); ++y) {
        // bgCouleur(KVert); // Commenté pour supprimer la bordure
        // cout << ' ';
        couleur(KReset);
        for (size_t x = 0; x < Mat[y].size(); ++x) {
            if (Mat[y][x] == kTokenPlayer1) {
                couleur(KJaune);
                cout << kTokenPlayer1;
            } else if (Mat[y][x] == kTokenPlayer2) {
                couleur(KBleu);
                cout << kTokenPlayer2;
            } else if (Mat[y][x] == kWall) {
                bgCouleur(KVert); // Commenté pour supprimer la bordure
                cout << ' ';
                couleur(KReset);
            } else {
                cout << ' ';
            }
        }
        // bgCouleur(KVert); // Commenté pour supprimer la bordure
        // cout << ' ';
        couleur(KReset);
        cout << endl;
    }
    // bgCouleur(KVert); // Commenté pour supprimer la bordure
    // for (size_t i = 0; i < Mat[0].size() + 2; ++i)
    //     cout << ' ';
    couleur(KReset);
    cout << endl;
}

void printCurrentDirectory() {
    char cwd[PATH_MAX];
    if (getcwd(cwd, sizeof(cwd)) != nullptr) {
        cout << "Répertoire courant : " << cwd << endl;
    } else {
        cerr << "Erreur : Impossible de récupérer le répertoire courant." << endl;
    }
}

void loadLevelFromFile(const string &filename, vector<vector<char>> &Mat) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Erreur : Impossible d'ouvrir le fichier " << filename << endl;
        exit(EXIT_FAILURE);
    }

    Mat.clear();
    string line;
    while (getline(file, line)) {
        vector<char> row(line.begin(), line.end());
        Mat.push_back(row);
    }

    file.close();
}

void initMat(vector<vector<char>> &Mat, /*unsigned nLevel,*/ CPosition &posPlayer1, CPosition &posPlayer2) {
    string filename = "levels/nLevel0.txt";
    loadLevelFromFile(filename, Mat);

    Mat[23][13] = kTokenPlayer1;
    posPlayer1 = CPosition(13, 23);

    Mat[20][20] = kTokenPlayer2;
    posPlayer2 = CPosition(20, 20);
}

/*
void initMat (vector <vector<char>> & Mat, unsigned nLevel, CPosition & posPlayer1,
             CPosition & posPlayer2)
{
    Mat = {
           {'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'},
           {'#','.','.','.','.','.','.','.','.','.','.','.','.','#','#','.','.','.','.','.','.','.','.','.','.','.','.','#'},
           {'#','.','#','#','#','#','.','#','#','#','#','#','.','#','#','.','#','#','#','#','#','.','#','#','#','#','.','#'},
           {'#','.','#','#','#','#','.','#','#','#','#','#','.','#','#','.','#','#','#','#','#','.','#','#','#','#','.','#'},
           {'#','.','#','#','#','#','.','#','#','#','#','#','.','#','#','.','#','#','#','#','#','.','#','#','#','#','.','#'},
           {'#','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','#'},
           {'#','.','#','#','#','#','.','#','#','.','#','#','#','#','#','#','#','#','.','#','#','.','#','#','#','#','.','#'},
           {'#','.','#','#','#','#','.','#','#','.','#','#','#','#','#','#','#','#','.','#','#','.','#','#','#','#','.','#'},
           {'#','.','.','.','.','.','.','#','#','.','.','.','.','#','#','.','.','.','.','#','#','.','.','.','.','.','.','#'},
           {'#','#','#','#','#','#','.','#','#','#','#','#','.','#','#','.','#','#','#','#','#','.','#','#','#','#','#','#'},
           {'.','.','.','.','.','#','.','#','#','#','#','#','.','#','#','.','#','#','#','#','#','.','#','.','.','.','.','.'},
           {'.','.','.','.','.','#','.','#','#','.','.','.','.','.','.','.','.','.','.','#','#','.','#','.','.','.','.','.'},
           {'.','.','.','.','.','#','.','#','#','.','#','#','#','.','.','#','#','#','.','#','#','.','#','.','.','.','.','.'},
           {'#','#','#','#','#','#','.','#','#','.','#','.','.','.','.','.','.','#','.','#','#','.','#','#','#','#','#','#'},
           {'.','.','.','.','.','.','.','.','.','.','#','.','.','.','.','.','.','#','.','.','.','.','.','.','.','.','.','.'},
           {'#','#','#','#','#','#','.','#','#','.','#','.','.','.','.','.','.','#','.','#','#','.','#','#','#','#','#','#'},
           {'.','.','.','.','.','#','.','#','#','.','#','#','#','#','#','#','#','#','.','#','#','.','#','.','.','.','.','.'},
           {'.','.','.','.','.','#','.','#','#','.','.','.','.','.','.','.','.','.','.','#','#','.','#','.','.','.','.','.'},
           {'.','.','.','.','.','#','.','#','#','.','#','#','#','#','#','#','#','#','.','#','#','.','#','.','.','.','.','.'},
           {'#','#','#','#','#','#','.','#','#','.','#','#','#','#','#','#','#','#','.','#','#','.','#','#','#','#','#','#'},
           {'#','.','.','.','.','.','.','.','.','.','.','.','.','#','#','.','.','.','.','.','.','.','.','.','.','.','.','#'},
           {'#','.','#','#','#','#','.','#','#','#','#','#','.','#','#','.','#','#','#','#','#','.','#','#','#','#','.','#'},
           {'#','.','#','#','#','#','.','#','#','#','#','#','.','#','#','.','#','#','#','#','#','.','#','#','#','#','.','#'},
           {'#','.','.','.','#','#','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','#','#','.','.','.','#'},
           {'#','#','#','.','#','#','.','#','#','.','#','#','#','#','#','#','#','#','.','#','#','.','#','#','.','#','#','#'},
           {'#','#','#','.','#','#','.','#','#','.','#','#','#','#','#','#','#','#','.','#','#','.','#','#','.','#','#','#'},
           {'#','.','.','.','.','.','.','#','#','.','.','.','.','#','#','.','.','.','.','#','#','.','.','.','.','.','.','#'},
           {'#','.','#','#','#','#','#','#','#','#','#','#','.','#','#','.','#','#','#','#','#','#','#','#','#','#','.','#'},
           {'#','.','#','#','#','#','#','#','#','#','#','#','.','#','#','.','#','#','#','#','#','#','#','#','#','#','.','#'},
           {'#','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','#'},
           {'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'},
           };

    Mat[23][13] = kTokenPlayer1;
    posPlayer1 = CPosition(13,23);

    Mat[20][20] = kTokenPlayer2;
    posPlayer2 = CPosition(20,20);
}
*/
void moveToken(vector<vector<char>> &Mat, char move, CPosition &pos) {
    short x = 0, y = 0;
    char kToken = Mat[pos.second][pos.first];
    Mat[pos.second][pos.first] = kEmpty;

    switch (move) {
    case 'z':
        y = -1; // Mouvement vers le haut
        break;
    case 'q':
        x = -1; // Mouvement vers la gauche
        break;
    case 'd':
        x = 1;  // Mouvement vers la droite
        break;
    case 's':
        y = 1;  // Mouvement vers le bas
        break;
    default:
        cout << "Mouvement invalide !" << endl;
        Mat[pos.second][pos.first] = kToken;
        return;
    }

    if (0 <= (int)(pos.first + x) && pos.first + x < Mat[0].size() &&
        0 <= (int)(pos.second + y) && pos.second + y < Mat.size() &&
        Mat[pos.second + y][pos.first + x] != kWall) {
        pos.first += x;
        pos.second += y;
    }

    Mat[pos.second][pos.first] = kToken;
}

int ppal ()
{
    // Init grille
    vector <vector<char>> Mat;
    CPosition posPlayer1, posPlayer2;

    initMat(Mat, /*1,*/ posPlayer1, posPlayer2);
    showMatrix2(Mat);

    while (posPlayer1 != posPlayer2){
        char input;

        cout << "Joueur 1, c'est votre tour!";
        cin >> input;
        moveToken(Mat, input, posPlayer1);
        showMatrix2(Mat);
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    if (posPlayer1 == posPlayer2){
        cout << "Le joueur " << ((Mat[posPlayer1.second][posPlayer1.first]==kTokenPlayer1) ?
                                     '1' : '2') << " a gagné !" << endl;
    }
    else{
        cout << "Aucun vainqueur...";
    }

    return 0;
}

int gameBoard()
{
    printCurrentDirectory();
    ppal();
    return 0;
}
