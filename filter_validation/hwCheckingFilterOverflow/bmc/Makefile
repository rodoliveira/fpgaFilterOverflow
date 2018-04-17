CC = cbmc
CFLAGS = --function filterVerify --no-unwinding-assertions
FILTER_DIR = ../filters
DIRECTORIES = $(abspath $(sort $(dir $(wildcard $(FILTER_DIR)/*/))))
NUMBER_OF_DIRECTORIES = $(words $(DIRECTORIES))
SUBDIRECTORIES = $(wordlist 2, $(NUMBER_OF_DIRECTORIES), $(DIRECTORIES))
SUBDIRNAMES = $(notdir $(SUBDIRECTORIES:%/=%))
OUTPUTS = $(SUBDIRNAMES:=.txt)


SRC = $(sort $(wildcard $(FILTER_DIR)/*.c/)) $(sort $(wildcard ./src/*.c/))

all: $(OUTPUTS)
SHELL = /bin/bash
$(OUTPUTS): 
	@echo 
	@echo Processing $@ ...
	$(eval VALUE=$(shell time(timeout 1800 $(CC) $(CFLAGS) $(SRC) -I$(FILTER_DIR)/$(basename $@) -I$(FILTER_DIR)) | grep 'input\|Runtime decision procedure' | awk '{if(NR!=2)print}' > ./$@; echo $${PIPESTATUS[0]}))
	@[[ $(VALUE) -eq 10 ]] && (echo Found a counterexample; cat ./$@;echo $@ , Failed >> dones.txt) || ([[ $(VALUE) -eq 0 ]] && (echo Verification Successful; rm ./$@;echo $@ , Success >> dones.txt) || (echo CBMC internal error; rm ./$@;echo $@ , Timeout >> dones.txt))
	@echo done $@...
	@echo 
	
.PHONY : clean

clean: 
	@rm -rf $(OUTPUTS)
	@rm -rf dones.txt
