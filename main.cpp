#include <Engine.h>
using namespace std;

bool ask(){ // choi nhieu lan
    SDL_Event e;
    bool wait =true;
    while (wait) {
        if (SDL_WaitEvent(&e) != 0)
        {   if (e.type == SDL_KEYDOWN){
                switch(e.key.keysym.sym)
                {
                    case SDLK_1:{
                        return true;
                    }
                    case SDLK_0:{
                        return false;
                    }
                }
            }
        }
    }
}

int main(int argc, char* argv[]){
    Engine Obj;
    Obj.Init();

    bool play_again = true;
    do{
        Obj.game();
        play_again = ask();
    } while (play_again);
    Obj.Quit();
    return 0;
}
