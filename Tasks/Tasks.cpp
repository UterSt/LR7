#include <iostream>
#include <string.h>
#include "func.h"

int main ()
{
    int number = 0;
    while (number == 0)
    {
        std::cout << "1 - запустить первую таску." << std::endl;
        std::cout << "2 - запустить вторую таску." << std::endl;
        std::cout << "3 - запустить третью таску." << std::endl;
        std::cout << "4 - запустить первую таску." << std::endl;
        std::cout << "5 - запустить первую таску." << std::endl;
        std::cout << "Какую запустить?: ";
        std::cin >> number;
        if (number == 1)
        {
            std::cin.ignore();
            std::string direct;
            std::cout << "Введите прямой код: ";
            std::getline(std::cin, direct);
            Task1(direct);
        }
        else if (number == 2)
        {
            int num1 = 0, num2 = 0;
            std::string str1;
            std::string str2;
            std::string res;
            std::cout << "Введите первое число: ";
            std::cin >> num1;
            std::cout << "Введите второе число: ";
            std::cin >> num2;
            zeroone(num1, str1);
            zeroone(num2, str2);
            while (str1.size() != str2.size())
            {
                str1.size()<str2.size()?str1.insert(1, "0"):str2.insert(1, "0");
            }
            for (int i = 0; i < 3; ++i)
            {
                str1.insert(1, "0");
                str2.insert(1, "0");
            }
            dop(str1);
            dop(str2);
            Sum(str1,str2,res);
            std::cout << res << std::endl;
        }
        else if (number == 3)
        {
            std::string str1;
            std::string str2;
            std::string res;
            int num;
            std::cout << "Введите систему счисления: ";
            std::cin >> num;
            std::cin.ignore();
            std::cout << "Введите первое число: ";
            std::getline(std::cin, str1);
            std::cout << "Введите второе число: ";
            std::getline(std::cin, str2);
            char znak;
            std::cout << "Сумма или разность?( - || + ): ";
            std::cin >> znak;
            if (znak == '+')
            {
                Sum3(str1, str2, res, num);
            }
            else 
            {
                raz(str1, str2, res, num);
            }
            std::cout << res << std::endl;
        }
        else if (number == 4)
        {
            int number;
            std::cout << "Введите число: ";
            std::cin >> number;
            int num1 = 7;
            int num2 = 23;
            int num3 = 197;
            std::cout << "Результат: " << std::endl;
            std::cout << "Делится ли на " << num1 << ": "<< (isDel(number, num1) ? "Да" : "Нет") << std::endl;
            std::cout << "Делится ли на " << num2 << ": "<< (isDel(number, num2) ? "Да" : "Нет") << std::endl;
            std::cout << "Делится ли на " << num3 << ": "<< (isDel(number, num3) ? "Да" : "Нет") << std::endl;
        }
        else if (number == 5)
        {
            bool arrayTF[30][5] = 
            {
                {false, true, true, true, true},
                {true, false, true, true, true},
                {true, true, false, true, true},
                {true, true, true, false, true},
                {true, true, true, true, false},
                {false, false, true, true, true},
                {false, true, false, true, true},
                {false, true, true, false, true},
                {false, true, true, true, false},
                {true, false, false, true, true},
                {true, false, true, false, true},
                {true, false, true, true, false},
                {true, true, false, false, true},
                {true, true, false, true, false},
                {true, true, true, false, false},
                {false, false, false, true, true},
                {false, false, true, false, true},
                {false, false, true, true, false},
                {false, true, false, false, true},
                {false, true, true, false, false},
                {false, true, false, true, false},
                {true, false, false, false, true},
                {true, false, false, true, false},
                {true, false, true, false, false},
                {true, true, false, false, false},
                {false, false, false, false, true},
                {true, false, false, false, false},
                {false, true, false, false, false},
                {false, false, true, false, false},
                {false, false, false, true, false},
            };
            bool arrayTF16[16][4] =
            {
                {true, true, true, true},
                {false, true, true, true},
                {true, false, true, true},
                {true, true, false, true},
                {true, true, true, false},
                {false, false, true, true},
                {false, true, false, true},
                {false, true, true, false},
                {true, false, false, true},
                {true, false, true, false},
                {true, true, false, false},
                {false, false, false, true},
                {false, false, true, false},
                {false, true, false, false},
                {true, false, false, false},
                {false, false, false, false}
            };
            bool arrayTF8[8][3] =
            {
                {true, true, true},
                {false, true, true},
                {true, false, true},
                {true, true, false},
                {false, false, true},
                {false, true, false},
                {true, false, false},
                {false, false, false}
            };
            bool arrayTF4[4][2] =
            {
                {true, true},
                {false, true},
                {true, false},
                {false, false}
            };
            int group = 31;
            std::cout << "Первый день" << std::endl;
            std::cout << "Для того чтобы проверить  все бочки нужно отбросить часть бучек чтобы хватило студентов поит для проверки, осталяем 30 т.к. такое количество мы сможем проверить когда выживут 5 поитовцев" << std::endl;
            std::cout << "Разделяем на такие группы что после смети n колтичества нам хватило бы проверить бочки при помощи 5 - n студентов поит" << std::endl;
            std::cout << "А именно 5 групп по 16, 10 по 8, 10 по 4 и 5 по 2" << std::endl;
            std::cout << std::endl;
            Table30(arrayTF);
            DorLgroup(arrayTF, group);
            std::cout << "Второй день" << std::endl;
            if (group <= 5)
            {
                int start = 1 + 16*(group - 1);
                int end = start + 15;
                std::cout << "Умер 1 поитовец и отсалось 4. У нас осталось 16 бочек в зоне подозрения, как раз у нас осталось нужное количество чтобы мы смогли проверить их." << std::endl;
                std::cout << std::endl;
                Table16(arrayTF16, start);
                DorL16(arrayTF16, start);
            }
            else if (group >= 6 && group <=15)
            {
                int start = 81 + 8 * (group - 6);
                int end = start + 7;
                std::cout << "Умерли 2 поитовца и отсалось 3. У нас осталось 8 бочек в зоне подозрения, как раз у нас осталось нужное количество чтобы мы смогли проверить их." << std::endl;
                std::cout << std::endl;
                Table8(arrayTF8, start);
                DorL8(arrayTF8, start);
            }
            else if (group >= 16 && group <= 25)
            {
                int start = 161 + 4 * (group - 16);
                int end = start + 3;
                std::cout << "Умерли 3 поитовца и отсалось 2. У нас осталось 4 бочки в зоне подозрения, как раз у нас осталось нужное количество чтобы мы смогли проверить их." << std::endl;
                std::cout << std::endl;
                Table4(arrayTF4, start);
                DorL4(arrayTF4, start);
            }
            else if (group >= 26 && group <= 30)
            {
                int flag = 0;
                int start = 201 + 2 * (group - 26);
                int end = start + 1;
                std::cout << "Умерли 4 поитовца и отсался 1. У нас осталось 2 бочки в зоне подозрения, как раз у нас осталось нужное количество чтобы мы смогли проверить их." << std::endl;
                std::cout << std::endl;
                std::cout << "| " << 1 << " | " << start << std::endl;
                std::cout << "|   | " << start + 1 << std::endl;
                std::cout << std::endl;
                std::cout << "Умер ли поитовец? (1 - Да :) | 0 - Нет :( ): ";
                std::cin >> flag;
                if (flag == 1)
                {
                    std::cout << "Это бочка под номером: " << start << std::endl;
                }
                else
                {
                    std::cout << "Это бочка под номером: " << end << std::endl;
                }
            }
            else
            {
                std::cout << "Никто не умер :(" << std::endl;
                std::cout << "Значит отравленная бочка в отброшенных 30 бочках." << std::endl;
                std::cout << std::endl;
                Table30fin(arrayTF);
                DorL30(arrayTF);
            }
        }
        else
        {
            std::cout << "Некорректное значение, повторите попытку." << std::endl;
            number = 0;
        }
    }
    return 0;
}