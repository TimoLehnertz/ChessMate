#include <stdint.h>
#include <string>
#include <iostream>

#define PIECE_COLOR_MASK 0b10000000
#define PIECE_TYPE_MASK 0b00001111

// info https://pages.cs.wisc.edu/~psilord/blog/data/chess-pages/rep.html

// info https://www.chessprogramming.org/Efficient_Generation_of_Sliding_Piece_Attacks

// Pieces
// types of pieces
#define PIECE_TYPE_PAWN 0
#define PIECE_TYPE_BISHOP 1
#define PIECE_TYPE_KNIGHT 2
#define PIECE_TYPE_ROOK 3
#define PIECE_TYPE_QUEEN 4
#define PIECE_TYPE_KING 5
// colors of pieces
#define COLOR_WHITE 1
#define COLOR_BLACK 0
// piece indices
#define BITBOARD_BLACK_PAWN		0
#define BITBOARD_BLACK_BISHOP	1
#define BITBOARD_BLACK_KNIGHT	2
#define BITBOARD_BLACK_ROOK		3
#define BITBOARD_BLACK_QUEEN	4
#define BITBOARD_BLACK_KING		5

// Bitboards
#define BITBOARD_WHITE_PAWN		6
#define BITBOARD_WHITE_BISHOP	7
#define BITBOARD_WHITE_KNIGHT	8
#define BITBOARD_WHITE_ROOK		9
#define BITBOARD_WHITE_QUEEN	10
#define BITBOARD_WHITE_KING		11

#define BITBOARD_BLACK_PIECES	12
#define BITBOARD_WHITE_PIECES	13
#define BITBOARD_ALL_PIECES		13

#define BITBOARDS_FIGURES_SIZE (BITBOARD_WHITE_KING + 1)
#define BITBOARDS_SIZE (BITBOARD_ALL_PIECES + 1)

// initial piece positions
#define STARTUP_WHITE_PAWNS_BITMAP		0b0000000000000000000000000000000000000000000000001111111100000000
#define STARTUP_BLACK_PAWNS_BITMAP		0b0000000011111111000000000000000000000000000000000000000000000000

#define STARTUP_WHITE_ROOKS_BITMAP		0b0000000000000000000000000000000000000000000000000000000010000001
#define STARTUP_BLACK_ROOKS_BITMAP		0b1000000100000000000000000000000000000000000000000000000000000000

#define STARTUP_WHITE_KNIGHTS_BITMAP	0b0000000000000000000000000000000000000000000000000000000001000010
#define STARTUP_BLACK_KNIGHTS_BITMAP	0b0100001000000000000000000000000000000000000000000000000000000000

#define STARTUP_WHITE_BISHOPS_BITMAP	0b0000000000000000000000000000000000000000000000000000000000100100
#define STARTUP_BLACK_BISHOPS_BITMAP	0b0010010000000000000000000000000000000000000000000000000000000000

#define STARTUP_WHITE_QUEEN_BITMAP		0b0000000000000000000000000000000000000000000000000000000000010000
#define STARTUP_BLACK_QUEEN_BITMAP		0b0001000000000000000000000000000000000000000000000000000000000000

#define STARTUP_WHITE_KING_BITMAP		0b0000000000000000000000000000000000000000000000000000000000001000
#define STARTUP_BLACK_KING_BITMAP		0b0000100000000000000000000000000000000000000000000000000000000000

#define STARTUP_WHITE_PIECES_BITMAP		0b0000000000000000000000000000000000000000000000001111111111111111
#define STARTUP_BLACK_PIECES_BITMAP		0b1111111111111111000000000000000000000000000000000000000000000000

#define STARTUP_ALL_PIECES_BITMAP		0b1111111111111111000000000000000000000000000000001111111111111111

#define MASK_1							0b0000000000000000000000000000000000000000000000000000000011111111
#define MASK_2							0b0000000000000000000000000000000000000000000000001111111100000000
//#define MASK_3							0b0000000000000000000000000000000000000000000000000000000000000000
//#define MASK_4							0b0000000000000000000000000000000000000000000000000000000000000000
//#define MASK_5							0b0000000000000000000000000000000000000000000000000000000000000000
//#define MASK_6							0b0000000000000000000000000000000000000000000000000000000000000000
//#define MASK_7							0b0000000000000000000000000000000000000000000000000000000000000000
//#define MASK_8							0b0000000000000000000000000000000000000000000000000000000000000000

#define MASK_8_INVERSE					0b0000000011111111111111111111111111111111111111111111111111111111

#define MASK_8_INVERSE					0b0000000011111111111111111111111111111111111111111111111111111111
#define MASK_A_INVERSE					0b1111111011111110111111101111111011111110111111101111111011111110
#define MASK_H_INVERSE					0b0111111101111111011111110111111101111111011111110111111101111111

#define MASK_A8_INVERSE					(MASK_A_INVERSE | MASK_8_INVERSE)

// squares
#define SQUARE_BITMASK_X 0b00000111
#define SQUARE_BITMASK_Y 0b00111000
#define SQUARE_BITSHIFT_Y 3

#define SQUARE_BITS 6

// moves
// moves are a uint16_t containing 2 Squares each taking up 6 bits and 4 bits of extra options
#define MOVE_FROM_MASK			0b1111110000000000
#define MOVE_TO_MASK			0b0000001111110000
#define MOVE_OPTIONS_MASK		0b0000000000001111
#define MOVE_TO_BIT_SHIFT		6
#define MOVE_OPTIONS_BIT_SHIFT	12

#define MOVE_EN_PASSANT_MASK	0b0000000000000001

#define MAX_NUMBER_OF_PSEUDO_LEGAL_MOVES_PER_BOARD 3136 // in reality much much lower but lets start with the safest number. cumputed by assuming the field has 64 queens taht each have 7*4 moves

#define CASTLE_RIGHTS_Q 0b00000001
#define CASTLE_RIGHTS_q 0b00000010
#define CASTLE_RIGHTS_K 0b00000100
#define CASTLE_RIGHTS_k 0b00001000

/*Board definition:
56	57	58	59	60	61	62	63
48	49	50	51	52	53	54	55
40	41	42	43	44	45	46	47
32	33	34	35	36	37	38	39
24	25	26	27	28	29	30	31
16	17	18	19	20	21	22	23
8	9	10	11	12	13	14	15
0	1	2	3	4	5	6	7*/

// @ToDO
class Bitboard {
public:
	


private:
	uint64_t bitboard;
};

class PieceType {
public:
	PieceType(uint8_t bitboardIndex) : bitboardIndex(bitboardIndex) {}

	uint8_t getBitboardIndex() {
		return bitboardIndex;
	}

	uint8_t getBitboardColorIndex() {
		return BITBOARD_BLACK_PIECES + isWhite();
	}

	bool isWhite() {
		return bitboardIndex < BITBOARD_WHITE_PAWN;
	}
	
	operator uint8_t() {
		return bitboardIndex;
	}
private:
	uint8_t bitboardIndex;
};

class Square {
public:
	Square(uint8_t x, uint8_t y) {
		binary = (x & SQUARE_BITMASK_X) | (y << SQUARE_BITSHIFT_Y);
	}

	Square(uint8_t binary) : binary(binary) {}

	uint8_t getX() {
		return binary & SQUARE_BITMASK_X;
	}

	uint8_t getY() {
		return (binary & SQUARE_BITMASK_Y) >> SQUARE_BITSHIFT_Y;
	}

	uint8_t toIndex() {
		return (binary & SQUARE_BITMASK_X) + ((binary & SQUARE_BITMASK_Y) >> SQUARE_BITSHIFT_Y) * 8;
	}

	uint64_t toBitboard() {
		return ((uint64_t)1) << toIndex();
	}

	operator uint8_t() {
		return binary;
	}
private:
	uint8_t binary;
};

class Move {
public:
	Move() : binary(0) {}
	Move(Square from, Square to, uint8_t moveOptions) {
		binary = from | (to >> MOVE_TO_BIT_SHIFT) | (moveOptions >> MOVE_OPTIONS_BIT_SHIFT);
	}

	Square getFrom() {
		return (Square)(binary & MOVE_FROM_MASK);
	}

	Square getTo() {
		return (Square)((binary & MOVE_TO_MASK) >> MOVE_TO_BIT_SHIFT);
	}

	operator uint16_t() {
		return binary;
	}
private:
	uint16_t binary;
};

struct PseudoLegalMoves {
	PseudoLegalMoves() : size(0) {}
	Move moves[MAX_NUMBER_OF_PSEUDO_LEGAL_MOVES_PER_BOARD];
	uint16_t size;
};

class Board {
public:
	Board() {
		setupInitialBoard();
		PseudoLegalMoves moves;
		getPseudoLegalMoves(moves);
	}

	void getPseudoLegalMoves(PseudoLegalMoves& moves) {
		for (size_t pieceType= 0; pieceType < BITBOARDS_FIGURES_SIZE; pieceType++) {
			uint64_t bitboardMoves = generatePlmForPiece(pieceType);
		}
	}

	uint64_t generatePlmForPiece(PieceType type) {
		switch (type) {
		case BITBOARD_WHITE_PAWN: return plmForWhitePawn();
		}
	}

	uint64_t plmForWhitePawn() {
		uint64_t moves = 0;
		// one to front
		uint64_t shiftedOneToFront = (bitboards[BITBOARD_WHITE_PAWN] & MASK_H_INVERSE) << 8; // move all white pawns one to front
		moves |= shiftedOneToFront & ~bitboards[BITBOARD_ALL_PIECES]; // pawn can move shifted one to front when there is no other piece
		//two to front
		uint64_t twoToFront = (bitboards[BITBOARD_WHITE_PAWN] & MASK_2) << 16; // move all pawans that are on row 2 2 fields to front
		twoToFront &= ~bitboards[BITBOARD_ALL_PIECES]; // subtract all pieces
		moves |= twoToFront;
		// left hits
		uint64_t leftHits = (bitboards[BITBOARD_WHITE_PAWN] & MASK_A8_INVERSE) << ;
	}

	void getFenString(std::string& fen) {
		uint64_t pieceBitboard = 0;
		char fenCharArray[64];
		// initialise the FEN char array
		for (int i = 0; i < 64; i++) {
			fenCharArray[i] = '1';
		}
		pieceBitboard = bitboards[BITBOARD_BLACK_BISHOP];
		populateFenCharArray(fenCharArray, pieceBitboard, 'b');

		pieceBitboard = bitboards[BITBOARD_BLACK_KING];
		populateFenCharArray(fenCharArray, pieceBitboard, 'k');

		pieceBitboard = bitboards[BITBOARD_BLACK_KNIGHT];
		populateFenCharArray(fenCharArray, pieceBitboard, 'n');

		pieceBitboard = bitboards[BITBOARD_BLACK_PAWN];
		populateFenCharArray(fenCharArray, pieceBitboard, 'p');

		pieceBitboard = bitboards[BITBOARD_BLACK_QUEEN];
		populateFenCharArray(fenCharArray, pieceBitboard, 'q');

		pieceBitboard = bitboards[BITBOARD_BLACK_ROOK];
		populateFenCharArray(fenCharArray, pieceBitboard, 'r');

		pieceBitboard = bitboards[BITBOARD_WHITE_BISHOP];
		populateFenCharArray(fenCharArray, pieceBitboard, 'B');

		pieceBitboard = bitboards[BITBOARD_WHITE_KING];
		populateFenCharArray(fenCharArray, pieceBitboard, 'K');

		pieceBitboard = bitboards[BITBOARD_WHITE_KNIGHT];
		populateFenCharArray(fenCharArray, pieceBitboard, 'N');

		pieceBitboard = bitboards[BITBOARD_WHITE_PAWN];
		populateFenCharArray(fenCharArray, pieceBitboard, 'P');

		pieceBitboard = bitboards[BITBOARD_WHITE_QUEEN];
		populateFenCharArray(fenCharArray, pieceBitboard, 'Q');

		pieceBitboard = bitboards[BITBOARD_WHITE_ROOK];
		populateFenCharArray(fenCharArray, pieceBitboard, 'R');

		getFenPositionString(fenCharArray, fen);
		std::string fenStringFormat = "{0} w KQkq - 0 1";

		fenStringFormat += ' ';
		fenStringFormat += colorToMove ? 'w' : 'b';
		fenStringFormat += ' ';
		fenStringFormat += "KQkq - 0 1";
	}
private:
	uint64_t bitboards[BITBOARDS_SIZE];
	uint8_t colorToMove = COLOR_WHITE;
	bool enPassant;
	uint8_t castleRights;

	void setupInitialBoard() {
		bitboards[BITBOARD_WHITE_PAWN]		= STARTUP_WHITE_PAWNS_BITMAP;
		bitboards[BITBOARD_BLACK_PAWN]		= STARTUP_BLACK_PAWNS_BITMAP;

		bitboards[BITBOARD_WHITE_ROOK]		= STARTUP_WHITE_ROOKS_BITMAP;
		bitboards[BITBOARD_BLACK_ROOK]		= STARTUP_BLACK_ROOKS_BITMAP;

		bitboards[BITBOARD_WHITE_BISHOP]	= STARTUP_WHITE_BISHOPS_BITMAP;
		bitboards[BITBOARD_BLACK_BISHOP]	= STARTUP_BLACK_BISHOPS_BITMAP;

		bitboards[BITBOARD_WHITE_KNIGHT]	= STARTUP_WHITE_KNIGHTS_BITMAP;
		bitboards[BITBOARD_BLACK_KNIGHT]	= STARTUP_BLACK_KNIGHTS_BITMAP;

		bitboards[BITBOARD_WHITE_QUEEN]		= STARTUP_WHITE_QUEEN_BITMAP;
		bitboards[BITBOARD_BLACK_QUEEN]		= STARTUP_BLACK_QUEEN_BITMAP;

		bitboards[BITBOARD_WHITE_KING]		= STARTUP_WHITE_KING_BITMAP;
		bitboards[BITBOARD_BLACK_KING]		= STARTUP_BLACK_KING_BITMAP;

		bitboards[BITBOARD_WHITE_PIECES]	= STARTUP_WHITE_PIECES_BITMAP;
		bitboards[BITBOARD_BLACK_PIECES]	= STARTUP_BLACK_PIECES_BITMAP;
		bitboards[BITBOARD_ALL_PIECES]		= STARTUP_ALL_PIECES_BITMAP;
	}

	// Only used for initial setup because chess never adds figures to the board
	void addPiece(PieceType type, Square square) {
		uint64_t bitBoard = square.toBitboard();
		bitboards[type.getBitboardIndex()] |= bitBoard;
		bitboards[type.getBitboardColorIndex()] |= bitBoard;
		bitboards[BITBOARD_ALL_PIECES] |= bitBoard;
	}

	//void move(Move move) {
	//	colorToMove = (colorToMove + 1) % 2;
	//}

	void populateFenCharArray(char* fenCharArray, uint64_t pieceBitboard, char pieceChar) {
		int i = 0;
		int remainder = 0;
		while (pieceBitboard > 0) {
			remainder = (int)(pieceBitboard % 2);
			if (remainder == 1) {
				fenCharArray[i] = pieceChar;
			}
			pieceBitboard /= 2;
			i++;
		}
	}

	void getFenPositionString(char* fenCharArray, std::string& positionString) {
		positionString = "";
		std::string rankPositionBuilder = "";
		int emptySquareCount = 0;

		for (int i = 0; i < 64; i++) {
			if (fenCharArray[i] == '1') {
				emptySquareCount++;
			} else {
				if (emptySquareCount > 0) {
					rankPositionBuilder += std::to_string(emptySquareCount);
					emptySquareCount = 0;
				}
				rankPositionBuilder += fenCharArray[i];
			}
			if ((i + 1) % 8 == 0) {
				if (emptySquareCount > 0) {
					rankPositionBuilder += std::to_string(emptySquareCount);
					emptySquareCount = 0;
				}
				positionString = "/" + rankPositionBuilder + positionString;
				rankPositionBuilder = "";
			}
		}
		positionString = positionString.substr(1);
	}
};