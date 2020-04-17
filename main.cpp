#include <cstdlib>
#include <cmath>
#include <iostream>
#include <ctime>
#include <SDL.h>
#include <SDL_image.h>



using namespace std;

const int WIDTH = 320;
const int HEIGHT = 180;

int main(int argc, char *argv[])
{

    cout << boolalpha;

    SDL_Surface* imageSurface = NULL;
    SDL_Surface* windowSurface = NULL;


    //initializing and checking full SDL package
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
    {
        cout << "SDL could not initialize! SDL Error: " 
             << SDL_GetError() << endl;
    }


    //Creating blank window, then checking if it has been made
    SDL_Window *window = SDL_CreateWindow("Battle Music",
        SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH,
        HEIGHT, SDL_WINDOW_ALLOW_HIGHDPI);

    windowSurface = SDL_GetWindowSurface(window);

    if (NULL == window)
    {
        cout << "Could not create window: " << SDL_GetError() << endl;
    
        return EXIT_FAILURE;
    }


    //Initializing and checking SDL_image
    if (!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG))
    {
        cout << "Failed to initialize SDL_image for PNG files: "
            << IMG_GetError() << endl;
    }


    //Populating imageSurface
    SDL_Event windowEvent;

    imageSurface = IMG_Load("Sprites.png");

    if (imageSurface == NULL)
    {
        cout << "SDL could not load image! SDL Error: " 
             << SDL_GetError() << endl;
    }


    //Rendering imageSurface to windowSurface until window is closed
    while (true)
    {
        if (SDL_PollEvent(&windowEvent))
        {
            if (SDL_QUIT == windowEvent.type)
            {
                break;
            }
        }

        SDL_BlitSurface(imageSurface, NULL, windowSurface, NULL);

        SDL_UpdateWindowSurface(window);
    }


    //Cleaning up and closing window
    SDL_FreeSurface(imageSurface);
    SDL_FreeSurface(windowSurface);

    imageSurface = NULL;
    windowSurface = NULL;

    SDL_DestroyWindow(window);
    SDL_Quit();


    return EXIT_SUCCESS;
}
