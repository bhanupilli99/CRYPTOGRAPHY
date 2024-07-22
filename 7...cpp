#include<iostream>
using namespace std;

int main() {
    int n, sum = 0, i = 0;

    cout << "Enter the value of n: ";
    cin >> n;

    cout << "Enter the numbers: ";
    while (i < n) {
        int num;
        cin >> num;
        sum += num;
        i++;
    }

    cout << "Sum: " << sum << endl;

    return 0;
}