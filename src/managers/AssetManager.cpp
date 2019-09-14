//
// Created by joserivas1998 on 9/14/19.
//

#include <iostream>
#include "AssetManager.hpp"

AssetManager::AssetManager() = default;

AssetManager::~AssetManager() {
    for (auto &font : fonts) {
        delete font.second;
    }
    fonts.clear();
    for (auto &sound : soundEffects) {
        Mix_FreeChunk(sound.second);
    }
    soundEffects.clear();
}

Font *AssetManager::getFont(const std::string &font) {
    return fonts[font];
}

void AssetManager::addFont(const std::string &font, const char *path, int size, const Color &color) {
    fonts[font] = new Font(path, size);
    fonts[font]->setColor(color);
}

void AssetManager::addSoundEffect(const std::string &sound, const char *path) {

    soundEffects[sound] = Mix_LoadWAV(path);
    if (soundEffects[sound] == nullptr) {
        std::cout << "Error opening " << sound << " at path" << path << " : " << Mix_GetError() << std::endl;
    }
}


void AssetManager::playSoundEffect(const std::string &sound) {
    if(Mix_PlayChannel(-1, soundEffects[sound], 0) == -1) {
        std::cout << "Error playing " << sound << ": " << Mix_GetError() << std::endl;
    }
}
