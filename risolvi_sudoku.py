mio_file = open("sudoku")

r = 0
c = 0


def print_vector(vec):
    for v in vec:
        string = ""

        for n in v:
            if n != -1:
                string += str(n) + " "
            else:
                string += "x "

        print(string)


def is_solution(array, array_s):
    return True


def gen_solution(array, size, array_s, pos=0):
    if (pos >= size):
        if (is_solution(array, array_s) == True):
            print_vector(array_s)
        return

    for i in range(1, 9):
        array[pos] = i
        gen_solution(array, size, pos + 1)


original = [[0 for i in range(9)] for i in range(9)]
size = 0

for s in mio_file:
    a = s.split(" ")

    for n in a:
        if (n != "x" and n != "x\n"):
            original[r][c] = int(n)
        else:
            original[r][c] = -1
            size += 1
        c = c + 1

    r = r + 1
    c = 0


sol = [0 for i in range(size)]

gen_solution(sol, size, original)

print_vector(original)
