#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <Windows.h>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <io.h>
#include <vector>
#include <regex> 

using namespace std;
//маск строка
typedef vector<string>::size_type vec_size;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    setlocale(LC_ALL, "Russian");

    ifstream ifs("test.txt");

    vector<string> vec;

    string myString;

    vec_size max_size = 0;

    int index = 0;

    if (!ifs) {
        cerr << "Файл открыть не удалось" << endl;
        cin.get();
        return 1;
    }
    else {
        for (int i = 0; getline(ifs, myString); ++i) {
            vec.push_back(myString);
            if (vec[i].size() > max_size) {
                max_size = vec[i].size();
                index = i;
            }
        }
    }

    vec_size size = vec.size();
    cout << "Считанные строки из файла: " << endl;

    for (int i = 0; i != size; ++i)
        cout << i + 1 << ". " << vec[i] << endl;

    cout << endl << "Строка с максимальной длиной под номером " << index + 1
        << endl << vec[index] << endl;

  //Поиска слова в файле
    ifstream fin("test.txt");
    if (fin.good()) {
        regex reg("[A-Za-zА-Яа-я]+");
        int k = 0;
        string str, word;
        cout << "Введи слово которые нужно посчитать: ";
        cin >> word;
        while (getline(fin, str)) {
            regex_iterator<string::iterator> it(str.begin(), str.end(), reg);
            regex_iterator<string::iterator> end;
            for (; it != end; ++it) {
                if (it->str() == word) k++;
            }
        }
        if (k) {
            cout << "Слов в файле найдено => " << k << endl;
        }
        else {
            cout << "В тексте нет такого слова \n";
        }
        fin.close();
    }
    else {
        cout << "Не найден файл\n";
    }
    system("pause");
    return 0;
}
