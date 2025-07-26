#include <iostream>
#include <set>
#include <ctime>


char getUserChoice(){
    std::set<char> choices = {'r','s','p','R','S','P'};
    char choice;
    std::cout<<"Press\nr for Rock\ns for Scissor\np for Paper\n";
    do{
        std::cin>>choice;

        if( !choices.count(choice) )
            std::cout<<"enter valid choice\n";

    }while( !choices.count(choice) );

    return tolower(choice);
}

char getComputerChoice(){
    char choices[] = {'r','s','p'};

    
    return choices[rand() % 3];
}

void showChoice(char choice){
    switch(choice){
        case 'r' : std::cout<<"Rock\n";break;
        case 'p' : std::cout<<"Paper\n";break;
        case 's' : std::cout<<"Scissor\n";
    }
}

void showWinner(const char player , const char computer){
    if(player == computer)
    std::cout<<"---------- It's a Tie ----------";
    else if( (player == 'r' && computer == 's') || (player == 's' && computer == 'p') || (player == 'p' && computer == 'r') )
    std::cout<<"🥇🥇🥇🥇🥇 You Win 🥇🥇🥇🥇🥇🎉🎉🎉🎉";
    else 
    std::cout<<"---------- Computer Win ----------";
}

int main(){
    srand(time(0));
    
    std::cout<<"************************** GAME **************************\n";
    std::cout<<"************************** Rock Paper Scissor Game **************************\n";
    
    char player = getUserChoice();
    char computer = getComputerChoice();

    std::cout << "\n You Choose "; showChoice(player);
    std::cout << "\n Computer Choose "; showChoice(computer);

    showWinner(player , computer);

    std::cout<<"\n************************** Game End **************************\n";
    return 0;
}