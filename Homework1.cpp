// Homework1.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <stdlib.h>
using namespace std;

typedef struct sudoku {
	int** a;
	int** mark;
	int** back;
}sudoku;


void input(sudoku *s) {
	cout << "----------------------------------\n";
	for (int i = 1; i <= 9; i++)
	{
		cout << "| ";
		for (int j = 1; j <= 9; j++) {
			printf("%d  ", s->a[i][j]);
			if (j%3 == 0)	cout << "| ";
		}
		cout << "\n";
		if (i % 3 == 0) {
			cout << "----------------------------------\n";
			
		}
	}
}
void inputMark(sudoku* s) {
	cout << "----------------------------------\n";
	for (int i = 1; i <= 9; i++)
	{
		cout << "| ";
		for (int j = 1; j <= 9; j++) {
			printf("%d  ", s->mark[i][j]);
			if (j % 3 == 0)	cout << "| ";
		}
		cout << "\n";
		if (i % 3 == 0) {
			cout << "----------------------------------\n";

		}
	}
}
void inputBack(sudoku* s) {
	cout << "----------------------------------\n";
	for (int i = 1; i <= 9; i++)
	{
		cout << "| ";
		for (int j = 1; j <= 9; j++) {
			printf("%d  ", s->back[i][j]);
			if (j % 3 == 0)	cout << "| ";
		}
		cout << "\n";
		if (i % 3 == 0) {
			cout << "----------------------------------\n";

		}
	}
}

void init(sudoku *s) {
	s->a = (int**)malloc(sizeof(int*) * 10);
	for (int i = 0; i < 10; i++) {
		s->a[i] = (int*)malloc(sizeof(int) * 10);
		for (int j = 0; j < 10; j++)
			s->a[i][j] = 0;
	}
	s->mark = (int**)malloc(sizeof(int*) * 10);
	for (int i = 0; i < 10; i++) {
		s->mark[i] = (int*)malloc(sizeof(int) * 10);
		for (int j = 0; j < 10; j++)
			s->mark[i][j] = 1;
	}
	s->back = (int**)malloc(sizeof(int*) * 10);
	for (int i = 0; i < 10; i++) {
		s->back[i] = (int*)malloc(sizeof(int) * 10);
		for (int j = 0; j < 10; j++)
			s->back[i][j] = 0;
	}
}

void addValue(sudoku* s, int row, int line, int value) {
	s->a[row][line] = value;
}

void addValues(sudoku* s, int row, int* values) {
	for (int i = 1; i < 10; i++)
	{
		s->a[row][i] = values[i];
		if (values[i] != 0) {
			s->mark[row][i] = 0;
		}
	}
}

int findFirstRowElem(sudoku* s, int firstRow, int firstLine) {
	for (int line = firstLine; line < 10; line++)
	{
		if (s->mark[firstRow][line] != 0)
			return line;
	}
	int row = firstRow + 1;
	for (int line = 1; line < 10; line++)
	{
		if (s->mark[row][line] != 0)
			return line;
	}
	return 9;
}

int findFirstLineElem(sudoku* s, int firstRow, int firstLine) {
	for (int line = firstLine; line < 10; line++)
	{
		if (s->mark[firstRow][line] != 0)
			return firstRow;
	}
	return firstRow + 1;
}

int Sudoku(sudoku* s, int row, int line, int mark) {
	if (s->mark[row][line] == 0) {
		return 1;
	}
	int flag = 1;
	for (int i = mark; i < 10; i++) {
		s->a[row][line] = i;
		flag = 1;
		for (int ro = 1; ro < 10; ro++)
		{
			if (ro == row) continue;
			if (s->a[ro][line] == s->a[row][line]) {
				flag = 0;
				break;
			}
		}
		if (!flag)
		{
			if (s->a[row][line] == 9) {
				s->a[row][line] = 0;
				return 0;
			}
			continue;
		}
		for (int li = 1; li < 10; li++)
		{
			if (li == line) continue;
			if (s->a[row][li] == s->a[row][line]) {
				flag = 0;
				break;
			}
		}
		if (!flag)
		{
			if (s->a[row][line] == 9) {
				s->a[row][line] = 0;
				return 0;
			}

			continue;
		}
		int r = (row - 1) / 3;
		int l = (line - 1) / 3;
		switch (r)
		{
		case 0:
			switch (l)
			{
			case 0:
				for (int i = 1; i < 4; i++) {
					for (int j = 1; j < 4; j++)
					{
						if (i == row && j == line) continue;
						if (s->a[row][line] == s->a[i][j]) {
							flag = 0;
							break;
						}
					}
				}
				break;
			case 1:
				for (int i = 1; i < 4; i++) {
					for (int j = 4; j < 7; j++)
					{
						if (i == row && j == line) continue;
						if (s->a[row][line] == s->a[i][j]) {
							flag = 0;
							break;
						}
					}
				}
				break;
			case 2:
				for (int i = 1; i < 4; i++) {
					for (int j = 7; j < 10; j++)
					{
						if (i == row && j == line) continue;
						if (s->a[row][line] == s->a[i][j]) {
							flag = 0;
							break;
						}
					}
				}
				break;
			}
			break;
		case 1:
			switch (l)
			{
			case 0:
				for (int i = 4; i < 7; i++) {
					for (int j = 1; j < 4; j++)
					{
						if (i == row && j == line) continue;
						if (s->a[row][line] == s->a[i][j]) {
							flag = 0;
							break;
						}
					}
				}
				break;
			case 1:
				for (int i = 4; i < 7; i++) {
					for (int j = 4; j < 7; j++)
					{
						if (i == row && j == line) continue;
						if (s->a[row][line] == s->a[i][j]) {
							flag = 0;
							break;
						}
					}
				}
				break;
			case 2:
				for (int i = 4; i < 7; i++) {
					for (int j = 7; j < 10; j++)
					{
						if (i == row && j == line) continue;
						if (s->a[row][line] == s->a[i][j]) {
							flag = 0;
							break;
						}
					}
				}
				break;
			}
			break;
		case 2:
			switch (l)
			{
			case 0:
				for (int i = 7; i < 10; i++) {
					for (int j = 1; j < 4; j++)
					{
						if (i == row && j == line) continue;
						if (s->a[row][line] == s->a[i][j]) {
							flag = 0;
							break;
						}
					}
				}
				break;
			case 1:
				for (int i = 7; i < 10; i++) {
					for (int j = 4; j < 7; j++)
					{
						if (i == row && j == line) continue;
						if (s->a[row][line] == s->a[i][j]) {
							flag = 0;
							break;
						}
					}
				}
				break;
			case 2:
				for (int i = 7; i < 10; i++) {
					for (int j = 7; j < 10; j++)
					{
						if (i == row && j == line) continue;
						if (s->a[row][line] == s->a[i][j]) {
							flag = 0;
							break;
						}
					}
				}
				break;
			}
		}
		if (!flag && s->a[row][line] == 9) {
			s->a[row][line] = 0;
			return 0;
		}
		if (flag) {
			s->mark[row][line] = s->a[row][line];
			return 1;
		}
	}
}

void back(int* row, int* line, int firstRow, int firstLine) {
	//if (*line > 1) {
	//	(*line)--;
	//}
	//else
	//{	
	//	if (*row == 1)
	//	{
	//		return;
	//	}
	//	(*row)--;
	//	*line = 9;
	//}
	if (*row > firstRow) {
		if (*line > 1)
		{
			(*line)--;
		}
		else
		{
			(*row)--;
			*line = 9;
		}
	}
	else
	{
		if (*line > firstLine) {
			(*line)--;
		}
		else
		{
			return;
		}
	}

}

int creatSudoku(sudoku* s, int firstRow, int firstLine) {
	int flag = 1;

	int firstRowElem = findFirstRowElem(s, firstRow, firstLine);
	int firstLineElem = findFirstLineElem(s, firstRow, firstLine);

	int isFirstLine = 1;
	for (int row = firstRow;  row < 10; row++)
	{
		for (int line = 1; line < 10; line++)
		{
			if (row == firstRow && isFirstLine) {
				line = firstLine;
				isFirstLine = 0;
			}
			flag = Sudoku(s, row, line, s->mark[row][line]);
			if (!flag)
			{
				int isInitNum = 0;
				while (!flag)
				{
					if (isInitNum) {
						if (s->mark[row][line] == 0) {
							back(&row, &line, firstRow, firstLine);
							isInitNum = 1;
							continue;
						}
						if (s->mark[row][line] >= 9)
						{
							s->a[row][line] = 0;
							s->mark[row][line] = 1;
							back(&row, &line, firstRow, firstLine);
							isInitNum = 1;
							continue;
						}
						isInitNum = 0;
						int value = s->mark[row][line] + 1;
						flag = Sudoku(s, row, line, value);
						if (row == firstRowElem && line == firstLineElem && !flag) {
							cout << "NO!!!\n";
							return 0;
						}
						continue;
					}
					s->mark[row][line] = 1;
					back(&row, &line,firstRow, firstLine);
					if (s->mark[row][line] == 0) {
						back(&row, &line, firstRow, firstLine);
						isInitNum = 1;
						continue;
					}
					if (s->mark[row][line] >= 9)
					{
						s->a[row][line] = 0;
						s->mark[row][line] = 1;
						back(&row, &line, firstRow, firstLine);
						isInitNum = 1;
						continue;
					}
					
					int value = s->mark[row][line] + 1;
					flag = Sudoku(s, row, line, value);
					if (row == firstRowElem && line == firstLineElem && !flag) {
						cout << "NO!!!\n";
						return 0;
					}
				}
			}
		}
	}
	return 1;
}

void findAllSudoku(sudoku* s) {
	int flag = 0;
	int row;
	int line;
	int count = 0;
	for (row = 9; row > 0; row--)
	{
		for (line = 9; line > 0; line--)
		{
			if (s->mark[row][line] == 0)	continue;
			if (s->mark[row][line] == 9) {
				s->a[row][line] = 0;
				s->mark[row][line] = 1;
				continue;
			}
			s->mark[row][line]++;
			s->a[row][line] = 0;
			for (int backRow = 9; backRow >= row; backRow--)
			{
				for (int backLine = 9; backLine > 1; backLine--)
				{
					if (row == backRow && backLine == line)	break;
					if (s->mark[backRow][backLine] == 0)	continue;
					s->mark[backRow][backLine] = 1;
					s->a[backRow][backLine] = 0;
				}
			}
			flag = creatSudoku(s, row, line);
			if (flag)
			{
				cout << "*********************************************" << ++count << endl;
				input(s);
			}
		}
	}
}



int main(){
	sudoku s;
	init(&s);
//	addValue(&s, 1, 2, 6);
	int row1[10] = {0,0,4,0,0,0,0,0,9,0};
	int row2[10] = {0,9,0,5,8,0,6,2,0,1};
	int row3[10] = {0,0,2,0,0,3,0,0,8,0};
	int row4[10] = {0,0,8,0,0,0,0,0,5,0};
	int row5[10] = {0,0,0,1,0,0,0,6,0,0};
	int row6[10] = {0,0,7,0,0,0,0,0,1,0};
	int row7[10] = {0,0,9,0,0,5,0,0,2,0};
	int row8[10] = {0,3,0,7,4,0,9,5,0,0};
	int row9[10] = {0,0,6,0,0,0,0,0,0,0};
	//int row1[10] =  {0, 1, 4, 8, 2, 7, 5, 3, 9, 6};
	//int row2[10] =  {0, 9, 3, 5, 8, 4, 6, 2, 7, 1};
	//int row3[10] =  {0, 7, 2, 6, 9, 3, 1, 4, 8, 5};
	//int row4[10] =  {0, 2, 8, 9, 1, 6, 3, 7, 5, 4};
	//int row5[10] =  {0, 4, 5, 1, 7, 8, 2, 6, 3, 9};
	//int row6[10] =  {0, 6, 7, 3, 5, 9, 4, 8, 1, 2};
	//int row7[10] =  {0, 8, 9, 4, 6, 5, 7, 1, 2, 3};
	//int row8[10] =  {0, 3, 1, 7, 4, 2, 9, 5, 6, 8};
	//int row9[10] =  {0, 5, 6, 2, 3, 1, 8, 9, 0, 0};
	addValues(&s, 1, row1); 
	addValues(&s, 2, row2);
	addValues(&s, 3, row3);
	addValues(&s, 4, row4);
	addValues(&s, 5, row5);
	addValues(&s, 6, row6);
	addValues(&s, 7, row7);
	addValues(&s, 8, row8);
	addValues(&s, 9, row9);
	input(&s);
	
	s.a[1][1] = 2;
	creatSudoku(&s, 1, 1);
//	findAllSudoku(&s);

	
	input(&s);
	//inputMark(&s);
	return 0;
}

