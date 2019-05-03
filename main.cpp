/*	TermSnake: A game by Michael Dandrea
 *	Last Updated: 3/21/19
 *	Description: This game will ultimately be a version of the classic Snake game to be played in terminal
 */

#include <ncurses.h>
#include "snake.h"
//#include "game.h"

int main(void)
{
	WINDOW *board;
	int rows, cols, inity, initx, size;
	char key;
	srand(time(nullptr));

	// Initializing the curses environment for the game
	initscr(); 
	cbreak();
	halfdelay(1);
	noecho();
	keypad(stdscr, TRUE);
	curs_set(0);
	refresh();

	// Calculate the size of the board
	getmaxyx(stdscr, rows, cols);
	if(rows <= 50 || cols <= 100)
	{
		if(rows < (cols / 2))
			size = rows;
		else
			size = cols / 2;
	}
	else
		size = 50;

	initx = (cols - size) / 2;
	inity = (rows - size) / 2;
	board = newwin(size, size * 2, inity, initx);
	box(board, 0, 0);
	mvwprintw(board, (size / 2) - 1, (size) - 13, "Welcome to TermSnake v0.5!");
	mvwprintw(board, (size / 2), (size) - 13, "Press any key to continue");
	wrefresh(board);

	while(getch() == ERR);

	werase(board);
	box(board, 0, 0);

	Pos2D velocity = { 0, 0 }, init = { size, size/2 }, draw, temp;
	Snake snake(init);
	randomDraw(board, (Pos2D){(size * 2) - 1, size - 1}, 'o');
	
	while(key != 'q' && snake.inBounds(size))
	{
		draw = snake.getHead().get_pos();
		mvwprintw(board, draw.y, draw.x, "O");		

		if(key == 'w')
		{
			velocity = { 0, -1 };
		}
		if(key == 's')
		{
			velocity = { 0, 1 };
		}
		if(key == 'a')
		{
			velocity = { -2, 0 };
		}
		if(key == 'd')
		{
			velocity = { 2, 0 };
		}

		snake.move(velocity);
		draw = snake.getHead().get_pos();
		if((mvwinch(board, draw.y, draw.x) & A_CHARTEXT) != 'o')
		{
			temp = snake.getTail().get_pos();
			mvwprintw(board, temp.y, temp.x, " ");
			snake.removeTail();
		}
		else
		{
			randomDraw(board, (Pos2D){(size * 2) - 1, size - 1}, 'o');
		}

		if((mvwinch(board, draw.y, draw.x) & A_CHARTEXT) == 'O')
		{
			break;
		}
		
		mvwprintw(board, draw.y, draw.x, "0");		

		wrefresh(board);
		key = getch();
	}
	
	endwin();
	return 0;
}
