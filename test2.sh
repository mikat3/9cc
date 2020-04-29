#!/bin/bash

assert() {
  expected="$1"
  input="$2"

  ./9cc "$input" > tmp.s
  cc -o tmp tmp.s
  ./tmp
  actual="$?"

  if [ "$actual" = "$expected" ]; then
    echo "$input => $actual"
  else
    echo "$input => $expected expected, but got $actual"
    exit 1
  fi
}

# Step.9

assert 25 "a = 3; b = 5 * 6 - 8; a + b;"
# assert 12 "a = 3; b = 5 * 6 - 8; a + b / 2;"    # Why 14 ?
assert 6  "foo = 1; bar = 2 + 3; foo + bar;"

echo OK
