#include "../headers/story/storynode.hpp"

StoryNode intro1("story/intro1.txt");
StoryNode intro2("story/intro2.txt");

void setupStory() {
    intro1.choices = { &intro2 };
    intro1.choiceTitles = { "Continue..." };
}

StoryNode* StoryNode::getRootNode() { return &intro1; }