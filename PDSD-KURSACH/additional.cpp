#include "additional.h"
int inputInt(const char* prompt, int m = INT_MIN, int M = INT_MAX)
{
	int N;
	for (;;) {
		std::cout << prompt << " (����� �� " << m << " �� " << M << "): " <<
			std::flush;
		if ((std::cin >> N).good() && (m <= N) && (N <= M)) return N;
		if (std::cin.fail()) {
			std::cin.clear();
			std::cout << "������������ ��������� ������, ��������� ����.\n";
		}
		else {
			std::cout << "��������� ������ ��� �������� ���������� ��������. ��������� ����.\n";
		}
		std::cin.ignore(LONG_MAX, '\n');
	}
}