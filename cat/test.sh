#!bin/bash
COUNTER_SUCCESS=0
COUNTER_FAIL=0

./s21_cat s21_cat.c > s21_cat.txt
cat s21_cat.c > cat.txt
echo [1]
if [ -z "$(diff -q s21_cat.txt cat.txt)" ]; then
  echo "OK : Тест пройден"
  (( COUNTER_SUCCESS++ ))
else
  echo "ERROR : Тест не пройден"
    (( COUNTER_FAIL++ ))
fi
rm s21_cat.txt cat.txt

./s21_cat -b s21_cat.c > s21_cat.txt
cat -b s21_cat.c > cat.txt
echo [2]
if [ -z "$(diff -q s21_cat.txt cat.txt)" ]; then
  echo "OK : Тест пройден"
  (( COUNTER_SUCCESS++ ))
else
  echo "ERROR : Тест не пройден"
    (( COUNTER_FAIL++ ))
fi
rm s21_cat.txt cat.txt

./s21_cat -e s21_cat.c > s21_cat.txt
cat -e s21_cat.c > cat.txt
echo [3]
if [ -z "$(diff -q s21_cat.txt cat.txt)" ]; then
  echo "OK : Тест пройден"
  (( COUNTER_SUCCESS++ ))
else
  echo "ERROR : Тест не пройден"
    (( COUNTER_FAIL++ ))
fi
rm s21_cat.txt cat.txt

./s21_cat -n s21_cat.c > s21_cat.txt
cat -n s21_cat.c > cat.txt
echo [4]
if [ -z "$(diff -q s21_cat.txt cat.txt)" ]; then
  echo "OK : Тест пройден"
  (( COUNTER_SUCCESS++ ))
else
  echo "ERROR : Тест не пройден"
    (( COUNTER_FAIL++ ))
fi
rm s21_cat.txt cat.txt

./s21_cat -s s21_cat.c > s21_cat.txt
cat -s s21_cat.c > cat.txt
echo [5]
if [ -z "$(diff -q s21_cat.txt cat.txt)" ]; then
  echo "OK : Тест пройден"
  (( COUNTER_SUCCESS++ ))
else
  echo "ERROR : Тест не пройден"
    (( COUNTER_FAIL++ ))
fi
rm s21_cat.txt cat.txt

./s21_cat -t s21_cat.c > s21_cat.txt
cat -t s21_cat.c > cat.txt
echo [6]
if [ -z "$(diff -q s21_cat.txt cat.txt)" ]; then
  echo "OK : Тест пройден"
  (( COUNTER_SUCCESS++ ))
else
  echo "ERROR : Тест не пройден"
    (( COUNTER_FAIL++ ))
fi
rm s21_cat.txt cat.txt

./s21_cat -t s21_cat.c > s21_cat.txt
cat -t s21_cat.c > cat.txt
echo [7] 
if [ -z "$(diff -q s21_cat.txt cat.txt)" ]; then
  echo "OK : Тест пройден"
  (( COUNTER_SUCCESS++ ))
else
  echo "ERROR : Тест не пройден"
  (( COUNTER_FAIL++ ))
fi
rm s21_cat.txt cat.txt

echo "SUCCESS: $COUNTER_SUCCESS"
echo "FAIL: $COUNTER_FAIL"