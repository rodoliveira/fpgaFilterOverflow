#!/bin/bash

echo GENERATING FILTER CONFIG FILE:

FILTER_NAME=$1
FILTERS_PATH="/home/rodrigo/ufmg/fpgaFilterOverflow/filteroverflow/filters/"

C_SCRIPT="c/printFilter.c"

EXEC_PATH="execs/"
CONFIG_PATH="config_files/"
CONFIG_EXT=".yaml"


if [ ! -z $FILTER_NAME ]
then
    gcc $C_SCRIPT -I$FILTERS_PATH -I$FILTERS_PATH$FILTER_NAME -w -o $EXEC_PATH$FILTER_NAME
    $EXEC_PATH$FILTER_NAME $FILTER_NAME > $CONFIG_PATH$FILTER_NAME$CONFIG_EXT
    echo Generated finish: $CONFIG_PATH$FILTER_NAME$CONFIG_EXT
else
    echo Generated ERROR -- Wrong argument
    echo usage ./gen_filter_config "FILTER_NAME" ex: ./gen_filter_config lp2B_D10_F5
fi


