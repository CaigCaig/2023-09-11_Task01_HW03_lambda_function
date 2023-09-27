#include <functional>
#include <iostream>
#include <windows.h>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

constexpr auto PI = 3.1415926;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    vector<double> angles = { 30, 60, 90 };
 
    cout << "[Входные данные]: ";
    int size = angles.size();
    for (int i = 0; i < size; i++)
    {
        cout << static_cast<int>(angles[i]) << " * " << PI << " / 180";
        if (i < (size - 1)) cout << ", ";
        angles[i] *= PI / 180;
    }
    cout << " // перевод из градусов в радианы" << endl;
    cout << "[Выходные данные]:" << endl;

    vector<function<void(double)>> functions;
    functions.push_back([](double angle) { cout << "sin: " << sin(angle) << " "; });
    functions.push_back([](double angle) { cout << "cos: " << cos(angle) << " "; });
    functions.push_back([](double angle) { cout << "tan: " << tan(angle) << " "; });
    for (const auto& angle : angles)
    {
        cout << angle << ": ";
        for (const auto& function : functions)
            function(angle);
        std::cout << std::endl;
    }

    system("pause");
}