#!/bin/bash

PROG=/home/kyrylopolis/pa1/Cv03CAS/cas

for IN_FILE  in progtest2tests/*_in.txt ; do
        REF_FILE=`echo -n $IN_FILE | sed -e 's/\(.*\)_in.txt$/\1_out.txt/'`
        $PROG < $IN_FILE > my_out.txt
        if ! diff $REF_FILE my_out.txt ; then
                echo "Fail: $IN_FILE";
                exit
        else
                echo "OK: $IN_FILE";
        fi
done

