#include <stdio.h>
#include <math.h>
#include <locale.h>

void menu();
void weightIndex();
void maxOf4digits();
void seasons();
void Routes();
void LCS();

int userInput(char message, int minDigit, int maxDigit);

int main(int argc, char* argv[])
{
	char* locale = setlocale(LC_ALL, "RU");
	setlocale(LC_NUMERIC, "C");

	int selector = 100;

	do
	{
		menu();
		scanf_s("%i", &selector);
		switch (selector) {
		case 1:
			weightIndex();
			break;
		case 2:
			maxOf4digits();
			break;
		case 3:
			seasons();
			break;
		case 4:
			Routes();
		case 5:
			LCS();
		case 0:
			printf("До свидания!");
			break;
		default:
			printf("Выберите 0-5\n");
		}
	} while (selector != 0);
	return 0;
}

void menu() {
	printf("1 - Индекс массы тела\n");
	printf("2 - Максимальное из 4 цифр\n");
	printf("3 - Название времени года\n");
	printf("4 - Маршруты\n");
	printf("5 - LCS\n");
	printf("0 - Выход\n");
}

void weightIndex() {

	int weight, stature;
	double index;

	printf("Введите вес (кг): ");
	scanf_s("%i", &weight);
	printf("Введите рост (см): ");
	scanf_s("%i", &stature);

	index = (double)weight / pow((double)stature / 100, 2);
	printf("Индекс массы тела = %lf\n\n", index);

	return 0;
}

void maxOf4digits() {

	int digit, maxDigit = 0;
	int cycle = 4;

	for (int i = 1; i <= cycle; i++) {
		printf("Введите %i число: ", i);
		scanf_s("%i", &digit);
		if (digit >= maxDigit) {
			maxDigit = digit;
		}
	}
	printf("Максимальное число = %i\n\n", maxDigit);

	return 0;
}

void seasons() {
	int month = 0;

	//do {
	//	printf("Введите номер месяца (1-12): ");
	//	while (scanf_s("%i", &month) != 1) {
	//		printf("Неверный символ!");
	//		while (getchar() != '\n');
	//	}
	//} while (month < 1 || month > 12);

	month = userInput("Введите номер месяца (1-12): ", 1, 12);

	switch (month) {
	case 12:
	case 1:
	case 2:
		printf("Время года - зима\n\n");;
		break;
	case 3:
	case 4:
	case 5:
		printf("Время года - весна\n\n");;
		break;
	case 6:
	case 7:
	case 8:
		printf("Время года - лето\n\n");;
		break;
	case 9:
	case 10:
	case 11:
		printf("Время года - осень\n\n");;
	}
	return 0;
}

int userInput(char message, int minDigit, int maxDigit) {
	int digit;
	do {
		printf(message);
		while (scanf_s("%i", &digit) != 1) {
			printf("Неверный символ!");
			while (getchar() != '\n');
		}
	} while (digit < minDigit || digit > maxDigit);

	return digit;
}

