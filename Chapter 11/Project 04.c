#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define RANK 5
#define SUIT 2
#define NUM_RANKS 13
#define NUM_SUITS 4
#define NUM_CARDS 5

void read_cards(int hand[RANK][SUIT]);
void analyze_hand(int hand[RANK][SUIT], bool* royalstraight, bool* ace_low_straight, bool* straight, bool* flush, bool* four, bool* three, int* pairs);
void print_result(bool royalstraight, bool ace_low_straight, bool straight, bool flush, bool four, bool three, int pairs);
bool is_duplicated(int hand[RANK][SUIT], int rank, int suit, int cards_read);

int main(void) {
    int hand[RANK][SUIT];

    bool royalstraight, ace_low_straight, straight, flush, A, five, four, three;
    int pairs;

    for (;;) {
        read_cards(hand);
        analyze_hand(hand, &royalstraight, &ace_low_straight, &straight, &flush, &four, &three, &pairs);
        print_result(royalstraight, ace_low_straight, straight, flush, four, three, pairs);
    }
}

void read_cards(int hand[RANK][SUIT]) {
    char ch, rank_ch, suit_ch;
    int rank, suit;
    bool bad_card;
    int cards_read = 0;

    for (int i = 0; i < NUM_CARDS; i++) {
        hand[i][0] = -1;
        hand[i][1] = -1;
    }

    while (cards_read < NUM_CARDS) {
        bad_card = false;
        printf("Enter a card: ");
        rank_ch = getchar();
        switch (rank_ch) {
        case '0': exit(EXIT_SUCCESS);
        case '2': rank = 0; break;
        case '3': rank = 1; break;
        case '4': rank = 2; break;
        case '5': rank = 3; break;
        case '6': rank = 4; break;
        case '7': rank = 5; break;
        case '8': rank = 6; break;
        case '9': rank = 7; break;
        case 't': case 'T': rank = 8; break;
        case 'j': case 'J': rank = 9; break;
        case 'q': case 'Q': rank = 10; break;
        case 'k': case 'K': rank = 11; break;
        case 'a': case 'A': rank = 12; break;
        default: bad_card = true;
        }
        suit_ch = getchar();
        switch (suit_ch) {
        case 'c': case 'C': suit = 0; break;
        case 'd': case 'D': suit = 1; break;
        case 'h': case 'H': suit = 2; break;
        case 's': case 'S': suit = 3; break;
        default: bad_card = true;
        }
        while ((ch = getchar()) != '\n')
            if (ch != ' ') bad_card = true;

        if (bad_card)
            printf("Bad card, ignored.\n");
        else if (is_duplicated(hand, rank, suit, cards_read)) {
            printf("Duplicate card; ignored.\n");
        }
        else {
            hand[cards_read][0] = rank;
            hand[cards_read][1] = suit;
            cards_read++;
        }
    }
}

bool is_duplicated(int hand[RANK][SUIT], int rank, int suit, int cards_read) {
    for (int i = 0; i < cards_read; i++) {
        if (hand[i][0] == rank && hand[i][1] == suit) {
            return true;
        }
    }

    return false;
}

void analyze_hand(int hand[RANK][SUIT], bool* royalstraight, bool* ace_low_straight, bool* straight, bool* flush, bool* four, bool* three, int* pairs) {
    int num_consec = 0;
    int rank_count[NUM_CARDS] = { 0 };
    int suit_count[NUM_CARDS] = { 0 };

    *royalstraight = false;
    *straight = false;
    *flush = false;
    *four = false;
    *three = false;
    *pairs = 0;

    // suit count
    for (int i = 0; i < NUM_CARDS; i++) {
        suit_count[hand[i][1]]++;
    }

    // check flush
    for (int i = 0; i < NUM_SUITS; i++) {
        if (suit_count[i] == NUM_CARDS)
            *flush = true;
    }

    // rank count
    for (int i = 0; i < NUM_CARDS; i++) {
        rank_count[hand[i][0]]++;
    }

    // check four, three, pairs
    for (int rank = 0; rank < NUM_RANKS; rank++) {
        if (rank_count[rank] == 4) *four = true;
        if (rank_count[rank] == 3) *three = true;
        if (rank_count[rank] == 2) (*pairs)++;
    }

    // check straight
    for (int i = 0; i <= 8; i++) {
        num_consec = 0;
        for (int j = 0; j < NUM_CARDS; j++) {
            if (rank_count[i + j] > 0) {
                num_consec++;
            }
            else {
                break;
            }
        }

        if (num_consec == NUM_CARDS) {
            *straight = true;
            return;
        }
    }

    // A,2,3,4,5
    if (rank_count[0] == 1 && rank_count[1] == 1 && rank_count[2] == 1 && rank_count[3] == 1 && rank_count[12] == 1) {
        *straight = true;
    }

    // A, K, Q, J, 10
    if (rank_count[12] == 1 && rank_count[11] == 1 && rank_count[10] == 1 && rank_count[9] == 1 && rank_count[8] == 1) {
        *royalstraight = true;
    }
}

void print_result(bool royalstraight, bool ace_low_straight, bool straight, bool flush, bool four, bool three, int pairs) {
    if (royalstraight && flush) printf("Royal Straight flush");
    else if (straight && flush) printf("Straight flush");
    else if (four) printf("Four of a kind");
    else if (three && pairs == 1) printf("Full house");
    else if (flush) printf("Flush");
    else if (straight) printf("Straight");
    else if (three) printf("Three of a kind");
    else if (pairs == 2) printf("Two pairs");
    else if (pairs == 1) printf("Pair");
    else printf("High card");
    printf("\n\n");
}