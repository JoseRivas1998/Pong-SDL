//
// Created by joserivas1998 on 9/14/19.
//

#ifndef PONG_ASSETMANAGER_HPP
#define PONG_ASSETMANAGER_HPP

#include <map>
#include <SDL_mixer.h>
#include "../graphics/Font.hpp"

class AssetManager {

private:
    std::map<std::string, Font*> fonts;
    std::map<std::string, Mix_Chunk*> soundEffects;

public:
    AssetManager();
    ~AssetManager();
    void addFont(const std::string& font, const char *path, int size, const Color &color);
    Font *getFont(const std::string& font);

    void addSoundEffect(const std::string &sound, const char *path);
    void playSoundEffect(const std::string &sound);


};


#endif //PONG_ASSETMANAGER_HPP
