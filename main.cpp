#define SDL_MAIN_HANDLED
#include<iostream>
#include<stdlib.h>
#include<SDL2/SDL.h>
#include "stars.h"

using namespace std;
#define Win_Width 1000
#define Win_Height 800
#define G 6
#define Pi 3.141528


int main(){
    SDL_Init(SDL_INIT_EVERYTHING);

    SDL_Window *win = SDL_CreateWindow("Binary Star System",SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, Win_Width, Win_Height, SDL_WINDOW_RESIZABLE);
    SDL_Renderer *ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED);
    bool running = true;
    SDL_Event e1;
    struct COM{
        double x;
        double y;
        double m;
    };
    double x1 = 200, y1 = 250;
    double x2 = 625, y2 = 510;
    int m1, m2, r_1, r_2;
    m1 = 19; m2 = 38; r_1 = 20; r_2 = 40;
    Star s1(m1,r_1), s2(m2,r_2);
    COM c;
    c.x = (((m1*x1) + (m2*x2))/(m1 + m2));
    c.y = (((m1*y1) + (m2*y2))/(m1 + m2));
    double r1_x = ((x2 - x1)*m2/(m1+m2)), r1_y = (y2-y1)*m2/(m1+m2);
    double r1 = sqrt((r1_x*r1_x) + (r1_y*r1_y));

    double r2_x = (x1-x2)*m1/(m1+m2), r2_y = (y1-y2)*m1/(m1+m2);
    double r2 = sqrt((r2_x*r2_x) + (r2_y*r2_y));
    double th1 = 0, th2 = -Pi;
    while (running)
    {
        SDL_PollEvent(&e1);
        if (e1.type == SDL_QUIT)
        {
            running = false;
            break;
        }
        system("cls");
        x1 = c.x + r1*cos(th1);
        x2 = c.x + r2*cos(th2);
        y1 = c.y + r1*sin(th1);
        y2 = c.y + r2*sin(th2);
        th1 += 0.1; th2 += 0.1;
        if(th1 >= 2*Pi) th1 = 0;
        if(th2 >= Pi) th2 = -Pi;

        cout << "The coordinates of COM are : "<< c.x << " " << c.y << "\n";
        cout << "The coordinates of M1 are : "<< x1 << " "<< y1 << "\n";
        cout << "The coordinates of M2 are : "<< x2 << " " << y2 << "\n";
        SDL_SetRenderDrawColor(ren,0,0,0,255);
        SDL_RenderClear(ren);

        SDL_SetRenderDrawColor(ren,255,255,0,255);
        SDL_RenderDrawPoint(ren,c.x,c.y);
        SDL_SetRenderDrawColor(ren,255,255,0,255);
        s1.SpawnStar(ren,x1,y1);
        SDL_SetRenderDrawColor(ren,255,255,0,255);
        s2.SpawnStar(ren,x2,y2);
        SDL_RenderPresent(ren);
        
        SDL_Delay(12);
    }
    
    return 0;
}