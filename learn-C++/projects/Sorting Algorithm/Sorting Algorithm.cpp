#include <iostream>
#include <iomanip>
#include <vector>
#include <ctime>
#define NOMINMAX
#include <windows.h>
#include <limits>

using namespace std;

// Function to display the array state and header
void displayArray(const vector<int>& arr) {
    system("cls");
    cout << "\n";
    cout << "  ============================================\n";
    cout << "  ||        Visualizing Sorting Process     ||\n";
    cout << "  ============================================\n\n";

    cout << "  Array State:\n";

    // Top border
    cout << "  +";
    for (size_t i = 0; i < arr.size(); ++i) cout << "-------+";
    cout << "\n";

    // Array elements
    cout << "  |";
    for (const int& num : arr) {
        cout << setw(5) << num << "  |";
    }
    cout << "\n";

    // Bottom border
    cout << "  +";
    for (size_t i = 0; i < arr.size(); ++i) cout << "-------+";
    cout << "\n";
}

// Sort 1: Adjacent comparison (Bubble)
void sort1(vector<int>& arr, bool ascending) {
    for (size_t i = 0; i < arr.size() - 1; ++i) {
        for (size_t j = 0; j < arr.size() - i - 1; ++j) {
            if ((ascending && arr[j] > arr[j + 1]) || (!ascending && arr[j] < arr[j + 1])) {
                swap(arr[j], arr[j + 1]);
                displayArray(arr); // Display the array on every swap
                Sleep(1200);
            }
        }
    }
}

// Sort 2: Compare index to all other indices (Selection)
void sort2(vector<int>& arr, bool ascending) {
    for (size_t i = 0; i < arr.size(); ++i) {
        for (size_t j = i + 1; j < arr.size(); ++j) {
            if ((ascending && arr[i] > arr[j]) || (!ascending && arr[i] < arr[j])) {
                swap(arr[i], arr[j]);
                displayArray(arr); // Display the array on every swap
                Sleep(1200); 
            }
        }
    }
}

// Function to display both unsorted and sorted arrays at the end
void displayResults(const vector<int>& unsorted, const vector<int>& sorted) {
    system("cls");

    cout << "\n";
    cout << "  =========================\n";
    cout << "  ||        Results      ||\n";
    cout << "  =========================\n";

    cout << "\nNumbers to sort:\n";
    cout << "+";
    for (size_t i = 0; i < unsorted.size(); ++i) cout << "-------+";
    cout << "\n";

    cout << "|";
    for (const int& num : unsorted) {
        cout << setw(5) << num << "  |";
    }
    cout << "\n";

    cout << "+";
    for (size_t i = 0; i < unsorted.size(); ++i) cout << "-------+";
    cout << "\n";

    cout << "\nFinal Sorted Array:\n";
    cout << "+";
    for (size_t i = 0; i < sorted.size(); ++i) cout << "-------+";
    cout << "\n";

    cout << "|";
    for (const int& num : sorted) {
        cout << setw(5) << num << "  |";
    }
    cout << "\n";

    cout << "+";
    for (size_t i = 0; i < sorted.size(); ++i) cout << "-------+";
    cout << "\n";
}

void title() {
    cout << "                             ========================================\n";
    cout << "                             ||         Sorting Visualizer         ||\n";
    cout << "                             ========================================\n\n";
}

int main() {
    int cont = 0, con = 0;

    do {
        title();
        cout << "This program visually demonstrates Bubble Sort and Selection Sort. Users can input an array, choose\n";
        cout << " the sorting order, and watch the step-by-step sorting process, making learning sorting algorithms\n";
        cout << "                               interactive and engaging.\n\n";
        cout << "Enter 1 to continue...";
        cin >> con;
        if (cin.fail()) {
            // Clear the error flag
            cin.clear();

            // Discard invalid input
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            // Reset `con` to ensure the loop continues
            con = 0;
        }
        if (con != 1) con = 0;
        system("cls");
    } while (con == 0);

    do {
        system("cls");
        int size, choice;
        bool ascending;

        title();

        // Get array size from user
        cout << "   Enter the size of the array: ";
        cin >> size;

        // Input validation
        if (size <= 0) {
            cout << "   Invalid array size. Exiting...\n";
            return 1;
        }

        vector<int> arr(size);

        // Get array elements from user
        cout << "   Enter " << size << " elements for the array: ";
        for (int i = 0; i < size; ++i) {
            cin >> arr[i];
        }

        // Store the original array for display later
        vector<int> originalArr = arr;

        do {
            cout << "\n   Choose Sorting Algorithm:\n";
            cout << "   1. Sort 1 (Bubble Sort)\n";
            cout << "   2. Sort 2 (Selection Sort)\n";
            cout << "   Choice: ";
            cin >> choice;

            if (choice != 1 && choice != 2) {
                cout << "   Invalid choice! Please enter 1 or 2.\n";
                cin.clear(); // Clear the error flag.
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input.
            }
        } while (choice != 1 && choice != 2);

        int order;
        do {
            cout << "\n   Choose Order:\n   1. Ascending\n   2. Descending\n";
            cout << "   Choice: ";
            cin >> order;

            if (order != 1 && order != 2) {
                cout << "   Invalid choice! Please enter 1 for Ascending or 2 for Descending.\n";
                cin.clear(); // Clear the error flag.
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input.
            }
        } while (order != 1 && order != 2);

        ascending = (order == 1);

        displayArray(arr); // Initial display of array state

        if (choice == 1) {
            sort1(arr, ascending);
        }
        else if (choice == 2) {
            sort2(arr, ascending);
        }

        do {
            // Display both unsorted and sorted arrays
            displayResults(originalArr, arr);
            // Ask user if they want to sort another array
            cout << "\n   Sort another numbers?\n";
            cout << "   [1] Yes      [2] No\n";
            cin >> cont;
            if (cin.fail() || (cont != 1 && cont != 2)) {
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                cont = 0;
            }
            system("cls");
        } while (cont == 0);
    } while (cont == 1);
        system("cls");
        cout << "\n   Thank you for using our program!\n";
        cout << "\n================================= CREATORS =========================================\n";
        cout << "                               BOLOR, Angela C.\n";
        cout << "                         GONZALES, Trisha Ysabelle Q.\n";
        cout << "                         ESTRELLA, Dioslhyn Nicole S.\n";
        cout << "                           JACOBE, Jan Leander G.\n";
        cout << "                          PLACENTE, Nina Christel C.\n";
        cout << "                        SOLINAP, Charles Hendricks D.\n";

        return 0;
}