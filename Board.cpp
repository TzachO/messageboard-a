#include "Board.hpp"

void ariel::Board::post(unsigned int row, unsigned int column, Direction direction, string text)
{
	const unsigned int length = text.size();

	init(row, column, direction, length);

	if (direction == Direction::Horizontal) {
		for (int i = column; i < column + length; ++i) {
			_board[row][i] = text[i - column];
		}
	}
	else {
		for (int i = row; i < row + length; ++i) {
			_board[i][column] = text[i - row];
		}
	}
}

string ariel::Board::read(unsigned int row, unsigned int column, Direction direction, unsigned int length)
{
	/*
	init(row, column, direction, length);

	string result = "";

	if (direction == Direction::Horizontal) {
		result = _board[row].substr(column, length);
	}
	else {
		for (int i = row; i < row + length; ++i) {
			result += _board[i][column];
		}
	}

	return result;
	*/

	#pragma region optimized

	string result = "";

	if (direction == Direction::Horizontal) {
		if (_max_row < row) {
			return getFill(length);
		}

		if (_max_col < column + length - 1) {
			for (int i = column; i <= _max_col; ++i) {
				result += _board[row][i];
				--length;
			}

			result.append(getFill(length));
		}
		else {
			return _board[row].substr(column, length);
		}
	}
	else {
		if (_max_col < column) {
			return getFill(length);
		}

		if (_max_row < row + length - 1) {
			for (int i = row; i <= _max_row; ++i) {
				result += _board[i][column];
				--length;
			}

			result.append(getFill(length));
		}
		else {
			for (int i = row; i < row + length; ++i) {
				result += _board[i][column];
			}
		}
	}


	return result;

	#pragma endregion
}

void ariel::Board::show()
{
	for (int i = 0; i < _board.size(); ++i) {
		cout << _board[i] << endl;
	}
}



void ariel::Board::init(unsigned int row, unsigned int column)
{
	string str = getFill(column + 1);

	for (int i = 0; i <= row; ++i) {
		_board.push_back(str);
	}

	_max_row = row;
	_max_col = column;
}

void ariel::Board::init(unsigned int row, unsigned int column, Direction direction, unsigned int length)
{
	if (_board.empty()) {
		if (direction == Direction::Horizontal) {
			this->init(row, column + length - 1);
		}
		else {
			this->init(row + length - 1, column);
		}
	}

	if (direction == Direction::Horizontal) {
		const int col_dif = column + length - 1 - _max_col;

		// we need to allocate more columns
		if (col_dif > 0) {
			string str = getFill(col_dif);

			for (int i = 0; i <= _max_row; ++i) {
				_board[i].append(str);
			}

			_max_col = column + length - 1;
		}

		const int row_dif = row - _max_row;

		// we need to allocate more rows
		if (row_dif > 0) {
			string str = getFill(_max_col + 1);

			for (int i = 0; i < row_dif; ++i) {
				_board.push_back(str);
			}

			_max_row = row;
		}
	}
	else {
		const int col_dif = column - _max_col;

		// we need to allocate more columns
		if (col_dif > 0) {
			string str = getFill(col_dif);

			for (int i = 0; i <= _max_row; ++i) {
				_board[i].append(str);
			}

			_max_col = column;
		}

		const int row_dif = row + length - 1 - _max_row;

		// we need to allocate more rows
		if (row_dif > 0) {
			string str = getFill(_max_col + 1);

			for (int i = 0; i < row_dif; ++i) {
				_board.push_back(str);
			}

			_max_row = row + length - 1;
		}
	}
}

string ariel::Board::getFill(unsigned int length)
{
	string result = "";

	for (int i = 0; i < length; ++i) {
		result.append("_");
	}

	return result;
}


void ariel::Board::fill(unsigned int row, unsigned int start_column, unsigned int end_column)
{
	if (_board.empty()) {
		this->init(row, end_column);
	}
	const int dif = end_column - _board[row].size();

	if (dif > 0) {
		char* str = new char[dif];

		for (int i = 0; i < dif; ++i) {
			str[i] = '_';
		}

		_board[row].append(str);
	}
}

