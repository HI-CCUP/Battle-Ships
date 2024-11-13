#include <iostream>
#include "functions/functions.cc"
#include "board/board.cc"
#include "player/player.cc"
#include "ship/ship.cc"
#include "bot/bot.cc"

using namespace std;

int main()
{
    intro();

    char answer;

    cout << "First player";
    Player p1("Player1");
    do
    {
        cout << "Are you lonely? (y/n)";
        cin >> answer;
    }while(answer != 'y' && answer != 'Y' && answer != 'n' && answer != 'N');

    clear();

        if(answer == 'y' || answer == 'Y')
        {
            cout << "=\033[1;34m'\033[0m[" <<endl;
            sleep(2000);
            clear();
            cout << "Bot's ";
            Bot b1("Computer");
            do
            {
                cout << p1.name << " is placing ships.";
                sleep(2000);
                p1.placeShip(b1);
                sleep(1000);
                
                clear();
                cout << b1.name << " is placing ships.";
                sleep(2000);
                b1.placeShips();

                bool sbLost = false;
                while(!sbLost)
                {

                    if(p1.turn(b1))
                    {
                        clear();
                        cout << "Congratulations! Player " << p1.name << " won!";
                        p1.increaseWinCount();
                        sbLost = true;
                        sleep(2000);
                        break;
                    }
                    
                    cout << b1.name << " is shooting";
                    sleep(2000);
                    if(b1.turn(p1))
                    {
                        clear();
                        cout << "Congratulations! Bot " << b1.name << " won!";
                        b1.increaseWinCount();
                        sbLost = true;
                        sleep(2000);
                        break;
                    }
                }

                clear();
                cout << "Do you want to play next game? (y/n) ";
                cin >> answer;
                if (answer == 'y' || answer == 'Y')
                {
                    p1.clearBoardToNextGame();
                    b1.clearBoardToNextGame();
                }else{
                    clear();  
                    cout << p1.name << " score: " << "\033[1;31m" << p1.returnWinCount() << "\033[0m" <<endl;
                    cout << b1.name << " score: " << "\033[1;31m" << b1.returnWinCount() << "\033[0m" <<endl;
                    system("pause");
                }
            } while (answer == 'y' || answer == 'Y');


            

        }else{

            cout << "Second player";
            Player p2("Player2");

            do
            {
                cout << p1.name << " is placing ships.";
                sleep(2000);
                p1.placeShip(p2);
                restBetweenPlayers();

                cout << p2.name << " is placing ships.";
                sleep(2000);
                p2.placeShip(p1);

                bool sbLost = false;
                while(!sbLost)
                {
                    if(p1.turn(p2))
                    {
                        clear();
                        cout << "Congratulations! Player " << p1.name << " won!";
                        p1.increaseWinCount();
                        sbLost = true;
                        sleep(2000);
                        break;
                    }

                    if(p2.turn(p1))
                    {
                        clear();
                        cout << "Congratulations! Player " << p2.name << " won!";
                        p2.increaseWinCount();
                        sbLost = true;
                        sleep(2000);
                        break;
                    }
                }

                clear();
                cout << "Do you want to play next game? (y/n) ";
                cin >> answer;
                if (answer == 'y' || answer == 'Y')
                {
                    p1.clearBoardToNextGame();
                    p2.clearBoardToNextGame();
                }else{
                    clear();  
                    cout << p1.name << " score: " << "\033[1;31m" << p1.returnWinCount() << "\033[0m" <<endl;
                    cout << p2.name << " score: " << "\033[1;31m" << p2.returnWinCount() << "\033[0m" <<endl;
                    system("pause");
                }
        
            } while (answer == 'y' || answer == 'Y');
        }

    ending();
}