#include "Window.h"
#include <gl/glew.h>
#include <stdio.h>
 /*Vytvori okno so zadanov sirkov a vyskov*/
Window::Window(int width,int height,bool doubleBuffering) {
    this->doubleBuffering=doubleBuffering;
    (doubleBuffering)?
        SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER,1):
            SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER,0);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 2);
    /*Vytvory okno ktore bude centrovane*/
    window = SDL_CreateWindow("Majncraft", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_OPENGL);
    /*Vytvori obsah zariadenia do ktoreho sa bude dat zapisovat*/
    context = SDL_GL_CreateContext(window);
    
    glewExperimental = GL_TRUE;
    glewInit();

    // Init GLEW
    glewExperimental = GL_TRUE;
    if (glewInit() != GLEW_OK) {
        fprintf(stderr, "Failed to initialize GLEW\n");
        return;
    }
    /*Kontroluje ci dany pixel je pred inym(ci ho ma vykreslit)*/
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);
    glEnable(GL_LINE_SMOOTH);
}

/*Vymeni aktualny snimok za novy*/
void Window::Update(){
    SDL_GL_SwapWindow(window);
}

Window::~Window() {
    SDL_GL_DeleteContext(context);
    SDL_DestroyWindow(window);
}
