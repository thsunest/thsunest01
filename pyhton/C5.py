ex =[0]*8
def es(x,possibility):
    ex[x-1]=possibility
def init():
    es(3,0.8)
    es(4,0.9)
    es(5,0.8)
    es(6,0.1)
    es(7,0.5)
def judge():
    ex[1]=min(ex[3], ex[4])*0.9
    ex[2]= ex[5]*0.7
    ex[2]= max(ex[6],ex[7])*(-0.3)
    r1 = ex[1] * 0.8
    r2 = ex[2] * 0.9
    return (r1 + r2)/(1 - min(abs(r1),abs(r2)))
if __name__ == '__main__':
    init()  
    print(judge())