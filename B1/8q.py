import json
#simport numpy as np
global N
N = 8
def printSolution(board):
    for i in range(N):
        for j in range(N):
            print board[i][j],
        print
def isSafe(board, row, col):
    for i in range(8):
    	if board[row][i] == 1 and i!=col: #checks the same row.
        	return False
    for i in range(8):
    	if board[i][col] == 1 and i!=row: #checks the same column
        	return False

    for i,j in zip(range(row,-1,-1), range(col,-1,-1)):
        if board[i][j] == 1 and i!=row and j!=col :
            return False
    for i,j in zip(range(row,N,1), range(col,-1,-1)):
        if board[i][j] == 1  and i!=row and j!=col :
            return False
 
    return True

def solveNQUtil(board,board1,  col):
    if col >= N:
        return True
    for i in range(N):
 
        if isSafe(board, i, col): #this is iterating through every column and finding if the queen is placed safely.
            board[i][col] = 1
            if solveNQUtil(board, board1, col+1) == True:
                return True
            if board1[i][col]==0 :
                board[i][col] = 0
    return False
def solveNQ():
	inf = open("8q.json")  #json map read kiya
	board = json.loads(inf.read())
	board = board["matrix"]
	print(" board: ")
	printSolution(board) #empty board printing here.
	inf = open("8q.json")  #json map read kiya
	board1 = json.loads(inf.read())
	board1 = board1["matrix"]
	
	if solveNQUtil(board, board1, 0) == False:
		print "Solution does not exist"
		return False
	print ""
	printSolution(board)
	return True
solveNQ()   #start.
