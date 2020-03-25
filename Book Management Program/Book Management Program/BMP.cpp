#include <iostream>

using namespace std;

#define NAME_SIZE 32
#define BOOKNUMBER_SIZE 128
#define BOOKTITLE_SIZE 128
#define PUBLISH_SIZE 32


struct _tagBook
{
	char	strBookname[NAME_SIZE];
	char	strBookNum[BOOKNUMBER_SIZE];
	char	strTitle[BOOKTITLE_SIZE];
	char	strPublish[PUBLISH_SIZE];		// 출판사,지은이,등록년도
	int		iRent;							// 대여상태
	int		iPrice;							// 책가격
	int		iPage;							// 쪽수
};

enum MENU
{
	MENU_NONE,								// NONE
	MENU_INSERT,							// 책 등록
	MENU_RENT,								// 책 대여
	MENU_RETURN,							// 책 반납
	MENU_CATEGORY,							// 책 목록
	MENU_EXIT								// EXIT
};

int main()
{
	while (1)
	{
		system("cls");

		cout << "======================= MENU =======================" << endl;
		cout << "1. 책 등록" << endl;
		cout << "2. 책 대여" << endl;
		cout << "3. 책 반납" << endl;
		cout << "4. 책 목록" << endl;
		cout << "5. 종료 " << endl;
		cout << "====================================================" << endl;
		cout << "메뉴를 선택하세요 : ";

		int iMenu;
		cin >> iMenu;
	}

	return 0;
}