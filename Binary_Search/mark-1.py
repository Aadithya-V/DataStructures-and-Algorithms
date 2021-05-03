# This is the initial version of my own binary search algorithm.
# 100, 22 is a curious case

upper_bound_ans, target_q = int(
    input("Enter the upperbound integer of the binary search : ")
), int(input("Enter the target integer : "))
prev_high: int

while upper_bound_ans != target_q:
    if upper_bound_ans > target_q:
        prev_high = upper_bound_ans
        upper_bound_ans = int(upper_bound_ans / 2)

        print(upper_bound_ans, prev_high)

    else:
        upper_bound_ans = upper_bound_ans + (int((prev_high - upper_bound_ans) / 2))
        print(upper_bound_ans)

print(str(upper_bound_ans) + " is the binary search result.")
