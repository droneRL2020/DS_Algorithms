class Solution:
    def floodFill(self, image, sr, sc, newColor):
        target_color = image[sr][sc]
        sr_len = len(image)
        sc_len = len(image[0])
        def rec(sr, sc):

            if image[sr][sc]  != target_color:
                #image[sr][sc] = newColor
                return
            else:
                image[sr][sc] = '-'
                if not (sr+1>sr_len-1):
                    rec(sr+1, sc)
                if not (sc+1>sc_len-1):
                    rec(sr, sc+1)
                if not (sr-1<0):
                    rec(sr-1, sc)
                if not (sc-1<0):
                    rec(sr, sc-1)
                image[sr][sc] = newColor
        
        rec(sr,sc)
        return image
    

if __name__ == "__main__":
    solution = Solution()
    print(solution.floodFill([[1,1,1],[1,1,0],[1,0,1]], 1, 1, 2))
    # Expected Output: [[2,2,2],[2,2,0],[2,0,1]])
    