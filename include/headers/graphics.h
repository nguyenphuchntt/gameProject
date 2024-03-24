#ifndef _GRAPHICS__H

#define _GRAPHICS__H

#include "media.h"
#include "chessPiece.h"
#include "function.h"

struct graphics{
    SDL_Window* window = NULL; 
    SDL_Renderer* renderer = NULL;
    std::vector<SDL_Texture*> gamePicture;
    std::vector<Mix_Chunk*> gameAudio;
    Mix_Music* backgrounMusic = NULL;

    graphics(){
    }

    void initSDL();
    void prepareScene();

    void loadMedia();
    void freeMedia();

    SDL_Texture* loadTexture(const char* fileName);
    Mix_Music* loadMusic(const char* path);
    Mix_Chunk* loadSound(const char* path);
    void play(Mix_Chunk* gChunk);
    void play(Mix_Music* gMusic);
    void renderTexture(SDL_Texture* texture, int x, int y);
    
    void QuitSDL();

    void renderChessPiece(int n, const ChessPiece& chessPiece);
    void displayChessPiece(const ChessPiece& chessPiece);
};

#endif