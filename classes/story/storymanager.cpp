#include "../headers/story/storymanager.hpp"
#include <fstream>
#include <iostream>
#include <thread>
#include <chrono>

void StoryManager::typewriterPrint(const std::string& text, int charDelayMs = 30, int lineDelayMs = 500) {
    for(char c : text) {
        std::cout << c << std::flush;
        std::this_thread::sleep_for(std::chrono::milliseconds(charDelayMs));
    }

    std::cout << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(lineDelayMs));
}

void StoryManager::printStoryFile(const std::string& filePath) {
    std::ifstream file(filePath);

    if(!file.is_open()) {
        std::cout << "Failed to open story file: " << filePath << std::endl;
        return;
    }

    std::string line;
    while(std::getline(file, line)) {
        typewriterPrint(line);
    }

    file.close();
}