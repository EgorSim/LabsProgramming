#include <iostream>
#include <fstream>
#include <cassert>
#include "AVLTree.h"

int main() {
	std::ifstream fin;
	fin.open("input.txt");
	assert(fin);

	AVLTree tr;
	while (!fin.eof()) {
		int temp;
		fin >> temp;
		tr.insert(temp);
	}


	tr.prinfTree();


	//tr.checkAllNodesBF();

	return 0;
}