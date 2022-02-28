#!/bin/bash

fileName="../data/ks_1000.dat"
maxTriesList="100 500 1000 5000 10000"
nbRun=100

echo "" > result.csv
echo "Iterations, Max try, fitness" >> result.csv
for maxTries in ${maxTriesList}
do
  for((i=0; i<"${nbRun}";i++))
  do
    { echo -n "$i" ','; echo -n "$maxTries" ',';}  >> result.csv
    ./cmake-build-release/TP1 ${fileName} ${maxTries} ${i} >> result.csv
  done
  echo
done