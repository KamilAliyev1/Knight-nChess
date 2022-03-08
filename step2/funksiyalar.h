#pragma once

void spaceGiver() {
	int i = _getch();
	if (i<58 && i>47)
		i = 32;
	_putch(char(i));
	spaceGiver();
}
void BigLowchanger() {
	int i = _getch();
	if (i < 123 && i>96)
		i -= 32;
	else if (i < 91 && i>64)
		i += 32;

	_putch(char(i));
	BigLowchanger();
}
void displayWay(int wayArr[][2]) {
	for (size_t i = 0; i < 64; i++)
	{
		cout << wayArr[i][0] + 1 << ' ' << char(wayArr[i][1] + 65) << " | ";
	}
}
void showTable(char arr[][8], int size) {
	for (size_t i = 0; i < size + 1; i++)
	{
		if (i < size)cout << i + 1;
		if (i == size) cout << ' ';
		for (size_t j = 0; j < size; j++)
		{
			i < size ? cout << arr[i][j] : cout << char(65 + j);
		}
		cout << '\n';
	}
}
void Knightfinder(char arr[][8], int adressKnightArr[], int size) {
	for (size_t i = 0; i < size; i++)
	{
		for (size_t j = 0; j < size; j++)
		{
			if (arr[i][j] == 'N') {
				adressKnightArr[0] = i;
				adressKnightArr[1] = j;
				break;
			}
		}
	}
}
void KnightLegalMoves(char arr[][8], int movesArr[][2], int adressKnightArr[]) {
	int x = adressKnightArr[0];
	int y = adressKnightArr[1];
	int i = 0;
	if (x - 1 > -1 && y - 2 > -1) { // moves1    left-2 up-1 
		movesArr[i][0] = x - 1;
		movesArr[i][1] = y - 2;
		i++;
	}
	if (x - 1 > -1 && y + 2 < 8) { //move2  right-2 up-1
		movesArr[i][0] = x - 1;
		movesArr[i][1] = y + 2;
		i++;
	}
	if (x - 2 > -1 && y + 1 < 8) { //move3 right-1 up-2
		movesArr[i][0] = x - 2;
		movesArr[i][1] = y + 1;
		i++;
	}
	if (x - 2 > -1 && y - 1 > -1) { //move4 left-1 up-2
		movesArr[i][0] = x - 2;
		movesArr[i][1] = y - 1;
		i++;
	}
	if (x + 2 < 8 && y + 1 < 8) { // move5 right-1 down-2
		movesArr[i][0] = x + 2;
		movesArr[i][1] = y + 1;
		i++;
	}
	if (x + 1 < 8 && y + 2 < 8) {  //move6 right-2 down-1
		movesArr[i][0] = x + 1;
		movesArr[i][1] = y + 2;
		i++;
	}
	if (x + 1 < 8 && y - 2 > -1) { //move7 left-2 down-1
		movesArr[i][0] = x + 1;
		movesArr[i][1] = y - 2;
		i++;
	}
	if (x + 2 < 8 && y - 1 > -1) { //move8 left-1 down-2
		movesArr[i][0] = x + 2;
		movesArr[i][1] = y - 1;
		i++;
	}
	//fill with garbage
	if (i < 8) {
		for (i; i < 8; i++)
		{
			for (size_t j = 0; j < 2; j++)
			{
				movesArr[i][j] = -100;
			}
		}
	}

}
void KnightMove(char arr[][8], int adresKnightArr[], int movesArr[][2], int wayArr[][2], int back = 1) {
	int x = adresKnightArr[0];
	int y = adresKnightArr[1];
	int z = 0;
	bool stop = false;
	bool movement = false;
	//nece mumkun gedis oldugunu deyir
	for (size_t i = 0; i < 8; i++)// nece gedisin oldugunu deyir
	{
		if (movesArr[i][0] > -1) z++;
	} // nece gedisin oldugunu deyir
	//ilk mumkun gedisle yerini deyisir atin
	for (size_t i = 0; i < z; i++)
	{
		stop = false;
		for (size_t f = 0; f < 64; f++)
		{
			if (wayArr[f][0] == movesArr[i][0] && wayArr[f][1] == movesArr[i][1]) {
				stop = true; break;
			}
		}
		if (stop) continue; // eger gedis daha evvel gedilibse iterasyani kecir
		if (back > 1) {
			showTable(arr, 8);
			cout << "\ngeri itrasya1:" << x + 1 << char(y + 65) << endl;
		}
		arr[movesArr[i][0]][movesArr[i][1]] = 'N';
		//if (back > 1)
		//	showTable(arr, 8);
		arr[x][y] = ' ';
		movement = true;
		break;
	}
	//eger hereket olmayibsa evvelki yerine qayidib baska herket getsin
	//evvelki iterasyaya qayitmaliyam
	int evvelkiyeri = 1;
	for (size_t i = 0; i < 64; i++)
	{
		if (wayArr[i][0] < 0) {
			evvelkiyeri = i - 1;
			break;
		}
	}
	if (movement == false) {
		arr[x][y] = ' ';
		arr[wayArr[evvelkiyeri - back][0]][wayArr[evvelkiyeri - back][1]] = 'N';
		adresKnightArr[0] = wayArr[evvelkiyeri - back][0];
		adresKnightArr[1] = wayArr[evvelkiyeri - back][1];
		KnightLegalMoves(arr, movesArr, adresKnightArr);
		for (size_t i = 0; i < 8; i++)// nece gedisin oldugunu deyir
		{
			if (movesArr[i][0] > -1) z++;
		}
		for (size_t i = 0; i < z; i++)
		{
			stop = false;
			for (size_t f = 0; f < 64; f++)
			{
				if (wayArr[f][0] == movesArr[i][0] && wayArr[f][1] == movesArr[i][1]) {
					stop = true; break;
				}
			}
			movement = false;
			if (stop) break;
			movement = true;
		}
	}
	//cout << "\ngeri itrasya:" << x << y << endl;

	if (movement == false) {

		KnightMove(arr, adresKnightArr, movesArr, wayArr, back + 1);

	}

}
void fillOther(char arr[][8], bool colorchanger = false) {
	for (size_t i = 0; i < 8; i++)
	{
		for (size_t j = 0; j < 8; j++)
		{
			if (arr[i][j] != 'N') {
				if (colorchanger ? j % 2 == 0 : j % 2 != 0) arr[i][j] = ' ';
				else arr[i][j] = char(254);
			}
		}
		colorchanger = !colorchanger;
	}
}