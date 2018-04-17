CC = gcc
CFLAGS = 
FILTER_DIR = ../filters
DIRECTORIES = $(abspath $(sort $(dir $(wildcard $(FILTER_DIR)/*/))))
NUMBER_OF_DIRECTORIES = $(words $(DIRECTORIES))
SUBDIRECTORIES = $(wordlist 2, $(NUMBER_OF_DIRECTORIES), $(DIRECTORIES))
SUBDIRNAMES = $(notdir $(SUBDIRECTORIES:%/=%))
OUTPUTS = $(SUBDIRNAMES)

SRC = $(sort $(wildcard $(FILTER_DIR)/*.c/)) $(sort $(wildcard ./src/*.c/))

all: $(OUTPUTS)
SHELL = /bin/bash
$(OUTPUTS): 
	@echo 
	@echo Compiling $@ ...
	$(CC) $(CFLAGS) $(SRC) -lm -I$(FILTER_DIR)/$(basename $@) -I$(FILTER_DIR) -I./src -o $@
	@echo done $@...
	@echo 
	
.PHONY : clean

clean: 
	@rm -rf $(OUTPUTS)
