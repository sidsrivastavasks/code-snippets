import numpy as np
for _ in range(int(input())):
    n,x,p,k=map(int,input().split())
    a,r=list(sorted(map(int,input().split()))),1
    if(a[p-1]==x):
        print(0)
    elif(p<k and a[p-1]<x) or (p>k and a[p-1]>x):
        print(-1)
    else:
        a[k-1]=x
        a=sorted(a)
        arr = np.array(a)
        xx,yy = np.searchsorted(arr,x,side='left'),np.searchsorted(arr,x,side='right')-1
        xp=xx if abs(p-xx)<abs(p-yy) else yy
        if arr[p-1]!=x:
            r+=abs(xp-(p-1))
        print(r)