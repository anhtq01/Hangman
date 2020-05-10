#ifndef ENGINE_H
#define ENGINE_H

#include <UnknownWord.h>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <SDL_ttf.h>
using namespace std;

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;



class Engine
{
    public:
        Engine();
        virtual ~Engine();
        bool Init();
        void draw_text(const char* msg, SDL_Rect rect, SDL_Renderer* ren);
        void draw_image(const char* filename);
        void music(const char* mp3);
        void effect();
        void waitUntilKeyPressed(string word, string &mystery_word, bool &correct_guess, SDL_Rect mystery_rect, SDL_Renderer* ren);
        void game();
        void Quit();

    protected:

    private:
};

#endif // ENGINE_H
