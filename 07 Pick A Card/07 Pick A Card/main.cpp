// Name:			Rebecca Deal
// Date:			2/25/18
// Title:			Pick A Card
// Description:		A C++ program that uses an array of structs to represent a
//					card deck, where the card values are represented by
//					enumerated types for the suit and cardValue.

#include <iostream>
#include <string>
#include <cstdlib> // for rand & srand
#include <ctime> // for time function
using namespace std;

// Define enumerated data
enum suits {CLUBS, DIAMONDS, HEARTS, SPADES};
enum cardValues {TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING, ACE};

// Define structured data
struct cards
{
	suits suit;
	cardValues card;
};

// Declare function prototypes
void createDeck(cards[]);
void printDeck(cards[]);
void printCard(cards);
void deal(cards[], cards&);
void winner(cards, cards);

// Declare global constant for number of cards in deck
const int NUM_CARDS = 52;

int main()
{
	// Declare array
	cards deck[NUM_CARDS];
	
	// Declare variables
	cards card1, card2;
	
	// Display some title text
	cout << "Pick A Card" << endl << endl;
	cout << "The deck of cards:" << endl << endl;
	
	// Call functions to create & print the deck
	createDeck(deck);
	printDeck(deck);
	
	// Call functions to deal & print 2 cards
	cout << endl << "Press enter key to deal card #1...";
	string deal1;
	getline(cin, deal1);
	deal(deck, card1);
	printCard(card1);
	cout << endl << endl << "Press enter key to deal card #2...";
	string deal2;
	getline(cin, deal2);
	deal(deck, card2);
	printCard(card2);
	cout << endl << endl;
	
	// Call function to determine & print the winning card
	winner(card1, card2);
	cout << endl << endl;
	
	// Begin cross-platform alternative to system("pause")
	cout << "Press enter key to continue...";
	string pause;
	getline(cin, pause);
	return 0;
}

// Create the deck in the deck array
void createDeck(cards deck[])
{
	for (suits s = CLUBS; s <= SPADES; s = static_cast<suits>(s + 1))
	{
		for (cardValues c = TWO; c <= ACE; c = static_cast<cardValues>(c + 1))
		{
			deck[c + (s * (NUM_CARDS / 4))].suit = static_cast<suits>(s);
			deck[c + (s * (NUM_CARDS / 4))].card = static_cast<cardValues>(c);
		}
	}
}

// Print the deck from the deck array
void printDeck(cards deck[])
{
	for (int i = 0; i < NUM_CARDS; i++) {
		printCard(deck[i]);
		cout << endl;
	}
}

// Print a specified card
void printCard(cards printedCard)
{
	switch (printedCard.card) {
		case TWO	:	cout << "Two";
			break;
		case THREE	:	cout << "Three";
			break;
		case FOUR	:	cout << "Four";
			break;
		case FIVE	:	cout << "Five";
			break;
		case SIX	:	cout << "Six";
			break;
		case SEVEN	:	cout << "Seven";
			break;
		case EIGHT	:	cout << "Eight";
			break;
		case NINE	:	cout << "Nine";
			break;
		case TEN	:	cout << "Ten";
			break;
		case JACK	:	cout << "Jack";
			break;
		case QUEEN	:	cout << "Queen";
			break;
		case KING	:	cout << "King";
			break;
		case ACE	:	cout << "Ace";
			break;
	}
	cout << " of ";
	switch (printedCard.suit) {
		case CLUBS		:	cout << "Clubs";
			break;
		case DIAMONDS	:	cout << "Diamonds";
			break;
		case HEARTS		:	cout << "Hearts";
			break;
		case SPADES		:	cout << "Spades";
			break;
	}
}

// Randomly deal a card
void deal(cards deck[], cards &dealtCard)
{
	unsigned seed = static_cast<unsigned>(time(0)); // get the system time
	// use static_cast in above line to avoid Xcode warning about conversion
	srand(seed); // seed the random number generator
	// formula:	(rand() % (MAX_VALUE - MIN_VALUE + 1)) + MIN_VALUE
	//			= (rand() % ((NUM_CARDS - 1) - 0 + 1)) + 0
	//			= rand() % (NUM_CARDS - 1 + 1)
	//			= rand() % NUM_CARDS
	dealtCard = deck[rand() % NUM_CARDS];
}

// Determine & print the winning card
void winner(cards card1, cards card2)
{
	cout << "And the winner is..." << endl;
	if ((card1.suit * (NUM_CARDS / 13) + card1.card) > (card2.suit * (NUM_CARDS / 13) + card2.card))
	{
		cout << "Card #1!" << endl;
		printCard(card1);
	}
	else
	{
		cout << "Card #2!" << endl;
		printCard(card2);
	}
}
