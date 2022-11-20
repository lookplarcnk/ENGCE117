#include <iostream>

using namespace std;

int main()
{
    int scores[] = {17, 30, 96, 49, 92, 41, 38, 15, 90, 100};
    int n = sizeof(scores) / sizeof(int);

    // find maximum score
    int max = scores[0];
    for (int i = 1; i < n; i++) {
        if (scores[i] > max) {
            max = scores[i];
        }
    }

    cout << "Max: " << max << endl;
    return 0;
}