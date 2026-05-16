def solution(length):
    beautiful = [0] * length
    ref = []

    # Generate even numbers: 2, 4, 6, ...
    for i in range(1, length + 1, 2):
        ref.append(i + 1)

    # Fill first half of the array with even numbers
    for i in range(length // 2):
        beautiful[i] = ref[i]

    # Fill second half with corresponding odd numbers
    for i in range(length // 2, length):
        beautiful[i] = ref[i - length // 2] - 1

    return beautiful


def main():
    s = int(input())

    if s > 3:
        ans = solution(s)
        print(*ans)
    elif s == 2 or s == 3:
        print("NO SOLUTION")
    else:
        print(s)

    # Equivalent to the final `cin >> s;` in the C++ code.
    # This waits for one more input before the program exits.
    input()


if __name__ == "__main__":
    main()