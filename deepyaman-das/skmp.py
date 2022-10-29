from copy import deepcopy
for _ in range(int(input())):
    s=list(input())
    p=list(input())
    for i in p:
        s.remove(i)
    s.sort()
    a=deepcopy(s)
    a.append(p[0])
    a=sorted(a,reverse=True)
    if p[0] not in s:
        print(''.join(s[0:len(a) - a.index(p[0]) - 1])+''.join(p)+''.join(s[len(a)-a.index(p[0])-1:]))
    else:
        nwstr=''.join(s[0:s.index(p[0])])+''.join(p)+''.join(s[s.index(p[0]):])
        print(min(nwstr,''.join(s[0:len(a)-a.index(p[0])-1])+''.join(p)+''.join(s[len(a)-a.index(p[0])-1:])))