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
	char	strPublish[PUBLISH_SIZE];		// ���ǻ�,������,��ϳ⵵
	int		iRent;							// �뿩����
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
	}

	return 0;
}