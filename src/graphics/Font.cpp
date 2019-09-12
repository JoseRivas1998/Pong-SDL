/**
* Name: Jose de Jesus Rodriguez Rivas
* Lab: Lab 
* Date: 9/12/19
**/

#include "Font.hpp"
#include "../app/LichPP.hpp"

Font::Font(const char *path, int size) {
    this->font = TTF_OpenFont(path, size);
}

Font::~Font() {
    TTF_CloseFont(font);
}

int Font::getWidth(SDL_Renderer *renderer, const char *str) {
    SDL_Texture *texture = renderText(renderer, str);
    int width = getWidth(texture);
    SDL_DestroyTexture(texture);
    return width;
}

int Font::getWidth(SDL_Renderer *renderer, const std::string &str) {
    return getWidth(renderer, &str[0]);
}

int Font::getHeight(SDL_Renderer *renderer, const char *str) {
    SDL_Texture *texture = renderText(renderer, str);
    int height = getHeight(texture);
    SDL_DestroyTexture(texture);
    return height;
}

int Font::getHeight(SDL_Renderer *renderer, const std::string &str) {
    return getHeight(renderer, &str[0]);
}

void Font::draw(SDL_Renderer *renderer, const char *str, float x, float y) {
    SDL_Texture *texture = renderText(renderer, str);
    SDL_Rect rect;
    rect.x = (int) x;
    rect.y = (int) y;
    rect.w = Font::getWidth(texture);
    rect.h = Font::getHeight(texture);
    SDL_RenderCopy(renderer, texture, nullptr, &rect);
    SDL_DestroyTexture(texture);
}

void Font::draw(SDL_Renderer *renderer, const std::string &str, float x, float y) {
    this->draw(renderer, &str[0], x, y);
}

void Font::setColor(Uint32 rgba8888) {
    this->color.set(Color(rgba8888));
}

void Font::setColor(const Color &c) {
    this->color.set(c);
}

void Font::setColor(int r, int g, int b, int a) {
    this->color.set(r, g, b, a);
}

int Font::getWidth(SDL_Texture *texture) {
    int width = 0;
    SDL_QueryTexture(texture, nullptr, nullptr, &width, nullptr);
    return width;
}

int Font::getHeight(SDL_Texture *texture) {
    int height = 0;
    SDL_QueryTexture(texture, nullptr, nullptr, nullptr, &height);
    return height;
}

SDL_Texture *Font::renderText(SDL_Renderer *renderer, const char *str) {
    SDL_Color c = this->color.toSDLColor();
    SDL_Surface *surface = TTF_RenderText_Blended(this->font, str, c);
    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);
    return texture;
}
