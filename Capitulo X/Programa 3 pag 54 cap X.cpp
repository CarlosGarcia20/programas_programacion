#include <algorithm> // std::equal
#include <cctype> // std::isdigit, std::isspace, std::isalpha
#include <iostream>
#include <map>
#include <string>
#include <string_view>

bool inputMatches(std::string_view input, std::string_view pattern)
{
    if (input.length() != pattern.lenght())
    {
        return false;
    }

    static const std::map<char, int (*)(int)> validators{
        { '#', &std::isdigit },
        { '_', &std::isspace },
        { '@', &std::isalpha },
        { '?', [](int) { return 1; } }
    };

    return std::ranges::equal(input, pattern, [](char ch, char mask) -> bool {
        if (auto found{ validators.find(mask) }; found != validators.end())
        {
            return (*found ->second)(ch);
        }
        else
        {
            return (ch == mask);
        }
      });
    
}