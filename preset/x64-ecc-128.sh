#!/bin/sh
cmake -DCHECK=off -DARITH=x64-hacl-25519 -DFP_PRIME=255 -DFP_QNRES=off -DSTRIP=on -DEC_ENDOM=off -DEC_METHD="EDDIE" -DFP_METHD="INTEG;INTEG;INTEG;QUICK;LOWER;LOWER;SLIDE" -DED_METHD='EXTND;LWNAF;COMBS;INTER' -DCFLAGS="-O3 -funroll-loops -fomit-frame-pointer -march=native -mtune=native" -DWITH="DV;MD;BC;BN;FP;ED;EC;CP" $1
