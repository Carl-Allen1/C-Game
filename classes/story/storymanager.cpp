#include "../headers/story/storymanager.hpp"
#include "../headers/story/storynode.hpp"
#include <fstream>
#include <sstream>
#include <iostream>
#include <thread>
#include <chrono>
#include <vector>
#include <cctype>
#include <string>

void StoryManager::typewriterPrint(const std::string& text, int charDelayMs, int lineDelayMs) {
    for(int i = 0; i < static_cast<int>(text.size()); ) {
        if(text[i] == '^' && i + 1 < static_cast<int>(text.size())) {
            std::string esc = "\x1b[";

            i++;

            while(i < static_cast<int>(text.size()) && text[i] != 'm') { esc += text[i++]; }
            if(i < static_cast<int>(text.size())) { esc += text[i++]; }

            std::cout << esc;
        } else if(text[i] == '%' && i + 1 < static_cast<int>(text.size())) {
            std::string time = "";

            i++;

            while(i < static_cast<int>(text.size()) && isdigit(text[i])) { time += text[i++]; }

            switch(text[i]) {
                case 's': std::this_thread::sleep_for(std::chrono::seconds(std::stoi(time))); break;
                case 'm': std::this_thread::sleep_for(std::chrono::milliseconds(std::stoi(time))); break;
                case 'c': std::this_thread::sleep_for(std::chrono::microseconds(std::stoi(time))); break;
                case 'n': std::this_thread::sleep_for(std::chrono::nanoseconds(std::stoi(time))); break;
            }

            if(i < static_cast<int>(text.size())) std::cout << text[++i] << std::flush;

            i++;
        } else {
            std::cout << text[i++] << std::flush;
            std::this_thread::sleep_for(std::chrono::milliseconds(charDelayMs));
        }
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

void StoryManager::deleteStoryFile(StoryNode* node) {
    std::string filePath = node->storyFile;
    
    std::ifstream file(filePath);

    if(!file.is_open()) {
        std::cout << "Failed to open story file: " << filePath << std::endl;
        return;
    }

    std::vector<std::string> lines;
    std::string line;

    while(std::getline(file, line)) {
        lines.push_back(line);
    }

    for(int i = 0; i < static_cast<int>(node->choiceTitles.size()); i++) {
        lines.push_back(node->choiceTitles[i]);
    }

    lines.push_back("Enter choice: ");
    lines.push_back("p");

    int lIndex = static_cast<int>(lines.size());

    for(int i = lIndex - 1; i >= 0; --i) {
        std::cout << "\x1b[F";
        
        for(int j = 0; j < static_cast<int>(lines[i].length()); j++) {
            std::cout << "\x1b[C";
        }

        for(int j = 0; j < static_cast<int>(lines[i].length()); j++) {
            std::cout << "\b \b";
            std::this_thread::sleep_for(std::chrono::milliseconds(1));
        }

        std::this_thread::sleep_for(std::chrono::milliseconds(1));
    }

    file.close();
}