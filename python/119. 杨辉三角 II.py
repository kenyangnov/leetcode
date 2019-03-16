#´úÂëµÄ¼ò½àĞÔ

if rowIndex == 0:
	return [1]
cur = [1, 1]
for i in range(rowIndex):
    temp = cur
    cur = [1]
	for j in range(i):
		cur.append(temp[j]+temp[j+1])
	cur.append(1)
return cur
		