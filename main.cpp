#include <iostream>
#include <functional>
 

/* Домашка №1 
*  Программа выводит 25 вариантов квадратов,
*  заполненных по формулам* 
*/
int main() {

	constexpr int N = 25; //размер матрицы
	constexpr int n = N - 1; // индекс последнего элемента по строке / столбцу

	std::function<bool(int, int)> conditions[26]; //массив условий (25 задачек + 0 - просто квадрат)
	// описания условий
	conditions[0] = [](int x, int y) -> bool { return true; }; //заполненный квадрат - не входит в задачки, просто чтобы индексы совпали
	conditions[1] = [](int x, int y) -> bool { return (x > y); }; //правый верхний угол
	conditions[2] = [](int x, int y) -> bool { return (x == y); }; //диагональ
	conditions[3] = [n](int x, int y) -> bool { return (x == (n - y)); }; //обратная диагональ
	conditions[4] = [n](int x, int y) -> bool { return (x <= (n + 5 - y)); }; //не закрашен левый нижний угол	
	conditions[5] = [](int x, int y) -> bool { return (x / 2 == y); }; //кривая полоса
	conditions[6] = [](int x, int y) -> bool { return (x < 10 || y < 10); }; //нижний правый квадратик не закрашен
	conditions[7] = [n](int x, int y) -> bool { return (x > (n - 9) && y > (n - 9)); }; //нижний правый квадратик (9x9) закрашен
	conditions[8] = [](int x, int y) -> bool { return (x == 0 || y == 0); }; //угловая рамка в один слой
	conditions[9] = [](int x, int y) -> bool { return  (x + 11 <= y) || x >= y + 11; }; //два закрашенных угла (11 - отступ)
	conditions[10] = [](int x, int y) -> bool { return (x >= y + 1 && x / 2 <= y); }; //луч из верхнего левого угла
	conditions[11] = [n](int x, int y) -> bool { return ((x % (n - 2) == 1) || (y % (n - 2) == 1)); }; //рамочка с отступом на 1 клетку
	
	conditions[12] = [](int x, int y) -> bool { 
		constexpr int radius_sq = 20 * 20;  
		return (x * x  +  y * y <= radius_sq); 
	}; // четверть круга в левом верхнем углу
	
	conditions[13] = [n](int x, int y) -> bool { 		
		return (x + y) > (n - 5) && (x + y) < (n + 5);
	}; //косая полоса посередине (5 - ширина полосы)	
	
	conditions[14] = [n](int x, int y) -> bool { 
		constexpr int radius_sq = 20 * 20;
		return ((n - x + 1) * (n - x) + (n - y + 1) * (n - y) >= radius_sq); 
	}; // не закрашена четверть круга в правом нижнем углу

	conditions[15] = [](int x, int y) -> bool {
		return  ((x + 9 < y) && (x + 21 > y)) ||
			((x > y + 9) && (x < y + 21));  
	}; //две косые ленты по углам (9 сдвиг лент от угла(индекс), 21 - правая и нижняя коордитата края ленты)

	conditions[16] = [](int x, int y) -> bool {
		return (x + y) >= 15 &&
			(x + y) < 34 && abs(x - y) < 10;
	}; // ромбик посередине с отступом 3 клеточки

	conditions[17] = [](int x, int y) -> bool {				
		return y >= int(std::sin(float(x) / 3) * 8 + 17);
	}; //синусоида
	
	conditions[18] = [](int x, int y) -> bool { return ((x < 2 || y < 2) && x + y != 0); }; //угловая рамка в два слоя за исключением 0,0
	conditions[19] = [n](int x, int y) -> bool { return (x % n == 0 || y % n == 0); }; //рамка в один слой
	conditions[20] = [](int x, int y) -> bool { return (x % 2) == (y % 2); }; //шахматка
	conditions[21] = [](int x, int y) -> bool { return (x % (y + 1) == 0); }; // неочевидная абстракция 
	conditions[22] = [n](int x, int y) -> bool { return (x % 3) == ((n - y) % 3); }; // диагональная полоска справа-сверху
	conditions[23] = [](int x, int y) -> bool { return (x % 2 == 0 && y % 3 == 0); }; //разреженные горизонтальные полоски
	conditions[24] = [n](int x, int y) -> bool { return (x == y) || (x == (n - y)); }; //две диагонали
	conditions[25] = [](int x, int y) -> bool { return (x % 6) == 0 || (y % 6) == 0; }; //клеточка 

	
	// выводим все квадраты
	constexpr int tasks_count = 26; //размер массива условий
	for (int counter = 1; counter != tasks_count; ++counter) { //начинаем с 1, потому что 0 - пустое поле
		std::cout << "\n\n" <<"** Square number " << counter << " ** \n\n"; //по английски, потому что лень локаль подключать
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