#include <iostream>
#include <random>

using namespace std;

void numberGuess(int bet, int guess) {
    random_device number_gen;
    mt19937_64 gen(number_gen());
    uniform_int_distribution<int> distribution(1,10);

    int random_num = distribution(gen);

    if (guess == random_num) {
        bet = bet * 2;
        cout << "Congrats! Your bet is == " << bet;
    }
    else {
        bet = bet / 2;
        cout << "Oh this is bad! Your bet is == " << bet << endl;
        cout << "The number was :" << random_num;
    }
}

string cityGuess(int bet2, string city_guess){
    random_device string_gen;
    mt19937_64 gen(string_gen());

    string city_list[] = {"istanbul","ankara","izmır","batman","sivas","edirne","mardin","urfa"};

    int size = sizeof(city_list) / sizeof(city_list[0]);

    uniform_int_distribution distribution(0, size - 1);

    int random_string = distribution(gen);

    if(city_guess == city_list[random_string]){
        bet2 = bet2 * 2;
        cout << "Congrats! Your bet is == " << bet2;
    }
    else {
        bet2 = bet2 / 2;
        cout << "Oh this is bad! Your bet is == " << bet2 << endl;
        cout << "The city was :" << city_list[random_string];
    }
}

int main(){

    int gameChoice,bet,guess,bet2;
    basic_string<char> guess2;

    cout << "What do you want to play today?" << endl;
    cout << "1) Number Guess Game" << endl
    << "2) Word Guess Game" << endl;

    cout << endl << "Please Type a Choice: ";
    cin >> gameChoice;

    try {
        if(gameChoice > 2 || gameChoice < 1) {
            throw 88;
        }
    }
    catch (int errorCode0) {
        cout << "The gameChoice must be 1 or 2!";
        terminate();
    }

    if(gameChoice == 1) {
        cout << endl << "Please Type a Bet: ";
        cin >> bet;
        cout << "Please Type a Guess Between 1 with 10: ";
        cin >> guess;

        cout << endl;

        // Error Control Start

        try{
            if(guess < 1 || guess > 10 && bet < 10){
                throw 91;
            }
        }

        catch(int errorCode3) {
            cout << "The guess must be between 1 with 10 and the min. bet must be bigger than 10$!";
            terminate();
        }

        try{
            if(bet < 10) {
                throw 89;
            }
        }

        catch(int errorCode1) {
            cout << "The min. bet must be 10$!";
            terminate();
        }

        try{
            if(guess < 1 || guess > 10){
                throw 90;
            }
        }

        catch(int errorCode2) {
            cout << "The guess must be between 1 with 10";
            terminate();
        }


        // Error Control Stop

        numberGuess(bet,guess);
    }

    if(gameChoice == 2){
        cout << endl << "Please Type a Bet: ";
        cin >> bet2;

        try{
            if(bet2 < 10) {
                throw 31;
            }
        }

        catch(int errorCode6) {
            cout << "The min. bet must be 10$!";
            terminate();
        }

        cout << "Please Type a City Name: ";
        cin >> guess2;

        cityGuess(bet2,guess2);
    }

    return 0;
}