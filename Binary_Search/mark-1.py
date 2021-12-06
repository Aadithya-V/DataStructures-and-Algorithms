# This is the initial version of my own binary search algorithm.
# 100, 22/78 is a curious case

upper_bound_ans, target = int(
    input("Enter the upperbound integer of the binary search : ")
), int(input("Enter the target integer : "))
prev_high: int

while upper_bound_ans != target:
    if upper_bound_ans > target:
        prev_high = upper_bound_ans
        upper_bound_ans = int(upper_bound_ans / 2)

    else:
        upper_bound_ans = upper_bound_ans + (int((prev_high - upper_bound_ans) / 2))


print(str(upper_bound_ans) + " is the binary search result.")
