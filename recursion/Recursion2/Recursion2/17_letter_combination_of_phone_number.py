
def letterCombinations(digits):
    A = [];
    mp = {
        "2":"abc",
        "3":"def",
        "4":"ghi",
        "5":"jkl",
        "6":"mno",
        "7":"pqrs",
        "8":"tuv",
        "9":"wxyz",
    }
    def rec(digits, cur_string = ""):
        if len(digits) == 0:
            A.append(cur_string)
            return
        digit_in = digits[0]
        digits = digits[1:]
        for c in mp[digit_in]:
            rec(digits, cur_string + c)
        return A
    return rec(digits)

if __name__ == "__main__":
    #test1. digits="23"
    digits = "23"
    print(letterCombinations(digits))
