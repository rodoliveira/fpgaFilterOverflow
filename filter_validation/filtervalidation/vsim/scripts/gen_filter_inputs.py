import yaml
import sys
import random

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

#MAIN
iir = Filter()

# --- FILES --- #
fileGen = open(sys.argv[2], 'w')
configFilename = sys.argv[1]
# ------------ #

getFilterParam(configFilename, iir)


