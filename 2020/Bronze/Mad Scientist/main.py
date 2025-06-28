# Read input
with open("breedflip.in", "r") as f:
    N = int(f.readline().strip())
    A = f.readline().strip()
    B = f.readline().strip()

count = 0
i = 0
while i < N:
    if A[i] != B[i]:
        # Start of a mismatch block
        count += 1
        # Skip to end of this block
        while i < N and A[i] != B[i]:
            i += 1
    else:
        i += 1

# Output
with open("breedflip.out", "w") as f:
    f.write(str(count) + "\n")
