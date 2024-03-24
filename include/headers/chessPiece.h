#ifndef _CHESSPIECE__H
#define _CHESSPIECE__H

#include "include.h"
#include "defs.h"
#include "move.h"
struct ChessPiece{

    SDL_Texture* texture;
    MOVE Move;
    int selected;
    int tmp_selected;    

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
    // int pieceColor[90] = {
    // 0, 0, 0, 1, 1, 1, 0, 0, 0,
    // 0, 0, 0, 0, 0, 0, 0, 0, 0,
    // 0, 0, 0, 0, 0, 0, 0, 0, 0,
    // 1, 0, 1, 0, 1, 0, 1, 0, 1,
    // 0, 0, 0, 0, 0, 0, 0, 0, 0,
    // 0, 0, 0, 0, 0, 0, 0, 0, 0,
    // 2, 0, 2, 0, 2, 0, 2, 0, 2,
    // 0, 2, 0, 0, 0, 0, 0, 2, 0,
    // 0, 0, 0, 0, 0, 0, 0, 0, 0,
    // 2, 2, 2, 2, 2, 2, 2, 2, 2    
    // }; 

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
    // int piecePos[90] = {
    // 0, 0, 0, 2, 7, 2, 0, 0, 0,
    // 0, 0, 0, 0, 0, 0, 0, 0, 0,
    // 0, 0, 0, 0, 0, 0, 0, 0, 0,
    // 1, 0, 1, 0, 1, 0, 1, 0, 1,
    // 0, 0, 0, 0, 0, 0, 0, 0, 0,
    // 0, 0, 0, 0, 0, 0, 0, 0, 0,
    // 6, 0, 1, 0, 1, 0, 1, 0, 6,
    // 0, 5, 0, 0, 0, 0, 0, 5, 0,
    // 0, 0, 0, 0, 0, 0, 0, 0, 0,
    // 6, 4, 3, 2, 7, 2, 3, 4, 6};

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

    short Offset[8][8] =
    {   
        {0, 0, 0, 0, 0, 0, 0, 0},
        { -1, 1, 13, 0, 0, 0, 0, 0 },           // PAWN {for DARK side}
        { -12, -14, 12, 14, 0, 0, 0, 0 },           // BISHOP
        { -28, -24, 24, 28, 0, 0, 0, 0 },           // ELEPHAN
        { -11, -15, -25, -27, 11, 15, 25, 27 },         // KNIGHT
        { -1, 1, -13, 13, 0, 0, 0, 0 },         // CANNON
        { -1, 1, -13, 13, 0, 0, 0, 0 },         // ROOK
        { -1, 1, -13, 13, 0, 0, 0, 0 }          // KING
    };

    short Mailbox90[90] =
    {
        28, 29, 30, 31, 32, 33, 34, 35, 36,
        41, 42, 43, 44, 45, 46, 47, 48, 49,
        54, 55, 56, 57, 58, 59, 60, 61, 62,
        67, 68, 69, 70, 71, 72, 73, 74, 75,
        80, 81, 82, 83, 84, 85, 86, 87, 88,
        93, 94, 95, 96, 97, 98, 99, 100, 101,
        106, 107, 108, 109, 110, 111, 112, 113, 114,
        119, 120, 121, 122, 123, 124, 125, 126, 127,
        132, 133, 134, 135, 136, 137, 138, 139, 140,
        145, 146, 147, 148, 149, 150, 151, 152, 153
    };
    short Largebox[182] =
    {
        -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
        -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
        -1, -1,  0,  1,  2,  3,  4,  5,  6,  7,  8, -1, -1,
        -1, -1,  9, 10, 11, 12, 13, 14, 15, 16, 17, -1, -1,
        -1, -1, 18, 19, 20, 21, 22, 23, 24, 25, 26, -1, -1,
        -1, -1, 27, 28, 29, 30, 31, 32, 33, 34, 35, -1, -1,
        -1, -1, 36, 37, 38, 39, 40, 41, 42, 43, 44, -1, -1,
        -1, -1, 45, 46, 47, 48, 49, 50, 51, 52, 53, -1, -1,
        -1, -1, 54, 55, 56, 57, 58, 59, 60, 61, 62, -1, -1,
        -1, -1, 63, 64, 65, 66, 67, 68, 69, 70, 71, -1, -1,
        -1, -1, 72, 73, 74, 75, 76, 77, 78, 79, 80, -1, -1,
        -1, -1, 81, 82, 83, 84, 85, 86, 87, 88, 89, -1, -1,
        -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
        -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1
    };

    short Legalposition[90] =
    {
        1, 1, 5, 3, 3, 3, 5, 1, 1,
        1, 1, 1, 3, 3, 3, 1, 1, 1,
        5, 1, 1, 3, 7, 3, 1, 1, 5,
        1, 1, 1, 1, 1, 1, 1, 1, 1,
        9, 1, 13, 1, 9, 1, 13, 1, 9,
        9, 9, 9, 9, 9, 9, 9, 9, 9,
        9, 9, 9, 9, 9, 9, 9, 9, 9,
        9, 9, 9, 9, 9, 9, 9, 9, 9,
        9, 9, 9, 9, 9, 9, 9, 9, 9,
        9, 9, 9, 9, 9, 9, 9, 9, 9
    };
    short   Maskpiece[8] = {0, 8, 2, 4, 1, 1, 1, 2 };
    short   Knightcheck[8] = { 1, -1, -9, -9, -1, 1, 9, 9 };
    short   Elephancheck[8] = { -10, -8, 8, 10, 0, 0, 0, 0 };        




    ChessPiece(){
    }
    void init();
    
    ~ChessPiece();

};


#endif