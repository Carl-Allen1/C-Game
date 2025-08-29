#ifndef COLORS_H
#define COLORS_H

#include <string>
#include <map>

class Color {
public:
    enum class Colors {
        Reset,
        Black,
        Red,
        Green,
        Yellow,
        Blue,
        Magenta,
        Cyan,
        White,
        Default,
        BrightBlack,
        BrightRed,
        BrightGreen,
        BrightYellow,
        BrightBlue,
        BrightMagenta,
        BrightCyan,
        BrightWhite
    };
    
    inline static std::map<Color::Colors, std::string> colorCodes = {
        {Color::Colors::Reset, "\x1b[0m"},
        {Color::Colors::Black, "\x1b[30m"},
        {Color::Colors::Red, "\x1b[31m"},
        {Color::Colors::Green, "\x1b[32m"},
        {Color::Colors::Yellow, "\x1b[33m"},
        {Color::Colors::Blue, "\x1b[34m"},
        {Color::Colors::Magenta, "\x1b[35m"},
        {Color::Colors::Cyan, "\x1b[36m"},
        {Color::Colors::White, "\x1b[37m"},
        {Color::Colors::Default, "\x1b[39m"},
        {Color::Colors::BrightBlack, "\x1b[90m"},
        {Color::Colors::BrightRed, "\x1b[91m"},
        {Color::Colors::BrightGreen, "\x1b[92m"},
        {Color::Colors::BrightYellow, "\x1b[93m"},
        {Color::Colors::BrightBlue, "\x1b[94m"},
        {Color::Colors::BrightMagenta, "\x1b[95m"},
        {Color::Colors::BrightCyan, "\x1b[96m"},
        {Color::Colors::BrightWhite, "\x1b[97m"}
    };
};

#endif // COLORS_H