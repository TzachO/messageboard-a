#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Direction.hpp"


using namespace std;

namespace ariel {
	class Board
	{
		unsigned int _max_col;
		unsigned int _max_row;
		vector<string> _board;
		
		static string getFill(unsigned int length);
		void fill(unsigned int start_row, unsigned int start_column, unsigned int end_column);
		void init(unsigned int row, unsigned int column);
		void init(unsigned int row, unsigned int column, Direction direction, unsigned int steps);
		
	public:
		void post(unsigned int row, unsigned int column, Direction direction, string text);
		string read(unsigned int row, unsigned int column, Direction direction, unsigned int length);
		void show();
	};
}

