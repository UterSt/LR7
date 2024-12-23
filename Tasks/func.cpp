#include <iostream>
#include <string.h>
#include "func.h"

void Task1 (std::string direct) // O(n);
{
    for (int i = 1; i < direct.size(); ++i)
    {
        if (direct[0] == '0') break;
        if (direct[i] == '1')
        {
            direct[i] = '0';
        }
        else
        {
            direct[i] = '1';
        }
    }
    std::cout << direct;
}

void dop (std::string& str) //O(n)
{
    if (str[0] == '1')
    {
        for (int i = 1; i < str.size(); ++i)
        {
            if (str[i] == '1')
            {
                str[i] = '0';
            }
            else
            {
                str[i] = '1';
            }
        }
        char keis = '1';
        for (int i = str.size() - 1; i > 0; --i)
        {
            if(str[i] == '0' && keis == '1')
            {
                str[i] = '1';
                break;
            }
            else
            {
                str[i] = '0';
            }
        }
    }
}

void zeroone (int num, std::string& str) // O(n)
{
    int flag = 0;
    num < 0?flag = 1:flag = 0;
    num < 0?num = num*(-1):num = num;
    while (num >= 1)
    {
        if (num % 2 == 0)
        {
            str.insert(0, "0");
        }
        else
        {
            str.insert(0, "1");
        }
        num = num/2;
    }
    flag == 1?str.insert(0, "1"):str.insert(0, "0");
}

void Sum (std::string str1, std::string str2, std::string& res) // O(n)
{
    char keis = '0';
    for (int i = str1.size() - 1; i >= 0; --i)
    {
        if (str1[i] == '1' && str2[i] == '1' && keis == '0')
        {
            res.insert(0, "0");
            keis = '1';
        }
        else if (((str1[i] == '1' && str2[i] == '0') || (str1[i] == '0' && str2[i] == '1')) && keis == '0')
        {
            res.insert(0, "1");
        }
        else if (str1[i] == '0' && str2[i] == '0' && keis == '1')
        {
            res.insert(0, "1");
            keis = '0';
        }
        else if (str1[i] == '1' && str2[i] == '1' && keis == '1')
        {
            res.insert(0, "1");
        }
        else
        {
            res.insert(0, "0");
        }
    }
    if (res[0] == '1')
    {
        for (int i = 1; i < res.size(); ++i)
        {
            if (res[i] == '1')
            {
                res[i] = '0';
            }
            else
            {
                res[i] = '1';
            }
        }
        char keis = '1';
        for (int i = res.size() - 1; i > 0; --i)
        {
            if(res[i] == '0' && keis == '1')
            {
                res[i] = '1';
                break;
            }
            else
            {
                res[i] = '0';
            }
        }
    }
}

void Sum3 (std::string str1, std::string str2, std::string& res, int num) // O(n)
{
    std::string simbols = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    bool haveMinus1 = str1[0] == '-';
    bool haveMinus2 = str2[0] == '-';
    if (haveMinus1) str1.erase(0, 1);
    if (haveMinus2) str2.erase(0, 1);
    int diff = str1.size() - str2.size();
    if (diff < 0)
    {
        diff *= -1;
        for (int i = 0; i < diff; ++i)
        {
            str1.insert(0, "0");
        }
    }
    else if (diff > 0)
    {
        for (int i = 0; i < diff; ++i)
        {
            str2.insert(0, "0");
        }
    }
    int keis = 0;
    int sum;
    if (num <= 36 && num >= 2)
    {
        if (haveMinus1 == haveMinus2)
        {
            for (int i = str1.size() - 1; i >= 0; --i)
            {
                sum = simbols.find(str1[i]) + simbols.find(str2[i]) + keis;
                keis = sum / num;
                sum = sum % num;
                res.insert(0, 1, simbols[sum]);
            }
            if (keis > 0)
            {
                res.insert(0, 1, simbols[keis]);
            }
            while (res.size() > 1 && res[0] == '0')
            {
                res.erase(0, 1);
            }
            if (haveMinus1 && haveMinus2)
            {
                res.insert(0, "-");
            }
        }
        else
        {
            bool minus = false;
            if (str1 < str2)
            {
                std::swap(str1, str2);
                minus = haveMinus2;
            }
            else
            {
                minus = haveMinus1;
            }
            int kont = 0;
            for (int i = str1.size() - 1; i >= 0; --i)
            {
                int sector1 = simbols.find(str1[i]);
                int sector2 = simbols.find(str2[i]) + kont;
                int raz;
                if (sector1 < sector2)
                {
                    raz = sector1 - sector2 + num;
                    kont = 1;
                }
                else
                {
                    raz = sector1 - sector2;
                    kont = 0;
                }
                res.insert(0, 1, simbols[raz]);
            }
            while (res.size() > 1 && res[0] == '0')
            {
                res.erase(0, 1);
            }
            if (minus && res[0] != '0')
            {
                res.insert(0, "-");
            }
        }
    }
    else
    {
        std::cout << "Неверная система счисления (2-36)" << std::endl;
    }
}

void raz (std::string str1, std::string str2, std::string& res, int num)
{
    if (str2[0] == '-')
    {
        str2.erase(0, 1);
    }
    else 
    {
        str2.insert(0, "-");
    }
    Sum3(str1, str2, res, num);
}

bool isDel(int number, int num) // O(n)
{
    if (number < 0)
    {
        number = ~number + 1;
    }
    int sum = 0;
    while (sum <= number)
    {
        int flag = num;
        while (flag != 0)
        {
            if (sum == number)
            {
                return true;
            }
            int perenos = sum & flag;
            sum = sum ^ flag;
            flag = perenos << 1;
        }
    }
    return false;
}

void Table30 (bool arrayTF[30][5]) // O(n)
{
    char one, two, tree, four, five;
    for (int i = 0; i < 30; ++i)
    {
        if (!arrayTF[i][0])
        {
            one = '1';
        }
        else
        {
            one = ' ';
        }
        if (!arrayTF[i][1])
        {
            two = '2';
        }
        else
        {
            two = ' ';
        }
        if (!arrayTF[i][2])
        {
            tree = '3';
        }
        else
        {
            tree = ' ';
        }
        if (!arrayTF[i][3])
        {
            four = '4';
        }
        else
        {
            four = ' ';
        }
        if (!arrayTF[i][4])
        {
            five = '5';
        }
        else
        {
            five = ' ';
        }
        std::cout << "| " << one << " | " << two << " | " << tree << " | " << four << " | " << five << " |";
        if (i+1 <= 5)
        {
            std::cout << " " << 1 + 16*i << "-" << 1 + 16*i + 15;
        }
        else if (i+1 >= 6 && i+1 <= 15)
        {
            std::cout << " " << 81 + 8 * (i - 5) << "-" << 81 + 8 * (i - 5) + 7;
        }
        else if (i+1 >= 16 && i+1 <= 25)
        {
            std::cout << " " << 161 + 4 * (i - 15) << "-" << 161 + 4 * (i - 15) + 3;
        }
        else if (i+1 >= 25 && i+1 <= 30)
        {
            std::cout << " " << 201 + 2 * (i - 25) << "-" << 201 + 2 * (i - 25) + 1;
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

void DorLgroup (bool arrayTF[30][5], int &group) // O(n)
{
    bool sost1 = true, sost2 = true, sost3 = true, sost4 = true, sost5 = true;
    int flag = 0;
    std::cout << "Умер ли первый поитовец? (1 - Да :) | 0 - Нет :( ): ";
    std::cin >> flag;
    if (flag == 1)
    {
        sost1 = false;
    }
    std::cout << "Умер ли второй поитовец? (1 - Да :) | 0 - Нет :( ): ";
    std::cin >> flag;
    if (flag == 1)
    {
        sost2 = false;
    }
    std::cout << "Умер ли третий поитовец? (1 - Да :) | 0 - Нет :( ): ";
    std::cin >> flag;
    if (flag == 1)
    {
        sost3 = false;
    }
    std::cout << "Умер ли четвёртый поитовец? (1 - Да :) | 0 - Нет :( ): ";
    std::cin >> flag;
    if (flag == 1)
    {
        sost4 = false;
    }
    std::cout << "Умер ли пятый поитовец? (1 - Да :) | 0 - Нет :( ): ";
    std::cin >> flag;
    if (flag == 1)
    {
        sost5 = false;
    }
    for (int i = 0; i < 30; ++i)
    {
        if (arrayTF [i][0] == sost1 && arrayTF [i][1] == sost2 && arrayTF [i][2] == sost3 && arrayTF [i][3] == sost4 && arrayTF [i][4] == sost5)
        {
            std::cout << "Бочка находится в " << i + 1 << " группе" << std::endl;
            group = i + 1;
        }
    }
}

void Table16 (bool arrayTF16[16][4], int start) // O(n)
{
    char one, two, tree, four, five;
    for (int i = 0; i < 16; ++i)
    {
        if (!arrayTF16[i][0])
        {
            one = '1';
        }
        else
        {
            one = ' ';
        }
        if (!arrayTF16[i][1])
        {
            two = '2';
        }
        else
        {
            two = ' ';
        }
        if (!arrayTF16[i][2])
        {
            tree = '3';
        }
        else
        {
            tree = ' ';
        }
        if (!arrayTF16[i][3])
        {
            four = '4';
        }
        else
        {
            four = ' ';
        }
        std::cout << "| " << one << " | " << two << " | " << tree << " | " << four << " | ";
        std::cout << start + i << std::endl;
    }
    std::cout << std::endl;
}

void DorL16 (bool arrayTF16[16][4], int start) // O(n)
{
    bool sost1 = true, sost2 = true, sost3 = true, sost4 = true, sost5 = true;
    int flag = 0;
    std::cout << "Умер ли первый поитовец? (1 - Да :) | 0 - Нет :( ): ";
    std::cin >> flag;
    if (flag == 1)
    {
        sost1 = false;
    }
    std::cout << "Умер ли второй поитовец? (1 - Да :) | 0 - Нет :( ): ";
    std::cin >> flag;
    if (flag == 1)
    {
        sost2 = false;
    }
    std::cout << "Умер ли третий поитовец? (1 - Да :) | 0 - Нет :( ): ";
    std::cin >> flag;
    if (flag == 1)
    {
        sost3 = false;
    }
    std::cout << "Умер ли четвёртый поитовец? (1 - Да :) | 0 - Нет :( ): ";
    std::cin >> flag;
    if (flag == 1)
    {
        sost4 = false;
    }
    for (int i = 0; i < 16; ++i)
    {
        if (arrayTF16 [i][0] == sost1 && arrayTF16 [i][1] == sost2 && arrayTF16 [i][2] == sost3 && arrayTF16 [i][3] == sost4)
        {
            std::cout << "Это бочка под номером: " << i + start<< std::endl;
        }
    }
}

void Table8 (bool arrayTF8[8][3], int start) // O(n)
{
    char one, two, tree, four, five;
    for (int i = 0; i < 8; ++i)
    {
        if (!arrayTF8[i][0])
        {
            one = '1';
        }
        else
        {
            one = ' ';
        }
        if (!arrayTF8[i][1])
        {
            two = '2';
        }
        else
        {
            two = ' ';
        }
        if (!arrayTF8[i][2])
        {
            tree = '3';
        }
        else
        {
            tree = ' ';
        }
        std::cout << "| " << one << " | " << two << " | " << tree << " | ";
        std::cout << start + i << std::endl;
    }
    std::cout << std::endl;
}

void DorL8 (bool arrayTF8[8][3], int start) // O(n)
{
    bool sost1 = true, sost2 = true, sost3 = true, sost4 = true, sost5 = true;
    int flag = 0;
    std::cout << "Умер ли первый поитовец? (1 - Да :) | 0 - Нет :( ): ";
    std::cin >> flag;
    if (flag == 1)
    {
        sost1 = false;
    }
    std::cout << "Умер ли второй поитовец? (1 - Да :) | 0 - Нет :( ): ";
    std::cin >> flag;
    if (flag == 1)
    {
        sost2 = false;
    }
    std::cout << "Умер ли третий поитовец? (1 - Да :) | 0 - Нет :( ): ";
    std::cin >> flag;
    if (flag == 1)
    {
        sost3 = false;
    }
    for (int i = 0; i < 8; ++i)
    {
        if (arrayTF8 [i][0] == sost1 && arrayTF8 [i][1] == sost2 && arrayTF8 [i][2] == sost3)
        {
            std::cout << "Это бочка под номером: " << i + start<< std::endl;
        }
    }
}

void Table4 (bool arrayTF4[4][2], int start) // O(n)
{
    char one, two, tree, four, five;
    for (int i = 0; i < 4; ++i)
    {
        if (!arrayTF4[i][0])
        {
            one = '1';
        }
        else
        {
            one = ' ';
        }
        if (!arrayTF4[i][1])
        {
            two = '2';
        }
        else
        {
            two = ' ';
        }
        std::cout << "| " << one << " | " << two << " | ";
        std::cout << start + i << std::endl;
    }
    std::cout << std::endl;
}

void DorL4 (bool arrayTF4[4][2], int start) // O(n)
{
    bool sost1 = true, sost2 = true, sost3 = true, sost4 = true, sost5 = true;
    int flag = 0;
    std::cout << "Умер ли первый поитовец? (1 - Да :) | 0 - Нет :( ): ";
    std::cin >> flag;
    if (flag == 1)
    {
        sost1 = false;
    }
    std::cout << "Умер ли второй поитовец? (1 - Да :) | 0 - Нет :( ): ";
    std::cin >> flag;
    if (flag == 1)
    {
        sost2 = false;
    }
    for (int i = 0; i < 4; ++i)
    {
        if (arrayTF4 [i][0] == sost1 && arrayTF4 [i][1] == sost2)
        {
            std::cout << "Это бочка под номером: " << i + start<< std::endl;
        }
    }
}

void Table30fin (bool arrayTF[30][5]) // O(n)
{
    char one, two, tree, four, five;
    for (int i = 0; i < 30; ++i)
    {
        if (!arrayTF[i][0])
        {
            one = '1';
        }
        else
        {
            one = ' ';
        }
        if (!arrayTF[i][1])
        {
            two = '2';
        }
        else
        {
            two = ' ';
        }
        if (!arrayTF[i][2])
        {
            tree = '3';
        }
        else
        {
            tree = ' ';
        }
        if (!arrayTF[i][3])
        {
            four = '4';
        }
        else
        {
            four = ' ';
        }
        if (!arrayTF[i][4])
        {
            five = '5';
        }
        else
        {
            five = ' ';
        }
        std::cout << "| " << one << " | " << two << " | " << tree << " | " << four << " | " << five << " | ";
        std::cout << 211 + i << std::endl;
    }
    std::cout << std::endl;
}

void DorL30 (bool arrayTF[30][5]) // O(n)
{
    bool sost1 = true, sost2 = true, sost3 = true, sost4 = true, sost5 = true;
    int flag = 0;
    std::cout << "Умер ли первый поитовец? (1 - Да :) | 0 - Нет :( ): ";
    std::cin >> flag;
    if (flag == 1)
    {
        sost1 = false;
    }
    std::cout << "Умер ли второй поитовец? (1 - Да :) | 0 - Нет :( ): ";
    std::cin >> flag;
    if (flag == 1)
    {
        sost2 = false;
    }
    std::cout << "Умер ли третий поитовец? (1 - Да :) | 0 - Нет :( ): ";
    std::cin >> flag;
    if (flag == 1)
    {
        sost3 = false;
    }
    std::cout << "Умер ли четвёртый поитовец? (1 - Да :) | 0 - Нет :( ): ";
    std::cin >> flag;
    if (flag == 1)
    {
        sost4 = false;
    }
    std::cout << "Умер ли пятый поитовец? (1 - Да :) | 0 - Нет :( ): ";
    std::cin >> flag;
    if (flag == 1)
    {
        sost5 = false;
    }
    for (int i = 0; i < 30; ++i)
    {
        if (arrayTF [i][0] == sost1 && arrayTF [i][1] == sost2 && arrayTF [i][2] == sost3 && arrayTF [i][3] == sost4 && arrayTF [i][4] == sost5)
        {
            std::cout << "Это бочка под номером: " << 211 + i << std::endl;
        }
    }
}