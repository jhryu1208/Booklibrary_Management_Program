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
	int		iPrice;							// å����
	int		iPage;							// �ʼ�
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
	int iBookCount = 0;
	int iRent=0;
	char strcan[9];
	char strcant[9];

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
			cout << "å �̸� : ";
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
				iRent = 1;
				cout << "�뿩 ���� ���·� ����� �Ϸ�Ǿ����ϴ�" << endl;
			}
			else if (!strcmp(tBookArr[iBookCount].iRent,strcant))
			{
				iRent = 0;
				cout << "�뿩 �Ұ����� ���·� ����� �Ϸ�Ǿ����ϴ�" << endl;
			}
			else
				cout << "�߸��� ���� �Է��Ͽ����ϴ�." << endl;

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