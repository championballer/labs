#!/bin/sh

echo "Please enter x:"
read x
echo "Please enter y:"
read y

echo "x+y = $(( x + y ))"
echo "x*y = $(( x * y ))"
echo "x/y = $(( x / y ))"
echo "x-y = $(( x - y ))"

echo "x%y = $(( x % y ))"
echo "x**y = $(( x ** y ))"
echo "++x = $(( ++x ))"
