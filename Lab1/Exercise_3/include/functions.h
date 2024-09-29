#ifndef FUNCTIONS_H
#define FUNCTIONS_H

struct Card {
  char* suit;
  char* rank;
  int value;
};

static struct Card deck[52];

/**
 * @brief Fills the deck with 52 cards.
 *
 * This function initializes a deck of cards by filling it with all combinations
 * of the four suits ("clubs", "diamonds", "hearts", "spades") and thirteen ranks 
 * ("A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King").
 * Each card is assigned a rank value from 1 to 13. The function iterates through
 * all suits and ranks, creating and adding each card to the deck array.
 *
 */
void fill_deck();

/**
 * @brief Fills a hand with 5 random cards from the deck.
 *
 * This function selects 5 random cards from the deck and assigns them to the 
 * provided `hand`. It uses the `rand` function seeded with the current time 
 * to ensure randomness.
 *
 * @param hand An array of 5 Card structures to be filled with random cards from the deck.
 *
 */
void fill_hand(struct Card hand[5]);

/**
 * @brief Checks and displays the contents and classification of the hand.
 *
 * This function prints each card in the provided hand in the format `{rank:suit}`.
 * It then evaluates the hand to determine and print its classification, such as
 * "STRAIGHT", "FOUR OF A KIND", "FLUSH", "THREE OF A KIND", "TWO PAIRS", or "PAIR".
 *
 * @param hand An array of 5 Card structures representing the player's hand.
 */
void hand_contains(struct Card hand[5]);

/**
 * @brief Counts the number of pairs in the hand.
 *
 * This function compares each card in the hand with every other card to count
 * the number of pairs (two cards of the same rank). It increments the count
 * each time a pair is found.
 *
 * @param hand An array of 5 Card structures representing the player's hand.
 * @return int The number of pairs found in the hand.
 */
int is_pair(struct Card hand[5]);

/**
 * @brief Counts the number of cards of the same suit in a hand.
 *
 * This function counts the number of cards for each suit in the hand. 
 * It then checks if any suit has exactly 3 or 4 cards and returns the 
 * count of cards of the most frequent suit.
 *
 * @param hand An array of 5 Card structures representing the player's hand.
 * @return int The number of cards of the same suit (3 or 4). Returns 0 if no suit has 3 or 4 cards.
 */
int count_kinds(struct Card hand[5]);

/**
 * @brief Checks if all cards in a hand are of the same suit.
 *
 * This function examines each card in the hand to determine if all cards share
 * the same suit. If all cards have the same suit, the function returns 1 to
 * indicate a flush; otherwise, it returns 0.
 *
 * @param hand An array of 5 Card structures representing the player's hand.
 * @return int Returns 1 if all cards have the same suit (flush), otherwise returns 0.
 */
int is_flush(struct Card hand[5]);

/**
 * @brief Checks if the hand contains a straight.
 *
 * This function determines if the cards in the hand form a straight. It first
 * sorts the hand by card value and then checks if the values form a consecutive
 * sequence. If all values are consecutive, the function returns 1 to indicate a
 * straight; otherwise, it returns 0.
 *
 * @param hand An array of 5 Card structures representing the player's hand.
 * @return int Returns 1 if the hand is a straight, otherwise returns 0.
 */
int is_straight(struct Card hand[5]);

#endif  // FUNCTIONS_H
