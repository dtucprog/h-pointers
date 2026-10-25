#include <stdcountof.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

const char *suits[] = {"Clubs", "Hearts", "Spades", "Diamonds"},
           *faces[] = {"Ace",  "Deuce", "Three", "Four", "Five",
                       "Six",  "Seven", "Eight", "Nine", "Ten",
                       "Jack", "Queen", "King"};
constexpr size_t ROW_COUNT = countof(suits), COLUMN_COUNT = countof(faces);
constexpr int CARD_COUNT = ROW_COUNT * COLUMN_COUNT, DEAL_PRINT_ROW_COUNT = 4;

// A deck is an array of countof(suits) * countof(faces) elements. Each element
// show the order of the card beginning at 1.
typedef int Deck[ROW_COUNT][COLUMN_COUNT];

// YOUR CODE HERE

void shuffle(Deck deck) {
  for (int card = 1; card <= CARD_COUNT; ++card) {
    size_t column, row;
    do {
      column = rand() % COLUMN_COUNT;
      row = rand() % ROW_COUNT;
    } while (deck[row][column]);
    // Choose a random element until an empty element (0) is found

    deck[row][column] = card;
  }
}

void print_deck(const Deck deck) {
  puts("Deck:");
  for (size_t row = 0; row < ROW_COUNT; ++row) {
    for (size_t column = 0; column < COLUMN_COUNT; ++column) {
      printf("%2d ", deck[row][column]);
    }
    puts("");
  }
}

void print_card(size_t row, size_t column) {
  printf("%5s of %-8s  ", faces[column], suits[row]);
}

void deal_all(Deck deck) {
  puts("52 dealt cards:");
  for (int card = 1; card <= CARD_COUNT; ++card) {
    for (size_t row = 0; row < ROW_COUNT; ++row)
      for (size_t column = 0; column < COLUMN_COUNT; ++column)
        if (deck[row][column] == card) {
          print_card(row, column);
          if (card % DEAL_PRINT_ROW_COUNT == 0)
            puts("");
        }
  }
}

void scan_deck(Deck deck) {
  puts("Waiting for the deck:");
  for (size_t row = 0; row < ROW_COUNT; ++row)
    for (size_t column = 0; column < COLUMN_COUNT; ++column)
      scanf("%2d", &deck[row][column]);
}

// YOUR CODE HERE

int main() {
  Deck deck = {};
  // Uncomment the following to create a random deck
  // srand(time(nullptr));
  // shuffle(deck);
  // print_deck(deck);
  // puts("");
  // deal_all(deck);
  // puts("");

  scan_deck(deck);
  puts("");
  print_deck(deck);
  puts("");

  // YOUR CODE HERE
}