#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>
#include <cmath>

using namespace std;

void bubbleSort(vector<int>& temp) {
 
    int n = temp.size();

    for (int i = 0; i < n - 1; i++) {

        bool flag = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (temp[j] > temp[j + 1]) {
                swap(temp[j], temp[j + 1]);
              
                flag = true;
            }
        }
    
        if (!flag)
            break;
    }
}

int main() {
    fstream MyFile("Day1.txt");

    string text;
    int int1;
    int int2;

    vector<int> d1;
    vector<int> d2;

    while (getline(MyFile, text)) {
        char *cstr = new char[text.length() + 1];
        strcpy(cstr, text.c_str());

        int1 = atoi(strtok(cstr, "   "));
        int2 = atoi(strtok(NULL, "   "));

        d1.push_back(int1);
        d2.push_back(int2);
        
        delete[] cstr;
    }

    bubbleSort(d1);
    bubbleSort(d2);

    int tot = 0;

    for (size_t i = 0; i < d1.size(); i++) {

        tot = tot + abs(d1[i] - d2[i]);
    }
        
    cout << tot << "\n";

    return 0;

}
