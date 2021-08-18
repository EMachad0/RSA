#!/bin/bash
for i in {64..1024..64};
do 
    echo "test $i";
    for j in {1..100}
        do
            ./a.out ./main.cpp -t --sz $i;
        done
done > time_testing/time_test_log.txt