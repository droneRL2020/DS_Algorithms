class Solution:
    def exist(self, board, word):
        if(not board):
            return False
        rows = len(board)
        cols = len(board[0])

        def findStr(x, i, j):
            if(x == len(word)):
                return True
            else:
                if(not ((i>-1)and(i<rows)and(j>-1)and(j<cols))):
                    return False
                else:
                    if(word[x] != board[i][j]):
                        return False
                    else:
                        x+=1
                        c = board[i][j]
                        board[i][j] = '-'
                        foundString = findStr(x, i-1, j) or findStr(x, i+1, j) or findStr(x, i, j-1) or findStr(x, i, j+1)
                        board[i][j] = c

                        return foundString # this gets True or False
                 
        for row in range(rows):
            for col in range(cols):
                if(findStr(0, row, col)):
                    return True
        return False

sol = Solution()
board =[
  ['A','B','C','E'],
  ['S','F','C','S'],
  ['A','D','E','E']
]
word = "ABCCED"

print(sol.exist(board, word))

