#ifndef _CHESSPIECE__H
#define _CHESSPIECE__H

#include "include.h"
#include "defs.h"
struct ChessPiece{

    SDL_Texture* texture;

    int pieceColor[90] = {
    1, 1, 1, 1, 1, 1, 1, 1, 1,
    0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 1, 0, 0, 0, 0, 0, 1, 0,
    1, 0, 1, 0, 1, 0, 1, 0, 1,
    0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0,
    2, 0, 2, 0, 2, 0, 2, 0, 2,
    0, 2, 0, 0, 0, 0, 0, 2, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0,
    2, 2, 2, 2, 2, 2, 2, 2, 2    
    }; 

    int piecePos[90] = {
    6, 4, 3, 2, 7, 2, 3, 4, 6,
    0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 5, 0, 0, 0, 0, 0, 5, 0,
    1, 0, 1, 0, 1, 0, 1, 0, 1,
    0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0,
    1, 0, 1, 0, 1, 0, 1, 0, 1,
    0, 5, 0, 0, 0, 0, 0, 5, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0,
    6, 4, 3, 2, 7, 2, 3, 4, 6};

    const int lightPos[7][4] = {
        // do
        {138,200,60,60}, // tot         
        {71,135,60,60}, //si
        {138,135,60,60}, //tuong
        {272,200,60,60}, // ma   
        {339,135,60,60}, // phao
        {205,200,60,60}, // xe 
        {4,135,60,60} // tuong -king
    };

    const int darkPos[7][4] = {
        //den
        {205,70,60,60},//tot
        {71,4,60,60},//si
        {138,4,60,60},//tuong
        {272,4,60,60},//ma
        {272,70,60,60},//phao
        {205,4,60,60},//xe
        {4,4,60,60}//tuong-king
    };       

    int turn;
    int selected;
    // int type;

    ChessPiece(){
    }
    void init();
    void getInput(int pos);
    bool processClick();

    void move(int from, int dest);
    void undo(int dest, int from);

    bool ValidStep();

    void switchTurn();
    
    ~ChessPiece();

};


#endif