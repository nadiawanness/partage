#include <stdio.h>
#include "SDL/SDL.h"
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include<SDL/SDL_ttf.h>
#include"partage.h"

void initposition(SDL_Rect *posb1,SDL_Rect *posb2,SDL_Rect *posp1,SDL_Rect *posp2)
{ posb1->x=0;
  posb1->y=0;
  posb1->h=300;
  posb1->w=1200;



posp1->x=20;
posp1->y=100;

posp2->x=20;
posp2->y=400;

posb2->x=0;
posb2->y=0;
posb2->h=300;
posb2->w=1200;
}



void movementjoueur(int *directionSDL1,int *directionSDL2,SDL_Rect *posp1,SDL_Rect *posp2)
{
if(*directionSDL1==1)
posp1->x+=10;
if(*directionSDL1==2)
posp1->x-=10;
if(*directionSDL2==1)
posp2->x+=10;
if(*directionSDL2==2)
posp2->x-=10;

if (posp1->x>1100)
posp1->x-=10;
if (posp2->x>1100)
posp2->x-=10;
}
void scrolling (SDL_Rect *posb , int mouvement_personnage,SDL_Rect *positionpersonage )
{

	switch(mouvement_personnage)
	{

		case 1:
			if ((posb->x<5800)&&(positionpersonage->x>=300))
                		posb->x=posb->x+50;
			if (((positionpersonage->x<300)||((posb->x>=5800))&&(positionpersonage->x<800)))
				positionpersonage->x=positionpersonage->x+50;
	
		break;
		case 2:
			if (posb->x>0)
                		posb->x=posb->x-50;
	    		if (((posb->x!=0)&&(positionpersonage->x>=150))||((posb->x==0)&&(positionpersonage->x>=50)))
				positionpersonage->x=positionpersonage->x-50;
		break;

	}

}
