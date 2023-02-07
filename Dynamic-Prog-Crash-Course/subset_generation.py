def combination_util(arr, tam_arr,tam_sub_conjunto, index, data, i):


    if index == tam_sub_conjunto:
        for j in range(tam_sub_conjunto):
            print(data[j], end=" ")
        print(" ")
        return


    if i >= tam_arr:
        return


    data[index] = arr[i]
    combination_util(arr, tam_arr,tam_sub_conjunto, index + 1, data, i + 1)


    combination_util(arr, tam_arr,tam_sub_conjunto, index, data, i + 1)


def print_combination(arr, tam_arr, tam_sub_conjunto):


    data = [0] * tam_sub_conjunto
    combination_util(arr, tam_arr,tam_sub_conjunto, 0, data, 0)


# Driver function to check for above function
arr = ['1', '[', ']', '40', 50]
print_combination(arr, len(arr), 4)
# This code is contributed by Ambuj sahu