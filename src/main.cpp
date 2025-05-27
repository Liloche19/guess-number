#include "../include/guess.h"

int get_random_number(int min, int max) {
    int nb = 0;

    std::srand(time(NULL));
    nb = std::rand() % max + min;
    return nb;
}

std::vector<int> create_vector(int min, int max) {
    std::vector<int> vec;

    for (int i = min; i < max; i++)
        vec.push_back(i);
    return vec;
}

int dico_try(std::vector<int> vec, int min, int max, int guess) {
    int middle = (max - min) / 2 + min;

    if (vec[middle] == guess)
        return 1;
    if (vec[middle] < guess)
        return dico_try(vec, middle, max, guess) + 1;
    if (vec[middle] > guess)
        return dico_try(vec, min, middle, guess) + 1;
    return 1;
}

int get_best_try(int min, int max, int guess) {
    std::vector<int> vec = create_vector(min, max);

    return dico_try(vec, min, max, guess);
}

int get_nbr(int test) {
    std::string line;
    int nb;

    std::cout << "Try number " << test << " : Pick a number between " << MIN << " and " << MAX << ": ";
    std::getline(std::cin, line);
    std::istringstream iss(line);
    iss >> nb;
    if (iss.fail()){
        if (line == EXIT_COMMAND)
            std::exit(0);
        return -1;
    }
    return nb;
}

int main(void) {
    int number_to_guess = get_random_number(MIN, MAX);
    int user_number = -1;
    int test = 0;
    int min_test = 0;
    std::string line;

    while (user_number != number_to_guess) {
        test++;
        user_number = get_nbr(test);
        if (user_number < 0) {
            test--;
            continue;
        }
        if (user_number < number_to_guess)
            std::cout << "The number is higher!\n";
        if (user_number > number_to_guess)
            std::cout << "The number is lower!\n";
    }
    min_test = get_best_try(MIN, MAX, number_to_guess);
    std::cout << "\n";
    std::cout << "Best try to do : " << min_test << " | You did it in " << test << " tries\n";
    if (min_test > test)
        std::cout << "You are lucky!\n";
    if (min_test == test)
        std::cout << "You did it by the optimized way!\n";
    if (min_test < test)
        std::cout << "You are dumb!\n";
    std::cout << "The right number is " << number_to_guess << "\n";
    return 0;
}
