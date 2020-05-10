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

SDL_Window* window = nullptr;
SDL_Renderer* renderer = nullptr;

class Engine
{
    public:
        Engine() {}
        virtual ~Engine() {}
        bool Init(){
            if(SDL_Init(SDL_INIT_EVERYTHING) != 0){
                cout << " failed to initialized SDL " << SDL_GetError() << endl;
                return -1;
            }
            window = SDL_CreateWindow(" A VERY NEW GAME ", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, 0);
            if(window == nullptr){
                cout << " failed to create window " << SDL_GetError() << endl;
                return -1;
            }
            renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
            if(renderer == nullptr){
                cout << "failed to create renderer " << SDL_GetError() << endl;
                return -1;
            }
            if(TTF_Init() != 0){
                cout << "failed to initialized TTF " << SDL_GetError() << endl;
                return -1;
            }
            if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) != 0){
                cout << " failed to load music " << endl;
                return -1;
            }
            return true;
        }

        void draw_text(const char* msg, SDL_Rect rect, SDL_Renderer* ren){
            TTF_Font* font = TTF_OpenFont("pictures/JOKERMAN.ttf", 50);

            SDL_Color color = {255, 0, 255, 255};
            SDL_Surface* sur = TTF_RenderText_Solid(font, msg, color);
            SDL_Texture* tex = SDL_CreateTextureFromSurface(ren, sur);

            SDL_RenderCopy(ren, tex, NULL, &rect);
            SDL_FreeSurface(sur);
            SDL_DestroyTexture(tex);
        }

        void draw_image(const char* filename){
            SDL_Surface* surface = IMG_Load(filename);
            SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
            SDL_FreeSurface(surface);
            SDL_RenderClear(renderer);
            SDL_RenderCopy(renderer, texture, NULL, NULL);
            SDL_DestroyTexture(texture);
            SDL_RenderPresent(renderer);
        }

        void music(const char* mp3){
            Mix_Music* music = nullptr;
            music = Mix_LoadMUS(mp3);
            Mix_PlayMusic(music, -1);
        }

        void effect(){
            Mix_Chunk* chunk = nullptr;
            chunk = Mix_LoadWAV("pictures/OMG.wav");
            Mix_PlayChannel(-1, chunk, 0);
        }

        void waitUntilKeyPressed(string word, string &mystery_word, bool &correct_guess, SDL_Rect mystery_rect, SDL_Renderer* ren){
            SDL_Event e;
            bool wait =true;
            while (wait) {
                if (SDL_WaitEvent(&e) != 0){
                        if (e.type == SDL_KEYDOWN){
                            switch(e.key.keysym.sym)
                                {
                                    case SDLK_a:{
                                        for(int i = 0; i< word.length(); i++){
                                            if(word[i] == 'a'){
                                                mystery_word[i] = 'a';
                                                draw_text(mystery_word.c_str(),mystery_rect,ren);
                                                correct_guess = true;
                                            }
                                        }
                                        wait = false; break;
                                    }
                                    case SDLK_b:{
                                        for(int i = 0; i< word.length(); i++){
                                            if(word[i] == 'b'){
                                                mystery_word[i] = 'b';
                                                draw_text(mystery_word.c_str(),mystery_rect,ren);
                                                correct_guess = true;
                                            }
                                        }
                                        wait = false; break;
                                    }
                                    case SDLK_c:{
                                        for(int i = 0; i< word.length(); i++){
                                            if(word[i] == 'c'){
                                                mystery_word[i] = 'c';
                                                draw_text(mystery_word.c_str(),mystery_rect,ren);
                                                correct_guess = true;
                                            }
                                        }
                                        wait = false; break;
                                    }
                                    case SDLK_d:{
                                        for(int i = 0; i< word.length(); i++){
                                            if(word[i] == 'd'){
                                                mystery_word[i] = 'd';
                                                draw_text(mystery_word.c_str(),mystery_rect,ren);
                                                correct_guess = true;
                                            }
                                        }
                                        wait = false; break;
                                    }
                                    case SDLK_e:{
                                        for(int i = 0; i< word.length(); i++){
                                            if(word[i] == 'e'){
                                                mystery_word[i] = 'e';
                                                draw_text(mystery_word.c_str(),mystery_rect,ren);
                                                correct_guess = true;
                                            }
                                        }
                                        wait = false; break;
                                    }
                                    case SDLK_f:{
                                        for(int i = 0; i< word.length(); i++){
                                            if(word[i] == 'f'){
                                                mystery_word[i] = 'f';
                                                draw_text(mystery_word.c_str(),mystery_rect,ren);
                                                correct_guess = true;
                                            }
                                        }
                                        wait = false; break;
                                    }
                                    case SDLK_g:{
                                        for(int i = 0; i< word.length(); i++){
                                            if(word[i] == 'g'){
                                                mystery_word[i] = 'g';
                                                draw_text(mystery_word.c_str(),mystery_rect,ren);
                                                correct_guess = true;
                                            }
                                        }
                                        wait = false; break;
                                    }
                                    case SDLK_h:{
                                        for(int i = 0; i< word.length(); i++){
                                            if(word[i] == 'h'){
                                                mystery_word[i] = 'h';
                                                draw_text(mystery_word.c_str(),mystery_rect,ren);
                                                correct_guess = true;
                                            }
                                        }
                                        wait = false; break;
                                    }
                                    case SDLK_i:{
                                        for(int i = 0; i< word.length(); i++){
                                            if(word[i] == 'i'){
                                                mystery_word[i] = 'i';
                                                draw_text(mystery_word.c_str(),mystery_rect,ren);
                                                correct_guess = true;
                                            }
                                        }
                                        wait = false; break;
                                    }
                                    case SDLK_j:{
                                        for(int i = 0; i< word.length(); i++){
                                            if(word[i] == 'j'){
                                                mystery_word[i] = 'j';
                                                draw_text(mystery_word.c_str(),mystery_rect,ren);
                                                correct_guess = true;
                                            }
                                        }
                                        wait = false; break;
                                    }
                                    case SDLK_k:{
                                        for(int i = 0; i< word.length(); i++){
                                            if(word[i] == 'k'){
                                                mystery_word[i] = 'k';
                                                draw_text(mystery_word.c_str(),mystery_rect,ren);
                                                correct_guess = true;
                                            }
                                        }
                                        wait = false; break;
                                    }
                                    case SDLK_l:{
                                        for(int i = 0; i< word.length(); i++){
                                            if(word[i] == 'l'){
                                                mystery_word[i] = 'l';
                                                draw_text(mystery_word.c_str(),mystery_rect,ren);
                                                correct_guess = true;
                                            }
                                        }
                                        wait = false; break;
                                    }
                                    case SDLK_m:{
                                        for(int i = 0; i< word.length(); i++){
                                            if(word[i] == 'm'){
                                                mystery_word[i] = 'm';
                                                draw_text(mystery_word.c_str(),mystery_rect,ren);
                                                correct_guess = true;
                                            }
                                        }
                                        wait = false; break;
                                    }
                                    case SDLK_n:{
                                        for(int i = 0; i< word.length(); i++){
                                            if(word[i] == 'n'){
                                            mystery_word[i] = 'n';
                                            draw_text(mystery_word.c_str(),mystery_rect,ren);
                                            correct_guess = true;
                                            }
                                        }
                                        wait = false; break;
                                    }
                                    case SDLK_o:{
                                        for(int i = 0; i< word.length(); i++){
                                            if(word[i] == 'o'){
                                                mystery_word[i] = 'o';
                                                draw_text(mystery_word.c_str(),mystery_rect,ren);
                                                correct_guess = true;
                                            }
                                        }
                                        wait = false; break;
                                    }
                                    case SDLK_p:{
                                        for(int i = 0; i< word.length(); i++){
                                            if(word[i] == 'p'){
                                                mystery_word[i] = 'p';
                                                draw_text(mystery_word.c_str(),mystery_rect,ren);
                                                correct_guess = true;
                                            }
                                        }
                                        wait = false; break;
                                    }
                                    case SDLK_q:{
                                        for(int i = 0; i< word.length(); i++){
                                            if(word[i] == 'q'){
                                                mystery_word[i] = 'q';
                                                draw_text(mystery_word.c_str(),mystery_rect,ren);
                                                correct_guess = true;
                                            }
                                        }
                                        wait = false; break;
                                    }
                                    case SDLK_r:{
                                        for(int i = 0; i< word.length(); i++){
                                            if(word[i] == 'r'){
                                                mystery_word[i] = 'r';
                                                draw_text(mystery_word.c_str(),mystery_rect,ren);
                                                correct_guess = true;
                                            }
                                        }
                                        wait = false; break;
                                    }
                                    case SDLK_s:{
                                        for(int i = 0; i< word.length(); i++){
                                            if(word[i] == 's'){
                                                mystery_word[i] = 's';
                                                draw_text(mystery_word.c_str(),mystery_rect,ren);
                                                correct_guess = true;
                                            }
                                        }
                                        wait = false; break;
                                    }
                                    case SDLK_t:{
                                        for(int i = 0; i< word.length(); i++){
                                            if(word[i] == 't'){
                                                mystery_word[i] = 't';
                                                draw_text(mystery_word.c_str(),mystery_rect,ren);
                                                correct_guess = true;
                                            }
                                        }
                                        wait = false; break;
                                    }
                                    case SDLK_u:{
                                        for(int i = 0; i< word.length(); i++){
                                            if(word[i] == 'u'){
                                                mystery_word[i] = 'u';
                                                draw_text(mystery_word.c_str(),mystery_rect,ren);
                                                correct_guess = true;
                                            }
                                        }
                                        wait = false; break;
                                    }
                                    case SDLK_v:{
                                        for(int i = 0; i< word.length(); i++){
                                            if(word[i] == 'v'){
                                                mystery_word[i] = 'v';
                                                draw_text(mystery_word.c_str(),mystery_rect,ren);
                                                correct_guess = true;
                                            }
                                        }
                                        wait = false; break;
                                    }
                                    case SDLK_w:{
                                        for(int i = 0; i< word.length(); i++){
                                            if(word[i] == 'w'){
                                                mystery_word[i] = 'w';
                                                draw_text(mystery_word.c_str(),mystery_rect,ren);
                                                correct_guess = true;
                                            }
                                        }
                                        wait = false; break;
                                    }
                                    case SDLK_x:{
                                        for(int i = 0; i< word.length(); i++){
                                            if(word[i] == 'x'){
                                                mystery_word[i] = 'x';
                                                draw_text(mystery_word.c_str(),mystery_rect,ren);
                                                correct_guess = true;
                                            }
                                        }
                                        wait = false; break;
                                    }
                                    case SDLK_y:{
                                        for(int i = 0; i< word.length(); i++){
                                            if(word[i] == 'y'){
                                                mystery_word[i] = 'y';
                                                draw_text(mystery_word.c_str(),mystery_rect,ren);
                                                correct_guess = true;
                                            }
                                        }
                                        wait = false; break;
                                    }
                                    case SDLK_z:{
                                        for(int i = 0; i< word.length(); i++){
                                            if(word[i] == 'z'){
                                                mystery_word[i] = 'z';
                                                draw_text(mystery_word.c_str(),mystery_rect,ren);
                                                correct_guess = true;
                                            }
                                        }
                                        wait = false; break;
                                    }
                                }
                            }
                        }
                    }
                }

        void game(){
            int tries = 8;
            bool correct_guess = false;
            bool isRunning = true;

            UnknownWord obj;
            string word = obj.m_word ;
            string mystery_word(word.length(), '*');

            SDL_Rect rule_rect = {50, 300, 700, 60};
            SDL_Rect mystery_rect = {500,100,100,60};
            SDL_Rect tries_rect = {740, 20, 60, 60};

            draw_image("pictures/background.png");
            draw_text("press any key to start, press 1 to play again, 0 to quit play again", rule_rect, renderer);

            while(isRunning){
                music("pictures/megalovania.mp3");
                correct_guess = false;
                draw_text(mystery_word.c_str(), mystery_rect, renderer);
                SDL_RenderPresent(renderer);
                waitUntilKeyPressed(word, mystery_word, correct_guess, mystery_rect, renderer);

                if(word == mystery_word){
                    draw_image("pictures/passed.png");
                    music("pictures/congratulation.mp3");
                    SDL_Delay(3000);
                    break;
                }
                if(correct_guess == false){
                    tries--;
                }
                switch(tries)
                {
                    case 7:{
                        draw_image("pictures/hang.png");
                        draw_text("6", tries_rect, renderer);
                        effect();
                        break;
                    }
                    case 6:{
                        draw_image("pictures/hang_head.png");
                        draw_text("5", tries_rect, renderer);
                        effect();
                        break;
                    }
                    case 5:{
                        draw_image("pictures/hang_body.png");
                        draw_text("4", tries_rect, renderer);
                        effect();
                        break;
                    }
                    case 4:{
                        draw_image("pictures/hang_leftarm.png");
                        draw_text("3", tries_rect, renderer);
                        effect();
                        break;
                    }
                    case 3:{
                        draw_image("pictures/hang_rightarm.png");
                        draw_text("2", tries_rect, renderer);
                        effect();
                        break;
                    }
                    case 2:{
                        draw_image("pictures/hang_leftleg.png");
                        draw_text("1", tries_rect, renderer);
                        effect();
                        break;
                    }
                    case 1:{
                        draw_image("pictures/hang_rightleg.png");
                        draw_text("0", tries_rect, renderer);
                        effect();
                        tries = 0;
                        break;
                    }
                }
                if(tries == 0){
                    draw_image("pictures/wasted.png");
                    music("pictures/Coffin_Dance.mp3");
                    isRunning = false;
            }
        }
    }
    void Quit(){
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        Mix_Quit();
        TTF_Quit();
        IMG_Quit();
        SDL_Quit();
    }
    protected:

    private:
};

#endif // ENGINE_H
