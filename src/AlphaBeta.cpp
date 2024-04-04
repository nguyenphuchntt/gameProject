#include "../include/headers/logic.h"

short ChineseChess::AlphaBeta(short alpha, short beta, short depth){
    static short hdp;
    short value, best;
    if (!depth){
        short   piecevalue[8] = {0, 10, 25, 20, 40, 45, 90, 1000};
        short   iEval = 0;
        for (short i = 0; i < 90; i++){ // evaluate
        if (this->piece->pieceColor[i] == turn)
            iEval += piecevalue[this->piece->piecePos[i]];
        else if (this->piece->pieceColor[i] == xturn)
            iEval -= piecevalue[this->piece->piecePos[i]];
        }
        return iEval;           
    }
    this->gen();
    best = -20000;
    for (short i = gen_begin[ply]; i < gen_end[ply] && best < beta; i++){
        if (best > alpha){
            alpha = best;
        }
        // make a sample move
        short from, dest, p;
        from = arMove[i].from;
        dest = arMove[i].dest;

        MoveData[hdp].dest = arMove[i].dest;
        MoveData[hdp].from = arMove[i].from;
        MoveData[hdp].capture = this->piece->piecePos[dest];
        p = this->piece->piecePos[dest];

        this->piece->piecePos[dest] = this->piece->piecePos[from];
        this->piece->piecePos[from] = EMPTY;
        this->piece->pieceColor[dest] = this->piece->pieceColor[from];
        this->piece->pieceColor[from] = EMPTY;
        
        hdp++;
        ply++;
        this->switchTurn();
        if (p == KING){
            value = 1000 - ply;
        }else{
            value = - AlphaBeta(-beta, -alpha, depth-1);
        }
        // recover sample move

        hdp--;
        ply--;
        this->switchTurn();
        from = MoveData[hdp].from;
        dest = MoveData[hdp].dest;

        this->piece->piecePos[from] = this->piece->piecePos[dest];
        this->piece->pieceColor[from] = this->piece->pieceColor[dest];
        this->piece->piecePos[dest] = MoveData[hdp].capture;

        if (this->piece->piecePos[dest] == EMPTY){
            this->piece->pieceColor[dest] = EMPTY;
        }else{
            this->piece->pieceColor[dest] = xturn;
        }

        if (value > best){
            best = value;
            if (!ply){
                NewMove->dest = arMove[i].dest;
                NewMove->from = arMove[i].from;
            }
        }

    }
    return best;
}