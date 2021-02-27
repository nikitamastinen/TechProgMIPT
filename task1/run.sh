#!/bin/bash

copy_from=$1
extension=$2
copy_to=$3
archive_name=$4

if ! [[ -d $copy_to ]] 
then
  mkdir "$copy_to"
fi
find "$copy_from" -type f -name "*.$extension" -exec cp --parents \{\} "$copy_to" \;
tar -czf "$archive_name" "$copy_to"
echo "done"
