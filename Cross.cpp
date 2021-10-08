#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include "array"
#include <Windows.h>
#include <thread>
#include <conio.h>
#include <string.h>
#include <time.h>
using namespace std;

// Hằng số
#define MAX_CAR 17
#define MAX_CAR_LENGTH 10
#define MAx_SPEED 20
//Biến toàn cục
POINT** X; // Mảng chứa MAX_CAR xe
POINT Y; // Đại diện người qua đường
POINT A;
int a[88] = { 0 };
int t = 7;
int z = 0;
int cnt = 0; // Biến hỗ trợ trong quá trình tăng tốc độ xe di chuyển
int MOVING; // Biến xác đinh hướng di chuyển của người
int SPEED; // Tốc độ xe chạy
int HEIGH_CONSOLE = 20, WIDTH_CONSOLE = 80; // Độ rộng và độ cao của màn hình game
bool STATE; // Trạng thái sống/ chết của người qua đường

			// Hàm cố định màn hình
void FixConsoleWindow() {
	HWND consoleWindow = GetConsoleWindow();
	LONG style = GetWindowLong(consoleWindow, GWL_STYLE);
	style = style & ~(WS_MAXIMIZEBOX) & ~(WS_THICKFRAME);
	SetWindowLong(consoleWindow, GWL_STYLE, style);
}


// Hàm xóa màn hình.
void XoaManHinh()
{
	HANDLE hOut;
	COORD Position;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	Position.X = 0;
	Position.Y = 0;
	SetConsoleCursorPosition(hOut, Position);
}
// Hàm tô màu
void textcolor(int x)
{
	HANDLE mau;
	mau = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(mau, x);
}

// Hàm di chuyển tới vị trí trong màn hình console
void GotoXY(int x, int y) {
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

// Hàm khởi tọa dữ liệu mặc định ban đầu
void ResetData() {
	MOVING = 'D'; // Ban đầu cho người di chuyển qua bên phải
	SPEED = 1; // Tốc độ ban đầu
	Y = { WIDTH_CONSOLE / 2,19 }; // Vị trí ban đầu của người
								  // Tạo mảng xem chạy
	if (X == NULL) {
		X = new POINT * [MAX_CAR];
		for (int i = 0; i < MAX_CAR; i++)
			X[i] = new POINT[MAX_CAR_LENGTH];
		for (int i = 0; i < MAX_CAR; i++)
		{
			int temp = (rand() % (WIDTH_CONSOLE - MAX_CAR_LENGTH)) + 1;
			for (int j = 0; j < MAX_CAR_LENGTH; j++)
			{
				X[i][j].x = temp + j;
				X[i][j].y = 2 + i;
			}
		}
	}
}

// Hàm vẽ khung
void DrawBoard(int x, int y, int width, int height, int curPosX = 0, int curPosY = 0)
{
	textcolor(15);
	GotoXY(x, y);
	printf("*");
	for (int i = 1; i <= width; i++)
		printf("*"); // Vẽ viền trên
	GotoXY(x, height + y);
	printf("*");
	for (int i = 1; i <= width; i++)
		printf("*"); // Vẽ viền dưới
	for (int i = y + 1; i <= height + y; i++)
	{
		GotoXY(x, i); printf("*"); // Vẽ viền bên trái
		GotoXY(x + width, i); printf("*"); // Vẽ viền bên phải
	}
	GotoXY(curPosX, curPosY);
	textcolor(7);
}


// Hàm dọn dẹp tài nguyên
void GabageCollect()
{
	for (int i = 0; i < MAX_CAR; i++)
	{
		delete[] X[i];
	}
	delete[] X;
}

// Hàm thoát game
void ExitGame(HANDLE t) {
	system("cls");
	TerminateThread(t, 0);
	GabageCollect();
}

// Hàm dừng game
void PauseGame(HANDLE t) {
	SuspendThread(t);
}

// Xóa miền trong bảng
void DeleteInBoard(int x, int y, int width, int heigh) {
	for (int i = x; i < x + width - 1; i++)
		for (int j = y; j < y + heigh - 1; j++) {
			GotoXY(i, j);
			printf(" ");
		}
}

void ProcessDead() {
	int x;
	STATE = 0;
	for (int b = 0; b < 4; b++)
	{
		Beep(523, 500);
	}
	int heigh = 10, width = 30;
	DrawBoard(20, 3, width, heigh);
	for (int i = 0; i < 3; i++) {
		x = 7;
		DeleteInBoard(21, 4, width, heigh);
		// vẽ người 
		GotoXY(25 + i, x);
		cout << "Y";
		GotoXY(25 + i, x + 1);
		cout << "Y";
		GotoXY(30 - i, x + 1);
		cout << "Y";
		x = 7;
		// vẽ xe 
		textcolor(12);
		GotoXY(30 - i, x);
		cout << "<<<<<<<<<<";

		Sleep(500);
	}
	GotoXY(0, HEIGH_CONSOLE + 2);
	printf("Dead, type y to continue or anykey to exit");
}

// Hàm xử lý khi người băng qua đường thành công
void ProcessFinish(POINT& p, int& dem) {
	a[p.x - 1] = 1;
	SPEED == MAx_SPEED ? SPEED = 0.5 : SPEED++;
	p = { WIDTH_CONSOLE / 2,19 }; // Vị trí lúc đầu của người đứng
	dem++;
	MOVING = 'D'; // Ban đầu cho người di chuyển qua bên phải
}

// Hàm vẽ các toa xe
void DrawCars(const char* s) {
	for (int i = 0; i < MAX_CAR; i += 2) {
		for (int j = 0; j < MAX_CAR_LENGTH; j++) {
			textcolor(6);
			if (i == t)
				textcolor(10);
			GotoXY(X[i][j].x, X[i][j].y);
			cout << ">";
		}
	}
}

// Hàm vẽ các người qua đường
void DrawSticker(const POINT& p, const char* s) {
	GotoXY(p.x, p.y);
	printf(s);
}
void DrawRoadside()
{
	for (int i = 2; i < MAX_CAR; i += 2) {
		for (int j = 0; j < 30; j++) {
			GotoXY(X[i][j].x, X[i][j].y);
			printf("-");
		}
	}
}

// Hàm kiểm tra xem người có đụng xe hay người trước đó không
bool IsImpact(const POINT& p, int d) {
	if (d == 1 && a[p.x - 1] == 1) return true;
	if (d == 19 || d == 1 || d % 2 == 1) return false;
	for (int i = 0; i < MAX_CAR_LENGTH; i++) {
		if (p.x == X[d - 2][i].x && p.y == X[d - 2][i].y)
			return true;
	}
	return false;
}


void MoveCars() {
	for (int i = 0; i < MAX_CAR; i += 2)
	{
		cnt = 0;
		if (i != t)
		{
			do {
				cnt++;
				for (int j = 0; j < MAX_CAR_LENGTH - 1; j++) {
					X[i][j] = X[i][j + 1];
				}
				X[i][MAX_CAR_LENGTH - 1].x + 1 == WIDTH_CONSOLE ? X[i][MAX_CAR_LENGTH - 1].x = 1 : X[i][MAX_CAR_LENGTH - 1].x++; // Kiểm tra xem xe có đụnng màn hình không
			} while (cnt < SPEED);
		}
	}
	for (int i = 1; i < MAX_CAR; i += 2)
	{
		cnt = 0;
		if (i != t) {
			do {
				cnt++;
				for (int j = MAX_CAR_LENGTH - 1; j > 0; j--)
				{
					X[i][j] = X[i][j - 1];
				}
				X[i][0].x - 1 == 0 ? X[i][0].x = WIDTH_CONSOLE - 1 : X[i][0].x--;// Kiểm tra xem xe có đụnng màn hình không
			} while (cnt < SPEED);
		}
	}
}

// Hàm xóa xe 
void EraseCars() {
	for (int i = 1; i < MAX_CAR; i += 2) {
		cnt = 0;
		do {
			GotoXY(X[i][MAX_CAR_LENGTH - 1 - cnt].x, X[i][MAX_CAR_LENGTH - 1 - cnt].y);
			printf(" ");
			cnt++;
		} while (cnt < SPEED);
	}
	for (int i = 0; i < MAX_CAR; i += 2) {
		cnt = 0;
		do {
			GotoXY(X[i][0 + cnt].x, X[i][0 + cnt].y);
			printf(" ");
			cnt++;
		} while (cnt < SPEED);
	}
}

void MoveRight() {
	if (Y.x < WIDTH_CONSOLE - 1) {
		DrawSticker(Y, " ");
		Y.x++;
		DrawSticker(Y, "Y");
	}
}

void MoveLeft() {
	if (Y.x > 1) {
		DrawSticker(Y, " ");
		Y.x--;
		DrawSticker(Y, "Y");
	}
}

void MoveDown() {
	if (Y.y < HEIGH_CONSOLE - 1) {
		DrawSticker(Y, " ");
		Y.y++;
		DrawSticker(Y, "Y");
	}
}

void MoveUp() {
	if (Y.y > 1) {
		DrawSticker(Y, " ");
		Y.y--;
		DrawSticker(Y, "Y");
	}
}

void SubThread() {
	int dem = 0;
	int diem = 0;
	while (1) {
		if (STATE) {
			dem++;
			switch (MOVING) {
			case 'A':
				MoveLeft();
				break;
			case 'D':
				MoveRight();
				break;
			case 'W':
				MoveUp();
				break;
			case 'S':
				MoveDown();
				break;
			case 'a':
				MoveLeft();
				break;
			case 'd':
				MoveRight();
				break;
			case 'w':
				MoveUp();
				break;
			case 's':
				MoveDown();
				break;
			}
			MOVING = ' ';
			EraseCars();
			if (dem == 20)
			{
				dem = 0;
				t = ((float)rand() / (float)RAND_MAX) * MAX_CAR;
			}
			MoveCars();
			DrawCars(".");
			if (IsImpact(Y, Y.y)) {
				ProcessDead();
			}
			if (Y.y == 1)
			{
				ProcessFinish(Y, diem);
				GotoXY(92, 15);
				textcolor(6);
				cout << "Diem : " << diem;
			}
			Sleep(100);
		}
	}
}

// Menu game
void Menu()
{
	//DrawBoard(40, 9, 30, 2);
	textcolor(9);
	GotoXY(40, 6);

	printf("MENU GAME");
	textcolor(15);
	GotoXY(40, 10);
	printf("1.Start Game");
	GotoXY(40, 12);
	printf("2.tutorial");
	GotoXY(40, 14);
	printf("3.Information");
	GotoXY(40, 16);
	printf("4.Quit");
	GotoXY(40, 18);
	printf("T. Load Game");
	GotoXY(60, 10);
	//printf("Ten : Vo Van Quan");
	//GotoXY(60, 12);
	//printf("MSSV : 1712698");
}

// hướng dẫn cách chơi
void instruction()
{
	system("cls");
	int x = 8;
	textcolor(12);
	GotoXY(50, 5);
	printf("INSTRUCTION");
	textcolor(7);
	FILE* out = fopen("instruction.txt", "rt");
	while (!feof(out))
	{
		GotoXY(30, x);
		char s[255];
		fgets(s, 255, out);
		printf("%s", s);
		x++;
		Sleep(100);
	}
	GotoXY(40, 28);
	system("pause");
	system("cls");
}

// thông tin game và NXS
void information()
{
	system("cls");
	int x = 8;
	textcolor(12);
	GotoXY(50, 5);
	printf("INFORMATION");
	textcolor(7);
	FILE* out = fopen("information.txt", "rt");
	while (!feof(out))
	{
		GotoXY(20, x);
		char s[255];
		fgets(s, 255, out);
		printf("%s", s);
		x++;
		Sleep(100);
	}
	GotoXY(40, 28);
	system("pause");
	system("cls");
}

void SaveData()
{
	FILE* f;
	char g[20];
	GotoXY(0, HEIGH_CONSOLE + 1);
	printf("enter your file's name : ");
	gets_s(g);

	fopen_s(&f, g, "wb");
	fwrite(&STATE, sizeof(bool), 1, f);
	fwrite(&Y, sizeof(POINT), 1, f);
	fwrite(&MOVING, sizeof(char), 1, f);
	for (int i = 0; i < 88; i++) {
		fwrite(&a[i], sizeof(int), 1, f);
	}
	fwrite(&SPEED, sizeof(INT), 1, f);
	for (int i = 0; i < MAX_CAR; i++)
		fwrite(X[i], sizeof(POINT), MAX_CAR_LENGTH, f);
	fclose(f);
}
// huong dan game 
void printintroduction()
{
	textcolor(12);
	GotoXY(95, 4);
	cout << "HUONG DAN";
	DrawBoard(90, 6, 20, 10);
	GotoXY(92, 8);
	cout << "W : Len";
	GotoXY(92, 9);
	cout << "S : Xuong";
	GotoXY(92, 10);
	cout << "A : qua Trai";
	GotoXY(92, 11);
	cout << "D : qua Phai";
	GotoXY(92, 12);
	cout << "P : Dung game";
	GotoXY(92, 13);

	cout << "L : luu game";
	GotoXY(92, 14);
	cout << "T : load lai game";

}


void LoadData()
{
	system("cls");

	FILE* f;
	char g[20];
	printf("enter your file's name : ");
	gets_s(g);

	fopen_s(&f, g, "rb");
	if (g == NULL)printf("file is NULL please enter anothername");
	fread(&STATE, sizeof(bool), 1, f);
	fread(&Y, sizeof(POINT), 1, f);
	fread(&MOVING, sizeof(char), 1, f);
	for (int i = 0; i < 88; i++) {
		fread(&a[i], sizeof(int), 1, f);
	}
	fwrite(&SPEED, sizeof(INT), 1, f);
	X = new POINT * [MAX_CAR];
	for (int i = 0; i < MAX_CAR; i++)
		X[i] = new POINT[MAX_CAR_LENGTH];
	for (int i = 0; i < MAX_CAR; i++)
		fread(X[i], sizeof(POINT), MAX_CAR_LENGTH, f);
	fclose(f);
	printintroduction();
	DrawBoard(0, 0, WIDTH_CONSOLE, HEIGH_CONSOLE);
	GotoXY(Y.x, Y.y);
	printf("Y");
	for (int i = 0; i < 88; i++) {
		if (a[i] == 1) {
			GotoXY(i - 1, 1);
			printf("Y");
		}
	}
}

// Hàm bắt đầu game
void StartGame() {
	system("cls");
	ResetData(); // Khởi tạo dữ liệu gốc
				 //DrawRoadside();www
	printintroduction();
	DrawBoard(0, 0, WIDTH_CONSOLE, HEIGH_CONSOLE); // Vẽ màn hình game

	STATE = true; //Bắt đầu cho Thread chạy
}

void Game() {
	system("cls");
	int temp;
	srand(time(NULL));
	if (z == 0) StartGame();
	else LoadData();
	thread t1(SubThread);
	while (1) {
		temp = toupper(_getch());
		if (STATE == 1) {
			if (temp == 27) {
				ExitGame(t1.native_handle());
				return;
			}
			else if (temp == 'T') {
				PauseGame(t1.native_handle());
				LoadData();
				Game();
			}
			else if (temp == 'P') {
				PauseGame(t1.native_handle());
			}
			else if (temp == 'L') {
				PauseGame(t1.native_handle());
				SaveData();
				exit(0);
			}
			/*	else if (temp == 'M') {
			system("cls");
			Menu();
			}*/
			else {
				ResumeThread((HANDLE)t1.native_handle());
				if (temp == 'D' || temp == 'A' || temp == 'W' || temp == 'S' || temp == 'd' || temp == 'a' || temp == 'w' || temp == 's') {
					MOVING = temp;
				}
			}
		}
		else {
			if (temp == 'Y') {
				StartGame();
			}
			else {
				ExitGame(t1.native_handle());
				exit(0);
			}
		}
	}
}

void main() {
	FixConsoleWindow();
	textcolor(12);
	GotoXY(45, 1);

Start:

	Menu();
	char c = _getch();
	switch (c)
	{
	case '1': Game(); break;
	case '2': instruction(); break;
	case '3': information(); break;
	case '4':
	{
		GotoXY(40, 28);
		return;
		break;
	}
	case 'L':
	{
		system("cls");
		goto Start;
		break;
	}
	case 't':
	{
		z = 1;
		Game();
	}
	}
	goto Start;
}
