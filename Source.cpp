#include<iostream>
#include<iomanip>
#include<string>
#define SIZE 100
#define COLUMN 6
#define col 2
using namespace std;
void database(string name[][col], int regno[], int subs[][COLUMN], int&, int&, int tmsub[], int&);
void append(string name[][col], int regno[], int subs[][COLUMN], int& n, int nofsub, int tmsub[]);
void search(string name[][col], int regno[], int subs[][COLUMN], int n, int nofsub);
void update(string name[][col], int regno[], int subs[][COLUMN], int n, int nofsub, int tmsub[]);
void mydel(string name[][col], int regno[], int subs[][COLUMN], int& n, int nofsub);
void prepare(string name[][col], int regno[], int subs[][COLUMN], int n, int nofsub, int markobtained[], float percentage[], char grade[], int total);
void sort(string name[][col], int regno[], int subs[][COLUMN], int n, int nofsub, int markobtained[], float percentage[], char grade[], int total);
void reporta(string name[][col], int regno[], int subs[][COLUMN], int n, int nofsub, int markobtained[], float percentage[], char grade[], int total);
void reportb(string name[][col], int regno[], int subs[][COLUMN], int n, int nofsub, int markobtained[], float percentage[], char grade[], int total);
int main()
{
	system("color 17");
	string name[SIZE][col] = { "0" };
	int regno[SIZE] = { 0 };
	int subjects[SIZE][COLUMN] = { 0 };
	int tmsubject[COLUMN] = { 0 };
	int markobtained[SIZE] = { 0 };
	float percentage[SIZE] = { 0.0 };
	char grade[SIZE] = { '0' };
	int n, nofsub, total;
	char flag;
	cout << "USEFULL INSTRUCTION ABOUT PROGRAM: -\a\n";
	cout << "	Press Index Number of Each Option to Use that FEATURE\a\n";
	cout << "			<------MAIN-MENU------> \a\n";
	cout << "1. Create a DATABASE\a\n";
	cout << "2. Append New Record\a\n";
	cout << "3. Search\a\n";
	cout << "4. Update\a\n";
	cout << "5. Delete\a\n";
	cout << "6. Prepare Result\a\n";
	cout << "7. Sort w.r.t Marks Obtained\a\n";
	cout << "8. Report: -\a\n";
	cout << "	a. All Item\a\n";
	cout << "	b. Particular Item\a\n";
	cout << "9. Exit\a\n";
	int flag1 = 0;
	do
	{
		cout << "Enter Your Choice\a\n";
		cin >> flag;
		if ((flag > '0' && flag <= ' 9') || (flag == 'a' || flag == 'b'))
			break;
		else
			cout << "INVALID....RE-ENTER.....!!!!!!!\a\n";
	} while (true);
	while (flag != '9')
	{
		if (flag1 == 0)
		{
			if (flag != '1')
			{
				cout << "OOPSS.....SOORY......YOU HAVE TO PERFORM STEP (1) FIRST....!!!!\a\n ";
				cout << "USEFULL INSTRUCTION ABOUT PROGRAM: -\a\n";
				cout << "	Press Index Number of Each Option to Use that FEATURE\a\n";
				cout << "			<------MAIN-MENU------> \a\n";
				cout << "1. Create a DATABASE\a\n";
				do
				{
					cout << "Enter Your Choice\a\n";
					cin >> flag;
					if (flag == '1')
						break;
					else
						cout << "INVALID....RE-ENTER.....!!!!!!!\a\n";

				} while (true);
			}
			if (flag == '1')
			{
				flag1 = 1;
				database(name, regno, subjects, n, nofsub, tmsubject, total);
			}
		}
		else
		{
			switch (flag)
			{
			case '1':
				database(name, regno, subjects, n, nofsub, tmsubject, total);
				break;
			case '2':
				if (n == SIZE)
					cout << "YOU CANNOT APPEND ANY DATA BECAUSE THERE IS NO SPACE AVAILABLE......SOORY FOR INCOVINEANCE....!!!!!\a\n";
				else
					append(name, regno, subjects, n, nofsub, tmsubject);
				break;
			case '3':
				search(name, regno, subjects, n, nofsub);
				break;
			case '4':
				if (n == 0)
					cout << "OPPSSSS...........NO RECORD TO UPDATE\a\n";
				else
					update(name, regno, subjects, n, nofsub, tmsubject);
				break;
			case '5':
				mydel(name, regno, subjects, n, nofsub);
				break;
			case '6':
				prepare(name, regno, subjects, n, nofsub, markobtained, percentage, grade, total);
				break;
			case '7':
				sort(name, regno, subjects, n, nofsub, markobtained, percentage, grade, total);
				break;
			case '8':
				do
				{
					cout << "Enter Your Choice.....Either a or b...\a\n";
					cin >> flag;
					if (flag == 'a' || flag == 'b' || flag == 'A' || flag == 'B')
						break;
					else
						cout << "INVALID....RE-ENTER.....!!!!!!!\a\n";
				} while (true);
				switch (flag)
				{
				case 'A':
				case 'a':
					reporta(name, regno, subjects, n, nofsub, markobtained, percentage, grade, total);
					break;
				case'B':
				case'b':
					reportb(name, regno, subjects, n, nofsub, markobtained, percentage, grade, total);
					break;
				}
				break;
			case '9':
				break;
			}
		}
		if (flag == '9')
			break;
		cout << "		WELCOME BACK\a\n";
		cout << "USEFULL INSTRUCTION ABOUT PROGRAM: -\a\n";
		cout << "	Press Index Number of Each Option to Use that FEATURE\a\n";
		cout << "			<------MAIN-MENU------> \a\n";
		cout << "1. Create a DATABASE\a\n";
		cout << "2. Append New Record\a\n";
		cout << "3. Search\a\n";
		cout << "4. Update\a\n";
		cout << "5. Delete\a\n";
		cout << "6. Prepare Result\a\n";
		cout << "7. Sort w.r.t Marks Obtained\a\n";
		cout << "8. Report: -\a\n";
		cout << "	a. All Item\a\n";
		cout << "	b. Particular Item\a\n";
		cout << "9. Exit\a\n";
		do
		{
			cout << "Enter Your Choice\a\n";
			cin >> flag;
			if ((flag > '0' && flag <= ' 9') || (flag == 'a' || flag == 'b'))
				break;
			else
				cout << "INVALID....RE-ENTER.....!!!!!!!\a\n";

		} while (true);
	}
	system("pause");
	return 0;
}
void database(string name[][col], int regno[], int subs[][COLUMN], int& n, int& nofsub, int tmsub[], int& total)
{
	do
	{
		cout << "How many Students Record you are going to enter?????\a\n";
		cin >> n;
		if (n > 0 && n <= 100)
			break;
		else
			cout << "INVALID.....RE-ENTER...!!!!!\a\n";
	} while (true);
	do
	{
		cout << "How many Subjects Student Study [OUT OF 6]....\a\n";
		cin >> nofsub;
		if (nofsub > 0 && nofsub <= 6)
			break;
		else
			cout << "INVALID.....RE-ENTER...!!!!!\a\n";
	} while (true);
	total = 0;
	for (int i = 0; i < nofsub; i++)
	{
		do
		{
			cout << "Enter The Total MARKS[out of 200 alleast 50] of Subject " << i + 1 << endl;
			cin >> tmsub[i];
			if (tmsub[i] >= 50 && tmsub[i] <= 200)
				break;
			else
				cout << "INVALID.....RE-ENTER.....!!!\a\n";
		} while (true);
		total += tmsub[i];
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (j == 0)
			{
				cout << "ENTER FIRST NAME OF THE STUDENT....\a\n";
				cin >> name[i][j];
			}
			else
			{
				cout << "ENTER SECOND NAME OF THE STUDENT.....\a\n";
				cin >> name[i][j];
			}
		}
		do
		{
			int f = 0;
			cout << "Enter Reg no\n";
			cin >> regno[i];
			for (int k = 0; k < i; k++)
				if (regno[i] == regno[k])
				{
					f++;
					break;
				}
			if (f == 0)
			{
				if (regno[i] >= 1000 && regno[i] < 10000)
					break;
			}
			cout << "INVALID..... RE-ENTER....\a\n";
		} while (true);
		for (int j = 0; j < nofsub; j++)
		{
			do
			{
				cout << "Enter the MARKS of SUBJECT " << j + 1 << endl;
				cin >> subs[i][j];
				if (subs[i][j] >= 0 && subs[i][j] <= tmsub[j])
					break;
				else
					cout << "INVALID......RE-ENTER......\a\n";
			} while (true);
		}
	}
}
void append(string name[][col], int regno[], int subs[][COLUMN], int& n, int nofsub, int tmsub[])
{
	int pos;
	do
	{
		cout << "Enter the Position where you want to append data\a\n";
		cin >> pos;
		if (pos >= 1 && pos <= SIZE)
			break;
		else
			cout << "INVALID.....RE-ENTER.........!!!!!!\a\n";
	} while (true);
	if (pos >= n)
	{
		for (int j = 0; j < col; j++)
		{
			if (j == 0)
			{
				cout << "Enter First Name of the Student....\a\n";
				cin >> name[pos - 1][j];
			}
			else
			{
				cout << "Enter Second Name of the Student....\a\n";
				cin >> name[pos - 1][j];
			}
		}
		do
		{
			int f = 0;
			cout << "Enter Reg no\n";
			cin >> regno[pos - 1];
			for (int k = 0; k < pos; k++)
				if (regno[pos - 1] == regno[k])
				{
					f++;
					break;
				}
			if (f == 0)
			{
				if (regno[pos - 1] >= 1000 && regno[pos - 1] < 10000)
					break;
			}
			cout << "INVALID..... RE-ENTER....\a\n";
		} while (true);
		for (int j = 0; j < nofsub; j++)
		{
			do
			{
				cout << "ENTER Marks of Subject......." << j + 1 << endl;
				cin >> subs[pos - 1][j];
				if (subs[pos - 1][j] >= 0 && (subs[pos - 1][j] <= tmsub[j]))
					break;
				else
					cout << "INVALID......RE-ENTER.....!!!!!\a\n";
			} while (true);
		}
		n++;
	}
	else
	{
		for (int i = n; i > pos - 1; i--)
		{
			for (int j = 0; j < col; j++)
			{
				name[i][j] = name[i - 1][j];
			}
			regno[i] = regno[i - 1];
			for (int j = 0; j < nofsub; j++)
			{
				subs[i][j] = subs[i - 1][j];
			}
		}
		for (int j = 0; j < col; j++)
		{
			if (j == 0)
			{
				cout << "Enter First Name of Student\a\n";
				cin >> name[pos - 1][j];
			}
			if (j == 1)
			{
				cout << "Enter Second Name of Student\a\n";
				cin >> name[pos - 1][j];
			}
		}
		do
		{
			int f = 0;
			cout << "Enter Reg no\n";
			cin >> regno[pos - 1];
			for (int k = 0; k < pos - 1; k++)
				if (regno[pos - 1] == regno[k])
				{
					f++;
					break;
				}
			if (f == 0)
			{
				if (regno[pos - 1] >= 1000 && regno[pos - 1] < 10000)
					break;
			}
			cout << "INVALID..... RE-ENTER....\a\n";
		} while (true);
		for (int j = 0; j < nofsub; j++)
		{
			do
			{
				cout << "Enter MArks of Subject....." << j + 1 << endl;
				cin >> subs[pos - 1][j];
				if (subs[pos - 1][j] >= 0 && subs[pos - 1][j] <= tmsub[j])
					break;
				else
					cout << "INVALID......RE-ENTER....\a\n";
			} while (true);
		}
		n++;
	}
}
void search(string name[][col], int regno[], int subs[][COLUMN], int n, int nofsub)
{
	int svalue, pos = -1;
	do
	{
		cout << "Enter Registration Number that you want to Search\a\n";
		cin >> svalue;
		if (svalue >= 1000 && svalue <= 10000)
			break;
		else
			cout << "INVALID....RE-ENTER....\a\n";
	} while (true);
	for (int i = 0; i < n; i++)
		if (svalue == regno[i])
		{
			pos = i;
			break;
		}
	if (pos != -1)
	{
		cout << svalue << " is present in the list on " << pos + 1 << " number\a....\n";
		cout << name[pos][0] << " " << name[pos][1] << setw(10) << regno[pos] << setw(5);
		for (int j = 0; j < nofsub; j++)
		{
			cout << subs[pos][j] << setw(5);
		}
		cout << endl;
	}
	else
		cout << "The Registration Number " << svalue << " you enter cannot exixt in the record!!!!!!\a\n";
}
void update(string name[][col], int regno[], int subs[][COLUMN], int n, int nofsub, int tmsub[])
{
	int flag;
	do
	{
		cout << "If you wnat to update record using registration number press 1\a\n";
		cout << "If you want to update record using registration number press 2\a\n";
		cin >> flag;
		if (flag == 1 || flag == 2)
			break;
		else
			cout << "Invalid.....RE-ENTER......!!\a\n";
	} while (true);
	if (flag == 1)
	{
		int svalue, pos = -1;
		do
		{
			cout << "Enter Registration Number\a\n";
			cin >> svalue;
			if (svalue >= 1000 && svalue < 10000)
				break;
			else
				cout << "Invalid.....RE-ENTER.....!!!!!!/a/n";
		} while (true);
		for (int i = 0; i < n; i++)
			if (svalue == regno[i])
			{
				pos = i;
				break;
			}
		cout << "		<<<<==MENU==>>>>\a\n";
		cout << "If you only want to update NAME PRESS 1\a\n";
		cout << "If you ONLY Want to Edit Marks PRESS 2\a\n";
		cout << "If you want to update all-Data PRESS 3\a\n";
		int choice;
		do
		{
			cout << "Enter Your Choice....!!!!\a\n";
			cin >> choice;
			if (choice > 0 && choice <= 3)
				break;
			else
				cout << "INVALID....RE-ENTER....!!!!!\a\n";
		} while (true);
		switch (choice)
		{
		case 1:
			cout << "Enter First Name....!!!!!\a\n";
			cin >> name[pos][0];
			cout << "Enter Second Name......!!!!!\a\n";
			cin >> name[pos][1];
			break;
		case 2:
			for (int j = 0; j < nofsub; j++)
			{
				do
				{
					cout << "Enter Marks of subject...." << j + 1 << endl;
					cin >> subs[pos][j];
					if (subs[pos][j] >= 0 && subs[pos][j] <= tmsub[j])
						break;
					else
						cout << "INVALID......RE-ENTER...!!!!\a\n";
				} while (true);
			}
		default:
			cout << "Enter First Name....!!!!!\a\n";
			cin >> name[pos][0];
			cout << "Enter Second Name......!!!!!\a\n";
			cin >> name[pos][1];
			do
			{
				int f = 0;
				cout << "Enter Reg no\n";
				cin >> regno[pos];
				for (int k = 0; k < n; k++)
					if (regno[pos] == regno[k])
					{
						f++;
						break;
					}
				if (f == 0)
				{
					if (regno[pos] >= 1000 && regno[pos] < 10000)
						break;
				}
				cout << "INVALID..... RE-ENTER....\a\n";
			} while (true);
			for (int j = 0; j < nofsub; j++)
			{
				do
				{
					cout << "Enter Marks of subject...." << j + 1 << endl;
					cin >> subs[pos][j];
					if (subs[pos][j] >= 0 && subs[pos][j] <= tmsub[j])
						break;
					else
						cout << "INVALID......RE-ENTER...!!!!\a\n";
				} while (true);
			}
		}
	}
	else
	{
		int pos;
		do
		{
			cout << "Enter Your Position...!!!!\a\n";
			cin >> pos;
			if (pos > 0 && pos <= n)
				break;
			else
				cout << "INVALID.....RE-ENTER....!!!!\a\n";
		} while (true);
		cout << "		<<<<==MENU==>>>>\a\n";
		cout << "If you only want to update NAME PRESS 1\a\n";
		cout << "If you Want to Update REGISTRATION NUMBER PRESS 2\a\n";
		cout << "If you ONLY Want to Edit Marks Press 3\a\n";
		cout << "If you want to Edit all-Data PRESS 4\a\n";
		int choice;
		do
		{
			cout << "Enter Your Choice....!!!!\a\n";
			cin >> choice;
			if (choice > 0 && choice <= 3)
				break;
			else
				cout << "INVALID....RE-ENTER....!!!!!\a\n";
		} while (true);
		switch (choice)
		{
		case 1:
			cout << "Enter First Name....!!!!!\a\n";
			cin >> name[pos - 1][0];
			cout << "Enter Second Name......!!!!!\a\n";
			cin >> name[pos - 1][1];
			break;
		case 2:
			do
			{
				int f = 0;
				cout << "Enter Reg no\n";
				cin >> regno[pos - 1];
				for (int k = 0; k < pos - 1; k++)
					if (regno[pos - 1] == regno[k])
					{
						f++;
						break;
					}
				if (f == 0)
				{
					if (regno[pos - 1] >= 1000 && regno[pos - 1] < 10000)
						break;
				}
				cout << "INVALID..... RE-ENTER....\a\n";
			} while (true);
			break;
		case 3:
			for (int j = 0; j < nofsub; j++)
			{
				do
				{
					cout << "Enter Marks of subject...." << j + 1 << endl;
					cin >> subs[pos - 1][j];
					if (subs[pos - 1][j] >= 0 && subs[pos - 1][j] <= tmsub[j])
						break;
					else
						cout << "INVALID......RE-ENTER...!!!!\a\n";
				} while (true);
			}
		case 4:
			cout << "Enter First Name....!!!!!\a\n";
			cin >> name[pos - 1][0];
			cout << "Enter Second Name......!!!!!\a\n";
			cin >> name[pos - 1][1];
			do
			{
				int f = 0;
				cout << "Enter Reg no\n";
				cin >> regno[pos - 1];
				for (int k = 0; k < pos - 1; k++)
					if (regno[pos - 1] == regno[k])
					{
						f++;
						break;
					}
				if (f == 0)
				{
					if (regno[pos - 1] >= 1000 && regno[pos - 1] < 10000)
						break;
				}
				cout << "INVALID..... RE-ENTER....\a\n";
			} while (true);
			for (int j = 0; j < nofsub; j++)
			{
				do
				{
					cout << "Enter Marks of subject...." << j + 1 << endl;
					cin >> subs[pos - 1][j];
					if (subs[pos - 1][j] >= 0 && subs[pos - 1][j] <= tmsub[j])
						break;
					else
						cout << "INVALID......RE-ENTER...!!!!\a\n";
				} while (true);
			}
		}

	}
}
void mydel(string name[][col], int regno[], int subs[][COLUMN], int& n, int nofsub)
{
	int flag;
	do
	{
		cout << "If you want to DELETE DATA of STUDENT using REGISTRATION Number Press 1\a\n";
		cout << "IF you want to DELETE DATA of STUDENT using Position Press 2\a\n";
		cin >> flag;
		if (flag == 1 || flag == 2)
			break;
		else
			cout << "INVALID......RE-ENTER...\a\n";
	} while (true);
	if (flag == 1)
	{
		int svalue, pos = -1;
		do
		{
			cout << "Enter REGISTRATION NUMBER\a\n";
			cin >> svalue;
			if (svalue >= 1000 && svalue < 10000)
				break;
			else
				cout << "INVALID.....RE-ENTER.....\a\n";
		} while (true);
		for (int i = 0; i < n; i++)
			if (svalue == regno[i])
			{
				pos = i;
				break;
			}
		for (int i = pos; i < n; i++)
		{
			for (int j = 0; j < col; j++)
			{
				name[i][j] = name[i + 1][j];
			}
			regno[i] = regno[i + 1];
			for (int j = 0; j < nofsub; j++)
			{
				subs[i][j] = subs[i + 1][j];
			}
		}
		n--;
	}
	else
	{
		int pos;
		do
		{
			cout << "Enter Position on which Data must be DELETED\a\n";
			cin >> pos;
			if (pos > 0 && pos <= n)
				break;
			else
				cout << "INVALID....RE-ENTER....\a\n";
		} while (true);
		for (int i = pos - 1; i < n; i++)
		{
			for (int j = 0; j < col; j++)
			{
				name[i][j] = name[i + 1][j];
			}
			regno[i] = regno[i + 1];
			for (int j = 0; j < nofsub; j++)
			{
				subs[i][j] = subs[i + 1][j];
			}
		}
		n--;
	}
}
void prepare(string name[][col], int regno[], int subs[][COLUMN], int n, int nofsub, int markobtained[], float percentage[], char grade[], int total)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < nofsub; j++)
		{
			markobtained[i] += subs[i][j];
		}
		percentage[i] = (markobtained[i] * 100.0) / (total);
		if (percentage[i] >= 80.0)
			grade[i] = 'A';
		else
			if (percentage[i] >= 70.0 && percentage[i] <= 79.99)
				grade[i] = 'B';
			else
				if (percentage[i] >= 60.0 && percentage[i] <= 69.99)
					grade[i] = 'C';
				else
					if (percentage[i] >= 50.0 && percentage[i] <= 59.99)
						grade[i] = ' D';
					else
						grade[i] = 'F';
	}
}
void reporta(string name[][col], int regno[], int subs[][COLUMN], int n, int nofsub, int markobtained[], float percentage[], char grade[], int total)
{
	cout << "		<<<<<=====RECORD=====>>>>>\a\n";
	for (int i = 0; i < n; i++)
	{
		cout << i + 1 << ".";
		for (int j = 0; j < col; j++)
			cout << setw(5) << name[i][j] << " ";
		cout << setw(5) << regno[i] << setw(5);
		for (int j = 0; j < nofsub; j++)
			cout << subs[i][j] << setw(5);
		cout << markobtained[i] << setw(10) << percentage[i] << setw(5) << grade[i] << endl;
	}
}
void reportb(string name[][col], int regno[], int subs[][COLUMN], int n, int nofsub, int markobtained[], float percentage[], char grade[], int total)
{
	cout << "If you want to see result using REGISTRATION NUMBER PRESS 1...\a\n";
	cout << "If you want to see result using POSITION PRESS 2...\a\n";
	int flag;
	do
	{
		cout << "ENTER YOUR CHOICE\a\n";
		cin >> flag;
		if (flag == 1 || flag == 2)
			break;
		else
			cout << "INVALID.....RE-ENTER....!!!!/a/n";
	} while (true);
	if (flag == 1)
	{
		int svalue, pos;
		do
		{
			cout << "ENTER YOUR REGISTRATION NUMBER...\a\n";
			cin >> svalue;
			if (svalue >= 1000 && svalue < 10000)
				break;
			else
				cout << "INVALID......RE-ENTER....!!!!!\a\n";
		} while (true);
		for (int i = 0; i < n; i++)
			if (svalue == regno[i])
			{
				pos = i;
				break;
			}
		cout << "		<<<<<=====RECORD=====>>>>>\a\n";
		for (int j = 0; j < col; j++)
			cout << name[pos][j] << " ";
		cout << setw(8) << regno[pos] << setw(8);
		for (int j = 0; j < nofsub; j++)
			cout << subs[pos][j] << setw(8);
		cout << markobtained[pos] << setw(8) << percentage[pos] << setw(8) << grade[pos] << endl;
	}
	else
	{
		int pos;
		do
		{
			cout << "Enter The Serial No whose RECORD you want to print\a\n";
			cin >> pos;
			if (pos > 0 && pos <= n)
				break;
			else
				cout << "INVALID.....RE-ENTER....\a\n";
		} while (true);
		cout << "		<<<<<=====RECORD=====>>>>>\a\n";
		for (int j = 0; j < col; j++)
			cout << name[pos - 1][j] << " ";
		cout << setw(8) << regno[pos - 1];
		for (int j = 1; j < nofsub; j++)
			cout << setw(8) << subs[pos - 1][j];
		cout << setw(8) << markobtained[pos - 1] << setw(8) << percentage[pos - 1] << setw(8) << grade[pos - 1] << endl;
	}
}
void sort(string name[][col], int regno[], int subs[][COLUMN], int n, int nofsub, int markobtained[], float percentage[], char grade[], int total)
{
	string tempo;
	char tempor;
	int temp;
	float temporar;
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
			if (markobtained[i] < markobtained[j])
			{
				for (int k = 0; k < col; k++)
				{
					tempo = name[i][k];
					name[i][k] = name[j][k];
					name[j][k] = tempo;
				}
				temp = regno[i];
				regno[i] = regno[j];
				regno[j] = temp;
				for (int k = 0; k < nofsub; k++)
				{
					temp = subs[i][k];
					subs[i][k] = subs[j][k];
					subs[j][k] = temp;
				}
				temp = markobtained[i];
				markobtained[i] = markobtained[j];
				markobtained[j] = temp;
				temporar = percentage[i];
				percentage[i] = percentage[j];
				percentage[j] = temporar;
				tempor = grade[i];
				grade[i] = grade[j];
				grade[j] = tempor;
			}
	}
}

