/**
* Name: Jose de Jesus Rodriguez Rivas
* Lab: Lab 
* Date: 9/9/19
**/

#ifndef PONG_LICHPP_HPP
#define PONG_LICHPP_HPP

#include <SDL.h>
#include "../graphics/Graphics.hpp"
#include "ApplicationConfiguration.hpp"

class LichPP {

public:
    static bool init(ApplicationConfiguration appConfig);
    static void destroy();

    static Graphics *graphics;

};


#endif //PONG_LICHPP_HPP
