# 对于边界处理，如果需要多层判断，先分析哪些判断走的是相同的流程，可以减少代码量

# 对于本题遇到逆序，可以选择：
# 1.将当前数字减小到等于后面数字
# 2.或者后面数字变大到等于当前数字
# 优先选择1，但当前面数字大于后面数字时，只能选择2
# 如下：
if i>0 and a[i-1]>a[i+1]:
	a[i+1] = a[i]
else:
	a[i] = a[i+1]