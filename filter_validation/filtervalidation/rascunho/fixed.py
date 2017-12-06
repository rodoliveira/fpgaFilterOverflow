def fixed(num, nint, nfrac):
    data = int(num*2**nfrac)
    if num < 0:        
        data = int(((abs(data) ^ 0xffffffff) + 1) & 0xffffffff)
    return data

print(hex(fixed(-1.25, 2, 2)))
