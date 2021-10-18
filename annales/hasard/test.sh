#!/bin/sh

TARGET=tests

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

NOTE=0

annoncer "Compilation"

make clean >> $LOG 2>&1 || fail
make $TARGET >> $LOG 2>&1 || fail

coloredEcho "OK" green


#
# Test "entrée/sortie"
#
annoncer "Execution"
echo "100" | ./$TARGET >> $LOG 2>&1

EXIT_CODE=$?

if [ 2 -eq $EXIT_CODE ];
then
  NOTE=0
else
  if [ 1 -eq $EXIT_CODE ];
  then
    NOTE=20
  else
    coloredEcho "OK" green
    success
  fi
fi
fail
