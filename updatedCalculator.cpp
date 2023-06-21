// CALCULATOR
// with input validation + error handling + array + pointer + struct (new)

#include <iostream> 
#include <limits> 
using namespace std;

// structure that holds necessary variables related to the operation
struct Calculation {
    int num1;
    int num2;
    char operatorSymbol;
    int result;
};

int sum(int n1, int n2);
int dif(int n1, int n2);
int prod(int n1, int n2);
int quo(int n1, int n2);

// definition of functions 
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
    const int limit = 100; 
    Calculation history[limit]; 
    int history_size = 0; 

    do {
        cout << " ======================================" << endl;
        cout << "               CALCULATOR              " << endl;
        cout << " ======================================" << endl;
        
        cout << endl;
        cout << "Enter the numbers you'd like to calculate: \n\n";
        cout << "--> ";
        cin >> n1 >> opt >> n2;

        // handle invalid input 
        while (cin.fail()) {
            cout << endl << "Invalid input. Please try again (ex. 5+5): ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin >> n1 >> opt >> n2;
        }
        cout << endl;

        // perform the selected operation based on the value of 'opt'variable 
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

        // new 'calculation' struct to store calculations in history
        Calculation calc;
        calc.num1 = n1;
        calc.num2 = n2;
        calc.operatorSymbol = opt;
        calc.result = ans;
	
        history[history_size] = calc;
        history_size++;

        if (history_size > 0) {
            cout << endl << endl << " ======================================" << endl;
            cout << "                HISTORY            " << endl;
            cout << " ======================================" << endl;
           
            for (int i = 0; i < history_size; i++) {
                cout << endl <<" [ " << history[i].num1 << history[i].operatorSymbol << history[i].num2 << "=" << history[i].result <<" ]"<< endl;
               
                // display the memory addresses of the num1, num2, and result members
                cout << endl << "Addresses: " << endl;

                cout << history[i].num1 << "| Address = " << &history[i].num1 << endl;
                cout << history[i].num2 << "| Address = " << &history[i].num2 << endl;
                cout << history[i].result << "| Address = " << &history[i].result << endl;
            }
           
            //determines whether to continue calculating or terminate the program
            cout << endl << endl << "Try again? [Y/N]: ";
            cin >> back;
            cout << endl << endl;
        }
    } while (back == 'y' || back == 'Y'); //looping

    return 0;
}

