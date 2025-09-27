/*
#include <iostream>

// TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
int main() {
    // TIP Press <shortcut actionId="RenameElement"/> when your caret is at the <b>lang</b> variable name to see how CLion can help you rename it.
    auto lang = "C++";
    std::cout << "Hello and welcome to " << lang << "!\n";

    for (int i = 1; i <= 5; i++) {
        // TIP Press <shortcut actionId="Debug"/> to start debugging your code. We have set one <icon src="AllIcons.Debugger.Db_set_breakpoint"/> breakpoint for you, but you can always add more by pressing <shortcut actionId="ToggleLineBreakpoint"/>.
        std::cout << "i = " << i << std::endl;
    }

    return 0;
    // TIP See CLion help at <a href="https://www.jetbrains.com/help/clion/">jetbrains.com/help/clion/</a>. Also, you can try interactive lessons for CLion by selecting 'Help | Learn IDE Features' from the main menu.
}

*/





// to run code use Ctrl + Alt + N
/* good luck!*/
//для проверки комм, потом его можно удалить!!!!!!!!!



#include <iostream>
#include <vector>
#include <cstring>
#include <windows.h>
#include <locale>
using namespace std;


//общие ф calculate salary, tax && net salary

double cs(double hours, double rate, double bonus = 0){
    return hours*rate*(1+bonus/100);
}
double ct(double salary){
    return salary*0.13;
}
double cns(double salary){
    return salary - ct(salary);
}



//ex. 1
void task1(){
    cout << " Задача 1" << endl;
    double hours, rate, bonus;
    cout << "Количество часов: ";
    cin >> hours;
    cout << "Ставка оплаты (руб/час): ";
    cin >> rate;
    cout << "Процент премии: ";
    cin >> bonus;
    double total = cs(hours, rate, bonus);
    cout << "Общая заработанная сумма: " << total << " руб." << endl;
    cout << endl;
}



//задача 2
void task2(){
    cout << " Задача 2  " << endl;
    double hours, rate, bonus;
    cout << "Количество часов: ";
    cin >> hours;
    cout << "Ставка оплаты (руб/час): ";
    cin >> rate;
    cout << "Процент премии: ";
    cin >> bonus;
    double salary = cs(hours, rate, bonus);
    double tax = ct(salary);
    double netSalary = cns(salary);

    cout << "Общая сумма: " << salary << " руб." << endl;
    cout << "Подоходный налог: " << tax << " руб." << endl;
    cout << "На руки: " << netSalary << " руб." << endl;
    cout << endl;
}



// Функция для ввода данных работника
void inputWorkerData(double &hours, double &rate, double &bonus) {
    cout << "Введите количество часов: ";
    cin >> hours;
    cout << "Введите ставку оплаты (руб/час): ";
    cin >> rate;
    cout << "Введите процент премии: ";
    cin >> bonus;
}



// task 3
void task3() {
    cout << "=== ЗАДАЧА 3 ===" << endl;

    double hours, rate, bonus;

    inputWorkerData(hours, rate, bonus);
    double salary = cs(hours, rate, bonus);

    cout << "Общая заработанная сумма: " << salary << " руб." << endl;
    cout << endl;
}

// Функция с out-параметрами для всех расчетов
void calculateAll(double hours, double rate, double bonus,
                  double &totalSalary, double &tax, double &netSalary) {
    totalSalary = cs(hours, rate, bonus);
    tax = ct(totalSalary);
    netSalary = cns(totalSalary);
}



// 444444
void task4() {
    cout << "=== ЗАДАЧA 4 ===" << endl;

    double hours, rate, bonus;

    cout << "Введите количество часов: ";
    cin >> hours;
    cout << "Введите ставку оплаты (руб/час): ";
    cin >> rate;
    cout << "Введите процент премии: ";
    cin >> bonus;
    double totalSalary, tax, netSalary;
    calculateAll(hours, rate, bonus, totalSalary, tax, netSalary);

    cout << "Общая сумма: " << totalSalary << " руб." << endl;
    cout << "Подоходный налог: " << tax << " руб." << endl;
    cout << "На руки: " << netSalary << " руб." << endl;
    cout << endl;
}



//number 5
void task5() {
    cout << "=== ЗАДАЧА 5 ===" << endl;

    double hours1, rate1, hours2, rate2;

    cout << "=== Работник 1 ===" << endl;
    cout << "Количество часов: ";
    cin >> hours1;
    cout << "Ставка оплаты: ";
    cin >> rate1;

    cout << "=== Работник 2 ===" << endl;
    cout << "Количество часов: ";
    cin >> hours2;
    cout << "Ставка оплаты: ";
    cin >> rate2;
    double salary1 = cs(hours1, rate1);
    double salary2 = cs(hours2, rate2);

    if (salary1 > salary2) {
        cout << "Больше заработал работник 1" << endl;
    } else if (salary2 > salary1) {
        cout << "Больше заработал работник 2" << endl;
    } else {
        cout << "Оба работника заработали одинаково" << endl;
    }

    cout << "Общая сумма двух работников: " << salary1 + salary2 << " руб." << endl;
    cout << endl;
}



// 666
void task6() {
    cout << "=== ЗАДАЧА 6 ===" << endl;

    char surname1[21], surname2[21];
    double hours1, rate1, hours2, rate2;

    cout << "=== Работник 1 ===" << endl;
    cout << "Фамилия: ";
    cin >> surname1;
    cout << "Количество часов: ";
    cin >> hours1;
    cout << "Ставка оплаты: ";
    cin >> rate1;

    cout << "=== Работник 2 ===" << endl;
    cout << "Фамилия: ";
    cin >> surname2;
    cout << "Количество часов: ";
    cin >> hours2;
    cout << "Ставка оплаты: ";
    cin >> rate2;


    double salary1 = cs(hours1, rate1);
    double salary2 = cs(hours2, rate2);
    double netSalary1 = cns(salary1);
    double netSalary2 = cns(salary2);
    double tax1 = ct(salary1);
    double tax2 = ct(salary2);


    cout << "\nФамилии тех, кто получил меньше 1000 руб.:" << endl;
    if (netSalary1 < 1000) cout << surname1 << " (" << netSalary1 << " руб.)" << endl;
    if (netSalary2 < 1000) cout << surname2 << " (" << netSalary2 << " руб.)" << endl;

    cout << "\nСокращенные фамилии (налог > 50 руб.):" << endl;
    if (tax1 > 50) {
        cout << surname1[0] << "-" << surname1[strlen(surname1)-1] << " (налог: " << tax1 << " руб.)" << endl;
    }
    if (tax2 > 50) {
        cout << surname2[0] << "-" << surname2[strlen(surname2)-1] << " (налог: " << tax2 << " руб.)" << endl;
    }
    cout << endl;
}



//777, azino
void task7() {
    cout << "=== ЗАДАЧА 7 ===" << endl;

    double totalBrigade = 0;

    for (int i = 1; i <= 5; i++) {
        double hours, rate;
        cout << "=== Работник " << i << " ===" << endl;
        cout << "Количество часов: ";
        cin >> hours;
        cout << "Ставка оплаты: ";
        cin >> rate;
        double salary = cs(hours, rate);
        totalBrigade += salary;
        cout << "Зарплата: " << salary << " руб." << endl << endl;
    }
    cout << "Средняя зарплата в бригаде: " << totalBrigade / 5 << " руб." << endl;
    cout << endl;
}



// eight
void task8(){
    cout << "=== ЗАДАЧА 8 ===" << endl;

    int n;
    cout << "Введите количество работников: ";
    cin >> n;
    vector<double> hours(n), rate(n), salaries(n), taxes(n), netSalaries(n);
    for (int i = 0; i < n; i++) {
        cout << "=== Работник " << i+1 << " ===" << endl;
        cout << "Количество часов: ";
        cin >> hours[i];
        cout << "Ставка оплаты: ";
        cin >> rate[i];

        salaries[i] = cs(hours[i], rate[i]);
        taxes[i] = ct(salaries[i]);
        netSalaries[i] = cns(salaries[i]);
    }

    // Поиск минимальной зарплаты
    int minIndex = 0;
    for (int i = 1; i < n; i++) {
        if (netSalaries[i] < netSalaries[minIndex]) {
            minIndex = i;
        }
    }
    cout << "Меньше всех получил работник " << minIndex+1
         << " (" << netSalaries[minIndex] << " руб.)" << endl;

    // Поиск максимальной зарплаты
    int maxIndex = 0;
    for (int i = 1; i < n; i++) {
        if (salaries[i] > salaries[maxIndex]) {
            maxIndex = i;
        }
    }
    cout << "Максимальная зарплата: " << salaries[maxIndex]
         << " руб. (работник " << maxIndex+1 << ")" << endl;

    // Работники с зарплатой более 50000
    cout << "Работники с зарплатой более 50000 руб.: ";
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (netSalaries[i] > 50000) {
            cout << i+1 << " ";
            count++;
        }
    }
    cout << "\nВсего: " << count << " человек" << endl;

    // Общая сумма налога
    double totalTax = 0;
    for (int i = 0; i < n; i++) {
        totalTax += taxes[i];
    }
    cout << "Общая сумма налога: " << totalTax << " руб." << endl;
    cout << endl;
}



//)))))))))))))))))))))))))))
// Функции для работы с массивами: findMinIndex, findMaxElement & sumElements
int fmi(const vector<double>& arr) {
    int minIndex = 0;
    for (int i = 1; i < arr.size(); i++) {
        if (arr[i] < arr[minIndex]) {
            minIndex = i;
        }
    }
    return minIndex;
}

void fme(const vector<double>& arr, double &maxValue, int &index) {
    index = 0;
    maxValue = arr[0];
    for (int i = 1; i < arr.size(); i++) {
        if (arr[i] > maxValue) {
            maxValue = arr[i];
            index = i;
        }
    }
}

double se(const vector<double>& arr) {
    double sum = 0;
    for (double elem : arr) {
        sum += elem;
    }
    return sum;
}



//9mice
//9mice
//9mice
void task9() {
    cout << "=== ЗАДАЧА 9 ===" << endl;

    int n;
    cout << "Введите количество работников: ";
    cin >> n;

    vector<double> hours(n), rate(n), salaries(n), taxes(n), netSalaries(n);

    // Ввод данных
    for (int i = 0; i < n; i++) {
        cout << "=== Работник " << i+1 << " ===" << endl;
        cout << "Количество часов: ";
        cin >> hours[i];
        cout << "Ставка оплаты: ";
        cin >> rate[i];

        salaries[i] = cs(hours[i], rate[i]);
        taxes[i] = ct(salaries[i]);
        netSalaries[i] = cns(salaries[i]);
    }

    // Использование созданных функций))))))))))))
    int minNetIndex = fmi(netSalaries);
    cout << "Меньше всех получил работник " << minNetIndex+1
         << " (" << netSalaries[minNetIndex] << " руб.)" << endl;

    int maxSalaryIndex;
    double maxSalary;
    fme(salaries, maxSalary, maxSalaryIndex);
    cout << "Максимальная зарплата: " << maxSalary
         << " руб. (работник " << maxSalaryIndex+1 << ")" << endl;

    double totalTax = se(taxes);
    cout << "Общая сумма налога: " << totalTax << " руб." << endl;
    cout << endl;
}



//1010, u know, it's 10))
// Многомесячный расчет для бригады
void task10() {
    cout << "=== ЗАДАЧА 10 ===" << endl;

    const int MONTHS = 3; // Для тестирования используем 3 месяца вместо 12!!!!!!!!!!!!!!
    const int WORKERS = 4;

    // Структура для хранения данных работника
    struct WorkerData {
        double rate;
        double hours[MONTHS];
        double salary[MONTHS];
        double tax[MONTHS];
        double netSalary[MONTHS];
    };

    WorkerData workers[WORKERS];

    // Ввод данных
    for (int i = 0; i < WORKERS; i++) {
        cout << "=== Работник " << i+1 << " ===" << endl;
        cout << "Почасовая ставка: ";
        cin >> workers[i].rate;

        for (int j = 0; j < MONTHS; j++) {
            cout << "Часов в месяце " << j+1 << ": ";
            cin >> workers[i].hours[j];

            workers[i].salary[j] = workers[i].hours[j] * workers[i].rate;
            workers[i].tax[j] = workers[i].salary[j] * 0.13;
            workers[i].netSalary[j] = workers[i].salary[j] - workers[i].tax[j];
        }
        cout << endl;
    }

    // Вывод результатов
    cout << "РЕЗУЛЬТАТЫ:" << endl;
    cout << "1. Первый работник получил во втором месяце: "
         << workers[0].netSalary[1] << " руб." << endl;

    double totalTax3 = 0;
    for(int j = 0; j < MONTHS; j++) {
        totalTax3 += workers[2].tax[j];
    }
    cout << "2. Общий налог третьего работника: " << totalTax3 << " руб." << endl;

    int bestWorkerMonth3 = 0;
    for (int i = 1; i < WORKERS; i++) {
        if (workers[i].salary[2] > workers[bestWorkerMonth3].salary[2]) {
            bestWorkerMonth3 = i;
        }
    }
    cout << "3. В третьем месяце больше всех заработал работник "
         << bestWorkerMonth3+1 << endl;

    double totalYear = 0;
    for (int i = 0; i < WORKERS; i++) {
        for (int j = 0; j < MONTHS; j++) {
            totalYear += workers[i].salary[j];
        }
    }
    cout << "4. Общая годовая сумма бригады: " << totalYear << " руб." << endl;
    cout << endl;
}




// main void
// ===== ГЛАВНАЯ ФУНКЦИЯ =====



// main void
// ===== ГЛАВНАЯ ФУНКЦИЯ =====


int main() {
    int choice;
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    setlocale(LC_ALL, "Russian");

    do {
        cout << "\n==============================================" << endl;
        cout << "ВЫБЕРИТЕ ЗАДАНИЕ ДЛЯ ВЫПОЛНЕНИЯ:" << endl;
        cout << "1" << endl;
        cout << "2" << endl;
        cout << "3" << endl;
        cout << "4" << endl;
        cout << "5" << endl;
        cout << "6" << endl;
        cout << "7" << endl;
        cout << "8" << endl;
        cout << "9" << endl;
        cout << "10" << endl;

        cout << "0 - Выход" << endl;
        cout << "Ваш выбор: ";
        cin >> choice;

        switch (choice) {
            case 1: task1(); break;
            case 2: task2(); break;
            case 3: task3(); break;
            case 4: task4(); break;
            case 5: task5(); break;
            case 6: task6(); break;
            case 7: task7(); break;
            case 8: task8(); break;
            case 9: task9(); break;
            case 10: task10(); break;
            case 0: cout << "Выход из программы." << endl; break;
            default: cout << "Неверный выбор!" << endl;
        }

        if (choice != 0) {
            cout << "\nНажмите Enter для продолжения...";
            cin.ignore();
            cin.get();
        }

    } while (choice != 0);

    return 0;
}