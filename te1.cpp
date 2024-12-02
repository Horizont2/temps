#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> numbers = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    vector<int> even_numbers;

    for (auto it = numbers.begin(); it != numbers.end(); ++it) {
        if (*it % 2 == 0) {
            even_numbers.push_back(*it);
        }
    }

    cout << "Even numbers: ";
    for (const auto& num : even_numbers) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
