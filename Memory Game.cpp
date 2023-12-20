#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>
using namespace std;


void waitEnter() { // ожидание перед нажатием 
    cout << "Press Enter to continue...";
    cin.ignore(); //игнорирует все другие значения
    cin.get(); 
    cout << "\033[2J\033[H";  // команда для очистки экрана
    
}

int main() {
    srand(static_cast<unsigned int>(time(0)));//распределение чисел так чтобы после каждого запуска они не повторялись

    int n;
    int arr[20] = { 0,0,1,1,2,2,3,3,4,4,5,5,6,6,7,7,8,8,9,9 };
    bool matched[20] = { false }; 
    bool allMatched = false; 

    cout << "Welcome to the Memory Game!" << endl;
    cout << "Enter the size of array (6-20): ";
    cin >> n;

    while (n < 6 || n > 20) {
        cout << "Enter another size (6-20): ";
        cin >> n;
    }

    cout << endl << "Here is the array: ";
    for (int i = 0; i < n; ++i) {
        cout << "? ";
    }
    cout << endl << endl;

    int moves = 0; 
    while (!allMatched) {
        int Matches = 0;
        int a,b;
        bool validFirst = false, validSecond = false;

        cout << "Enter the first index to show: ";
        cin >> a;
        while (a < 0 || a >= n || matched[a]) {
            cout << "Enter another index to show: ";
            cin >> a;
        }

        cout << "The card at index " << a << " is: " << arr[a] << endl;
        validFirst = true;

        cout << "Enter the second index to show: ";
        cin >> b;
        while (b < 0 || b >= n || matched[b] || b == a) {
            cout << "Enter another valid index to show: ";
            cin >> b;
        }

        cout << "The card at index " << b << " is: " << arr[b] << endl;
        validSecond = true;

        if (validFirst && validSecond) {
            if (arr[a] == arr[b]) {    // проверка и сравнивание введенных чисел
                matched[a] = true;
                matched[b] = true;
                Matches += 2;
                cout << "Congratulations! You found a match!" << endl;
            }
            else {
                cout << "Not a match. Try again!" << endl;
            }
            waitEnter(); 
        }

        cout << "Current state of the game: ";
        for (int i = 0; i < n; ++i) {
            if (matched[i]) {       //вывод числа если угадал если нет то ?
                cout << arr[i] << " ";
            }
            else {
                cout << "? ";
            }
        }
        cout << endl << endl;

        moves++;

        int unmatched = 0;
        int lastUnmatched = -1;
        for (int i = 0; i < n; ++i) {
            if (!matched[i]) {
                unmatched++;
                lastUnmatched = i;
            }
        }

        if (unmatched == 0 || unmatched == 1) {  //если 0 то все пары найдены и выводится сколько ходов ушло
            allMatched = true;                      ///если 1 то одна осталась без пары
            if (unmatched == 0) {
                cout << "Congratulations! You've matched all cards in " << moves<< " moves!" << endl;
            }
            else {
                cout << "Congratulations! You've matched all cards except one in " << moves << " moves!" << endl;
               
            }
        }
    }

    return 0;
}
