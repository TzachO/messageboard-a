#include <iostream>
#include <vector>
#include "Board.hpp"
using namespace ariel;

using namespace std;

int main() {
	Board board;

	board.post(0, 0, Direction::Horizontal, "Hello");
	board.post(0, 6, Direction::Vertical, "World!");
	board.post(1, 8, Direction::Horizontal, "Very");
	board.post(2, 8, Direction::Horizontal, "Nice");
	board.post(0, 10, Direction::Vertical, "I Dominate");
	board.show();

	cout << endl;
	cout << board.read(0, 0, Direction::Horizontal, 5);

	cout << endl;
	cout << board.read(1, 8, Direction::Horizontal, 4);

	cout << endl;
	cout << board.read(2, 8, Direction::Horizontal, 4);

	cout << endl;
	cout << board.read(0, 6, Direction::Vertical, 6);

	cout << endl;
	cout << board.read(0, 10, Direction::Vertical, 10);

	cout << endl;
	cout << board.read(20, 20, Direction::Vertical, 5);

	//cout << endl << endl;
	//board.show();
	return 0;
}