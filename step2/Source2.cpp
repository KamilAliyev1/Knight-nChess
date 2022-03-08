#include <cctype>
#include<iostream>
#include<string>
#include <cmath>
#include <typeinfo>
#include <iomanip> 
#include <conio.h>

using namespace std;

#include "funksiyalar.h";


//AZE:
//plan:
//1)her defe duymeye basilanda herket edir at eger ENTER duymesine baslibsa gedilen butun yolu cap edir her defe
//2)taxtani yaradiram showtable ile gsoterirem 
//3)ati tapiram Knightfinder vasitesi ile
//4)Knight legalmoves ile atin mumkun 8 gedisinden hansilar varsa elave edirem legal gedislsere
//5)atin olmadigi yerlerde qara ve ag rengde prob ola biler die at olmayan yerleri yeniden doldururam fillother ile
//6) 1.knightmove ile mumkun gedislerden ilk olana gedir
//2.eger ilk mumkun gedis evveceden gedilibse onu nezere almir daha sonraki gedislere baxir
//3.eger mumkun gedis yolu qalmayibsa evvelki lokasyasina geri qayidir ve yeniden yuxarida verdiyim sertler tekrarlanir
//4.eger yenede mumkun gedis yoxdursa o zaman evvelki dahada evvelki lokasyalara(iterasyalara rekursiya ile qayidir 

//ENG:
// //plan
// 1) moves every time you press the button, if the ENTER button is pressed, it print all the way
// 2) I create a board and show it with a showtable
// 3) I find the knight by means of Knightfinder
// 4) Knight with legalmoves I add to the legal moves, which are 8 possible moves
// 5) Where there is no knight, there may be a black and white char.
// 6) Goes to the first of the possible moves with 1.knightmove
//2.if the first possible moves is already taken, it does not look this , it looks at the other moves
//3.If there is no way left, return to the previous location and repeat the hardships I gave above.
//4. If there is no possible moves again, then return to the previous locations (iterations with recursion)



int main() {

	//11111111111111
    //spaceGiver();
    //2222222222
    //BigLowchanger();
    //333333333
	int back = 1;

	bool icyoxmala = false;

	int sira = 0;

	int const size = 8;
	char arr[size][size];

	int const sizeN = 8; // Knight can max 8 moves 
	int movesArr[sizeN][2];

	int const sizeA = 2;
	int adressKnightArr[sizeA];

	int const sizeH = 64;
	int wayArr[sizeH][2];

	char temparr[size][size];
	//fill garbage with wayArr
	for (size_t i = 0; i < 64; i++)
	{
		for (size_t j = 0; j < 2; j++)
		{
			wayArr[i][j] = -1;
		}
	}

	int g;

	//fill array
	bool colorchanger = false;
	for (size_t i = 0; i < size; i++)
	{
		for (size_t j = 0; j < size; j++)
		{
			if (colorchanger ? j % 2 == 0 : j % 2 != 0) arr[i][j] = ' ';
			else arr[i][j] = char(254);

		}
		colorchanger = !colorchanger;
	}
	arr[0][0] = 'N';

	//show table
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
	while (true)
	{
		g = _getch();
		Knightfinder(arr, adressKnightArr, size);
		icyoxmala = true;//tekrarciligin qarsisini alir atin getdiyi butun yollarin icinde//can't add same value in this array
		for (size_t i = 0; i < 64; i++)
		{
			if (wayArr[i][0] == adressKnightArr[0] && wayArr[i][1] == adressKnightArr[1])
			{
				icyoxmala = false;
				break;
			}
		}
		if (icyoxmala) {
			wayArr[sira][0] = adressKnightArr[0];
			wayArr[sira][1] = adressKnightArr[1];
			sira++;
		}
		cout << "\n\n\n";
		cout << adressKnightArr[0] + 1 << ' ' << char(adressKnightArr[1] + 65);
		cout << "\n\n\n";
		KnightLegalMoves(arr, movesArr, adressKnightArr);
		//mumkun gedisleri cap edirem
		for (size_t i = 0; i < 8; i++)
		{
			for (size_t j = 0; j < 2; j++)
			{
				if (movesArr[i][j] > -1)
					j == 0 ? cout << movesArr[i][j] + 1 << ' ' : cout << char(movesArr[i][j] + 65);
				else
					break;
			}
			cout << endl;
		}
		KnightMove(arr, adressKnightArr, movesArr, wayArr, back);
		fillOther(arr);
		showTable(arr, size);
		if (g == 13) displayWay(wayArr);
	}

}






