#include <iostream>
#include <string>
#include <cassert>

std::string WordleResponse(std::string const & secret_word, std::string const & guess) {
    int const length_of_word = 5;
    assert(static_cast<int>(secret_word.size()) == length_of_word);
    assert(static_cast<int>(guess.size()) == length_of_word);
    
    std::string response;
    for (int location = 0; location < length_of_word; ++location) {
        char letter = guess.at(location);
        if (secret_word.at(location) == letter) {
            response.push_back(letter);
        } else if (secret_word.find(letter) != std::string::npos) {
            response.push_back('?');
        } else {
            response.push_back('.');
        }
    }
    return response;
}

int main() 
{
    std::cout << "Give me a secret word: " << std::endl;
    std::string secret_word;
    std::cin >> secret_word;
    bool correctly_guessed_word = false;
    int const total_rounds = 6; 
    for (int round = 0; round < total_rounds; ++round) {
        std::cout << "Give me a guess: " << std::endl;
        std::string guess;
        std::cin >> guess;
        if (!std::cin) {
            break;
        }

        std::string response = WordleResponse(secret_word, guess);
        std::cout << response << std::endl;
        if (secret_word == guess) {
            correctly_guessed_word = true;
            std::cout << "You Win!" << std::endl;
            break;
        } 
    }
    if (!correctly_guessed_word) {
        std::cout << "You Lose." << std::endl;
    }

    return 0;
}
