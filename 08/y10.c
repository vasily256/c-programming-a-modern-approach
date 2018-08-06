int i, j;
char checkers_board[8] [8] = {'\0'};

for (i = 0; i < 7; i++) {
	for (j = 0; j < 7; j++) {
		if ((i + j) % 2 == 0) {
			checkers_board[i] [j] = 'B';
		} else {
			checkers_board[i] [j] = 'R';
		}
	}
}
