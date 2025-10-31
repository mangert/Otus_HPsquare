#include <iostream>
#include <functional>
 

/* ������� �1 
*  ��������� ������� 25 ��������� ���������,
*  ����������� �� ��������* 
*/
int main() {

	constexpr int N = 25; //������ �������
	constexpr int n = N - 1; // ������ ���������� �������� �� ������ / �������

	std::function<bool(int, int)> conditions[26]; //������ ������� (25 ������� + 0 - ������ �������)
	// �������� �������
	conditions[0] = [](int x, int y) -> bool { return true; }; //����������� ������� - �� ������ � �������, ������ ����� ������� �������
	conditions[1] = [](int x, int y) -> bool { return (x > y); }; //������ ������� ����
	conditions[2] = [](int x, int y) -> bool { return (x == y); }; //���������
	conditions[3] = [n](int x, int y) -> bool { return (x == (n - y)); }; //�������� ���������
	conditions[4] = [n](int x, int y) -> bool { return (x <= (n + 5 - y)); }; //�� �������� ����� ������ ����	
	conditions[5] = [](int x, int y) -> bool { return (x / 2 == y); }; //������ ������
	conditions[6] = [](int x, int y) -> bool { return (x < 10 || y < 10); }; //������ ������ ��������� �� ��������
	conditions[7] = [n](int x, int y) -> bool { return (x > (n - 9) && y > (n - 9)); }; //������ ������ ��������� (9x9) ��������
	conditions[8] = [](int x, int y) -> bool { return (x == 0 || y == 0); }; //������� ����� � ���� ����
	conditions[9] = [](int x, int y) -> bool { return  (x + 11 <= y) || x >= y + 11; }; //��� ����������� ���� (11 - ������)
	conditions[10] = [](int x, int y) -> bool { return (x >= y + 1 && x / 2 <= y); }; //��� �� �������� ������ ����
	conditions[11] = [n](int x, int y) -> bool { return ((x % (n - 2) == 1) || (y % (n - 2) == 1)); }; //������� � �������� �� 1 ������
	
	conditions[12] = [](int x, int y) -> bool { 
		constexpr int radius_sq = 20 * 20;  
		return (x * x  +  y * y <= radius_sq); 
	}; // �������� ����� � ����� ������� ����
	
	conditions[13] = [n](int x, int y) -> bool { 		
		return (x + y) > (n - 5) && (x + y) < (n + 5);
	}; //����� ������ ���������� (5 - ������ ������)	
	
	conditions[14] = [n](int x, int y) -> bool { 
		constexpr int radius_sq = 20 * 20;
		return ((n - x + 1) * (n - x) + (n - y + 1) * (n - y) >= radius_sq); 
	}; // �� ��������� �������� ����� � ������ ������ ����

	conditions[15] = [](int x, int y) -> bool {
		return  ((x + 9 < y) && (x + 21 > y)) ||
			((x > y + 9) && (x < y + 21));  
	}; //��� ����� ����� �� ����� (9 ����� ���� �� ����(������), 21 - ������ � ������ ���������� ���� �����)

	conditions[16] = [](int x, int y) -> bool {
		return (x + y) >= 15 &&
			(x + y) < 34 && abs(x - y) < 10;
	}; // ������ ���������� � �������� 3 ��������

	conditions[17] = [](int x, int y) -> bool {				
		return y >= int(std::sin(float(x) / 3) * 8 + 17);
	}; //���������
	
	conditions[18] = [](int x, int y) -> bool { return ((x < 2 || y < 2) && x + y != 0); }; //������� ����� � ��� ���� �� ����������� 0,0
	conditions[19] = [n](int x, int y) -> bool { return (x % n == 0 || y % n == 0); }; //����� � ���� ����
	conditions[20] = [](int x, int y) -> bool { return (x % 2) == (y % 2); }; //��������
	conditions[21] = [](int x, int y) -> bool { return (x % (y + 1) == 0); }; // ����������� ���������� 
	conditions[22] = [n](int x, int y) -> bool { return (x % 3) == ((n - y) % 3); }; // ������������ ������� ������-������
	conditions[23] = [](int x, int y) -> bool { return (x % 2 == 0 && y % 3 == 0); }; //����������� �������������� �������
	conditions[24] = [n](int x, int y) -> bool { return (x == y) || (x == (n - y)); }; //��� ���������
	conditions[25] = [](int x, int y) -> bool { return (x % 6) == 0 || (y % 6) == 0; }; //�������� 

	
	// ������� ��� ��������
	constexpr int tasks_count = 26; //������ ������� �������
	for (int counter = 1; counter != tasks_count; ++counter) { //�������� � 1, ������ ��� 0 - ������ ����
		std::cout << "\n\n" <<"** Square number " << counter << " ** \n\n"; //�� ���������, ������ ��� ���� ������ ����������
		for (int y = 0; y != N; ++y) {
			for (int x = 0; x != N; ++x) {
				if (conditions[counter](x, y))
					std::cout << "# ";
				else std::cout << ". ";
			}
			std::cout << "\n";
		}
	}	
	return 0;
}