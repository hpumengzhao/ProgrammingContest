import math
try:
    while True:
        x,a,y,b=map(int,input().split());
        if x*b>a*y:
            print(">")
        if x*b==a*y:
            print("=")
        if x*b<a*y:
            print("<")
except EOFError:
    pass
