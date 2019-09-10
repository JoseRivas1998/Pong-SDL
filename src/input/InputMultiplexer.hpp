/**
* Name: Jose de Jesus Rodriguez Rivas
* Lab: Lab 
* Date: 9/10/19
**/

#ifndef PONG_INPUTMULTIPLEXER_HPP
#define PONG_INPUTMULTIPLEXER_HPP

#include <vector>
#include "InputListener.hpp"

class InputMultiplexer {
public:
    ~InputMultiplexer();
    void addInputListener(InputListener *inputListener);
    void handleKeyboardEvent(const SDL_KeyboardEvent &keyboardEvent);
private:
    std::vector<InputListener*> inputListeners;
};


#endif //PONG_INPUTMULTIPLEXER_HPP
