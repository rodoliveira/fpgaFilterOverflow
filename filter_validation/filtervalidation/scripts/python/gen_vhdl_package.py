import yaml
import sys

# --- FILTER PARAMETERS BEGIN--- #
class Filter:
    def __init__(self):
        self.entity_name = "iir_unseting"
        self.bits = 0
        self.order = 5
        self.inputs = 0
        self.coef_in = []
        self.coef_out = []
        self.coef_out.append(0)
        self.nbits_frac = 0
        self.nbits_int = 0
        self.uplimit = 0
        self.lwlimit = 0
# --- FILTER PARAMETERS END --- #

def f2fixed(num, nfrac):
    data = int(num*2**nfrac)
    if num < 0:        
        data = int(((abs(data) ^ 0xffff) + 1) & 0xffff)
    if num !=0 and data == 0:
        print "warning: underflow at number: " + str(num) + " with " + str(nfrac) + " frac points"
    return data

def vhdl_adapt_out_coef(coefs):
    for i in range(0, len(coefs)-1):
        coefs[i] = coefs[i+1]
    coefs[len(coefs)-1] = 0;
    return coefs
                   
def getFilterParam(configFile, filter):
    with open(configFile, 'r') as f:
        param = yaml.load(f)
    filter.entity_name = param["filter"]["name"]
    filter.bits = int(param["filter"]["bits"])
    filter.order = int(param["filter"]["order"])
    filter.coef_in = param["filter"]["coef_in"]
    filter.coef_out = vhdl_adapt_out_coef(param["filter"]["coef_out"])
    filter.nbits_frac = param["filter"]["nbits_frac"]
    filter.nbits_int = param["filter"]["nbits_int"]
    filter.inputs = param["filter"]["ninputs"]
    filter.uplimit = param["filter"]["uplimit"]
    filter.lwlimit = param["filter"]["lwlimit"]
    print ("Init Filter... ")
    print (param["filter"])
    if filter.bits != 0:
        print "INIT OK"
    else:
        print "ERROR INIT FILTER"


# --- FUNCTIONS --- #
def printVHDLHex(num, nfrac):
    data = num & 0xffff
    return str("x\"{:04x}\"".format(data))

def printVHDLMap(filename, vec, nfrac):
    for i in range(0, len(vec)):
        filename.write(printVHDLHex(vec[i], nfrac))
        if (i == len(vec)-1):
            filename.write("\n);\n\n")
        else :
            filename.write(",\n")


    


# def printVHDLCore(filename, fileCore, flag):            
#     print_core = 0
#     findFlag = 0
#     for line in fileCore:
#         if line.rstrip('\n') == flag:
#             print_core = 1
#             findFlag = 1
#         if print_core == 1:
#             filename.write(line)
#     if findFlag == 0:
#         print "READING CORE TEXT... ERROR -> CORE TEXT FLAG NOT FOUND"
#         exit()
#     else:
#         print "READING CORE TEXT... OK"
            


def printVHDLHeader():
    # --- VHDL HEADER --- #
    fileGen.write("---PACKAGE GENERETADED AUTOMATICALLY\n\n")

def printVHDLLibraries():
    fileGen.write("library ieee;\n")
    fileGen.write("use ieee.std_logic_1164.all;\n")
    fileGen.write("use ieee.std_logic_unsigned.all;\n\n")
    

        
# --- INTERNAL PARAMETERS --- *
iir = Filter()
max_bits_multiplier = 64
coreFlag = "---@CORE_INIT"
portFlags = ("---@INIT_PORT", "---@END_PORT")
# ---

# --- FILES --- #
fileGen = open(sys.argv[2], 'w')
configFilename = sys.argv[1]
# ------------ #


#MAIN:
getFilterParam(configFilename, iir)
printVHDLHeader()
printVHDLLibraries()

fileGen.write("package iir_package is\n\n")
fileGen.write("constant NBITS : integer := " + str(iir.bits) + ";\n")
fileGen.write("constant NBITS_FRAC : integer := " + str(iir.nbits_frac) + ";\n")
fileGen.write("constant NBITS_INT : integer := " + str(iir.nbits_int) + ";\n")
fileGen.write("constant UPPER_LIMIT : integer := " + str(iir.uplimit) + ";\n")
fileGen.write("constant LOWER_LIMIT : integer := " + str(iir.lwlimit) + ";\n\n")
fileGen.write("constant NORDER : integer := " + str(iir.order) + ";\n")
fileGen.write("constant NINPUTS : integer := " + str(iir.inputs) + ";\n")
fileGen.write("constant NBITS_INTERNAL_MULTIPLIERS : integer := " + str(max_bits_multiplier) + ";\n\n")

fileGen.write("type in_out_type is array (0 to NINPUTS-1) of std_logic_vector(NBITS-1 downto 0);\n\n")

fileGen.write("type in_coef_type is array (0 to NORDER-1) of std_logic_vector(NBITS-1 downto 0);\nconstant IN_COEF_MAP : in_coef_type := (\n")
printVHDLMap(fileGen, iir.coef_in, iir.nbits_frac)

fileGen.write("type out_coef_type is array (0 to NORDER-1) of std_logic_vector(NBITS-1 downto 0);\nconstant OUT_COEF_MAP : in_coef_type := (\n")
printVHDLMap(fileGen, iir.coef_out, iir.nbits_frac)

fileGen.write("end iir_package;")

print "GENERATING FILTER... DONE! File: " + str(fileGen) + " SUCCESS"



