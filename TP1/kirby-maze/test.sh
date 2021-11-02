#!/bin/sh

TARGET=kirby

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
rm -f $TARGET


if [ -z ${CFLAGS+x} ]; then CFLAGS=""; fi
CFLAGS="-DNO_UI -Wall -Werror -Wextra -g $CFLAGS" make $TARGET >> $LOG 2>&1 || fail
coloredEcho "OK" green


#
# Test "entrée/sortie"
#
annoncer "Test 1"
test_entree_sortie "-1 b 0
14 10
.W..W..W.W...W
...W.W.W.W.W..
.WW..W...W.WW.
.W...WWW...W..
.W.W.....W..W.
...W.WWWWWW.W.
.W.W.W...W..W.
.WWW.W.W.W.W..
.W.W...W.W.WWW
...W.W.W.W....
1
13 9 a
0 0
" "13 9$" test_grep


annoncer "Test 2"
test_entree_sortie "-1 b 0
14 10
.W..W..W.W...W
...W.W.W.W.W..
.WW..W...W.WW.
.W.W.WWW...W..
.W.W.....W..W.
...W.WWWWWW.W.
.W.W.W...W..W.
.WWW.W.W.W.W..
.W.W...W.W.WWW
.....W.W.W....
1
13 9 a
0 0
" "13 9$" test_grep

exit 0
