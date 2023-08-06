#include<iostream>
using namespace std;

string n1;
string n2;
int digit = 0;
char column;
char row;
char turn = 'x';
bool draw = true;

char gamearray[3][3] = {{'1','2','3'},{'4','5','6'},{'7','8','9'}};


void GameStructure(){

    

    cout<<"         |            |             \n";
    cout<< "   " << gamearray[0][0] <<"     |     "<< gamearray[0][1] << "      |     " << gamearray[0][2] << "\n";
    cout<<"_________|____________|____________\n";
    cout<<"         |            |             \n";
    cout<< "   " << gamearray[1][0] <<"     |     "<< gamearray[1][1] << "      |     " << gamearray[1][2] << "\n";
    cout<<"_________|____________|____________\n";
    cout<<"         |            |             \n";
    cout<< "   " << gamearray[2][0] <<"     |     "<< gamearray[2][1] << "      |     " << gamearray[2][2] << "\n";
    cout<<"         |            |             \n";
}


void GameInput(){

    if(turn == 'x'){

        cout<<n1<< ", it's your turn. Which number would you select? \n";
        cin>>digit;
    }
    else{

        cout<<n2<< ", it's your turn. Which number would you select? \n";
        cin>>digit;
    }




    if(digit == 1){
        column = 0;
        row = 0;
    }
    else if(digit == 2){
        column = 1;
        row = 0;
    }
    else if(digit == 3){
        column = 2;
        row = 0;
    }
    else if(digit == 4){
        column = 0;
        row = 1;
    }
    else if(digit == 5){
        column = 1;
        row = 1;
    }
    else if(digit == 6){
        column = 2;
        row = 1;
    }
    else if(digit == 7){
        column = 0;
        row = 2;
    }
    else if(digit == 8){
        column = 1;
        row = 2;
    }
    else if(digit == 9){
        column = 2;
        row = 2;
    }
    else{
        cout<<"you typed an invalid number" <<endl;
    }

    if(gamearray[row][column]!= 'x' && gamearray[row][column]!= '0' && turn == 'x'){

        gamearray[row][column]= 'x';
        turn = '0';
        
    }
    else if(gamearray[row][column]!= 'x' && gamearray[row][column]!= '0' && turn == '0'){
        
        gamearray[row][column]= '0';
        turn = 'x';
    }
}

bool WinningCondition(){

    if((gamearray[0][0] == gamearray[0][1] && gamearray[0][0] == gamearray[0][2]) || (gamearray[1][0] == gamearray[1][1] && gamearray[1][0] == gamearray[1][2]) || (gamearray[2][0] == gamearray[2][1] && gamearray[2][0] == gamearray[2][2])){

        return true;
    }
    else if((gamearray[0][0] == gamearray[1][0] && gamearray[0][0] == gamearray[2][0]) || (gamearray[0][1] == gamearray[1][1] && gamearray[0][1] == gamearray[2][1]) || (gamearray[0][2] == gamearray[1][2] && gamearray[0][2] == gamearray[2][2])){

        return true;
    }
    else if((gamearray[0][0] == gamearray[1][1] && gamearray[0][0] == gamearray[2][2]) || (gamearray[0][2] == gamearray[1][1] && gamearray[0][2] == gamearray[2][0])){

        return true;
    }

    for(int i= 0; i<3; i++){
        for(int j= 0; j<3; j++){
            if(gamearray[i][j] != 'x' && gamearray[i][j] != '0'){

                return false;
            }else{
                continue;
            }
        }
    }
    turn = 'd';
    return draw;

}


int main(){

    cout<< "Enter your name: \n";
    getline(cin, n1);
    cout<< "Enter your name: \n";
    getline(cin, n2);
    cout<< "First player name is : " << n1 << "\n";
    cout<< "Second player name is : " << n2 << "\n";


    while(WinningCondition() == false){

        GameStructure();
        GameInput();
        WinningCondition();
    }

    if( turn == '0'){
        
        GameStructure();
        cout<<n1<< " Wins!" <<endl;
    }
    else if( turn == 'x'){
        
        GameStructure();
        cout<<n2<< " Wins!" <<endl;
    }
    else if( turn == 'd'){

        GameStructure();
        cout<< "It's a draw" <<endl;
    }

}


