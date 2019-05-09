#ifndef FILE_H_INCLUDED
#define FILE_H_INCLUDED

#include<stdio.h>
#include<stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>



void initposition(SDL_Rect *posb1,SDL_Rect *posb2,SDL_Rect *posp1,SDL_Rect *posp2);

//void initimage(SDL_Surface *back1,SDL_Surface *back2 ,SDL_Surface *player1,SDL_Surface *player2);

void movementplayer(int *directionSDL1,int *directionSDL2,SDL_Rect *posp1,SDL_Rect *posp2);

void scrolling (SDL_Rect *posb , int mouvement_personnage,SDL_Rect *positionpersonage );

#endif 

// FILE_H_INCLUDED
