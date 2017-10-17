/*	TermSnake: A game by Michael Dandrea
 *	Last Updated: 10/17/17
 *	Description: This game will ultimately be a version of the classic Snake game to be played in terminal
 */

#include <ncurses.h>

int main(void)
{
	WINDOW *board;
	int rows, cols, inity, initx, size;

	// Initializing the curses environment for the game
	initscr(); 
	cbreak();
	noecho();
	keypad(stdscr, TRUE);

	// Calculate the size of the board
	getmaxyx(stdscr, rows, cols);
	if(rows <= 30 || cols <= 30)
	{
		if(rows < cols)
			size = rows;
		else
			size = cols;
	}
	else
		size = 30;

	initx = 0;
	inity = 0;
	board = newwin(size, size, inity, initx);
	box(board, 0, 0);
	wrefresh(board);
	refresh();

	getch();
	
	endwin();
	return 0;
}
