#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <vector>

#include "RenderWindow.hpp"
#include "Entity.hpp"
#include "Utils.hpp"

int main(int argc, char* args[])
{
    if (SDL_Init(SDL_INIT_VIDEO) > 0)
        std::cout << "SDL_Init has failed. SDL_Error: " << SDL_GetError() << std::endl;

    if (!(IMG_Init(IMG_INIT_PNG)))
        std::cout << "IMG_Init has failed. Error: " << SDL_GetError() << std::endl;

    RenderWindow window("GAME v1.0", 1920, 1080);

    SDL_Texture* sandBlock = window.loadTexture("res/gfx/Desert/Sandblock.png");

    
    std::vector<Entity> entities = {Entity (Vector2f(0,0), sandBlock),
                                     Entity (Vector2f(30,0), sandBlock),
                                     Entity (Vector2f(30,30), sandBlock),
                                     Entity (Vector2f(30,60), sandBlock)};

    {
        Entity wilson(Vector2f(100, 50), sandBlock);
        entities.push_back(wilson);
    }
    bool gameRunning = true;
    SDL_Event event;

    const float deltaTime =0.01f;
    float accumulator = 0.0f;
    float currentTime = utils::hireTimeInSeconds();

    while (gameRunning)
    {

        
        // begin by locking frames to 100fps and smoothing player movement by maths
        float newTime = utils::hireTimeInSeconds();
        float frameTime = newTime - currentTime;

        
        currentTime = newTime;
        //Assigning speed to display update
        accumulator += frameTime;

        //
        while (accumulator >= deltaTime)
        {
            while (SDL_PollEvent(&event))
                {
                    if (event.type == SDL_QUIT)
                    gameRunning = false;
                }

            //removing unneeded waste 
            accumulator -= deltaTime;
        }
        //time leftover in accumulator as a percentage.
        const float alpha = accumulator / deltaTime; 
        

        window.clear();

        for (Entity& e : entities)
            {
                window.render(e);
            }

        window.display();

        
    } 
    window.cleanUp();
    SDL_Quit();

    return 0;
}
