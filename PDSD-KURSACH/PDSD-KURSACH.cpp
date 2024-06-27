#include <iostream>
#include <string>
#include <iomanip>
#include "additional.h"
#include "SetOnNodes.h"
#include "SetOnNodeClass.h"
#include "SetOnList.h"
#include "SetOnSet.h"
#include "SetOnMset.h"
#include "SetOnQueue.h"
int main() {
	setlocale(LC_ALL, "RUS");
	auto times = time(NULL);
	unsigned int start_time;
	unsigned int end_time;
	int SET1_SIZE = inputInt("Введите размер первого множества", 100,100000);
	int SET2_SIZE = SET1_SIZE;
	const int col_width = 25;
	const char delimiter = '-';
	const char row_delimiter = '|';
	std::string headers[] = { "", " Односвязный список ", " Класс список ", " List", " Set", " Multiset", " queue" };
	std::string rows[] = { "Создание множества ", "Мощность   ", "Подмножество A - A ", "Подмножество B - A ", "Равенство A-A ", "Равенство B-A ", "Объединение ", "Пересечение ", "Разность A-B ", "Разность B-A" , "Симметричная разность "};
	std::cout << std::setfill(delimiter) << std::setw((col_width + 36) * 3)<< "" << std::endl;
	std::cout << std::setw(col_width) << std::setfill(' ') << (headers[0]) <<"|";
	for (int i = 1; i < 7; i++) {
	std::cout << std::left << std::setw(col_width) << std::setfill(' ')<< (headers[i]) << "|";
	}
	std::cout << std::endl;
	std::cout << std::setfill(delimiter) << std::setw((col_width + 36) * 3)<< "" << std::endl;
	Node* Set_1;
	SetOnNodeClass Set_2;
	SetOnList Set_3;
	SetOnSet Set_4;
	SetOnMset Set_5;
	SetOnQueue Set_6;
	// создание множества
	std::cout << std::left << std::setw(col_width) << std::setfill(' ') <<rows[0] << row_delimiter;
	// 1
	srand(times);
	start_time = clock();
	Set_1 = create_set(SET1_SIZE, 0, 10 * SET1_SIZE);
	end_time = clock();
	std::cout << std::fixed << std::setprecision(6) << std::right << std::setw(col_width) << std::setfill(' ') << (double(end_time - start_time) /CLOCKS_PER_SEC * 1000) << row_delimiter;
	// 2
	srand(times);
	start_time = clock();
	Set_2.create_set(SET1_SIZE, 0, 10 * SET1_SIZE);
	end_time = clock();
	std::cout << std::fixed << std::setprecision(6) << std::right <<std::setw(col_width) << std::setfill(' ') << (double(end_time - start_time) /CLOCKS_PER_SEC * 1000) << row_delimiter;
	// 3
	srand(times);
	start_time = clock();
	Set_3.create_set(SET1_SIZE, 0, 10 * SET1_SIZE);
	end_time = clock();
	std::cout << std::fixed << std::setprecision(6) << std::right <<std::setw(col_width) << std::setfill(' ') << (double(end_time - start_time) /CLOCKS_PER_SEC * 1000) << row_delimiter;
	// 4
	srand(times);
	start_time = clock();
	Set_4.create_set(SET1_SIZE, 0, 10 * SET1_SIZE);
	end_time = clock();
	std::cout << std::fixed << std::setprecision(6) << std::right <<std::setw(col_width) << std::setfill(' ') << (double(end_time - start_time) /CLOCKS_PER_SEC * 1000) << row_delimiter;
	// 5
	srand(times);
	start_time = clock();
	Set_5.create_set(SET1_SIZE, 0, 10 * SET1_SIZE);
	end_time = clock();
	std::cout << std::fixed << std::setprecision(6) << std::right <<std::setw(col_width) << std::setfill(' ') << (double(end_time - start_time) /CLOCKS_PER_SEC * 1000) << row_delimiter;
	// 6
	srand(times);
	start_time = clock();
	Set_6.create_set(SET1_SIZE, 0, 10 * SET1_SIZE);
	end_time = clock();
	std::cout << std::fixed << std::setprecision(6) << std::right << std::setw(col_width) << std::setfill(' ') << (double(end_time - start_time) /CLOCKS_PER_SEC * 1000) << row_delimiter;
	//
	std::cout << std::endl;
	std::cout << std::setfill(delimiter) << std::setw((col_width + 36) * 3)<< "" << std::endl;
	// мощность множества
	std::cout << std::left << std::setw(col_width) << std::setfill(' ') <<rows[1] << row_delimiter;
	// 1
	start_time = clock();
	set_size(Set_1);
	end_time = clock();
	std::cout << std::fixed << std::setprecision(6) << std::right <<std::setw(col_width) << std::setfill(' ') << (double(end_time - start_time) /CLOCKS_PER_SEC * 1000) << row_delimiter;
	// 2
	start_time = clock();
	Set_2.set_size();
	end_time = clock();
	std::cout << std::fixed << std::setprecision(6) << std::right <<std::setw(col_width) << std::setfill(' ') << (double(end_time - start_time) /CLOCKS_PER_SEC * 1000) << row_delimiter;
	// 3
	start_time = clock();
	Set_3.set_size();
	end_time = clock();
	std::cout << std::fixed << std::setprecision(6) << std::right <<std::setw(col_width) << std::setfill(' ') << (double(end_time - start_time) /CLOCKS_PER_SEC * 1000) << row_delimiter;
	// 4
	start_time = clock();
	Set_4.set_size();
	end_time = clock();
	std::cout << std::fixed << std::setprecision(6) << std::right <<std::setw(col_width) << std::setfill(' ') << (double(end_time - start_time) /CLOCKS_PER_SEC * 1000) << row_delimiter;
	// 5
	start_time = clock();
	Set_5.set_size();
	end_time = clock();
	std::cout << std::fixed << std::setprecision(6) << std::right <<std::setw(col_width) << std::setfill(' ') << (double(end_time - start_time) /CLOCKS_PER_SEC * 1000) << row_delimiter;
	// 6
	start_time = clock();
	Set_6.set_size();
	end_time = clock();
	std::cout << std::fixed << std::setprecision(6) << std::right <<std::setw(col_width) << std::setfill(' ') << (double(end_time - start_time) /CLOCKS_PER_SEC * 1000) << row_delimiter;
	//
	std::cout << std::endl;
	std::cout << std::setfill(delimiter) << std::setw((col_width + 36) * 3)	<< "" << std::endl;
	// А подможество А
	std::cout << std::left << std::setw(col_width) << std::setfill(' ') <<	rows[2] << row_delimiter;
	// 1
	start_time = clock();
	check_subset(Set_1, Set_1);
	end_time = clock();
	std::cout << std::fixed << std::setprecision(6) << std::right <<std::setw(col_width) << std::setfill(' ') << (double(end_time - start_time) /CLOCKS_PER_SEC * 1000) << row_delimiter;
	// 2
	start_time = clock();
	Set_2.check_subset(Set_2);
	end_time = clock();
	std::cout << std::fixed << std::setprecision(6) << std::right <<std::setw(col_width) << std::setfill(' ') << (double(end_time - start_time) /CLOCKS_PER_SEC * 1000) << row_delimiter;
	// 3
	start_time = clock();
	Set_3.check_subset(Set_3);
	end_time = clock();
	std::cout << std::fixed << std::setprecision(6) << std::right <<std::setw(col_width) << std::setfill(' ') << (double(end_time - start_time) /CLOCKS_PER_SEC * 1000) << row_delimiter;
	// 4
	start_time = clock();
	Set_4.check_subset(Set_4);
	end_time = clock();
	std::cout << std::fixed << std::setprecision(6) << std::right <<std::setw(col_width) << std::setfill(' ') << (double(end_time - start_time) /CLOCKS_PER_SEC * 1000) << row_delimiter;
	// 5
	start_time = clock();
	Set_5.check_subset(Set_5);
	end_time = clock();
	std::cout << std::fixed << std::setprecision(6) << std::right <<std::setw(col_width) << std::setfill(' ') << (double(end_time - start_time) /CLOCKS_PER_SEC * 1000) << row_delimiter;
	// 6
	start_time = clock();
	Set_6.check_subset(Set_6);
	end_time = clock();
	std::cout << std::fixed << std::setprecision(6) << std::right <<std::setw(col_width) << std::setfill(' ') << (double(end_time - start_time) /CLOCKS_PER_SEC * 1000) << row_delimiter;
	//
	std::cout << std::endl;
	std::cout << std::setfill(delimiter) << std::setw((col_width + 36) * 3)	<< "" << std::endl;
	// А подможество B
	times = time(NULL);
	std::cout << std::left << std::setw(col_width) << std::setfill(' ') << rows[3] << row_delimiter;
	// 1
	Node* Set_11;
	srand(times);
	Set_11 = create_set(SET2_SIZE, 0, 10 * SET2_SIZE);
	start_time = clock();
	check_subset(Set_1, Set_11);
	end_time = clock();
	std::cout << std::fixed << std::setprecision(6) << std::right <<std::setw(col_width) << std::setfill(' ') << (double(end_time - start_time) /CLOCKS_PER_SEC * 1000) << row_delimiter;
	// 2
	SetOnNodeClass Set_22;
	srand(times);
	Set_22.create_set(SET2_SIZE, 0, 10 * SET2_SIZE);
	start_time = clock();
	Set_2.check_subset(Set_22);
	end_time = clock();
	std::cout << std::fixed << std::setprecision(6) << std::right <<std::setw(col_width) << std::setfill(' ') << (double(end_time - start_time) /CLOCKS_PER_SEC * 1000) << row_delimiter;
	// 3
	SetOnList Set_33;
	srand(times);
	Set_33.create_set(SET2_SIZE, 0, 10 * SET2_SIZE);
	start_time = clock();
	Set_3.check_subset(Set_33);
	end_time = clock();
	std::cout << std::fixed << std::setprecision(6) << std::right <<std::setw(col_width) << std::setfill(' ') << (double(end_time - start_time) /CLOCKS_PER_SEC * 1000) << row_delimiter;
	// 4
	SetOnSet Set_44;
	srand(times);
	Set_44.create_set(SET2_SIZE, 0, 10 * SET2_SIZE);
	start_time = clock();
	Set_4.check_subset(Set_44);
	end_time = clock();
	std::cout << std::fixed << std::setprecision(6) << std::right <<std::setw(col_width) << std::setfill(' ') << (double(end_time - start_time) /CLOCKS_PER_SEC * 1000) << row_delimiter;
	// 5
	SetOnMset Set_55;
	srand(times);
	Set_55.create_set(SET2_SIZE, 0, 10 * SET2_SIZE);
	start_time = clock();
	Set_5.check_subset(Set_55);
	end_time = clock();
	std::cout << std::fixed << std::setprecision(6) << std::right <<std::setw(col_width) << std::setfill(' ') << (double(end_time - start_time) /CLOCKS_PER_SEC * 1000) << row_delimiter;
	// 6
	SetOnQueue Set_66;
	srand(times);
	Set_66.create_set(SET2_SIZE, 0, 10 * SET2_SIZE);
	start_time = clock();
	Set_6.check_subset(Set_66);
	end_time = clock();
	std::cout << std::fixed << std::setprecision(6) << std::right <<std::setw(col_width) << std::setfill(' ') << (double(end_time - start_time) /CLOCKS_PER_SEC * 1000) << row_delimiter;
	//
	std::cout << std::endl;
	std::cout << std::setfill(delimiter) << std::setw((col_width + 36) * 3) << "" << std::endl;
	// А равенство A
	std::cout << std::left << std::setw(col_width) << std::setfill(' ') <<rows[4] << row_delimiter;
	// 1
	start_time = clock();
	equality_set(Set_1, Set_1);
	end_time = clock();
	std::cout << std::fixed << std::setprecision(6) << std::right <<std::setw(col_width) << std::setfill(' ') << (double(end_time - start_time) /CLOCKS_PER_SEC * 1000) << row_delimiter;
	// 2
	start_time = clock();
	Set_2.equality_set(Set_2);
	end_time = clock();
	std::cout << std::fixed << std::setprecision(6) << std::right <<std::setw(col_width) << std::setfill(' ') << (double(end_time - start_time) /CLOCKS_PER_SEC * 1000) << row_delimiter;
	// 3
	start_time = clock();
	Set_3.equality_set(Set_3);
	end_time = clock();
	std::cout << std::fixed << std::setprecision(6) << std::right <<std::setw(col_width) << std::setfill(' ') << (double(end_time - start_time) /CLOCKS_PER_SEC * 1000) << row_delimiter;
	// 4
	start_time = clock();
	Set_4.equality_set(Set_4);
	end_time = clock();
	std::cout << std::fixed << std::setprecision(6) << std::right <<std::setw(col_width) << std::setfill(' ') << (double(end_time - start_time) /CLOCKS_PER_SEC * 1000) << row_delimiter;
	// 5
	start_time = clock();
	Set_5.equality_set(Set_5);
	end_time = clock();
	std::cout << std::fixed << std::setprecision(6) << std::right <<std::setw(col_width) << std::setfill(' ') << (double(end_time - start_time) /CLOCKS_PER_SEC * 1000) << row_delimiter;
	// 6
	start_time = clock();
	Set_6.equality_set(Set_6);
	end_time = clock();
	std::cout << std::fixed << std::setprecision(6) << std::right <<std::setw(col_width) << std::setfill(' ') << (double(end_time - start_time) /CLOCKS_PER_SEC * 1000) << row_delimiter;
	//
	std::cout << std::endl;
	std::cout << std::setfill(delimiter) << std::setw((col_width + 36) * 3)	<< "" << std::endl;
	// А равенство B
	std::cout << std::left << std::setw(col_width) << std::setfill(' ') <<	rows[5] << row_delimiter;
	// 1
	start_time = clock();
	equality_set(Set_1, Set_11);
	end_time = clock();
	std::cout << std::fixed << std::setprecision(6) << std::right <<std::setw(col_width) << std::setfill(' ') << (double(end_time - start_time) /CLOCKS_PER_SEC * 1000) << row_delimiter;
	// 2
	start_time = clock();
	Set_2.equality_set(Set_22);
	end_time = clock();
	std::cout << std::fixed << std::setprecision(6) << std::right <<std::setw(col_width) << std::setfill(' ') << (double(end_time - start_time) /CLOCKS_PER_SEC * 1000) << row_delimiter;
	// 3
	start_time = clock();
	Set_3.equality_set(Set_33);
	end_time = clock();
	std::cout << std::fixed << std::setprecision(6) << std::right <<std::setw(col_width) << std::setfill(' ') << (double(end_time - start_time) /CLOCKS_PER_SEC * 1000) << row_delimiter;
	// 4
	start_time = clock();
	Set_4.equality_set(Set_44);
	end_time = clock();
	std::cout << std::fixed << std::setprecision(6) << std::right <<std::setw(col_width) << std::setfill(' ') << (double(end_time - start_time) /CLOCKS_PER_SEC * 1000) << row_delimiter;
	// 5
	start_time = clock();
	Set_5.equality_set(Set_55);
	end_time = clock();
	std::cout << std::fixed << std::setprecision(6) << std::right <<std::setw(col_width) << std::setfill(' ') << (double(end_time - start_time) /CLOCKS_PER_SEC * 1000) << row_delimiter;
	// 6
	start_time = clock();
	Set_6.equality_set(Set_66);
	end_time = clock();
	std::cout << std::fixed << std::setprecision(6) << std::right <<std::setw(col_width) << std::setfill(' ') << (double(end_time - start_time) /CLOCKS_PER_SEC * 1000) << row_delimiter;
	//
	std::cout << std::endl;
	std::cout << std::setfill(delimiter) << std::setw((col_width + 36) * 3)	<< "" << std::endl;
	// объединение
	std::cout << std::left << std::setw(col_width) << std::setfill(' ') <<rows[6] << row_delimiter;
	// 1
	start_time = clock();
	set_union(Set_1, Set_11);
	end_time = clock();
	std::cout << std::fixed << std::setprecision(6) << std::right <<std::setw(col_width) << std::setfill(' ') << (double(end_time - start_time) /CLOCKS_PER_SEC * 1000) << row_delimiter;
	// 2
	start_time = clock();
	Set_2.set_union(Set_22);
	end_time = clock();
	std::cout << std::fixed << std::setprecision(6) << std::right <<std::setw(col_width) << std::setfill(' ') << (double(end_time - start_time) /CLOCKS_PER_SEC * 1000) << row_delimiter;
	// 3
	start_time = clock();
	Set_3.set_union(Set_33);
	end_time = clock();
	std::cout << std::fixed << std::setprecision(6) << std::right <<std::setw(col_width) << std::setfill(' ') << (double(end_time - start_time) /CLOCKS_PER_SEC * 1000) << row_delimiter;
	// 4
	start_time = clock();
	Set_4.set_union(Set_44);
	end_time = clock();
	std::cout << std::fixed << std::setprecision(6) << std::right <<std::setw(col_width) << std::setfill(' ') << (double(end_time - start_time) /CLOCKS_PER_SEC * 1000) << row_delimiter;
	// 5
	start_time = clock();
	Set_5.set_union(Set_55);
	end_time = clock();
	std::cout << std::fixed << std::setprecision(6) << std::right <<std::setw(col_width) << std::setfill(' ') << (double(end_time - start_time) /CLOCKS_PER_SEC * 1000) << row_delimiter;
	// 6
	start_time = clock();
	Set_6.set_union(Set_66);
	end_time = clock();
	std::cout << std::fixed << std::setprecision(6) << std::right <<std::setw(col_width) << std::setfill(' ') << (double(end_time - start_time) /CLOCKS_PER_SEC * 1000) << row_delimiter;
	//
	std::cout << std::endl;
	std::cout << std::setfill(delimiter) << std::setw((col_width + 36) * 3)	<< "" << std::endl;
	// пересечение
	std::cout << std::left << std::setw(col_width) << std::setfill(' ') <<	rows[7] << row_delimiter;
	// 1
	start_time = clock();
	set_intersection(Set_1, Set_11);
	end_time = clock();
	std::cout << std::fixed << std::setprecision(6) << std::right <<std::setw(col_width) << std::setfill(' ') << (double(end_time - start_time) /CLOCKS_PER_SEC * 1000) << row_delimiter;
	// 2
	start_time = clock();
	Set_2.set_intersection(Set_22);
	end_time = clock();
	std::cout << std::fixed << std::setprecision(6) << std::right <<std::setw(col_width) << std::setfill(' ') << (double(end_time - start_time) /CLOCKS_PER_SEC * 1000) << row_delimiter;
	// 3
	start_time = clock();
	Set_3.set_intersection(Set_33);
	end_time = clock();
	std::cout << std::fixed << std::setprecision(6) << std::right <<std::setw(col_width) << std::setfill(' ') << (double(end_time - start_time) /CLOCKS_PER_SEC * 1000) << row_delimiter;
	// 4
	start_time = clock();
	Set_4.set_intersection(Set_44);
	end_time = clock();
	std::cout << std::fixed << std::setprecision(6) << std::right <<std::setw(col_width) << std::setfill(' ') << (double(end_time - start_time) /CLOCKS_PER_SEC * 1000) << row_delimiter;
	// 5
	start_time = clock();
	Set_5.set_intersection(Set_55);
	end_time = clock();
	std::cout << std::fixed << std::setprecision(6) << std::right <<std::setw(col_width) << std::setfill(' ') << (double(end_time - start_time) /CLOCKS_PER_SEC * 1000) << row_delimiter;
	// 6
	start_time = clock();
	Set_6.set_intersection(Set_66);
	end_time = clock();
	std::cout << std::fixed << std::setprecision(6) << std::right <<std::setw(col_width) << std::setfill(' ') << (double(end_time - start_time) /CLOCKS_PER_SEC * 1000) << row_delimiter;
	//
	std::cout << std::endl;
	std::cout << std::setfill(delimiter) << std::setw((col_width + 36) * 3)	<< "" << std::endl;
	// Разность A-B
	std::cout << std::left << std::setw(col_width) << std::setfill(' ') <<	rows[8] << row_delimiter;
	// 1
	start_time = clock();
	set_difference(Set_1, Set_11);
	end_time = clock();
	std::cout << std::fixed << std::setprecision(6) << std::right <<std::setw(col_width) << std::setfill(' ') << (double(end_time - start_time) /CLOCKS_PER_SEC * 1000) << row_delimiter;
	// 2
	start_time = clock();
	Set_2.set_difference(Set_22);
	end_time = clock();
	std::cout << std::fixed << std::setprecision(6) << std::right <<std::setw(col_width) << std::setfill(' ') << (double(end_time - start_time) /CLOCKS_PER_SEC * 1000) << row_delimiter;
	// 3
	start_time = clock();
	Set_3.set_difference(Set_33);
	end_time = clock();
	std::cout << std::fixed << std::setprecision(6) << std::right <<std::setw(col_width) << std::setfill(' ') << (double(end_time - start_time) /CLOCKS_PER_SEC * 1000) << row_delimiter;
	// 4
	start_time = clock();
	Set_4.set_difference(Set_44);
	end_time = clock();
	std::cout << std::fixed << std::setprecision(6) << std::right <<std::setw(col_width) << std::setfill(' ') << (double(end_time - start_time) /CLOCKS_PER_SEC * 1000) << row_delimiter;
	// 5
	start_time = clock();
	Set_5.set_difference(Set_55);
	end_time = clock();
	std::cout << std::fixed << std::setprecision(6) << std::right <<std::setw(col_width) << std::setfill(' ') << (double(end_time - start_time) /CLOCKS_PER_SEC * 1000) << row_delimiter;
	// 6
	start_time = clock();
	Set_6.set_difference(Set_66);
	end_time = clock();
	std::cout << std::fixed << std::setprecision(6) << std::right <<std::setw(col_width) << std::setfill(' ') << (double(end_time - start_time) /CLOCKS_PER_SEC * 1000) << row_delimiter;
	//
	std::cout << std::endl;
	std::cout << std::setfill(delimiter) << std::setw((col_width + 36) * 3)	<< "" << std::endl;
	// Разность B-A
	std::cout << std::left << std::setw(col_width) << std::setfill(' ') <<	rows[9] << row_delimiter;
	// 1
	start_time = clock();
	set_difference(Set_11, Set_1);
	end_time = clock();
	std::cout << std::fixed << std::setprecision(6) << std::right <<std::setw(col_width) << std::setfill(' ') << (double(end_time - start_time) /CLOCKS_PER_SEC * 1000) << row_delimiter;
	// 2
	start_time = clock();
	Set_22.set_difference(Set_2);
	end_time = clock();
	std::cout << std::fixed << std::setprecision(6) << std::right <<std::setw(col_width) << std::setfill(' ') << (double(end_time - start_time) /CLOCKS_PER_SEC * 1000) << row_delimiter;
	// 3
	start_time = clock();
	Set_33.set_difference(Set_3);
	end_time = clock();
	std::cout << std::fixed << std::setprecision(6) << std::right <<std::setw(col_width) << std::setfill(' ') << (double(end_time - start_time) /CLOCKS_PER_SEC * 1000) << row_delimiter;
	// 4
	start_time = clock();
	Set_44.set_difference(Set_4);
	end_time = clock();
	std::cout << std::fixed << std::setprecision(6) << std::right <<std::setw(col_width) << std::setfill(' ') << (double(end_time - start_time) /CLOCKS_PER_SEC * 1000) << row_delimiter;
	// 5
	start_time = clock();
	Set_55.set_difference(Set_5);
	end_time = clock();
	std::cout << std::fixed << std::setprecision(6) << std::right <<std::setw(col_width) << std::setfill(' ') << (double(end_time - start_time) /CLOCKS_PER_SEC * 1000) << row_delimiter;
	// 6
	start_time = clock();
	Set_66.set_difference(Set_6);
	end_time = clock();
	std::cout << std::fixed << std::setprecision(6) << std::right <<std::setw(col_width) << std::setfill(' ') << (double(end_time - start_time) /CLOCKS_PER_SEC * 1000) << row_delimiter;
	//
	std::cout << std::endl;
	std::cout << std::setfill(delimiter) << std::setw((col_width + 36) * 3)	<< "" << std::endl;
	// Симметричная разность A-B
	std::cout << std::left << std::setw(col_width) << std::setfill(' ') <<	rows[10] << row_delimiter;
	// 1
	start_time = clock();
	set_symmetrical_difference(Set_1, Set_11);
	end_time = clock();
	std::cout << std::fixed << std::setprecision(6) << std::right <<std::setw(col_width) << std::setfill(' ') << (double(end_time - start_time) /CLOCKS_PER_SEC * 1000) << row_delimiter;
	// 2
	start_time = clock();
	Set_2.set_symmetrical_difference(Set_22);
	end_time = clock();
	std::cout << std::fixed << std::setprecision(6) << std::right <<std::setw(col_width) << std::setfill(' ') << (double(end_time - start_time) /CLOCKS_PER_SEC * 1000) << row_delimiter;
	// 3
	start_time = clock();
	Set_3.set_symmetrical_difference(Set_33);
	end_time = clock();
	std::cout << std::fixed << std::setprecision(6) << std::right <<std::setw(col_width) << std::setfill(' ') << (double(end_time - start_time) /CLOCKS_PER_SEC * 1000) << row_delimiter;
	// 4
	start_time = clock();
	Set_4.set_symmetrical_difference(Set_44);
	end_time = clock();
	std::cout << std::fixed << std::setprecision(6) << std::right <<std::setw(col_width) << std::setfill(' ') << (double(end_time - start_time) /CLOCKS_PER_SEC * 1000) << row_delimiter;
	// 5
	start_time = clock();
	Set_5.set_symmetrical_difference(Set_55);
	end_time = clock();
	std::cout << std::fixed << std::setprecision(6) << std::right <<std::setw(col_width) << std::setfill(' ') << (double(end_time - start_time) /CLOCKS_PER_SEC * 1000) << row_delimiter;
	// 6
	start_time = clock();
	Set_6.set_symmetrical_difference(Set_66);
	end_time = clock();
	std::cout << std::fixed << std::setprecision(6) << std::right <<std::setw(col_width) << std::setfill(' ') << (double(end_time - start_time) /CLOCKS_PER_SEC * 1000) << row_delimiter;
	//
	std::cout << std::endl;
	std::cout << std::setfill(delimiter) << std::setw((col_width + 36) * 3)	<< "" << std::endl;
	}
