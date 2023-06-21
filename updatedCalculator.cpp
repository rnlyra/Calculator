// CALCULATOR
/* with input validation + error handling
   array + pointer + struc (new)*/

#include <iostream> 
#include <limits> // handles invalid input
using namespace std;

// struct that holds necessary variables and functions related to the calculator's operation
struct Calculation {
    int num1;
    int num2;
    char operatorSymbol;
    int result;
};

// function prototypes/ declaration for the arithmetic operations
int sum(int n1, int n2);
int dif(int n1, int n2);
int prod(int n1, int n2);
int quo(int n1, int n2);

/* definition of functions for the arithmetic operations;
each function performs the corresponding operation */
int sum(int n1, int n2, int& ans) {
    ans = n1 + n2;
    return ans;
}

int dif(int n1, int n2, int& ans) {
    ans = n1 - n2;
    return ans;
}

int prod(int n1, int n2, int& ans) {
    ans = n1 * n2;
    return ans;
}

int quo(int n1, int n2, int& ans) {
    if (n2 == 0) {
        cout << "Undefined";
        return 0;
    }
    ans = n1 / n2;
    return ans;
}

int main() {
// declaration of variables
    int n1, n2; 
    char opt, back; 
    const int limit = 100; // defines the maximum size of the calculation history
    Calculation history[limit]; // array of 'Calculation' structs for storing the calculation history
    int history_size = 0; // keeps track of the number of calculations stored

// loop that allows the user to perform calculations repeatedly
    do {
        // display the calculator title
        cout << " ======================================" << endl;
        cout << "               CALCULATOR              " << endl;
        cout << " ======================================" << endl;
        
        cout << endl;
        cout << "Enter the numbers you'd like to calculate: \n\n";
        cout << "--> ";
        cin >> n1 >> opt >> n2;

        /* handle invalid input by checking if the input stream ('cin') has failed;
        If the input is invalid, an error message is displayed, and the user is prompted to enter valid input again */
        while (cin.fail()) {
            cout << endl << "Invalid input. Please try again (ex. 5+5): ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin >> n1 >> opt >> n2;
        }
        cout << endl;

        /* perform the selected operation based on the 'opt'variable entered by the user;
	it calls the corresponding operation and display the calculated result */
        int ans = 0;  
        switch (opt) {
            case '+':
                cout << "Answer: " << sum(n1, n2, ans);
                break;
            case '-':
                cout << "Answer: " << dif(n1, n2, ans);
                break;
            case '*':
                cout << "Answer: " << prod(n1, n2, ans);
                break;
            case '/':
                cout << "Answer: " << quo(n1, n2, ans);
                break;
            default:
                cout << "Answer: ";
        }

        // new 'calculation' struct to store calculation in history
        Calculation calc;
        calc.num1 = n1;
        calc.num2 = n2;
        calc.operatorSymbol = opt;
        calc.result = ans;

        history[history_size] = calc;
        history_size++;

        if (history_size > 0) { // if there are calculations in the history/(history_size > 0), the code enters this loop to display the calculation history
           
            cout << endl << endl << " ======================================" << endl;
            cout << "                HISTORY            " << endl;
            cout << " ======================================" << endl;
           
            //it iterates over the history array using this for loop and display the calculation's numbers (num1,num2), operator symbol, and result
            for (int i = 0; i < history_size; i++) {
                cout << endl <<" [ " << history[i].num1 << history[i].operatorSymbol << history[i].num2 << "=" << history[i].result <<" ]"<< endl;
               
                // display the memory addresses of the num1, num2, and result members
                cout << endl << "Addresses: " << endl;

                cout << history[i].num1 << "| Address = " << &history[i].num1 << endl;
                cout << history[i].num2 << "| Address = " << &history[i].num2 << endl;
                cout << history[i].result << "| Address = " << &history[i].result << endl;
            }
           
            //determines whether the user wants to continue calculating or terminates the program
            cout << endl << endl << "Try again? [Y/N]: ";
            cin >> back;
            cout << endl << endl;
        }
    } while (back == 'y' || back == 'Y');

    return 0;
}

