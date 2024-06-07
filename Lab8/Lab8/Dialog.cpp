#include "Dialog.h"
#include "Object.h"
#include "Vector.h"
#include "Event.h"
#include <iostream>
#include <string>
using namespace std;
//конструктор
Dialog::Dialog(void) :Vector()
{
	EndState = 0;
}
//деструктор
Dialog::~Dialog(void) {}
//получение событи€
void Dialog::GetEvent(TEvent& event) {
	string OpInt = "m+-sq?"; //строка содержит коды операций
	string s;
	string param;
	char code;
	cout << "m - создать группу\n+ - добавить объект в группу\n- - удалить объект из группы\nq - конец работы\ns - вывести информацию об элементах группы\n? - вывести информацию о элементе\n";
	cin >> s; code = s[0];//первый символ команды
	if (OpInt.find(code) >= 0)//€вл€етс€ ли символ кодом операции
	{
		event.what = evMessage;
		switch (code)
		{
		case 'm':event.command = cmMake; break;//создать группу
		case '+': event.command = cmAdd; break;//добавить объект в группу
		case '-': event.command = cmDel; break;//удалить объект из группы
		case 's': event.command = cmShow; break;//просмотр группы
		case'q': event.command = cmQuit; break; //конец работы
		case '?': event.command = cmGet; break;
		}
		//выдел€ем параметры команды, если они есть
		if (s.length() > 1)
		{
			param = s.substr(1, s.length() - 1);
			int A = atoi(param.c_str());//преобразуем парметр в число
			event.a = A;//записываем в сообщение
		}
	}
	else event.what = evNothing;//пустое событие
}
int Dialog::Execute()
{
	TEvent event; do {
		EndState = 0;
		GetEvent(event); //получить событие
		HandleEvent(event); //обработать событие
	} while (!Valid());
	return EndState;
}
int Dialog::Valid()
{
	if (EndState == 0) return 0;
	else return 1;
}
void Dialog::ClearEvent(TEvent& event) {
	event.what = evNothing;//пустое событие
}
void Dialog::EndExec()
{
	EndState = 1;
}
//обработчик событий
void Dialog::HandleEvent(TEvent& event)
{
	if (event.what == evMessage)
	{
		switch (event.command)
		{
		case cmMake://создание группы
			size = event.message; //размер группы
			beg = new Object * [size];//выдел€ем пам€ть под массив указателей
			cur = 0; //текуща€ позици€
			ClearEvent(event);//очищаем событие
			break;
		case cmAdd://добавление
			Add();
			ClearEvent(event);
			break;
		case cmDel:Del(); //удаление
			ClearEvent(event);
			break;
		case cmShow:Show(); //просмотр
			ClearEvent(event);
			break;
		case cmQuit:EndExec(); //выход
			ClearEvent(event);
			break;
		case cmGet:
			// обработка команды вывода информации об элементе с номером k
			int k; // извлекаем номер элемента k
			cout << "¬ведите номер элемента ";
			cin >> k;
			k--;  
			if (k >= 0 && k < cur) {
				beg[k]->HandleEvent(event); // выводим информацию об элементе с номером k
			}
			else {
				cout << "Ёлемент с номером " << k << " не найден." << endl;
			}
			ClearEvent(event);
			break;
		};
	};
}