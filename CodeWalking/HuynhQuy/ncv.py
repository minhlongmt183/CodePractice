fileIn = open("input", "r")
n = int(fileIn.readline())
t = [float(x) for x in fileIn.readline().split()]
r = [float(x) for x in fileIn.readline().split()]
fileIn.close()

t.reverse()
r.reverse()

cost = [t[0], min(t[0] + t[1], r[0])]

def recursive(cost, i):
    if i == n:
        return cost[-1]
    else:
        temp = min(t[i] + cost[i - 1], r[i - 1] + cost[i - 2])
        cost += [temp]
        return recursive(cost, i + 1)

print(recursive(cost, 2))
