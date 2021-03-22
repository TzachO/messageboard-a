#include "doctest.h"
#include "Board.hpp"
using namespace ariel;

#include <string>
#include <algorithm>
using namespace std;

TEST_CASE("Complete Strings") {
	Board board;

	board.post(0, 0, Direction::Horizontal, "Hello");
	board.post(0, 6, Direction::Vertical, "World!");
	board.post(1, 8, Direction::Horizontal, "Very");
	board.post(2, 8, Direction::Horizontal, "Nice");
	board.post(0, 13, Direction::Vertical, "I Dominate");

    CHECK(board.read(0, 0, Direction::Horizontal, 5) == "Hello");
	CHECK(board.read(1, 8, Direction::Horizontal, 4) == "Very");
	CHECK(board.read(2, 8, Direction::Horizontal, 4) == "Nice");
	CHECK(board.read(0, 6, Direction::Vertical, 6) == "World!");
	CHECK(board.read(0, 13, Direction::Vertical, 10) == "I Dominate");
}

TEST_CASE("Partial Strings") {
	Board board;

	board.post(0, 0, Direction::Horizontal, "Hello");
	board.post(0, 6, Direction::Vertical, "World!");
	board.post(1, 8, Direction::Horizontal, "Very");
	board.post(2, 8, Direction::Horizontal, "Nice");
	board.post(0, 10, Direction::Vertical, "I Dominate");

	CHECK(board.read(0, 0, Direction::Horizontal, 7) == "Hello_W");
	CHECK(board.read(1, 7, Direction::Horizontal, 7) == "_Ve y__");
	CHECK(board.read(2, 6, Direction::Horizontal, 8) == "r_NiDe__");
	CHECK(board.read(0, 6, Direction::Vertical, 8) == "World!__");
	CHECK(board.read(0, 10, Direction::Vertical, 15) == "I Dominate_____");
}

TEST_CASE("Blank") {
	Board board;

	board.post(0, 0, Direction::Horizontal, "Hello");
	board.post(0, 6, Direction::Vertical, "World!");
	board.post(1, 8, Direction::Horizontal, "Very");
	board.post(2, 8, Direction::Horizontal, "Nice");
	board.post(0, 10, Direction::Vertical, "I Dominate");

	CHECK(board.read(10, 50, Direction::Horizontal, 5) == "_____");
	CHECK(board.read(20, 40, Direction::Horizontal, 4) == "____");
	CHECK(board.read(30, 30, Direction::Horizontal, 3) == "___");
	CHECK(board.read(40, 20, Direction::Vertical, 2) == "__");
	CHECK(board.read(50, 10, Direction::Vertical, 1) == "_");
}

TEST_CASE("Overwrite") {
	Board board;

	board.post(0, 0, Direction::Horizontal, "Hello");
	CHECK(board.read(0, 0, Direction::Horizontal, 5) == "Hello");

	board.post(0, 2, Direction::Vertical, "World!");
	CHECK(board.read(0, 2, Direction::Vertical, 6) == "World!");
	CHECK(board.read(0, 0, Direction::Horizontal, 5) == "HeWlo");

	board.post(1, 8, Direction::Horizontal, "Very");
	CHECK(board.read(1, 8, Direction::Horizontal, 4) == "Very");

	board.post(2, 8, Direction::Horizontal, "Nice");
	CHECK(board.read(2, 8, Direction::Horizontal, 4) == "Nice");

	board.post(0, 10, Direction::Vertical, "I Dominate");
	CHECK(board.read(0, 10, Direction::Vertical, 10) == "I Dominate");
	CHECK(board.read(1, 8, Direction::Horizontal, 4) == "Ve y");
	CHECK(board.read(2, 8, Direction::Horizontal, 4) == "NiDe");
}

