#!/bin/sh

python3 pyviz.py `ruby -e "puts (-500..500).to_a.shuffle.join(' ')"
