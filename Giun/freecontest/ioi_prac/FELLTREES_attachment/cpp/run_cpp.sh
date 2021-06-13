#!/bin/bash

problem=felltrees
memory=524288  # 512MB
stack_size=524288  # 512MB

ulimit -v "${memory}"
ulimit -s "${stack_size}"
"./${problem}"
