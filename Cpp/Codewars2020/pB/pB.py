N = input()

arr1 = N.split(' ')[0]
arr2 = N.split(' ')[1]

ele1 = arr1[1:-1].split(',')
ele2 = arr2[1:-1].split(',')

L = len(ele1)

ans = [0] * L

for i in range(L):
    ans[i] += int(ele1[i]) + int(ele2[i])
    if ans[i] > 9:
        if i < L - 1:
            ans[i + 1] = 1
        else:
            ans.append(1)
        ans[i] %= 10

print('[' + str(ans[0]), end='')
for i in range(1, len(ans)):
    print(', ' + str(ans[i]), end='')
print(']')
