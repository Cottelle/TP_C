#!/bin/sh

TARGET=main

#
# Ce placer dans le répertoire courant
#
TESTDIR="$(cd "$(dirname "$0}")" && pwd)"
cd "$TESTDIR"

#
# Conserver une trace de toutes les actions
#
LOG="test.log"
rm -f "$LOG"
touch "$LOG"

#
# Importer les fonctions communes à tous les tests
#
. ./fonctions.sh


#
# Compilation du programme.
#

annoncer "Compilation"
make clean
make $TARGET >> $LOG 2>&1 || fail
coloredEcho "OK" green


#
# Test "entrée/sortie"
#
for dir in $(find ./test-* -maxdepth 1 -type d -printf "%f\n"); do
  annoncer "Test entrée/sortie : $dir"
  $VALGRIND ./$TARGET < $dir/in > $dir/student.out
  if [ $? -ne 0 ]
  then
    cat $dir/student.out >> $LOG
    fail
  fi
  cat $dir/student.out >> $LOG
  python3 test.py $dir/out $dir/student.out
  if [ $? -ne 0 ]
  then
    fail
  fi
  coloredEcho "OK" green
done


exit 0
