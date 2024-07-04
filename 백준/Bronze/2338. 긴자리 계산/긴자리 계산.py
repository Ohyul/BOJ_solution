import sys
input = sys.stdin.read
output = sys.stdout.write

data = input().split()
a, b = int(data[0]), int(data[1])

output(f"{a + b}\n")
output(f"{a - b}\n")
output(f"{a * b}\n")
