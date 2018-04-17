#!/bin/bash

echo GENERATING VHDL PACKAGE:

VHDL_SRC_PATH="../iir_standalone/"
VHDL_PACKAGE_NAME="iir_package.vhd"
CONFIG_NAME=$1
CONFIG_PATH="config_files/"
PYTHON_EXEC="python/gen_vhdl_package.py"

if [ ! -z $CONFIG_NAME ]
then
    python2 $PYTHON_EXEC $CONFIG_NAME $VHDL_SRC_PATH$VHDL_PACKAGE_NAME
    echo Generated finish: writefile ../iir_standalone/iir_package.vhd from $CONFIG_PATH$CONFIG_NAME
else
    echo usage ./gen_vhdl_package "CONFIG_FILE" ex: ./gen_vhdl_package config_files/teste.yaml
    echo Generated ERROR -- Wrong argument
fi


