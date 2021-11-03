#!/bin/sh

TARGET=monter-escalier

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
gcc -o $TARGET $TARGET.c -Wall -Wextra -Werror >> $LOG 2>&1 || fail
coloredEcho "OK" green

annoncer "Execution"


./$TARGET > /dev/null 2>&1  && fail
./$TARGET -1 > /dev/null 2>&1 && fail

annoncer "test 1"
test_args_sortie "1" "1" test_diff_end
annoncer "test 2"
test_args_sortie "2" "2" test_diff_end
annoncer "test 3"
test_args_sortie "3" "3" test_diff_end
annoncer "test 4"
test_args_sortie "4" "5" test_diff_end
annoncer "test 5"
test_args_sortie "10" "89" test_diff_end
annoncer "test 6"
test_args_sortie "20" "10946" test_diff_end

exit 0
