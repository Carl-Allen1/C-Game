#ifndef STORY_NODE_H
#define STORY_NODE_H

#include <string>
#include <vector>

void setupStory();

class StoryNode {
public:
    std::string storyFile;
    std::vector<StoryNode*> choices;
    std::vector<std::string> choiceTitles;

    StoryNode(const std::string& filePath) : storyFile(filePath) {}

    static StoryNode* getRootNode();
};

#endif // STORY_NODE_H