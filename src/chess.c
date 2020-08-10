Color get_piece_color(Piece piece) {
	return piece & WHITe >> 7;
}

Piece_Type get_piece_type(Piece piece) {
	return piece & ~WHITE;
}
