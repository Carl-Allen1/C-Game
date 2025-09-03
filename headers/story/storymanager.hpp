#ifndef STORY_MANAGER_H
#define STORY_MANAGER_H

#include <string>

class StoryNode;

class StoryManager {
public:
    static void printStoryFile(const std::string& filePath);
    static void deleteStoryFile(StoryNode* node);
    static void typewriterPrint(const std::string& text, int charDelayMs = 30, int lineDelayMs = 500);
};

#endif // STORY_MANAGER_H