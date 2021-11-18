#!/bin/sh

python3 pyviz.py `ruby -e "puts (-100..100).to_a.shuffle.join(' ')"
`
