#!/bin/bash

backup() {
  echo "Creating backup..."

  FILES="$@"

  for file in $FILES;
  do
    if [ -f "$file.bak" ]
    then
      echo "Skipping $file"
      continue
    fi
    echo "Creating backup of $file"
    cp "$file" "$file.bak"
  done



}

main() {

  echo "First Argument: $1"


  backup "$@"

}

main "$@"
