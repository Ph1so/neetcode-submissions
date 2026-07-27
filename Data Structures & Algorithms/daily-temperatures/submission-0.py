class Solution:
    def dailyTemperatures(self, temps: List[int]) -> List[int]:
        length = len(temps)
        output = [0] * length  # Initialize output list with zeros
        t = []  # stack for temps
        index = []  # stack for indexes

        for i in range(length):
            while t and temps[i] > t[-1]:
                output[index[-1]] = i - index[-1]
                t.pop()
                index.pop()
            t.append(temps[i])
            index.append(i)
        
        return output