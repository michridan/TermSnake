/*	TermSnake: A game by Michael Dandrea
 *	Last Updated: 8/7/19
 *	Description: This game will ultimately be a version of the classic Snake game to be played in terminal
 */

#include <ncurses.h>
#include "snake.h"
//#include "game.h"

int main(void)
{
	WINDOW *board;
	int rows, cols, inity, initx, size;
	int key, fresh;
	srand(time(nullptr));
	const Pos2D lft = {-2, 0}, rt = {2, 0}, u = {0, -1}, dn = {0, 1};

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

	initx = (cols - (size * 2)) / 2;
	inity = (rows - size) / 2;
	board = newwin(size, size * 2 + 1, inity, initx);
	box(board, 0, 0);
	mvwprintw(board, (size / 2) - 1, (size) - 13, "Welcome to TermSnake v1.0!");
	mvwprintw(board, (size / 2), (size) - 13, "Press any key to continue");
	wrefresh(board);
	while(getch() == ERR);

	while(key != 'q')
	{

		werase(board);
		box(board, 0, 0);

		Pos2D velocity = { 0, 0 }, init = { size, size/2 }, draw, temp;
		Snake snake(init);
		randomDraw(board, (Pos2D){size - 2, size - 2}, 'o');
	
		while(key != 'q' && snake.isAlive(size))
		{
			fresh = time(nullptr);
			draw = snake.getHead().get_pos();
			mvwprintw(board, draw.y, draw.x, "O");		

			if(key == KEY_UP)
			{
				if(velocity != u && velocity != dn)
					velocity = u;
			}
			if(key == KEY_DOWN)
			{
				if(velocity != u && velocity != dn)
					velocity = (Pos2D){ 0, 1 };
			}
			if(key == KEY_LEFT)
			{
				if(velocity != lft && velocity != rt)
					velocity = lft;
			}
			if(key == KEY_RIGHT)
			{
				if(velocity != lft && velocity != rt)
					velocity = rt;
			}

			Pos2D before = snake.getHead().get_pos();
			snake.move(velocity);
			draw = snake.getHead().get_pos();
			if(!charBetween(board, before, draw, 'o'))
			{
				temp = snake.getTail().get_pos();
				mvwprintw(board, temp.y, temp.x, " ");
				snake.removeTail();
			}
			else
			{
				randomDraw(board, (Pos2D){size - 2, size - 2}, 'o');
			}

			if((mvwinch(board, draw.y, draw.x) & A_CHARTEXT) == 'O')
			{
				break;
			}

			mvwaddch(board, draw.y, draw.x, '@');		

			wrefresh(board);
			key = getch();
		}
		mvwaddch(board, draw.y, draw.x, 'X');
		mvwprintw(board, (size / 2), (size) - 5, "Game Over");
		mvwprintw(board, (size / 2) + 1, (size - 5), "q to quit");
		wrefresh(board);
	
		while((key = getch()) == ERR);
	}

	endwin();
	return 0;
}
