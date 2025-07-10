#include "file.h"
using namespace std;

string generateCode() {
    string code;
    code += 'A' + rand() % 26;
    code += 'A' + rand() % 26;
    code += '-';
    code += '0' + rand() % 10;
    code += '0' + rand() % 10;
    return code;
}

string generateTitle() {
    string titles[] = {
        "Квантовые вычисления", "Искусственный интеллект", "Биотехнологии",
        "Нанотехнологии", "Космические исследования", "Робототехника",
        "Климатические изменения", "Генетика", "Чистая энергия"
    };
    return titles[rand() % (sizeof(titles)/sizeof(titles[0]))];
}

int generateCost() {
    return 10000 + rand() % 490000;
}

void generateAndSaveData(int count) {
    ofstream fileF("F.txt");
    ofstream fileG("G.txt");
    ofstream fileH("H.txt");
    for (int i = 0; i < count; i++) {
        string code = generateCode();
        string title = generateTitle();
        int cost = generateCost();        
        fileF << code << " " << cost << "\n";        
        fileG << code << " " << title << "p\n";        
        fileH << code << " " << title << " " << cost << "p\n";
    }
    fileF.close();
    fileG.close();
    fileH.close();
}

void printFile(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Ошибка: файл " << filename << " не найден!" << endl;
        return;
    }
    cout << "\nСодержимое файла " << filename << ":\n";
    char ch;
    while (file.get(ch)) {
        cout << ch;
    }
    file.close();
}

void runFileTask() {
    srand(time(0)); 
    int count;
    cout << "Введите количество научных тем: ";
    cin >> count;
    generateAndSaveData(count);
    cout << "\nФайлы успешно созданы:\n";
    printFile("F.txt");
    printFile("G.txt");
    printFile("H.txt");
}