#!/bin/bash
for i in {32..128..2};
do 
    echo "test $i";
    for j in {1..10}
        do
            ./a.out ./main.cpp -t -b --sz $i;
        done
done > time_testing/time_break_log.txt