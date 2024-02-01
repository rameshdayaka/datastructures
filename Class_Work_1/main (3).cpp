#include <iostream>
using namespace std;

int main() {
    // Creating an array of integers named "mynumbers" with a size of 5
    int mynumbers[5] = {10, 20, 30, 40, 50};

    // Using a range-based for loop to iterate through each element in the array
    // Printing each element followed by a newline
    for (int i : mynumbers) {
        cout << i << "\n";
    }

    // The main function returns 0 by default, indicating successful execution
    return 0;
}

