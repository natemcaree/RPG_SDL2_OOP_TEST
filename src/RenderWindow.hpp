#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include "Entity.hpp"

class RenderWindow
{
    public:
        RenderWindow(const char* p_title, int p_w, int p_h);
        SDL_Texture* loadTexture(const char* p_filePath);
        void clear();
        void render(Entity& p_entity);
        void display();
        void cleanUp();
    private:
        SDL_Window* window;
        SDL_Renderer* renderer;
};