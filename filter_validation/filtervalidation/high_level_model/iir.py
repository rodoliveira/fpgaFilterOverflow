import numpy as np

def fixedMul(a, b, frac):
    a_t = np.int32(a)# & 0xffff
    b_t = np.uint32(b)#
    c_t = np.int32(np.int32(a_t*b_t)>>frac)
    print str(hex(a_t & 0xffffffff)) + " * " + str(hex(b_t & 0xffffffff)) + " = " + str(hex(c_t & 0xffffffff))
    return c_t
    

def f2fixed(num, nfrac):
    if num >= 0:
        data = int(num*2**nfrac+0.5)
    else:
        data = int(num*2**nfrac-0.5)
        data = int(((abs(data) ^ 0xffffffff) + 1) & 0xffffffff)
    if num !=0 and data == 0:
        print "warning: underflow at number: " + str(num) + " with " + str(nfrac) + " frac points"
    return data

def vec2fp(vec_in, nfrac):
    vec_out = []
    for i in range(0, len(vec_in)):
        vec_out.append(f2fixed(vec_in[i],nfrac))
        print hex(vec_out[i] & 0xffffffff)
#    print vec_out
    return vec_out
        
x_int = [1,2,3,4,5,6,7,8,9,10]
b_int = [0.206572,0.41314416,0.206572]
a_int = [-0.369527377351241,0.19581571]

x = [1,2,3,4,5,6,7,8,9,10] #vec2fp(x_int, 5);
x = [-53,55,55,55,5,6,7,8,9,10] #vec2fp(x_int, 5);
b = vec2fp(b_int, 5)#[7,13,7] #vec2fp(b_int, 5);
a = vec2fp(a_int, 5)

y = [0,0,0,0,0,0,0,0,0,0]

print "-----------------"
for i in range(0,len(x)):
    if i == 0:
        y[i] = fixedMul(x[i],b[0],5)
    elif i == 1:
        y[i] = fixedMul(x[i],b[0],5) + fixedMul(x[i-1],b[1],5) - fixedMul(y[i-1],a[0],5)
    else:
        y[i] = fixedMul(x[i],b[0],5) + fixedMul(x[i-1],b[1],5) + fixedMul(x[i-2],b[2],5) - fixedMul(y[i-1],a[0],5) - fixedMul(y[i-2],a[1],5)
    print "y = " + (hex(y[i] & 0xffff))
    
