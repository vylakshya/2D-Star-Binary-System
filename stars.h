#include<SDL2/SDL.h>


class Star{
    protected:

    double mass, radius;

    public:
    Star(double m, double r) : mass(m), radius(r) {};
    void SpawnStar(SDL_Renderer *ren, int x0, int y0){

        for (int i = x0 - radius; i < x0 + radius ; i++)
            for (int j = y0 - radius; j < y0 + radius; j++)
            {
                double dist = ((i - x0)*(i - x0)) + ((j - y0)*(j - y0));
                if (dist <= (radius * radius))
                    SDL_RenderDrawPoint(ren,i,j);
            }   
    }

    void Revolve(SDL_Renderer *ren, int x_c, int y_c, int x_o, int y_o, double r){
        


    }
};
