#!/bin/sh
cmake -DCHECK=off -DARITH=gmp -DBN_PRECI=3072 -DFP_PRIME=3072 -DFP_QNRES=off -DFP_METHD="BASIC;COMBA;COMBA;MONTY;JMPDS;JMPDS;SLIDE" -DFPX_METHD="INTEG;INTEG;LAZYR" -DPP_METHD="LAZYR;OATEP" -DCFLAGS="-O2 -funroll-loops -fomit-frame-pointer" -DEP_PLAIN=on -DTESTS=10 -DBENCH=10 $1
