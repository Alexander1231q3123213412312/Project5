#define _USE_MATH_DEFINES //�������������� ��������� 
#include <iostream> 
#include <math.h> //��������� �������������� ��������� 

class ein_rechtwinkliges_Dreieck
{
private:
	int size, kkkk;
	float number;
	int* TRIANGLE_x = new int[size]; //������� �������������� ������������ 
	int* TRIANGLE_y = new int[size]; //������� �������������� ������������ 
	int* TRIANGLE_z = new int[size]; //���������� �������������� ������������ 
	float* TRIANGLE_coord_1 = new float[size]; //���� �������������� ������������ 
	float* TRIANGLE_coord_2 = new float[size]; //���� �������������� ������������ 
	float* TRIANGLE_coord_3 = new float[size]; //���� �������������� ������������ 
	float* TRIANGLE_Flaeche = new float[size]; //�������� ������������� ������������� 
	bool* flag = new bool[size];

public:
	ein_rechtwinkliges_Dreieck(int size)
	{
		this->size = size;
		this->TRIANGLE_x = new int[size];
		this->TRIANGLE_y = new int[size];
		this->TRIANGLE_z = new int[size];
		this->flag = new bool[size];
		this->TRIANGLE_coord_1 = new float[size];
		this->TRIANGLE_coord_2 = new float[size];
		this->TRIANGLE_coord_3 = new float[size];
		this->TRIANGLE_Flaeche = new float[size];
		std::cout << "������� ������� ������������: " << std::endl;

		for (int i = 0; i < size; i++)
		{
			std::cin >> TRIANGLE_x[i];
			std::cin >> TRIANGLE_y[i];
			std::cin >> TRIANGLE_z[i];
		}
	}

	void Loesung()
	{
		for (int i = 0; i < size; i++)
		{
			if (TRIANGLE_x[i] + TRIANGLE_y[i] > TRIANGLE_z[i] && TRIANGLE_y[i] + TRIANGLE_z[i] > TRIANGLE_x[i] && TRIANGLE_x[i] + TRIANGLE_z[i] > TRIANGLE_y[i]) // ������������� ������������ 
			{
				TRIANGLE_coord_1[i] = acos((pow(TRIANGLE_x[i], 2) + pow(TRIANGLE_y[i], 2) - pow(TRIANGLE_z[i], 2)) / (2 * TRIANGLE_x[i] * TRIANGLE_y[i])) * 180 / M_PI;//����� ���� 
				TRIANGLE_coord_2[i] = acos((pow(TRIANGLE_x[i], 2) + pow(TRIANGLE_z[i], 2) - pow(TRIANGLE_y[i], 2)) / (2 * TRIANGLE_x[i] * TRIANGLE_z[i])) * 180 / M_PI;//����� ���� 
				TRIANGLE_coord_3[i] = acos((pow(TRIANGLE_z[i], 2) + pow(TRIANGLE_y[i], 2) - pow(TRIANGLE_x[i], 2)) / (2 * TRIANGLE_z[i] * TRIANGLE_y[i])) * 180 / M_PI;//����� ���� 
				if (((TRIANGLE_coord_1[i] + TRIANGLE_coord_2[i] + TRIANGLE_coord_3[i]) == 180) && TRIANGLE_coord_1[i] != 0 && TRIANGLE_coord_2[i] != 0 && TRIANGLE_coord_3[i] != 0)
				{
					if (TRIANGLE_coord_1[i] == 90)
					{
						flag[i] = true;
						TRIANGLE_Flaeche[i] = (TRIANGLE_x[i] * TRIANGLE_y[i]) / 2.0; //���������� ������� �������������� ������������ 
						std::cout << "������������� ����������� �" << i << " ����������" << std::endl;
						number = TRIANGLE_z[i];
					}
					else
					{
						flag[i] = false;
						std::cout << "������������� ����������� �" << i << " �� ����������" << std::endl;
					}
				}
			}

			else
			{
				flag[i] = false;
				std::cout << "������������� ����������� �" << i << " �� ����������" << std::endl;
			}
		}

		for (int i = 0; i < size; i++)
		{
			std::cout << std::endl;
			if (flag[i] == true) {
				std::cout << "�" << i << std::endl << "�������: " << TRIANGLE_x[i] << " " << TRIANGLE_y[i] << " " << TRIANGLE_z[i] << std::endl;
				std::cout << "�������: " << TRIANGLE_Flaeche[i] << std::endl << "��������: " << TRIANGLE_x[i] + TRIANGLE_y[i] + TRIANGLE_z[i] << std::endl;
				std::cout << "����: " << TRIANGLE_coord_1[i] << " " << TRIANGLE_coord_2[i] << " " << TRIANGLE_coord_3[i] << std::endl;
			}
		}
	}

	float der_Suche()
	{
		for (int i = 0; i < size; i++)
	{
			if (number > TRIANGLE_z[i])
			{
				number = TRIANGLE_z[i];
				kkkk = i;
			}
		}
		return kkkk;
	}

	~ein_rechtwinkliges_Dreieck()
	{
		delete[] TRIANGLE_x, TRIANGLE_y, TRIANGLE_z, TRIANGLE_coord_1, TRIANGLE_coord_2, TRIANGLE_coord_3, TRIANGLE_Flaeche, flag;
	}
};



class ein_Dreieck
{
private:
	int size, kkkk;
	float number;
	int* TRIANGLE_x = new int[size]; //������� ������������ 
	int* TRIANGLE_y = new int[size]; //������� ������������ 
	int* TRIANGLE_z = new int[size]; //���������� ������������ 
	float* TRIANGLE_coord_1 = new float[size]; //���� ������������ 
	float* TRIANGLE_coord_2 = new float[size]; //���� ������������ 
	float* TRIANGLE_coord_3 = new float[size]; //���� ������������ 
	float* TRIANGLE_Flaeche = new float[size]; //������� ������������ 
	bool* flag = new bool[size]; //������������� ������������ ��� ������ ���������� 
public:
	ein_Dreieck(int size)
			{
		this->size = size;
		this->TRIANGLE_x = new int[size];
		this->TRIANGLE_y = new int[size];
		this->TRIANGLE_z = new int[size];
		this->flag = new bool[size];
		this->TRIANGLE_coord_1 = new float[size];
		this->TRIANGLE_coord_2 = new float[size];
		this->TRIANGLE_coord_3 = new float[size];
		this->TRIANGLE_Flaeche = new float[size];
		std::cout << "������� ������� ������������: " << std::endl;
		for (int i = 0; i < size; i++)
		{		std::cin >> TRIANGLE_x[i];
			std::cin >> TRIANGLE_y[i];
			std::cin >> TRIANGLE_z[i];
		}
	}

	void Loesung()
	{
		for (int i = 0; i < size; i++)
		{		if (TRIANGLE_x[i] + TRIANGLE_y[i] > TRIANGLE_z[i] && TRIANGLE_y[i] + TRIANGLE_z[i] > TRIANGLE_x[i] && TRIANGLE_x[i] + TRIANGLE_z[i] > TRIANGLE_y[i]) // ������������� ������������ 
			{
				TRIANGLE_coord_1[i] = acos((pow(TRIANGLE_x[i], 2) + pow(TRIANGLE_y[i], 2) - pow(TRIANGLE_z[i], 2)) / (2 * TRIANGLE_x[i] * TRIANGLE_y[i])) * 180 / M_PI;//����� ����
				TRIANGLE_coord_2[i] = acos((pow(TRIANGLE_x[i], 2) + pow(TRIANGLE_z[i], 2) - pow(TRIANGLE_y[i], 2)) / (2 * TRIANGLE_x[i] * TRIANGLE_z[i])) * 180 / M_PI;//����� ���� 
				TRIANGLE_coord_3[i] = acos((pow(TRIANGLE_z[i], 2) + pow(TRIANGLE_y[i], 2) - pow(TRIANGLE_x[i], 2)) / (2 * TRIANGLE_z[i] * TRIANGLE_y[i])) * 180 / M_PI;//����� ����
				if (((TRIANGLE_coord_1[i] + TRIANGLE_coord_2[i] + TRIANGLE_coord_3[i]) == 180) && TRIANGLE_coord_1[i] != 0 && TRIANGLE_coord_2[i] != 0 && TRIANGLE_coord_3[i] != 0)
				{

					flag[i] = true;

					if (TRIANGLE_x == TRIANGLE_y && TRIANGLE_x == TRIANGLE_z && TRIANGLE_y == TRIANGLE_z)

					{

						TRIANGLE_Flaeche[i] = (pow(TRIANGLE_x[i], 2) * pow(3, 0.5)) / 4; //<- 



					} 

					if (TRIANGLE_coord_1[i] == 90) // | 



					{



						TRIANGLE_Flaeche[i] = (TRIANGLE_x[i] * TRIANGLE_y[i]) / 2.0; //<- ������ ������� ������� ������������� � ������������ ���������� 



					} 
					else // | 

					{ // | 

						float P = (TRIANGLE_x[i] + TRIANGLE_y[i] + TRIANGLE_z[i]) / 2.0; // | 

						TRIANGLE_Flaeche[i] = pow(P * (P - TRIANGLE_x[i]) * (P - TRIANGLE_y[i]) * (P - TRIANGLE_z[i]), 0.5); //<- 

					}

					std::cout << "����������� �" << i << " ����������" << std::endl;

				}

			}

			else


			{

				flag[i] = false;



				std::cout << "����������� �" << i << " �� ����������" << std::endl;
			}
		}
		for (int i = 0; i < size; i++) //����� ���������� ������������ ������������� 
		{
			std::cout << std::endl;



			if (flag[i] == true) {



				std::cout << "�" << i << std::endl << "�������: " << TRIANGLE_x[i] << " " << TRIANGLE_y[i] << " " << TRIANGLE_z[i] << std::endl;



				std::cout << "�������: " << TRIANGLE_Flaeche[i] << std::endl << "��������: " << TRIANGLE_x[i] + TRIANGLE_y[i] + TRIANGLE_z[i] << std::endl;



				std::cout << "����: " << TRIANGLE_coord_1[i] << " " << TRIANGLE_coord_2[i] << " " << TRIANGLE_coord_3[i] << std::endl;



			}		}
	}
	float der_Suche() //����� ������������ ������� ������ 
	{
		number = -1;
		for (int i = 0; i < size; i++)
		{
			if (number < TRIANGLE_Flaeche[i])
			{	number = TRIANGLE_Flaeche[i];
				kkkk = i;
			}
		}
		return kkkk;
	}
	~ein_Dreieck()
	{delete[] TRIANGLE_x, TRIANGLE_y, TRIANGLE_z, TRIANGLE_coord_1, TRIANGLE_coord_2, TRIANGLE_coord_3, TRIANGLE_Flaeche, flag; //�������� ������ 
	}
};



void Input(int* n, int* m)
{
	std::cout << "������� ���������� ������������� � ������������ �������������: " << std::endl;
	std::cin >> *n;
	std::cin >> *m;
}



int main()
{
	setlocale(LC_ALL, "Ru");
	int n, m;
	Input(&n, &m);
	ein_rechtwinkliges_Dreieck a(n);
	a.Loesung();
	float c = a.der_Suche();
	std::cout << std::endl << "������������� ����������� � ����������� ����������� �: " << c << std::endl;
	std::cout << std::endl << "_____________________________________________________" << std::endl;
	ein_Dreieck b(m);
	b.Loesung();
	float d = b.der_Suche();
	std::cout << std::endl << "����������� � ����������� ����������� �: " << d << std::endl;
	system("pause");
	return 0;
}