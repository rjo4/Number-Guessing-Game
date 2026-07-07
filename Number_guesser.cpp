#include<iostream>
#include<cstdlib>
#include<string>
#include<ctime>
using namespace std;

void showMenu(bool &gc, bool &hs, bool &lg, int &upper_limit){
    string guess_counter = "off";
    string difficulty = "normal";
    string hint_system = "off";
    string limited_guesses = "off";
    char enter_game = 'n';

    do{
do{ //guess counter
    cout << "guess counter set to : " << guess_counter << endl;
    cout << "you would like this option to be: ";
    cin >> guess_counter;
    if(guess_counter == "on"){
        cout << "guess counter set to : " << guess_counter << endl;
        gc = true;
        break;
    }else if (guess_counter == "off"){
        cout << "guess counter set to : " << guess_counter << endl;
        gc = false;
        break;
    }
    else{
        cout << "please enter a valid input: ";
        cout << "guess counter set to : " << guess_counter << endl;
    }
}while(1==1);
do{ //difficulty
    cout << "difficulty is currently set to: " << difficulty << endl;
    cout << "the options are 'easy', 'normal', or 'hard' what would you like the dificulty to be? ";
    cin >> difficulty;
    if (difficulty == "easy") {
    cout << "difficulty is currently set to: " << difficulty << endl;
    upper_limit = 50;
    break;
    }else if (difficulty == "normal"){
    cout << "difficulty is currently set to: " << difficulty << endl;
    upper_limit = 100;
    break;
    }else if (difficulty == "hard"){
    cout << "difficulty is currently set to: " << difficulty << endl;
    upper_limit = 500;
    break;
    }else{
    cout << "please enter a valid input: ";
    cout << "difficulty is currently set to: " << difficulty << endl;
    }
}while(1==1);
do{ //Hint system
    cout << "Hints are set to: " << hint_system << endl;
    cout << "provides hints on how close you are? you would like this option to be: ";
    cin >> hint_system;
    if(hint_system == "on"){
        cout << "Hints are set to: " << hint_system << endl;
        hs = true;
        break;
    }else if (hint_system == "off"){
        cout << "Hints are set to: " << hint_system << endl;
        hs = false;
        break;
    }
    else{
        cout << "please enter a valid input: ";
        cout << "Hints are set to: " << hint_system << endl;
    }
}while(1==1);
do{ //limited guesses 
    cout << "limited guesses is set to: " << limited_guesses << endl;
    cout << "Limits the number of guesses you recieve, you would like this option to be: ";
    cin >> limited_guesses;
    if(limited_guesses == "on"){
        cout << "limited guesses is set to: " << limited_guesses << endl;
        lg = true;
        break;
    }else if (limited_guesses == "off"){
        cout << "limited guesses is set to: " << limited_guesses << endl;
        lg = false;
        break;
    }
    else{
        cout << "please enter a valid input: ";
        cout << "limited guesses is set to: " << limited_guesses << endl;
    }
}while(1==1);
    //enter game
    cout << "would you like to start the game: [Y/N] ";
    cin >> enter_game;
    if (enter_game == 'y'||enter_game == 'Y'){
    break;
    }
    }while(enter_game == 'n' || enter_game == 'N');

}


void playGame(bool &gc, bool &hs, bool &lg, int &upper_limit){
bool win = false;
int guess;
int random_number;
int times_guessed=0;
int guess_limit = 10;
int distance;
char play_again;
char enter_game;

cout << "***************Game Start*****************" << endl;
    do{
    srand(time(0));
    random_number = rand() % upper_limit + 1;  
    cout << "A number between 1 and " << upper_limit <<" has been generated What do you think the number is? ";
    while(win == false){
    cin >> guess;
    distance = abs(guess - random_number);

    if (gc == true){
    times_guessed++;
    cout << "you have guessed " << times_guessed << " times " << endl;
    }
    if (lg == true){
    guess_limit--;
    cout << "you have " << guess_limit << " guesses left " << endl;
    if (guess_limit == 0){
        cout << "you lose the correct answer was " << random_number;
        win = true;
        while(win == true){
    cout << " Would you like to play again? [Y/N], if you would like to go back to the menu type 'Q': ";
    cin >> play_again;
    if (play_again == 'Y' || play_again == 'y'){
        win = false;
        srand(time(0));
        random_number = rand() % upper_limit + 1;  
        cout << "A number between 1 and " << upper_limit <<" has been generated What do you think the number is? ";
    }else if (play_again == 'N' || play_again == 'n'){
        win = true;
        exit(0);
    }else if (play_again == 'Q' || play_again == 'q'){
        win = true;
        enter_game = 'n';
        break;
    }else{
        cout << "please enter a valid input Y or N: ";
    }
}
    }

    }

    if(hs == true ){
    if(guess < 1 || guess > upper_limit){
    cout << "please enter a number between 1 and " << upper_limit << ": ";
    }else if(distance >= 100){
    cout << "COLD ";
    if(guess > random_number){
        cout << "too high guess again: ";
    }else if(guess < random_number){
        cout << "too low guess again: ";
    }
    }else if(distance >= 50){
    cout << "your getting close ";
    if(guess > random_number){
        cout << "too high guess again: ";
    }else if(guess < random_number){
        cout << "too low guess again: ";
    }
    }else if(distance >= 10){
    cout << "your getting warm ";
    if(guess > random_number){
        cout << "too high guess again: ";
    }else if(guess < random_number){
        cout << "too low guess again: ";
    }
    }else if(distance >= 5){
    cout << "HOT ";
    if(guess > random_number){
        cout << "too high guess again: ";
    }else if(guess < random_number){
        cout << "too low guess again: ";
    }
    }
}

else{
    if(guess < 1 || guess > upper_limit){
        cout << "please enter a number between 1 and " << upper_limit << ": ";
    }else if(guess > random_number){
        cout << "too high guess again: ";
    }else if(guess < random_number){
        cout << "too low guess again: ";
    }else if(guess == random_number){
        cout << "thats right, you win!";
        win = true;
    }
}
    }
} while (true);
}

bool playAgain(int &upper_limit){
    bool win = false;
    char play_again;
    int random_number;
    char enter_game;
    while(win == true){
    cout << " Would you like to play again? [Y/N], if you would like to go back to the menu type 'Q': ";
    cin >> play_again;
    if (play_again == 'Y' || play_again == 'y'){
        win = false;
        srand(time(0));
        random_number = rand() % upper_limit + 1;  
        cout << "A number between 1 and " << upper_limit <<" has been generated What do you think the number is? ";
    }else if (play_again == 'N' || play_again == 'n'){
        win = true;
        exit(0);
    }else if (play_again == 'Q' || play_again == 'q'){
        win = true;
        enter_game = 'n';

    }else{
        cout << "please enter a valid input Y or N: ";
    }
}  
return win;
}

int main(){
    bool gc = false;
    bool lg = false;
    bool hs = false;
    int upper_limit = 100;

    showMenu(gc,hs,lg,upper_limit);

  do
    {
        playGame(gc,hs,lg,upper_limit);
    }while(playAgain(upper_limit));

}