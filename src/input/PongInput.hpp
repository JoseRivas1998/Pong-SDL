/**
* Name: Jose de Jesus Rodriguez Rivas
* Lab: Lab 
* Date: 9/10/19
**/

#ifndef PONG_PONGINPUT_HPP
#define PONG_PONGINPUT_HPP

#include <array>

constexpr size_t NUM_KEYS = 4;

class PongInput {
public:
    const static int UP = 0;
    const static int DOWN = 1;
    const static int START = 2;
    const static int BACK = 3;
    static void update();
    static void setKey(int k, bool value);
    static bool keyCheck(int k);
    static bool keyCheckPressed(int k);
private:
    static std::array<bool, NUM_KEYS> keys;
    static std::array<bool, NUM_KEYS> pkeys;
};


#endif //PONG_PONGINPUT_HPP
