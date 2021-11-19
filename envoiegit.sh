#!/bin/bash
if [ $# -eq 1 ]
then
cd $1
fi
git add .
git commit -m "Exercice"
git push origin master
