/**
* Name: Jose de Jesus Rodriguez Rivas
* Lab: Lab 
* Date: 9/9/19
**/

#ifndef PONG_APPLICATIONCONFIGURATION_HPP
#define PONG_APPLICATIONCONFIGURATION_HPP

#include "../graphics/Color.hpp"

typedef struct appConfig {
    const char *title;
    int xPos;
    int yPos;
    int width;
    int height;
    bool fullScreen;
    bool resizable;
    Color clearColor;
} ApplicationConfiguration;

#endif //PONG_APPLICATIONCONFIGURATION_HPP
