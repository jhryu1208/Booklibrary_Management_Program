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
	int		iRentCount;
	int		iPrice;							// 책가격
	int		iPage;							// 쪽수

};

struct _tagRent
{
	char strRentname[NAME_SIZE];
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
	_tagRent tRentArr[BOOK_MAX] = {};
	int iBookCount = 0;
	int iNumber;
	int iChoose;
	int iBR = 0;
	char strcan[9];
	char strcant[9];
	char strName[NAME_SIZE] = {};
	char strRented[30] = {};				// 책 대여상태
	

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
			cout << "책 제목 : ";
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
				tBookArr[iBookCount].iRentCount = 1;
				cout << "대여 가능 상태로 등록이 완료되었습니다" << endl;
			}
			else if (!strcmp(tBookArr[iBookCount].iRent,strcant))
			{
				tBookArr[iBookCount].iRentCount = 0;
				cout << "대여 불가능한 상태로 등록이 완료되었습니다" << endl;
			}
			else
				cout << "잘못된 값을 입력하였습니다." << endl;

			cin.ignore(1024, '\n');

			++iBookCount;

			cout << "도서가 추가되었습니다." << endl;

			break;
		
		case MENU_RENT:
			system("cls");
			
			cout << "======================= BOOK RENT =======================" << endl;
			for (int i = 0; i < iBookCount; ++i)
			{
				cout << i+1 << ". ";
				cout << tBookArr[i].strBookname << endl;
			}
			
			cin.ignore(1024, '\n');

			cout << " 대여하실 책의 제목을 입력해주세요 : ";
			cin.getline(strName, NAME_SIZE);

			for (int i = 0; i < iBookCount; ++i)
			{
				if (strcmp(tBookArr[i].strBookname, strName) == 0)
				{
					cout << "책 제목 : " << tBookArr[i].strBookname << endl;
					cout << "출판사 : " << tBookArr[i].strPublisher << endl;
					cout << "저자 : " << tBookArr[i].strWriter << endl;
					cout << "등록일 : " << tBookArr[i].strDay << endl;
					cout << "쪽수 : " << tBookArr[i].iPage << endl;
					cout << "가격 : " << tBookArr[i].iPrice << endl;

					if (tBookArr[i].iRentCount == 1)
						cout << "이 도서는 대여 가능한 상태입니다." << endl;
					else
						cout << "이 도서는 대여 불가능한 상태입니다." << endl;

					cout << endl;

					if (tBookArr[i].iRentCount == 1)
					{
						cout << "===========================================================" << endl;
						cout << "도서를 대여하시겠습니까?" << endl;
						cout << "확인 = 1" << "\t" << "취소=2" << endl;
						cin >> iChoose;
						if (iChoose==1)
						{
							tBookArr[i].iRentCount = 0;
							cout << "도서를 대여하였습니다" << endl;
							strcpy_s(tRentArr[iBR].strRentname, strName);
							++iBR;
							break;
						}
						else
						{
							cout << "대여를 취소하였습니다." << endl;
							continue;
						}
					}
					else
					{
						cout << "대여 할 수 없는 도서입니다." << endl;
					}
				}
				else
					cout << "잘못입력하였습니다" << endl;
			}
			break;
		
		case MENU_RETURN:
			system("cls");

			cin.ignore(1024, '\n');

			cout << "======================= BOOK RETURN =======================" << endl;
			
			cout << "반납할 수 있는 도서는 다음과 같습니다" << endl;
			
			for (int i = 0; i < iBR; ++i)
			{
				cout << i+1 << ". " << tRentArr[i].strRentname << endl;
			}
			
			cout << "===========================================================" << endl;

			cout << "반납하실 도서의 이름을 적어주세요 : ";

			cin.getline(strName, NAME_SIZE);

			for (int i = 0; i < iBR; ++i)
			{
				if (strcmp(tRentArr[i].strRentname, strName) == 0)
				{
					
					cout << "이 도서를 반납하시겠습니까?" << endl;
					
					cout << "확인 = 1" << "\t" << "취소=2" << endl;
					
					cin >> iChoose;
					
					if (iChoose == 1)
					{
						
						tBookArr[i].iRentCount = 1;
						
						cout << "도서를 반납하였습니다." << endl;
						
						--iBR;
						
						break;
					}
					
					else
					{
					
						cout << "도서 반납을 취소하였습니다." << endl;
						
						continue;
					}
				}
			}
			break;
		
		case MENU_CATEGORY:
			system("cls");
			
			cout << "======================= BOOK CATEGORY =======================" << endl;
			
			for (int i = 0; i < iBookCount; ++i)
			{
				cout << "책 제목 : " << tBookArr[i].strBookname << endl;
				cout << "출판사 : " << tBookArr[i].strPublisher << endl;
				cout << "저자 : " << tBookArr[i].strWriter << endl;
				cout << "등록일 : " << tBookArr[i].strDay << endl;
				cout << "쪽수 : " << tBookArr[i].iPage << endl;
				cout << "가격 : " << tBookArr[i].iPrice << endl;
				
				if (tBookArr[i].iRentCount == 1)
					cout << "이 도서는 대여 가능한 상태입니다." << endl;
				else
					cout << "이 도서는 대여 불가능한 상태입니다." << endl;
				
				cout << endl;
			}

			break;
		
		default:
			cout << "메뉴를 잘못 선택하셨습니다." << endl;
			break;
		}
		system("pause");
	}


	return 0;
}
