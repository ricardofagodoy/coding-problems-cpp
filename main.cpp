#include <iostream>
#include <vector>
#include <map>
#include <chrono>
using namespace std;

int find_even_index (const vector<int> numbers) {

    int numbersSize = numbers.size();
    map<int, vector<int>> sums;

    int sumAux = 0;
    for(int i = 0; i <= numbersSize - 1; i++)
        sums[(sumAux += numbers[i])].push_back(i);

    sumAux = 0;
    for(int i = numbersSize - 1; i >= 0; i--)
        sums[(sumAux += numbers[i])].push_back(i);

    for(map<int, vector<int>>::iterator t = sums.begin(); t != sums.end(); ++t) {
        
        vector<int> indexes = t->second;
        
        for(int i = 0; i < indexes.size() -1; i++)
            for(int j = i; j <= indexes.size() -1; i++) {

                cout << "Summing " << indexes[i] << " and " << indexes[j] << " to be " << numbersSize-1 << endl;

                if (indexes[i] + indexes[j] == numbersSize - 1)
                    return indexes[i];
            }
    }

    return -1;
}

int find_even_index_slow (const vector<int> numbers) {

    int numbersSize = numbers.size();

    for(int i = 0; i <= numbersSize - 1; i++) {

        int sumLeftRight = 0,
            sumRightLeft = 0;

        for(int l = 0; l < i; l++)
            sumLeftRight += numbers[l];

        for(int r = numbersSize - 1; r > i; r--)
            sumRightLeft += numbers[r];

        if (sumLeftRight == sumRightLeft)
            return i;
    }

    return -1;
}

int main(int argc, char** argv) {
    
    int n = 10;
    vector<int> v;

    for(int i = 1; i <= n; i++) v.push_back(i);
    v.push_back(0);
    for(int i = 1; i <= n; i++) v.push_back(i);

    cout << v.size() << " numbers" << endl;

    auto started = std::chrono::high_resolution_clock::now();
    cout << "found index: " << find_even_index({1, 2, 3, 4, 3, 2, 1}) << endl;
    auto done = std::chrono::high_resolution_clock::now();

    cout << "time taken: " << chrono::duration_cast<chrono::milliseconds>(done-started).count() << " ms" << endl;

    cout << v[0] << endl;

    return 0;
}