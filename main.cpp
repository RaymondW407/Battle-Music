#include <cstdlib>
#include <cmath>
#include <iostream>
#include <ctime>
#include <SDL.h>
#include <SDL_image.h>



using namespace std;

 int WIDTH = 320;
 int HEIGHT = 192;
 int fW = 32, fH = 32;
 int tW = (WIDTH / 10), tH = (HEIGHT / 6);







//16 by 16 chunks, 6 colums 6 rows
SDL_Rect assetChunk[36];

void pullAssetChunks()
{
    for (int i = 0; i < 36; i++)
    {
        assetChunk[i].x = ((i % 6) * 32);
        assetChunk[i].y = ((i / 6) * 32);
        assetChunk[i].w = fW;
        assetChunk[i].h = fH;
    }
    return;
}

//32 by 32 chunks, 10 colums 6 rows
SDL_Rect  DrawToBackground[60];

void populate_DrawToBackground()
{
    for (int i = 0; i < 60; ++i)
    {
        DrawToBackground[i].x = ((i % 10) * tW);
        DrawToBackground[i].y = ((i / 10) * tH);
        DrawToBackground[i].w = tW;
        DrawToBackground[i].h = tH;
    }
    return;
}



SDL_Rect* check_click_in_rect(int x, int y, struct SDL_Rect* rect)
{
    /* Check X coordinate is within rectangle range */
    if (x >= rect->x && x < (rect->x + rect->w))
    {
        /* Check Y coordinate is within rectangle range */
        if (y >= rect->y && y < (rect->y + rect->h))
        {
            /* X and Y is inside the rectangle */
            cout << rect << endl;
            return rect;
        }
    }

    /* X or Y is outside the rectangle */
    return nullptr;
}



SDL_Rect interactable[] = { DrawToBackground[21], DrawToBackground[22], DrawToBackground[23], DrawToBackground[31], DrawToBackground[32]
                          , DrawToBackground[33], DrawToBackground[41], DrawToBackground[42], DrawToBackground[43] };






int main(int argc, char *argv[])
{

    cout << boolalpha;

    pullAssetChunks();
    populate_DrawToBackground();


    SDL_Rect Map1[60] =
    {assetChunk[13],assetChunk[13],assetChunk[13],assetChunk[13],assetChunk[13],assetChunk[13],assetChunk[13],assetChunk[13],assetChunk[13],assetChunk[13]
    ,assetChunk[14],assetChunk[14],assetChunk[14],assetChunk[14],assetChunk[14],assetChunk[14],assetChunk[14],assetChunk[14],assetChunk[14],assetChunk[14]
    ,assetChunk[0 ],assetChunk[18],assetChunk[19],assetChunk[20],assetChunk[0 ],assetChunk[6 ],assetChunk[21],assetChunk[22],assetChunk[23],assetChunk[0 ]
    ,assetChunk[6 ],assetChunk[24],assetChunk[25],assetChunk[26],assetChunk[6 ],assetChunk[0 ],assetChunk[27],assetChunk[28],assetChunk[29],assetChunk[6 ]
    ,assetChunk[6 ],assetChunk[30],assetChunk[31],assetChunk[32],assetChunk[12],assetChunk[12],assetChunk[33],assetChunk[34],assetChunk[35],assetChunk[0 ]
    ,assetChunk[12],assetChunk[12],assetChunk[0 ],assetChunk[6 ],assetChunk[0 ],assetChunk[12],assetChunk[12],assetChunk[0 ],assetChunk[0 ],assetChunk[12]
    };


    SDL_Surface* spriteAsset = NULL;
    SDL_Surface* baseSurface = NULL;
    SDL_Surface* actionSurface = NULL;
    SDL_Surface* playerCamera = NULL;
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


    SDL_Event windowEvent;

    //Pulling Assets
    spriteAsset = IMG_Load("Sprites.png");

    if (spriteAsset == NULL)
    {
        cout << "SDL could not load image! SDL Error: " 
             << SDL_GetError() << endl;
    }

    //Creating Background
    baseSurface = SDL_CreateRGBSurface(SDL_SWSURFACE, WIDTH, HEIGHT, 32, 0, 0, 0, 0);

    if (baseSurface == NULL)
    {
        cout << "SDL could not load image! SDL Error: "
            << SDL_GetError() << endl;
    }

    //Creating Background
    actionSurface = SDL_CreateRGBSurface(SDL_SWSURFACE, WIDTH, HEIGHT, 32, 0, 0, 0, 0);

    if (actionSurface == NULL)
    {
        cout << "SDL could not load image! SDL Error: "
            << SDL_GetError() << endl;
    }


    //Rendering imageSurface to windowSurface until window is closed
    //Handling events
    while (true)
    {
        SDL_Rect MouseTile;
        int x = NULL, y = NULL;
        SDL_SetSurfaceAlphaMod(actionSurface, NULL);
        if (SDL_PollEvent(&windowEvent))
        {
            
            if (SDL_QUIT == windowEvent.type)
            {
                break;
            }
            if (SDL_BUTTON_LEFT == windowEvent.button.button)
            {
                SDL_GetMouseState(&x, &y);
                //cout << y << endl;
                //cout << x << endl;
                MouseTile.x = (x - 16);
                MouseTile.y = (y - 16);
                MouseTile.w = 32;
                MouseTile.h = 32;
                
            }
            
        }

        for (int i = 0; i < 60; ++i)
        {
            SDL_BlitSurface(spriteAsset, &Map1[i], baseSurface, &DrawToBackground[i]);
            //SDL_BlitSurface(spriteAsset, &assetChunk[4], baseSurface, &DrawToBackground[21]);
            //SDL_BlitSurface(actionSurface, NULL, baseSurface, NULL);
            //SDL_BlitSurface(spriteAsset, &assetChunk[4], baseSurface, &MouseTile);
            if(check_click_in_rect != nullptr)
            {
                SDL_BlitSurface(spriteAsset, &assetChunk[4], baseSurface, check_click_in_rect(x, y, &DrawToBackground[21]));
                SDL_BlitSurface(spriteAsset, &assetChunk[4], baseSurface, check_click_in_rect(x, y, &DrawToBackground[22]));
                SDL_BlitSurface(spriteAsset, &assetChunk[4], baseSurface, check_click_in_rect(x, y, &DrawToBackground[23]));
                SDL_BlitSurface(spriteAsset, &assetChunk[4], baseSurface, check_click_in_rect(x, y, &DrawToBackground[31]));
                SDL_BlitSurface(spriteAsset, &assetChunk[4], baseSurface, check_click_in_rect(x, y, &DrawToBackground[32]));
                SDL_BlitSurface(spriteAsset, &assetChunk[4], baseSurface, check_click_in_rect(x, y, &DrawToBackground[33]));
                SDL_BlitSurface(spriteAsset, &assetChunk[4], baseSurface, check_click_in_rect(x, y, &DrawToBackground[41]));
                SDL_BlitSurface(spriteAsset, &assetChunk[4], baseSurface, check_click_in_rect(x, y, &DrawToBackground[42]));
                SDL_BlitSurface(spriteAsset, &assetChunk[4], baseSurface, check_click_in_rect(x, y, &DrawToBackground[43]));
            }
            //SDL_BlitSurface(actionSurface, NULL, baseSurface, NULL);
            SDL_BlitSurface(baseSurface, NULL, windowSurface, NULL);
            //SDL_BlitSurface(actionSurface, NULL, baseSurface, NULL);

        }
       

        //SDL_BlitSurface(imageSurface, &DrawFrom[4], windowSurface, &DrawTo[23]);

        

        SDL_UpdateWindowSurface(window);
    }


    //Cleaning up and closing window
    SDL_FreeSurface(spriteAsset);
    SDL_FreeSurface(windowSurface);
    SDL_FreeSurface(baseSurface);
    SDL_FreeSurface(playerCamera);
    SDL_FreeSurface(actionSurface);


    actionSurface = NULL;
    spriteAsset = NULL;
    windowSurface = NULL;
    baseSurface = NULL;
    playerCamera = NULL;

    SDL_DestroyWindow(window);
    SDL_Quit();


    return EXIT_SUCCESS;
}
