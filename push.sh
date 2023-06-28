#!/bin/bash

if [ -z $1 ]; then
    echo "Please put message as parameter"
    exit 1
fi

git add .
git commit -m "$1"
git push origin master