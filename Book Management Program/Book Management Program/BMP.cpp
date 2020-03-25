#include <iostream>

using namespace std;

#define NAME_SIZE 32
#define BOOKNUMBER_SIZE 128
#define BOOKTITLE_SIZE 128
#define PUBLISH_SIZE 32
#define BOOK_MAX 10
#define DAY_SIZE 32

struct _tagBook
{
	char	strBookname[NAME_SIZE];
	char	strBookNum[BOOKNUMBER_SIZE];
	char	strTitle[BOOKTITLE_SIZE];
	char	strPublisher[PUBLISH_SIZE];		// 출판사
	char	strWriter[NAME_SIZE];			// 지은이
	char	strDay[DAY_SIZE];				// 등록년도
	char	iRent[10];							// 대여상태
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
	_tagBook tBookArr[BOOK_MAX] = { };
	int iBookCount = 0;
	int iRent=0;
	char strcan[9];
	char strcant[9];

	strcpy_s(strcan, "가능");
	strcpy_s(strcant, "불가능");
\
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

		// 에러버퍼 삭제
		if (cin.fail())
		{
			cin.clear();

			cin.ignore(1024, '\n');
			continue;
		}

		if (iMenu == MENU_EXIT)
			break;

		switch (iMenu)
		{
		case MENU_INSERT:
			
			system("cls");
			
			cout << "======================= BOOK 추가 =======================" << endl;
			cout << "책 이름 : ";
			cin >> tBookArr[iBookCount].strBookname;
			
			cin.ignore(1024, '\n');
			
			cout << "책 주제 : ";
			cin.getline(tBookArr[iBookCount].strTitle, BOOKTITLE_SIZE);

			cout << "출판사 : ";
			cin.getline(tBookArr[iBookCount].strPublisher, PUBLISH_SIZE);

			cout << "저자 : ";
			cin.getline(tBookArr[iBookCount].strWriter, NAME_SIZE);

			cout << "등록일 : ";
			cin.getline(tBookArr[iBookCount].strDay, DAY_SIZE);

			cout << "쪽수 : ";
			cin >> tBookArr[iBookCount].iPage;

			cout << "가격 : ";
			cin >> tBookArr[iBookCount].iPrice;

			cin.ignore(1024, '\n');
			
			cout << "대여가능시 '가능', 불가능 '불가능'을 입력해주세요" << endl;
			cin.getline(tBookArr[iBookCount].iRent, 9);
			
			if (!strcmp(tBookArr[iBookCount].iRent, strcan))
			{
				iRent = 1;
				cout << "대여 가능 상태로 등록이 완료되었습니다" << endl;
			}
			else if (!strcmp(tBookArr[iBookCount].iRent,strcant))
			{
				iRent = 0;
				cout << "대여 불가능한 상태로 등록이 완료되었습니다" << endl;
			}
			else
				cout << "잘못된 값을 입력하였습니다." << endl;

			cin.ignore(1024, '\n');

			break;
		
		case MENU_RENT:
			system("cls");

			break;
		
		case MENU_RETURN:
			system("cls");

			break;
		
		case MENU_CATEGORY:
			system("cls");

			break;
		
		default:
			break;
		}
	}


	return 0;
}