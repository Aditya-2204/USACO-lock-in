import sys

def main():
    input = sys.stdin.read
    data = input().split()
    T = int(data[0])
    Ns = list(map(int, data[1:]))
    for N in Ns:
        res = 0
        for k in range(1, 10):
            L = 5 * (10 ** (k-1))
            R = (10 ** k) -1
            if N < L:
                continue
            res += min(N, R) - L +1
        print(res)

if __name__ == "__main__":
    main()
