#include <stdio.h>
#include "SDL/SDL.h"
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include<SDL/SDL_ttf.h>
#include"partage.h"
int main() {


SDL_Surface *screen=NULL,*joueur1,*joueur2,*back1,*back2;
SDL_Rect posb1,posb2,posp1,posp2;
SDL_Rect E1,E2;
SDL_Event event;
E1.x=0;
E1.y=0;
E2.x=0;
E2.y=300;
  int game =1,directionSDL1,directionSDL2;
  back1=IMG_Load("back1.png");
  back2=IMG_Load("back2.png");
  joueur1=IMG_Load("joueur1.png");
  joueur2=IMG_Load("joueur2.png");
  SDL_Init( SDL_INIT_EVERYTHING );
  screen = SDL_SetVideoMode(1200, 600, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
initposition(&posb1,&posb2,&posp1,&posp2);
//initimage(back1,back2 ,joueur1,joueur2);
SDL_EnableKeyRepeat(SDL_DEFAULT_REPEAT_DELAY,SDL_DEFAULT_REPEAT_INTERVAL);

while (game)
{
  //input from SDL
  while(SDL_PollEvent(&event)){
        switch (event.type)
        {
        // exit if the window is closed
        case SDL_QUIT:
            game = 0;
            break;
        case SDL_KEYDOWN:
        {

            if (event.key.keysym.sym == SDLK_d)//joueur 1
              directionSDL1 = 1;

            if (event.key.keysym.sym == SDLK_q)//joueur 1
              directionSDL1 = 2;
          if (event.key.keysym.sym == SDLK_m)//joueur 2
          directionSDL2 = 1;
          if (event.key.keysym.sym == SDLK_l)//joueur 2
          directionSDL2 = 2;
        }break;
        break;
        case SDL_KEYUP:
          directionSDL1=0;
          directionSDL2=0;
        break;

      }}

scrolling (&posb1, directionSDL1,&posp1);
SDL_BlitSurface(back1,&posb1,screen,&E1);

scrolling (&posb2, directionSDL2,&posp2);
SDL_BlitSurface(back2,&posb2,screen,&E2);



SDL_BlitSurface(joueur1,NULL,screen,&posp1);
SDL_BlitSurface(joueur2,NULL,screen,&posp2);
SDL_Flip(screen);
}





SDL_FreeSurface(back1);
SDL_FreeSurface(back2);
SDL_FreeSurface(joueur1);
SDL_FreeSurface(joueur2);


}
