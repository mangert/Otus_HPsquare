#include <iostream>
#include <functional>
 

int main() {

	constexpr int N = 25; //размер матрицы
	constexpr int n = N - 1; // индекс последнего элемента по строке / столбцу

	std::function<bool(int, int)> conditions[26]; //массив условий (25 задачек + 0 - просто квадрат)
	// описания условий
	conditions[0] = [](int x, int y) -> bool { return true; }; //заполненный квадрат
	conditions[1] = [](int x, int y) -> bool { return (x > y); }; //правый верхний угол
	conditions[2] = [](int x, int y) -> bool { return (x == y); }; //диагональ
	conditions[3] = [n](int x, int y) -> bool { return (x == (n - y)); }; //обратная диагональ
	conditions[4] = [n](int x, int y) -> bool { return (x <= (n + 5 - y)); }; //не закрашен левый нижний угол	
	conditions[5] = [](int x, int y) -> bool { return (x / 2 == y); }; //кривая полоса
	conditions[6] = [](int x, int y) -> bool { return (x < 10 || y < 10); }; //нижний правый квадратик не закрашен
	conditions[7] = [n](int x, int y) -> bool { return (x > (n - 9) && y > (n - 9)); }; //нижний правый квадратик (9x9) закрашен
	conditions[8] = [](int x, int y) -> bool { return (x == 0 || y == 0); }; //угловая рамка в один слой
	
	conditions[10] = [](int x, int y) -> bool { return (x >= y + 1 && x / 2 <= y); }; //луч из верхнего левого угла
	conditions[11] = [N](int x, int y) -> bool { return ((x % 22 == 1) || (y % 22 == 1)); }; //рамочка с отступом на 1 клетку: 22 - размер "дырки"(23)+1; 1 - отступ левого и вернхнего от края
	conditions[12] = [](int x, int y) -> bool { 
			constexpr int radius_sq = 20 * 20;  
			return (x * x  +  y * y <= radius_sq); 
		}; // четверть круга в левом верхнем углу

	conditions[14] = [n](int x, int y) -> bool { 
			constexpr int radius_sq = 20 * 20;
			return ((n - x) * (n - x) + (n - y) * (n - y) >= radius_sq); 
		}; // не закрашена четверть круга в правом нижнем углу - НЕ ДОДЕЛАНА!!!
	
	conditions[18] = [](int x, int y) -> bool { return ((x < 2 || y < 2) && x + y != 0); }; //угловая рамка в два слоя за исключением 0,0
	conditions[20] = [](int x, int y) -> bool { return (x % 2) == (y % 2); }; //шахматка
	conditions[21] = [](int x, int y) -> bool { return (x % (y + 1) == 0); }; // неочевидная абстракция 
	conditions[22] = [n](int x, int y) -> bool { return (x % 3) == ((n - y) % 3); }; // диагональная полоска справа-сверху
	conditions[23] = [](int x, int y) -> bool { return (x % 2 == 0 && y % 3 == 0); }; //разреженные горизонтальные полоски
	conditions[24] = [n](int x, int y) -> bool { return (x == y) || (x == (n - y)); }; //две диагонали return
	conditions[25] = [](int x, int y) -> bool { return (x % 6) == 0 || (y % 6) == 0; }; //клеточка 
	

	for (int y = 0; y != N; ++y) {
		for (int x = 0; x != N; ++x) {
			if(conditions[21](x, y))
				std::cout << "# ";
			else std::cout << ". ";
		}
		std::cout << "\n";
	}	
	
	return 0;
}