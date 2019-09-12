/**
* Name: Jose de Jesus Rodriguez Rivas
* Lab: Lab 
* Date: 9/12/19
**/

#ifndef PONG_FONT_HPP
#define PONG_FONT_HPP

#include <SDL_ttf.h>
#include <string>
#include "Color.hpp"

class Font {
public:
    Font(const char *path, int size);
    ~Font();
    int getWidth(SDL_Renderer *renderer, const char *str);
    int getWidth(SDL_Renderer *renderer, const std::string &str);
    int getHeight(SDL_Renderer *renderer, const char *str);
    int getHeight(SDL_Renderer *renderer, const std::string &str);
    void draw(SDL_Renderer *renderer, const char *str, float x, float y);
    void draw(SDL_Renderer *renderer, const std::string &str, float x, float y);
    void setColor(Uint32 rgba8888);
    void setColor(const Color &c);
    void setColor(int r, int g, int b, int a);
private:
    TTF_Font *font;
    Color color;
    static int getWidth(SDL_Texture *texture);
    static int getHeight(SDL_Texture *texture);
    SDL_Texture *renderText(SDL_Renderer *renderer, const char *str);
};


#endif //PONG_FONT_HPP
