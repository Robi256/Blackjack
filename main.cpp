#include <iostream>
#include <random>
#include <string>


class drawCard
{
public:

	int randomNumber()
	{
		std::random_device rd; 
		std::mt19937 eng(rd()); 
		std::uniform_int_distribution<> distr(1, 11); 

		for (int n = 0; n < 2; ++n)
			distr(eng); 
		return distr(eng);
	}


	int firstCard = randomNumber();
	int secondCard = randomNumber();
	int cardSum = firstCard + secondCard;
	void playerDraw()
	{
		std::cout << "Your cards are: " << firstCard << " and " << secondCard << std::endl;
		std::cout << "Your total " << cardSum << std::endl << std::endl;
		total();
	}
	void total()
	{
		if (cardSum > 21)
		{
			playerLose();
			return;
		}
		if (cardSum == 21)
		{
			playerWin();
			return;
		}
	}
	void playerLose()
	{
		system("cls");
		std::cout << "You lose! Your total is " << cardSum << std::endl;
		return;
	}

	void playerWin()
	{
		system("cls");
		std::cout << "You won!!" << std::endl;
		return;
	}
	
	void drawNext()
	{
		std::string next;
		int thirdCard = randomNumber();
		std::cout << "Do you want another card? (Y/N) ";
		std::cin >> next;
		std::cin.ignore(1000, '\n');
		std::cin.clear();

		if (next == "Y" || next == "y")
		{
			std::cout << "You were dealt " << thirdCard << std::endl;
			cardSum += thirdCard;
			std::cout << "Your total " << cardSum << std::endl;		
		}
		else
		{
			std::cout << "Your total " << cardSum << std::endl << std::endl;
		}		
	}

	int opponentTotal;

	void resultCheck()
	{
		if (opponentTotal > cardSum)
		{
			std::cout << "Opponent won!" << std::endl;
		}
		else
		{
			std::cout << "You won!" << std::endl;
		}
	}
	
	void opponent()
	{
		int opponentFirstCard = randomNumber();
		int opponentSecondCard = randomNumber();
		int opponentThirdCard = randomNumber();
		int opponentFourthCard = randomNumber();


		std::cout << "**************" << std::endl;
		std::cout << "Opponents turn!" << std::endl;
		std::cout << "Opponent got: " << opponentFirstCard << " and " << opponentSecondCard << std::endl;
		opponentTotal = opponentFirstCard + opponentSecondCard;
		std::cout << "Opponents total is: " << opponentTotal << std::endl;

		if (opponentTotal > cardSum)
		{
			std::cout << "Opponent won!" << std::endl;
		}
		else if (opponentTotal < 13)
		{
			std::cout << "Opponent draw 3rd card: " << opponentThirdCard << std::endl;
			opponentTotal += opponentThirdCard;
			std::cout << "Opponent total is: " << opponentTotal << std::endl;
			if (opponentTotal < 13)
			{
				std::cout << "Opponent draw 4th card: " << opponentFourthCard << std::endl;
				opponentTotal += opponentFourthCard;
				std::cout << "Opponent total is: " << opponentTotal << std::endl;
			}
			resultCheck();
		}
		else if ( opponentTotal >= 13 && opponentTotal <= 21)
		{ 
			std::cout << "You won!!" << std::endl;
		}
		else if (opponentTotal == cardSum)
		{
			std::cout << "Call it a DRAW!!" << std::endl;
		}
	}

};



int main()
{
	drawCard draw;
	draw.playerDraw();
	draw.drawNext();
	draw.total();
	draw.opponent();


	system("pause");
}


// Napraviti pojednostavljenu simulaciju kartaske igre blackjack. Korisnika se pita hoce li uzeti kartu, y znaci da, n znaci ne.
// Ukoliko se korisnik odluci za kartu, dodaje mu se ta karta. Cilj je skupiti zbroj 21 ili sto blize tom broju. Ukoliko korisnik ima zbroj veci od 21, automatski gubi igru.
// Nakon korisnika racunalo bira karte, racunalo ce odustati tj. nece vise uzimati karte ukoliko ili ima bolji zbroj od igraca ili je u rasponu 13 - 21.