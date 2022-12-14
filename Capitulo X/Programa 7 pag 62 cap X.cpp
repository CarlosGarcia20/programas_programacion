#include <charconv> //std::from_chars
#include <iostream>
#include <optional>
#include <string>
#include <string_view>

std::optional<int> extractAge(std::string_view age)
{
    int resul{};
    auto end{ age.data() + age.length() };
    if (std::from_chars(age.data(), end, result).ptr != end)
    {
        return {};
    }

    if (result <= 0) 
    {
        return {};
    }

    return result;
    
    
}