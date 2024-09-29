#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#define HEIGHT 5
#define WIDTH 20

/**
 * @brief Handles user input for text alignment and displays the aligned text.
 *
 * This function allocates memory for a 2D array of characters to hold text,
 * retrieves the text using the getText function, and then prompts the user
 * to choose a text alignment option. Based on the user's input, it calls the
 * appropriate text alignment function (leftAlign, rightAlign, centerAlign,
 * or justifyAlign) to display the text in the selected alignment.
 *
 */
void textHandler();

/**
 * @brief Reads multiple lines of text from the user and stores them in a 2D array.
 *
 * This function prompts the user to enter text line by line. Each line is read
 * and stored in the provided 2D character array (text). The function stops
 * reading input when a line starting with a whitespace character or empty is encountered
 * or when the maximum height is reached. The function returns the number of lines
 * read and stored.
 *
 * @param text A pointer to a 2D array of characters where the input text will be stored.
 * @return int The number of lines.
 *
 */
int getText(char** text);

/**
 * @brief Displays text aligned to the left.
 *
 * This function prints each line of text stored in the 2D character array (text)
 * to the console, aligning the text to the left. It prints up to size lines of text,
 * followed by a newline character.
 *
 * @param size The number of lines of text to print.
 * @param text A 2D array of characters containing the text to be displayed.
 */
void leftAlign(int size, char** text);

/**
 * @brief Displays text aligned to the right.
 *
 * This function prints each line of text stored in the 2D character array (text)
 * to the console, aligning the text to the right. It pads each line with spaces to
 * ensure that the text appears right-aligned within a fixed width. It prints up to
 * size lines of text, followed by a newline character.
 *
 * @param size The number of lines of text to print.
 * @param text A 2D array of characters containing the text to be displayed.
 *
 */
void rightAlign(int size, char** text);

/**
 * @brief Displays text aligned to the center.
 *
 * This function prints each line of text stored in the 2D character array (text)
 * to the console, aligning the text to the center. It pads each line with spaces
 * on both sides to ensure that the text appears centered within a fixed width.
 * It prints up to size lines of text, followed by a newline character.
 *
 * @param size The number of lines of text to print.
 * @param text A 2D array of characters containing the text to be displayed.
 *
 */
void centerAlign(int size, char** text);

/**
 * @brief Displays text aligned with justified spacing.
 *
 * This function prints each line of text stored in the 2D character array (text)
 * to the console, aligning the text with justified spacing. It adjusts the spacing
 * between words to ensure that each line fills the entire width (WIDTH). It prints
 * up to size lines of text, followed by a newline character.
 *
 * @param size The number of lines of text to print.
 * @param text A 2D array of characters containing the text to be displayed.
 *
 */
void justifyAlign(int size, char** text);

#endif  // FUNCTIONS_H
