from random import randint


def get_rand_num():
    return randint(0, 100)


def quick_sort_exchange(vector, l, r):
    i = l
    j = r

    while (i < j):
        print(str(vector[i]) + " " + str(vector[j]))
        while (vector[i] < vector[r] and i < r):
            i = i + 1
        while (vector[j] > vector[r] and j > l):
            j = j - 1

        if (i < j):
            t = vector[i]
            vector[i] = vector[j]
            vector[j] = t
            i = i + 1
            j = j - 1

    t = vector[i]
    vector[i] = vector[r]
    vector[i] = t
    return i


def quick_sort(vector, l, r, level):
    print("level --> " + str(level) + " , l = " + str(l) + " , r = " + str(r))

    if (r <= l):
        return

    m = quick_sort_exchange(vector, l, r)
    quick_sort(vector, l, l + m - 1, level + 1)
    quick_sort(vector, l + m + 1, r, level + 1)


rand_vector = [get_rand_num() for i in range(20)]

print(rand_vector)

quick_sort(rand_vector, 0, 20, 0)
print(rand_vector)
