def almostIncreasingSequence(sequence):
    numError = 0
    seLength = len(sequence)
    i = 0
    while i < seLength -1:

        if (sequence[i] >= sequence[i + 1]):
            numError += 1
            
            if (numError == 1):
                sequence.pop(i + 1)
                seLength -= 1
                i -= 1
                continue
        i += 1

    if (numError > 1):
        return False
    return True

if __name__ == "__main__":
    sequence = [1, 2, 3,4,3,6]
    print(almostIncreasingSequence(sequence))