#ifndef STORY_MANAGER_H
#define STORY_MANAGER_H

#include <string>

class StoryManager {
public:
    static void printStoryFile(const std::string& filePath);
    static void typewriterPrint(const std::string& text, int charDelayMs, int lineDelayMs);
};

#endif // STORY_MANAGER_H