// (a) Chess piece
enum Piece {empty, pawn, knight, bishop, rook, queen, king};
enum Color {black, white};

// (b) square of chess board
struct square {
    enum Piece piece;
    enum Color color;
};

// (c) (d) Chess board:
struct square board[8] [8] = {
    {{rook, white}, {knight, white}, {bishop, white}, {queen, white},
     {king, white}, {bishop, white}, {knight, white}, {rook, white}},

    {{pawn, white}, {pawn, white}, {pawn, white}, {pawn, white},
     {pawn, white}, {pawn, white}, {pawn, white}, {pawn, white}},

    {{empty, black}, {empty, black}, {empty, black}, {empty, black},
     {empty, black}, {empty, black}, {empty, black}, {empty, black}},

    {{empty, black}, {empty, black}, {empty, black}, {empty, black},
     {empty, black}, {empty, black}, {empty, black}, {empty, black}},

    {{empty, black}, {empty, black}, {empty, black}, {empty, black},
     {empty, black}, {empty, black}, {empty, black}, {empty, black}},

    {{empty, black}, {empty, black}, {empty, black}, {empty, black},
     {empty, black}, {empty, black}, {empty, black}, {empty, black}},

    {{pawn, black}, {pawn, black}, {pawn, black}, {pawn, black},
     {pawn, black}, {pawn, black}, {pawn, black}, {pawn, black}},

    {{rook, black}, {knight, black}, {bishop, black}, {queen, black},
     {king, black}, {bishop, black}, {knight, black}, {rook, black}}
};
