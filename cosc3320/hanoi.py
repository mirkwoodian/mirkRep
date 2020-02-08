def TowerOfHanoi(n , from_rod, to_rod, aux_rod): 
    if n == 1: 
        print ("Move disk 1 from rod",from_rod,"to rod",to_rod)
        return
    TowerOfHanoi(n-1, from_rod, aux_rod, to_rod) 
    print ("Move disk",n,"from rod",from_rod,"to rod",to_rod) 
    TowerOfHanoi(n-1, aux_rod, to_rod, from_rod) 

def main():
    n = 4
    TowerOfHanoi(n, 'A', 'C', 'B')

main()

# code source from: https://www.geeksforgeeks.org/python-program-for-tower-of-hanoi/
# https://www.freecodecamp.org/news/analyzing-the-algorithm-to-solve-the-tower-of-hanoi-problem-686685f032e3/