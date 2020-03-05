class Solution:
    def combinationSum(self, candidates, target):
        A = []
        list_ele = []
        def rec(idx, list_ele):  #input of rec is [2,2,2,2] list
            #terminate when meet target
            if sum(list_ele) == target:
                A.append(list_ele)
                
               
            elif sum(list_ele) < target:
                for i in range(idx, len(candidates)):
                    new_ele = list_ele + [candidates[i]]
                    rec(i, new_ele)
        rec(0,list_ele)           
        return A
        
if __name__=="__main__":
    solution = Solution()
    print(solution.combinationSum([2,3,5], 8))
