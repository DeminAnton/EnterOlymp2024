def legal_move(king, rook, rook_move):
    king_moves = []
    if king%8 == 0:
        king_moves.append(king + 1)
    elif (king + 1) % 8 == 0:
        king_moves.append(king - 1)
    else:
        king_moves.append(king + 1)
        king_moves.append(king - 1)
    if king < 8:
        king_moves.append(king + 8)
    elif king > 55:
        king_moves.append(king - 8)
    else:
        king_moves.append(king + 8)
        king_moves.append(king - 8)
        
    rook_moves = []
    if  rook%8 == 0:
        for m in range(rook + 1, rook + 7):
            rook_moves.append(m)
    elif (rook + 1) % 8 == 0:
        for m in range(rook -7, rook):
            rook_moves.append(m)
    else:
        for m in range(rook + 1, rook + 8):
            rook_moves.append(m)
        for m in range(rook -7, rook):
            rook_moves.append(m)
    if rook < 8:
        for m in range(rook + 8, 64, 8):
            rook_moves.append(m)
    elif rook > 55:
        for m in range(rook - 8, 0, -8):
            rook_moves.append(m)
    else:
        for m in range(rook + 8, 64, 8):
            rook_moves.append(m)
        for m in range(rook - 8, 0, -8):
            rook_moves.append(m)
        
        
    print(rook_moves)
