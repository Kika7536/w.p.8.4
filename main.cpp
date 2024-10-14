#include<iostream>
using namespace std;

bool err(string number) {

	if (number.length() != 4) {
		cout << "Error." << endl;
		return false;
	}
	else {
		for (int i = 0; i < number.length(); i++) {
			if (!(number[i] >= '0' && number[i] <= '9')) {
				cout << "Error." << endl;
				return false;
			}
		}
		return true;
	}
}

void main() {
	setlocale(LC_ALL, "rus");

	cout << "4. «Быки и коровы» (дополнительное задание)" << endl;
	cout << "-------------------------------------------------" << endl << endl;

	string uncnown, searching; //вводимые переменные
	int bull = 0, cow = 0; //счетчик быков и коров
	bool good = false; //для проверки корректности ввода
	string f_num = "", s_num = ""; //числа без быков

	while (!good) {
		cout << "Enter intented number: ";
		cin >> uncnown;
		good = err(uncnown);
	}good = false;


	while (!good) {
		cout << "Enter second number: ";
		cin >> searching;
		good = err(searching);
	}good = false;

	for (int i = 0; i < uncnown.length(); i++) { //смотрим бычков и создаем числа без бычков
		if (uncnown[i] == searching[i]) {
			bull++;
		}
		else {
			if (f_num.length() == 0) {   //добавляем первого не быка, если он есть
				f_num += uncnown[i];
				s_num += searching[i];
			}

			for (int j = 0; j < f_num.length(); j++) {
				if (f_num[j] == uncnown[i]) {
					good = false;
					break;
				}
				else {
					good = true;
				}
			}
			if (good) f_num += uncnown[i];  //добавляем цифру только в том случае, если его нету в этом числе



			for (int j = 0; j < s_num.length(); j++) {
				if (s_num[j] == searching[i]) {
					good = false;
					break;
				}
				else {
					good = true;
				}
			}
			if (good) s_num += searching[i];
			
			
		}
	}

	if (bull < 4) {
		for (int i = 0; i < f_num.length(); i++) {
			for (int j = 0; j < s_num.length(); j++) {
				if (f_num[i] == s_num[j]) {
					cow++;
					break;
				}
			}
		}
	}

	cout << "bulls: " << bull << "   cows: " << cow << endl;

	//main();

	//
}