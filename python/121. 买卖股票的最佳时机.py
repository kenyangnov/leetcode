# 求顺序最大差值

for i in prices:
	if min>i:
		min = i
	else:
		res = max(res, i-min)