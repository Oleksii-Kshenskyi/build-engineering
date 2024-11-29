from build.Release import sorting

if __name__ == "__main__":
    print(dir(sorting))
    print("Examples of sorting with the C++ function:")
    v1 = [5, 6, 4, 1, 88, 3]
    v2 = [4, 3, 2, 1]
    v3 = [100, 2, 4, 645, 5, 11, 465, 1, 10, 44, 7, 2]
    print(f"v1 = {v1}, v2 = {v2}, v3 = {v3}, sorting...")
    print(f"Sorted, v1 = {sorting.the_sort(v1)}, v2 = {sorting.the_sort(v2)}, v3 = {sorting.the_sort(v3)}...")