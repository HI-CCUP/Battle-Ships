#include <iostream>
#include <thread>
#include <chrono>
#include <fstream>
#include "functions.h"

using namespace std;

void clear()
{
#ifdef _WIN32
    system("cls");
#else
    system(clear);
#endif
}

void sleep(int ms)
{
    this_thread::sleep_for(chrono::milliseconds(ms));
}

void restBetweenPlayers()
{
    clear();
    cout << "\033[1;31mSwitch players!\033[0m" <<endl;
    sleep(2000);
    cout << "\033[1;32mAre you ready?\033[0m\033" <<endl;
    system("pause");
    clear();
}

void intro()
{
    clear();
    cout << "                         |\\" <<endl;
    cout << "                         ||\\" <<endl;
    cout << "                        /|| \\       __" <<endl;
    cout << "              __       / ||  \\_____|==|_" <<endl;
    cout << "     ________|==|_____/  ||   |\033[1;31mBATTLE\033[0m|  \\ " <<endl;
    cout << "    /        |  |      \\ ||   | \033[1;31mSHIPS\033[0m|__\\_________\\ " <<endl;
    cout << "   /_____________________\\||___|______|_____________\\ " <<endl;
    cout << "   \\                  |             |                /" <<endl;
    cout << "\033[1;34m~~~~\033[0m\\\033[1;34m~~~~~~~~~~~~~~~~~~\033[0m|_____________|\033[1;34m~~~~~~~~~~~~~\033[0m /" <<endl;
    cout << "\033[1;34m~~~~~\033[0m\\       \033[1;34m~~~        ~           ~~~~\033[0m           /" <<endl;
    cout << "      \\______________________________\033[1;34m~~\033[0m___________ / " <<endl;
    cout << "\033[1;34m~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" <<endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\033[0m" <<endl;
    sleep(3000);
    system("pause");
    clear();

}

void ending()
{
    clear();
    cout << "\033[1;31mEND OF THE GAME\033[0m" <<endl;
    sleep(3000);
    clear();
    cout << "\033[1;34mThanks for playing!\033[0m" <<endl;
    sleep(2000);
    cout << "Author: " << "\033[1;32mMaciej Zawada\033[0m" <<endl;
    sleep(5000);
}
