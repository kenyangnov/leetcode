# 1.more pythonic
cnt = 0
for i in A:
	if i % 2 == 0:
		cnt += i
# 写成：
cnt = sum(x for x in A if x % 2 == 0)

# 2.more pythonic
for i in queries:
	val = i[0]
	index = i[1]
	...
	
for i in range(len(queries)):
	val = queries[i][0]
	index = queries[i][1]
	...
	
# 写成：
for val, index in queries:
	if A[index] % 2 == 0: cnt -= A[index]
		A[index] += val
	if A[index] % 2 == 0: cnt += A[index]
		ans.append(cnt)
	