#include <string>
#include <fstream>
#include <map>
#include <iostream>
#include <cctype>
#include <set>
#include <iterator>
#include <algorithm>

std::string MakeLowercase(std::string str) { // Intentional Copy
    std::transform(str.begin(), str.end(), str.begin(), 
        [](char c){return std::tolower(c);}
    );
    return str;
}

std::set<std::string> ReplacementCensor(std::istream & is, std::ostream & os, std::map<std::string, std::string> const & bad_to_good) {
    std::map<std::string, std::string> bad_lowercase_to_good;
    for (auto [bad, good]: bad_to_good) {
        std::string bad_lower = MakeLowercase(bad);
        bad_lowercase_to_good[bad_lower] = good;
    }

    // From https://stackoverflow.com/questions/3203452/how-to-read-entire-stream-into-a-stdstring
    std::string input_string(std::istreambuf_iterator<char>(is), {});

    std::set<std::string> words_replaced;
    for (auto const & [bad, good]: bad_lowercase_to_good) {
        std::string input_string_lowercase = MakeLowercase(input_string);
        for (std::string::size_type pos = input_string_lowercase.find(bad);
            pos != std::string::npos; pos = input_string_lowercase.find(bad)) {
            std::string bad_word_found = input_string.substr(pos, bad.length());
            words_replaced.insert(bad_word_found);
            input_string.replace(pos, bad.length(), good);
            input_string_lowercase = MakeLowercase(input_string);
        }
    }

    os << input_string;
    return words_replaced;
}