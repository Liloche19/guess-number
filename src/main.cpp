#include <cstdio>
#include <iostream>
#include <ctime>
#include <cstdlib>

#define MIN 0
#define MAX 1000

int get_random_number(int min, int max) {
    int nb = 0;

    std::srand(time(NULL));
    nb = std::rand() % max + min;
    return nb;
}

int main() {
    int number_to_guess = get_random_number(MIN, MAX);
    int user_number = -1;
    int test = 0;

    while (user_number != number_to_guess) {
        test++;
        std::cout << "Try number " << test << " : Pick a number between " << MIN << " and " << MAX << ": ";
        std::cin >> user_number;
        if (user_number < number_to_guess)
            std::cout << "The number is higher !\n";
        if (user_number > number_to_guess)
            std::cout << "The number is lower !\n";
    }
    std::cout << "You won ! After " << test << " tries \n";
    std::cout << "The right number is " << number_to_guess << "\n";
    return 0;
}
