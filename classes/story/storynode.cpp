#include "../headers/story/storynode.hpp"

StoryNode intro1("story/intro1.txt");

void setupStory() {
    
}

StoryNode* StoryNode::getRootNode() { return &intro1; }