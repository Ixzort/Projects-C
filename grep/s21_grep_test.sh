#!/bin/bash

DIFF_RES=""
COUNTER_SUCCESS=0
COUNTER_FAIL=0

./s21_grep e s21_grep.c > s21_grep.txt
grep e s21_grep.c > grep.txt
diff -s s21_grep.txt grep.txt
DIFF_RES="$(diff -s s21_grep.txt grep.txt)"
if [ "$DIFF_RES" == "Files s21_grep.txt and grep.txt are identical" ]
  then
    echo [1]
    (( COUNTER_SUCCESS++ ))
      echo "OK : Тест пройден"
  else
    echo "$TEST1" >> log.txt
      (( COUNTER_FAIL++ ))
fi
rm s21_grep.txt grep.txt

./s21_grep -e "for" s21_grep.c > s21_grep.txt
grep -e "for" s21_grep.c > grep.txt
DIFF_RES="$(diff -s s21_grep.txt grep.txt)"
if [ "$DIFF_RES" == "Files s21_grep.txt and grep.txt are identical" ]
  then
    echo [2]
    (( COUNTER_SUCCESS++ ))
      echo "OK : Тест пройден"
  else
    echo "$TEST1" >> log.txt
      (( COUNTER_FAIL++ ))
fi
rm s21_grep.txt grep.txt

./s21_grep -i e s21_grep.c > s21_grep.txt
grep -i e s21_grep.c > grep.txt
DIFF_RES="$(diff -s s21_grep.txt grep.txt)"
if [ "$DIFF_RES" == "Files s21_grep.txt and grep.txt are identical" ]
  then
    echo [3]
    (( COUNTER_SUCCESS++ ))
      echo "OK : Тест пройден"
  else
    echo "$TEST1" >> log.txt
      (( COUNTER_FAIL++ ))
fi
rm s21_grep.txt grep.txt

./s21_grep -v e s21_grep.c > s21_grep.txt
grep -v e s21_grep.c > grep.txt
DIFF_RES="$(diff -s s21_grep.txt grep.txt)"
if [ "$DIFF_RES" == "Files s21_grep.txt and grep.txt are identical" ]
  then
    echo [4]
    (( COUNTER_SUCCESS++ ))
      echo "OK : Тест пройден"
  else
    echo "$TEST1" >> log.txt
      (( COUNTER_FAIL++ ))
fi
rm s21_grep.txt grep.txt

./s21_grep -c e s21_grep.c > s21_grep.txt
grep -c e s21_grep.c > grep.txt
DIFF_RES="$(diff -s s21_grep.txt grep.txt)"
if [ "$DIFF_RES" == "Files s21_grep.txt and grep.txt are identical" ]
  then
    echo [5]
    (( COUNTER_SUCCESS++ ))
      echo "OK : Тест пройден"
  else
    echo "$TEST1" >> log.txt
      (( COUNTER_FAIL++ ))
fi
rm s21_grep.txt grep.txt

./s21_grep -l e s21_grep.c s21_grep.c s21_grep.c > s21_grep.txt
grep -l e s21_grep.c s21_grep.c s21_grep.c > grep.txt
DIFF_RES="$(diff -s s21_grep.txt grep.txt)"
if [ "$DIFF_RES" == "Files s21_grep.txt and grep.txt are identical" ]
  then
    echo [6]
    (( COUNTER_SUCCESS++ ))
      echo "OK : Тест пройден"
  else
    echo "$TEST1" >> log.txt
      (( COUNTER_FAIL++ ))
fi
rm s21_grep.txt grep.txt

./s21_grep -n e s21_grep.c > s21_grep.txt
grep -n e s21_grep.c > grep.txt
DIFF_RES="$(diff -s s21_grep.txt grep.txt)"
if [ "$DIFF_RES" == "Files s21_grep.txt and grep.txt are identical" ]
  then
    echo [7]
    (( COUNTER_SUCCESS++ ))
      echo "OK : Тест пройден"
  else
    echo "$TEST1" >> log.txt
      (( COUNTER_FAIL++ ))
fi
rm s21_grep.txt grep.txt


echo "SUCCESS: $COUNTER_SUCCESS"
echo "FAIL: $COUNTER_FAIL"