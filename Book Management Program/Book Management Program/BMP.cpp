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
	char	strPublisher[PUBLISH_SIZE];		// ���ǻ�
	char	strWriter[NAME_SIZE];			// ������
	char	strDay[DAY_SIZE];				// ��ϳ⵵
	char	iRent[10];							// �뿩����
	int		iRentCount;
	int		iPrice;							// å����
	int		iPage;							// �ʼ�

};

struct _tagRent
{
	char strRentname[NAME_SIZE];
};

enum MENU
{
	MENU_NONE,								// NONE
	MENU_INSERT,							// å ���
	MENU_RENT,								// å �뿩
	MENU_RETURN,							// å �ݳ�
	MENU_CATEGORY,							// å ���
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
	char strRented[30] = {};				// å �뿩����
	

	strcpy_s(strcan, "����");
	strcpy_s(strcant, "�Ұ���");
\
	while (1)
	{
		system("cls");

		cout << "======================= MENU =======================" << endl;
		cout << "1. å ���" << endl;
		cout << "2. å �뿩" << endl;
		cout << "3. å �ݳ�" << endl;
		cout << "4. å ���" << endl;
		cout << "5. ���� " << endl;
		cout << "====================================================" << endl;
		cout << "�޴��� �����ϼ��� : ";

		int iMenu;
		cin >> iMenu;

		// �������� ����
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
			
			cout << "======================= BOOK �߰� =======================" << endl;
			cout << "å ���� : ";
			cin >> tBookArr[iBookCount].strBookname;
			
			cin.ignore(1024, '\n');
			
			cout << "å ���� : ";
			cin.getline(tBookArr[iBookCount].strTitle, BOOKTITLE_SIZE);

			cout << "���ǻ� : ";
			cin.getline(tBookArr[iBookCount].strPublisher, PUBLISH_SIZE);

			cout << "���� : ";
			cin.getline(tBookArr[iBookCount].strWriter, NAME_SIZE);

			cout << "����� : ";
			cin.getline(tBookArr[iBookCount].strDay, DAY_SIZE);

			cout << "�ʼ� : ";
			cin >> tBookArr[iBookCount].iPage;

			cout << "���� : ";
			cin >> tBookArr[iBookCount].iPrice;

			cin.ignore(1024, '\n');
			
			cout << "�뿩���ɽ� '����', �Ұ��� '�Ұ���'�� �Է����ּ���" << endl;
			cin.getline(tBookArr[iBookCount].iRent, 9);
			
			if (!strcmp(tBookArr[iBookCount].iRent, strcan))
			{
				tBookArr[iBookCount].iRentCount = 1;
				cout << "�뿩 ���� ���·� ����� �Ϸ�Ǿ����ϴ�" << endl;
			}
			else if (!strcmp(tBookArr[iBookCount].iRent,strcant))
			{
				tBookArr[iBookCount].iRentCount = 0;
				cout << "�뿩 �Ұ����� ���·� ����� �Ϸ�Ǿ����ϴ�" << endl;
			}
			else
				cout << "�߸��� ���� �Է��Ͽ����ϴ�." << endl;

			cin.ignore(1024, '\n');

			++iBookCount;

			cout << "������ �߰��Ǿ����ϴ�." << endl;

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

			cout << " �뿩�Ͻ� å�� ������ �Է����ּ��� : ";
			cin.getline(strName, NAME_SIZE);

			for (int i = 0; i < iBookCount; ++i)
			{
				if (strcmp(tBookArr[i].strBookname, strName) == 0)
				{
					cout << "å ���� : " << tBookArr[i].strBookname << endl;
					cout << "���ǻ� : " << tBookArr[i].strPublisher << endl;
					cout << "���� : " << tBookArr[i].strWriter << endl;
					cout << "����� : " << tBookArr[i].strDay << endl;
					cout << "�ʼ� : " << tBookArr[i].iPage << endl;
					cout << "���� : " << tBookArr[i].iPrice << endl;

					if (tBookArr[i].iRentCount == 1)
						cout << "�� ������ �뿩 ������ �����Դϴ�." << endl;
					else
						cout << "�� ������ �뿩 �Ұ����� �����Դϴ�." << endl;

					cout << endl;

					if (tBookArr[i].iRentCount == 1)
					{
						cout << "===========================================================" << endl;
						cout << "������ �뿩�Ͻðڽ��ϱ�?" << endl;
						cout << "Ȯ�� = 1" << "\t" << "���=2" << endl;
						cin >> iChoose;
						if (iChoose==1)
						{
							tBookArr[i].iRentCount = 0;
							cout << "������ �뿩�Ͽ����ϴ�" << endl;
							strcpy_s(tRentArr[iBR].strRentname, strName);
							++iBR;
							break;
						}
						else
						{
							cout << "�뿩�� ����Ͽ����ϴ�." << endl;
							continue;
						}
					}
					else
					{
						cout << "�뿩 �� �� ���� �����Դϴ�." << endl;
					}
				}
				else
					cout << "�߸��Է��Ͽ����ϴ�" << endl;
			}
			break;
		
		case MENU_RETURN:
			system("cls");

			cin.ignore(1024, '\n');

			cout << "======================= BOOK RETURN =======================" << endl;
			
			cout << "�ݳ��� �� �ִ� ������ ������ �����ϴ�" << endl;
			
			for (int i = 0; i < iBR; ++i)
			{
				cout << i+1 << ". " << tRentArr[i].strRentname << endl;
			}
			
			cout << "===========================================================" << endl;

			cout << "�ݳ��Ͻ� ������ �̸��� �����ּ��� : ";

			cin.getline(strName, NAME_SIZE);

			for (int i = 0; i < iBR; ++i)
			{
				if (strcmp(tRentArr[i].strRentname, strName) == 0)
				{
					
					cout << "�� ������ �ݳ��Ͻðڽ��ϱ�?" << endl;
					
					cout << "Ȯ�� = 1" << "\t" << "���=2" << endl;
					
					cin >> iChoose;
					
					if (iChoose == 1)
					{
						
						tBookArr[i].iRentCount = 1;
						
						cout << "������ �ݳ��Ͽ����ϴ�." << endl;
						
						--iBR;
						
						break;
					}
					
					else
					{
					
						cout << "���� �ݳ��� ����Ͽ����ϴ�." << endl;
						
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
				cout << "å ���� : " << tBookArr[i].strBookname << endl;
				cout << "���ǻ� : " << tBookArr[i].strPublisher << endl;
				cout << "���� : " << tBookArr[i].strWriter << endl;
				cout << "����� : " << tBookArr[i].strDay << endl;
				cout << "�ʼ� : " << tBookArr[i].iPage << endl;
				cout << "���� : " << tBookArr[i].iPrice << endl;
				
				if (tBookArr[i].iRentCount == 1)
					cout << "�� ������ �뿩 ������ �����Դϴ�." << endl;
				else
					cout << "�� ������ �뿩 �Ұ����� �����Դϴ�." << endl;
				
				cout << endl;
			}

			break;
		
		default:
			cout << "�޴��� �߸� �����ϼ̽��ϴ�." << endl;
			break;
		}
		system("pause");
	}


	return 0;
}
