// Lab11.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <algorithm>
#include <fstream>
#include <functional>

class Sup
{
public:
	std::vector<int> shortest;
	std::vector<bool> visited;
	std::vector<int> parent;
	
	Sup(int graphSize)
		: shortest(graphSize, INT32_MAX)
		, visited(graphSize, false)
		, parent(graphSize, -1) {}


};

void InputGraph(const std::string& path)
{
	std::cout << "Input count top\n";
	int countTop = 0;
	std::cin >> countTop;

	std::cout << "Input count edge\n";
	int countEdge = 0;
	std::cin >> countEdge;

	std::cout << "Input graph (top1 <-> top2 sizeEdge)\n";

	std::ofstream fout(path);
	fout << countTop << " " << countEdge << '\n';
	int t1, t2;
	for (int i = 0; i < countEdge; i++)
	{
		std::cin >> t1 >> t2;
		fout << t1 << " " << t2 << '\n';
	}

	fout.close();
}

std::vector<std::list<std::pair<int, int>>> ReadGraph(const std::string& path)
{
	std::ifstream fin(path);

	int countTop, countEdge;
	fin >> countTop >> countEdge;
	std::vector<std::list<std::pair<int, int>>> graph(countTop, std::list<std::pair<int, int>>());
	std::vector<std::vector<int>> graphMatrix(countTop, std::vector<int>(countTop));
	int t1, t2, size;
	while (fin >> t1 >> t2 >> size)
	{
		graph[t1].push_back({ t2, size });
		graph[t2].push_back({ t1, size });
	}

	fin.close();

	return graph;
}

std::list<std::pair<int, int>>::iterator min_element_if(std::list<std::pair<int, int>>& list,
		std::function<bool(std::pair<int, int>)> Pred = [](const std::pair<int, int>& x) {return true; })
{
	auto itMin = list.end();
	int min = INT32_MAX;

	for (auto it = list.begin(); it != list.end(); it++)
	{
		if (it->second < min && Pred(*it))
		{
			min = it->second;
			itMin = it;
		}
	}
	return itMin;
}

void Dijckstra(const std::vector<std::list<std::pair<int, int>>>& graph)
{

}

int main()
{
	const std::string path = "graph.txt";
	InputGraph(path);

	ReadGraph(path);
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
