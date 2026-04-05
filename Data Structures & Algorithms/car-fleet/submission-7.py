class Solution:
    def carFleet(self, target: int, position: List[int], speed: List[int]) -> int:
        cars = []
        for i in range(len(position)):
            cars.append([position[i], speed[i]])
        cars.sort(reverse = True)
        
        fleets = 0
        maxSoFar = 0
        for car in cars:
            time = (target - car[0]) / car[1]
            if maxSoFar < time:
                maxSoFar = time
                fleets += 1
        return fleets