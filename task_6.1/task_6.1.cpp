#include <iostream>
#include <Windows.h> 
#include <string> 
#include <exception>

using namespace std;

enum class ageErrorEnumeration { // 6.8
	NEGATIVE,
	OVER,
	FEW,
	INCORRECT
};

class egeException : public exception {
	
private:
	ageErrorEnumeration notice;

public:
	egeException(ageErrorEnumeration notice) : notice(notice) {};

	const char* what() const throw() override {
		if (notice == ageErrorEnumeration::NEGATIVE) return "Вы ввели отрицательное число.";
		else if (notice == ageErrorEnumeration::OVER) return "Вы ещё не родились.";
		else if (notice == ageErrorEnumeration::FEW) return "Что-то не верится...";
		else if (notice == ageErrorEnumeration::INCORRECT) return "Ошибка: некорректные входные данные.";
		else return "Ошибка не опознана.";
	}
};

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	cout << "6 Лабораторная работа. Вопрос 1." << endl;

	// 1. Попросите пользователя ввести число 1, 2 или 3 и выведите его 
	// в текстовом виде : "Один", "Два" или "Три" соответственно.

	int myNum = 0;
	string trueMsg;
	try {
		cout << "Введите число 1, 2 или 3 : ";
		if (not (cin >> myNum)) throw "Ошибка: некорректные входные данные."; // если ввели не число
		switch (myNum) {
		case 1:
			trueMsg = "Один";
			break;
		case 2:
			trueMsg = "Два";
			break;
		case 3:
			trueMsg = "Три";
			break;
		default:
			throw "Некорректное значение.";
		}
		cout << trueMsg;
	}

	// 2. Если пользователь ввёл другое число, то выбросите исключение, 
	// в обработке которого выведите в консоль : "Некорректное значение".

	catch (const char* msg) {
		cout << msg;
		/* следующие две строчки кода честно стырены из инета для. нужно для очистки буфера ввода */
		cin.clear();
		while (cin.get() != '\n');
	}
	cout << endl;

	// 3. Попросите пользователя ввести год своего рождения.

	int myYear;
	string errMsg;
	cout << endl << "Введите год своего рождения : ";
	//cin >> myYear;

	// 4. Если пользователь ввёл число меньше 1850, то выбросите исключение 
	// и в catch выведите в консоли : "Что-то не верится...".

	try {
		if (not (cin >> myYear)) throw "Ошибка: некорректные входные данные."; // если ввели не число
		if (myYear < 1850) errMsg = "Что-то не верится...";

	// 5. Если пользователь ввёл число больше, чем текущий год, то 
	// выбросите исключение и в catch выведите в консоли : "Вы ещё не 
	// родились".

		if (myYear > 2022) errMsg = "Вы ещё не родились.";

	// 6. Если пользователь ввёл отрицательное число, то выбросите 
	// исключение и в catch выведите в консоли : "Вы ввели отрицательное 
	// число!".

		if (myYear < 0) errMsg = "Вы ввели отрицательное число";
		if (not (errMsg.empty())) throw errMsg; // если ошибка случилась, то в исключение
		else cout << "Спасибо!" << endl;
	}

	// 7. Если ввод был корректный (и не было, как следствие, исключений), 
	// то выведите в консоль : "Спасибо!".

	catch (const char* msg) {
		cout << msg << endl;
		cin.clear();
		while (cin.get() != '\n');
	}
	catch (string msg) {
		cout << msg << endl;
	}

	// 8. Создайте свой класс исключений с перечислением (для кода ошибок) 
	// и переработайте задание с годом рождения так, чтобы выбрасывалось 
	// уже Ваше исключение.

	cout << endl << "Введите год своего рождения : ";
	try {
		if (not (cin >> myYear)) throw egeException(ageErrorEnumeration::INCORRECT); // если ввели не число
		else if (myYear < 0) throw egeException(ageErrorEnumeration::NEGATIVE);
		else if (myYear < 1850) throw egeException(ageErrorEnumeration::FEW);
		else if (myYear > 2022) throw egeException(ageErrorEnumeration::OVER);
		cout << "Спасибо!" << endl;
	}
	catch (egeException msg) {
		cout << msg.what() << endl;
	}
}
