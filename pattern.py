str=""

for i in range(1,8):
    for j in range(1,6):
        if ((i==1 and j>=2 and j<=5) or ((i==2 or i==3) and j==1) or (i==4 and j>=2 and j<=4) or((i==5 or i==6) and j==5) or(i==7 and j>=1 and j<=4)):
            str=str+"*"
        else:
            str=str+" "
    str=str+"\n"
print(str)